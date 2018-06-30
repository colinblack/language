//《程序员面试宝典》 p76

#include <iostream>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int(*p)(int, int) = max;
	std::cout << p(1, 2) << std::endl; //形式1
	std::cout << p(p(1,3), 2) << std::endl;

	std::cout << (*p)(1, 2) << std::endl; //形式2
	std::cout << (*p)((*p)(1, 3), 2) << std::endl;


	return 0;
}
