#include<stdio.h>

typedef int (*func_1)(int);                       //创建一个函数指针
typedef int (*func_2)(int*, int*, int*);

int multi(int* a, int* b, int* c)
{
	return (*c = (*a) * (*b));
}

int inc(int a)
{
	return (++a);
}

void show(func_2 func, int var_1, int* var_2)
{
	func_1 p = inc;
	int tmp = p(var_1);
	func(&tmp, &var_1, var_2);
	printf("%d", *var_2);

}

int main(void)
{
	int a = 0;
	show(multi, 10, &a);
	getchar();
	return 0;
}