#include <iostream>
#include <cfloat>
#include <cstdio>


int main()
{
	float f = 1.4f;
	double d = 1.4d;
	float f1 = 1.5f;
	double d1 = 1.5d;
	if(d1 <= DBL_EPSILON && d1 >= -DBL_EPSILON)
		;
	std::cout << DBL_EPSILON << std::endl;
	
	std::cout << (f == d) << std::endl;
	std::cout << (f1 == d1) << std::endl;
 	std::cout << f1 << " " << d1 << std::endl;
	float a = 0.4;
	int * p = (int*)&a;
	printf("%x \n", *p);

	std::cout << FLT_MAX << std::endl;
	return 0;
}
