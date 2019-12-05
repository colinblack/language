#include <iostream>

//#pragma pack(4)

struct A{
    char  a;
    double b[2];
    char  c;
    int   d;
    char  e[3];
};
int main()
{
	char *buffer[1024];
	std::cout << &buffer[0]<< std::endl;
	int i = *reinterpret_cast<int *>(buffer+1);

	long long a;
	std::cout << sizeof(A) << std::endl;
	return 0;
}
