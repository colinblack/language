#include <iostream>

class Foo{
public:
	Foo(int i) :_i(i){}
	Foo() = default; //不加default err
	Foo(const Foo& f):_i(f._i){}
	//Foo(const Foo& f) = default // err, 拷贝构造不能被重载
	//Foo(const Foo& f) = delete; err,已有拷贝构造
	//void func() = default; //err
	//void func1() = delete //ok
private:
	int _i;
};



int main()
{
	Foo f;
	return 0;
}