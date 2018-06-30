#include <iostream>
#include <vector>

using namespace std;
#define SIZE 5

class MyString
{
};

template <class T>
void output_static_data(const T& obj)
{
}


template <class Container>
void test_moveable(Container c)
{
	typedef typename iterator_traits<typename Container::iterator>::value_type Valtype;
	for (long i = 0; i < SIZE; ++i)
	{
		c.insert(c.end(), Valtype());
	}
	output_static_data(*(c.begin()));
	Container c1(c);
	Container c2(std::move(c));
	c1.swap(c2);
}

int main()
{
	test_moveable(vector<MyString>());
	return 0;
}