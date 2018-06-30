//二级指针能用来依次访问含有虚函数类成员， 因此构造一个类似的结构由二级指针访问 2017.5.28

#include <iostream>


using Func = void(*)();

struct vtable{
	Func array[4];
	int a;
	char b;
	double c;
};
//这种包含指针数组的结构体和包含二级指针的结构体的内存布局是不一样的，所以后面我有二级指针访问导致程序崩溃

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



vtable instace = 
{
	{ &func1, &func2, &func3 , nullptr},
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

	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
	std::cout << p[2] << std::endl;

	//for (int i = 0; (Func)p[0][i] != nullptr; ++i)
	//{
	//	pfunc = (Func)p[0][i];
	//	std::cout << pfunc << std::endl;
	//}

	//
	return 0;
}