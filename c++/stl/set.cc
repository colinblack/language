#include <iostream>
#include <set>
#include <algorithm>
#include <functional>

using std::set;


//通及键值个数，0表示没有
void test_count(set<int>& a)
{
//	std::cout << a.size() << std::endl;
	std::cout << a.count(1) << std::endl;
	std::cout << a.count(-1) << std::endl;
}

void look(set<int>& a) //已经排序好了， 默认从小到大
{
	for (auto i : a)
	{
		std::cout << i << std::endl;
	}
}
//
//class compare{
//public:
//	bool operator()(const int& l, const int& r)  const
//	{
//		return l > r;
//	}
//
//};

void construct_down(set<int>& a)  //降序构造集合
{
	int array[10] = { 11,4,6,7,12,13,1,0,-1,5 };
//	set<int> a(array, array + 10, std::greater<int>()); 没有？
}

int main()
{
	int array[10] = { 2, 5, 6, 1, 3, 0, 10, 8, 9, 4 };
	set<int> a(array, array+10); //set的key值不能相同
	//test_count(a);
	look(a);

	return 0;
}
