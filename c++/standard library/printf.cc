//��putcharʵ��printf������װ�ӿ�
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
	���"hello world %d %d %c %s \n"

	system("pause");
	return 0;
}

void myprintf(const char *fmt, ...)
{
	int *addr = (int *)&fmt; ��ǿ��ת��(int *)�ᾯ��
	addr++;
	while (*fmt)
	{
		if (*fmt != '%')����'%'�ʹ�ӡ
		{
			putchar(*fmt);
			++fmt;
			continue;
		}
		++fmt; %����ĸ�ʽ��
		switch (*fmt)
		{
		case 'c': putchar(*((char *)addr++));	   break;
		case 'd': print_num(*((int *)addr++), 10); break;
		case 'o': print_num(*((int *)addr++), 8);  break;
		case 'x': print_num(*((int *)addr++), 16); break;
		case 's': print_array((char *)*addr++);   break;
		}
		++fmt;��ʽ�����������
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
void print_num(int number, int count)�տд��
{
	if (number / count != 0)
		print_num(number / count, count);
	putchar("0123456789abcdef"[number%count]);number%count��ֵ��Ӧǰ���ַ������±�
}
