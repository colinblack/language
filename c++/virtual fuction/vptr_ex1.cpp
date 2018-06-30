//二级指针能用来依次访问含有虚函数类成员， 因此构造一个类似的结构由二级指针访问
//http://blog.csdn.net/haoel/article/details/3081328
#include <iostream>


using Func = void(*)();

struct vtable{
	Func (*array)[4];
	int a;
	char b;
	double c;
};


void func1()
{
	std::cout << "fucn1" << std::endl;
}

void func2()
{
	std::cout << "fucn2" << std::endl;
}

void func3()
{
	std::cout << "fucn3" << std::endl;
}

Func parray[4] = {func1, func2, func3, nullptr};

vtable instace =
{
	&parray,
	1,
	'a',
	2.5
};



int main()
{

	

	Func pfunc = nullptr;
	for (auto i = 0; i < 3; ++i)
	{
		std::cout << instace.array[i] << std::endl;
	}

	std::cout << std::endl;

	int** p = (int**)(&instace);

	//std::cout << Func(*p) << std::endl;
	//std::cout << (Func)(*p)[1] << std::endl;
	//std::cout << (Func)(*p)[2] << std::endl;

	//std::cout << p[0] << std::endl;
	//std::cout << p[1] << std::endl;
	//std::cout << p[2] << std::endl;

	for (int i = 0; (Func)p[0][i] != nullptr; ++i)
	{
		pfunc = (Func)p[0][i];
		pfunc();
	}

	std::cout << (int)p[1] << std::endl;
	std::cout << (char)p[2] << std::endl;
    //怎么转换为double
	return 0;
}