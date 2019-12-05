#include <iostream>

class A{
	public:
	int a; 
	int b;
	char c[10];
};



int main()
{
	A a;
	std::cout << a.a << " " << a.b <<  std::endl;

	return 0;
}
