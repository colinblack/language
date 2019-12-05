#include <iostream>
#include <mutex>
#include <thread>
#include <exception>
#include <stdexcept>
#include <climits>

//层次锁

using namespace std;

class HierarchicalMutex {
private:
	mutex inter_mutex_;
	unsigned long const level_value_;
	unsigned long previous_value_;

	static thread_local unsigned long this_thread_value_;

public:
	HierarchicalMutex(unsigned long level_value) :level_value_(level_value),previous_value_(0) {}

	void checkLock() {
		//this_thread_value_是线程本地变量，所以每个线程各存一份，用来保存线程自带的层次值
		//线程获得锁之后，该层次值就成了该线程自带的值了，当该线程试图去获取层次值更高的锁时，这样是不允许的
		if (this_thread_value_ <= level_value_)
		{
			throw logic_error("can not lock\n");
		}
	}

	void lock() {
		checkLock();
		inter_mutex_.lock();
		//获得锁之后，首先将线程原有的值保存下来，然后如果其再去获得一个层次值较小的锁的话，更新值为更小的那个值
		previous_value_ = this_thread_value_;
		this_thread_value_ = level_value_;
	}

	void unlock() {
		//如果获得的层次较小的锁释放了，那么该线程的层次值恢复成原有的值
		this_thread_value_ = previous_value_;
		inter_mutex_.unlock();
	}

	bool trylock() {
		checkLock();
		if (!inter_mutex_.try_lock())
		{
			return false;
		}
		previous_value_ = this_thread_value_;
		this_thread_value_ = level_value_;
		return true;

	}
};

thread_local unsigned long HierarchicalMutex::this_thread_value_ = ULONG_MAX;


HierarchicalMutex high_level_mutex(10000); // 1
HierarchicalMutex low_level_mutex(5000);  // 2

int do_low_level_stuff()
{
	std::cout << "do low level stuff" << std::endl;
	return 0;
}

int low_level_func()
{
  std::lock_guard<HierarchicalMutex> lk(low_level_mutex); // 3
  return do_low_level_stuff();
}

void high_level_stuff(int some_param)
{
	std::cout << "high level stuff" << std::endl;
}

void high_level_func()
{
  std::lock_guard<HierarchicalMutex> lk(high_level_mutex); // 4
  high_level_stuff(low_level_func()); // 5
}

void thread_a()  // 6
{
  high_level_func();
}

HierarchicalMutex other_mutex(100); // 7
void do_other_stuff()
{
	std::cout << "do other stuff" << std::endl;
}

void other_stuff()
{
  high_level_func();  // 8
  do_other_stuff();
}

void thread_b() // 9
{
  std::lock_guard<HierarchicalMutex> lk(other_mutex); // 10
  other_stuff();
}

int main() {
	std::thread t1(thread_a);
	t1.join();

	std::thread t2(thread_b);
	t2.join();

	return 0;
}
