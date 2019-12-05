#include <iostream>


int main()
{
	short var = 0x1122;
	char* p = (char*)&var;
	if(*p == 0x11)
		std::cout << "big endian" << std::endl;
	else 
		std::cout << "little endian" << std::endl;

	return 0;
}
