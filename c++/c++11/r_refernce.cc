#include <iostream>

template <class T>
void f(T&& param)
{
}

void f1(int&& x)
{
}
int main()
{
	int x = 10;
	f(x);
	f1(x);//err 只有当&&为universal references 时才会引用左值
	return  0;
}