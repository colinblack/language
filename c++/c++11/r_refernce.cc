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
	f1(x);//err ֻ�е�&&Ϊuniversal references ʱ�Ż�������ֵ
	return  0;
}