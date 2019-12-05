#include <iostream>
#include <cstdio>
#include <typeinfo>

class A{
public:
	virtual void fun(){std::cout << "A" << std::endl;};
	int  a; 
};


class B : public A{
public:
	void fun(){std::cout << a << std::endl;};
	int  b; 
};

class C : public B{
};

void fun(int** argv)
{

}

int main()
{
	A a1;
	a1.a = 1;
	long* v_a  = (long*)&a1;
	printf("before: v_table a addr: 0x%p \n", *v_a);

	B b1;
	b1.b = 2;
	b1.a = 3;
	a1 = b1;
	v_a  = (long*)&a1;
	printf("after:  v_table a addr: 0x%p \n", *v_a);
	
	printf("==========================================\n ");
	A*p = &a1;
	p->fun();
	printf("%d \n", p->a);

	long*pb = (long*)&b1;	
	printf("before: v_table a addr: 0x%p \n", *pb);
	A*q = &b1;
	printf("after:  v_table a addr: 0x%p \n", *(long*)q);

	B* qq = (B*)p; 
	qq->fun();

	return 0;

}
