#include <iostream>
#pragma pack(2)

class A{
	int a;
	char b[10];
	short c;
	char d;
};

int main()
{
	std::cout << sizeof(A) << std::endl;
	return 0;
}