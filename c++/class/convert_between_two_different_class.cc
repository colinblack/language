//两个不同类之间的转换
//《程序员面试宝典第5版》 p72

#include <iostream>

class A{
public:
	A() :_a(1), _b(2){}
	~A(){}
	void func(){ std::cout << _a << " " << _b << std::endl; }

private:
	int _a;
	int _b;
};

class B{
public:
	B() :_c(3){}
	~B(){}
	void func(){ std::cout << _c << std::endl; }
private:
	int _c;
};

int main()
{
	A a;
	B* p = (B*)&a;
	p->func();

	return 0;
}