//#include <iostream>
#include <stdio.h>

struct S
{
	int arr[8];
//	S& operator=(const S& var)
//	{
//		std::cout << "copy operator" << std::endl;
//	}
};

int main()
{
	struct S s1;
//	s1.arr[0] = 1;
//	s1.arr[1] = 2;

	struct S s2;
//	s2.arr[0] = 3;
//	s2.arr[1] = 4;
//	s1 = s2;

//	std::cout << s1.arr[0] << " " << s1.arr[1] << std::endl;
//	printf("%d, %d", s1.arr[0], s2.arr[1]);
	return 0;
}
