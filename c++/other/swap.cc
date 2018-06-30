//交换两个数，要写成泛型
#include <iostream>

#define SWAP(a, b) \
do{\
	auto tmp = a; \
	a = b; \
	b = tmp; \
} while (0)

int main()
{
	float a = 5.5;
	float b = 6.11;
	SWAP(a, b);
	
	std::cout << a << " " << b << std::endl;
	return 0;
}
