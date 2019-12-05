#include <iostream>

union u{
	short a;
	char b;
};

int main()
{
	
	u test;
	test.a = 0x1122;
	if(test.b == 0x11)
		std::cout << "big endian" << std::endl;
	else 
		std::cout << "little endian" << std::endl;

	return 0;
}
