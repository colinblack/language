
#include <stdio.h>
#include <stdarg.h>

//va_start
//va_end
//va_arg

void func(int a, ...);

int main(void)
{
	func(10, 20, 30, 40, -1);//-1表示传完，一般行业标准
	return 0;
}
//va_start	va_arg	va_end
void func(int a, ...)
{
	va_list  ap;
	va_start(ap, a);
	printf("%p \n", &a);
	int tmp;

	tmp = va_arg(ap, int);

	printf("tmp:%d \n", tmp);

	tmp = va_arg(ap, int);

	printf("tmp:%d \n", tmp);
	tmp = va_arg(ap, int);

	printf("tmp:%d \n", tmp);
	tmp = va_arg(ap, int);

	printf("tmp:%d \n", tmp);

	va_end(ap);
}
