#include <iostream>
#include <vector>
using namespace std;

#define SIZE 5
class MyString
{
};

template <class T>
using Vec = vector<T, allocator<T>>;


template <class T>
void output_static_data(const T& obj)
{
}


template <class T, template<class> class Container>
class XCls
{
private:
	Container<T> c;
public:
	XCls(){
		for (long i = 0; i < SIZE; ++i)
		{
			c.insert(c.end(), T());
		}
		output_static_data(T());
		Container<T> c1(c);
		Container<T> c2(std::move(c));
		c1.swap(c2);
	};


};


int main()
{
	XCls<MyString, Vec> a;
	return 0; 
}