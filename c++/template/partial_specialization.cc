#include <iostream>


template <class T1, class T2>
void func(T1 a, T2 b)
{
}

template <class T2>
void func(int a, T2 b)
{
	std::cout << "partial_specialization" << std::endl;
}


int main()
{
	func(2, 2.5);

	return 0;
}