//°∂≥Ã–Ú‘±√Ê ‘±¶µ‰°∑P75
#include <iostream>

struct A{
	int a;
	int *b;
};

int main()
{
	A i;
	int* p = &i.a;
	p[0] = 1;
	p[1] = 2;

	std::cout << &i.a << " " <<  &i.b << std::endl;
	std::cout << p <<" " <<  p + 1 << std::endl;
	std::cout << i.a << " " << i.b << std::endl;
	return 0;
}