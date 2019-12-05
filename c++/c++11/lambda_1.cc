#include <iostream>

class A
{
public:
	A(){std::cout << "construct" << std::endl;}
	A(const A& obj){std::cout << "copy construct" << std::endl;}
	int e;

};

int main()
{
	A a;	
	int c = 0;
	if([&]()->int{a.e = 2;c = 2; return c} == 2)
		std::cout << "aa" << std::endl;
	std::cout << a.e << " " << c << std::endl;
	return 0;
}
