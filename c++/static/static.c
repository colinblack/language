//静态变量存储在静态区，压栈是不会再栈区分配内存
#include<stdio.h>

void fun()
{
	static int i = 0;
	i++;
	if(i > 10)
		return ;
	fun();
	printf("%d \n", i);
}

int main(void)
{
	fun();
	return 0; 
	
}