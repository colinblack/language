//����ָ�����������η��ʺ����麯�����Ա�� ��˹���һ�����ƵĽṹ�ɶ���ָ����� 2017.5.28

#include <iostream>


using Func = void(*)();

struct vtable{
	Func array[4];
	int a;
	char b;
	double c;
};
//���ְ���ָ������Ľṹ��Ͱ�������ָ��Ľṹ����ڴ沼���ǲ�һ���ģ����Ժ������ж���ָ����ʵ��³������

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