//数组指针
#include<iostream>
#include<stdlib.h>



int main(void)
{
	int array2[10]{1,2,3,4,5,6,7,8,9,0};
	typedef int(*PMyArrayType)[10];
	PMyArrayType pmyArray;
	pmyArray = &array2;
	(*pmyArray)[0] = -1;
	for(int i = 0; i < 10; ++i)
	{
		std::cout << array2[i] << " " << std::endl;
		
	}

	return 0;
}