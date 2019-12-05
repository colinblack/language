#include <iostream>
//const类型不能被修改

void test_1()
{
	const int a = 5;
	int& b = const_cast<int&>(a);
	b = 6;
	std::cout << a << b << std::endl;
}

void test_2()
{
	struct A{
		A(int a) :_a(a){}
		int _a;   //_a不是const类型所以能修改？
	};
	
	const A x(5);
	A b = x;
	A& y = const_cast<A&>(x);
	y._a = 6;

	std::cout << y._a << x._a << std::endl;

}

void test_3()
{
	int a = 7;
	const int b = 8;

	//a = b; //ok

	int* p1 = &a;
	const int *p2 = &b;

	//p1 = p2; //error
	p1 = const_cast<int*>(p2); //ok
	*p1 = 5;
	std::cout << a << b << std::endl;
	std::cout << p1 << " " << &b << std::endl;
}


int main()
{
	test_1();
	//test_2();
	//test_3();
	return 0;
}