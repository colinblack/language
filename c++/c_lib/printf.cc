//用putchar实现printf函数封装接口
#include <stdio.h>
#include <stdlib.h>

void myprintf(const char *fmt, ...);
void print_array(char *array);
void print_num(int number, int count);

int main(void)
{

	char a = 200;
	myprintf("%x \n", a);
	%d  %x  %o  %c  %s  %
	输出"hello world %d %d %c %s \n"

	system("pause");
	return 0;
}

void myprintf(const char *fmt, ...)
{
	int *addr = (int *)&fmt; 不强制转换(int *)会警告
	addr++;
	while (*fmt)
	{
		if (*fmt != '%')不是'%'就打印
		{
			putchar(*fmt);
			++fmt;
			continue;
		}
		++fmt; %后面的格式符
		switch (*fmt)
		{
		case 'c': putchar(*((char *)addr++));	   break;
		case 'd': print_num(*((int *)addr++), 10); break;
		case 'o': print_num(*((int *)addr++), 8);  break;
		case 'x': print_num(*((int *)addr++), 16); break;
		case 's': print_array((char *)*addr++);   break;
		}
		++fmt;格式符后面的内容
	}
#if 0
	addr++;
	printf("%d \n", *((int *)addr++));
	printf("%d \n", *((int *)addr++));
	printf("%c \n", *((char *)addr++));
	printf("%s \n", (char *)*addr++);
#endif
}

void print_array(char *array)
{
	while (*array)
	{
		putchar(*array++);
	}
}
void print_num(int number, int count)最精湛写法
{
	if (number / count != 0)
		print_num(number / count, count);
	putchar("0123456789abcdef"[number%count]);number%count的值对应前面字符串的下标
}
