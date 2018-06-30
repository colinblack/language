#include <iostream>
class A{
public:
	A():a(1){ std::cout << "A construct " << std::endl; }
	void funcA()
	{
		func();
	}
	void funcB()
	{
		this->func();
	}
	virtual void func()
	{
		std::cout << "A::func" << std::endl;
	}
	void func_a()
	{
		std::cout << "A::func_a" << std::endl;
	}

	int a;
};

class B :public A
{
public:
	B():b(2){ std::cout << "B construct " << std::endl; }
	void func()
	{
		std::cout << "B::func" << std::endl;
	}
	void func_b()
	{
		std::cout << "B::func_b" << std::endl;
	}
	int b;
};
class C :public A
{
public:
	void func()
	{                                                                             
		std::cout << "C::func" << std::endl;
	}
};

int main()
{
	A *p = new B;
	std::cout << p->a << std::endl;
//	std::cout << p->b << std::endl; 无法调用b中数据，只能通过虚函数
	p->funcA(); //打印什么
	p->funcB(); //打印什么

	C* p1 = (C*) new B;
	B* p2 = (B*) new A;
	p1->func();
	p2->func();
	p2->func_b();


	int a = 1;
	int &b = a;
	printf("%p, %p \n", &b, &a);
	return 0;
}
