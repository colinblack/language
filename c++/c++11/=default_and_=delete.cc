#include <iostream>

class Foo{
public:
	Foo(int i) :_i(i){}
	Foo() = default; //����default err
	Foo(const Foo& f):_i(f._i){}
	//Foo(const Foo& f) = default // err, �������첻�ܱ�����
	//Foo(const Foo& f) = delete; err,���п�������
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