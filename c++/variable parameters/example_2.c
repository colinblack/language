
#include <stdio.h>

void func(int *a, ...);

int main(void)
{
	int a = 10;

	func(&a, 20, 30, 40, 50, 60, 'e', "hello world");


	return 0;
}

void func(int *a, ...)
{
	//	(int *)(&a) ; 

	printf("a:%d \n", *a);
	printf("b:%d \n", *((int *)(&a) + 1));//&a取自*a，是2级指针(同下)
	printf("c:%d \n", *((int *)(&a) + 2));
	printf("d:%d \n", *((int *)(&a) + 3));
	printf("e:%d \n", *((int *)(&a) + 4));
	printf("f:%d \n", *((int *)(&a) + 5));
	printf("f:%c \n", *(char*)((int *)(&a) + 6));
	printf("f:%s \n", (char*)(*((int *)(&a) + 7)));
}
