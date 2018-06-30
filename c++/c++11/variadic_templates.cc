#include <iostream>
#include <bitset>

void print()  //����������
{
}

template <class T, class... Types>

//�������⣬ ����������
//1
void print(const T& firstArg, const Types&... args)
{
	std::cout << firstArg << std::endl;
	std::cout << "args" << sizeof...(args) << std::endl;
	print(args...); //�ݹ�
}

//2
template <class... Types>
void print(const Types&... args)
{

}

//1,2����ģ����ͬʱ����

int main()
{
	
	print(7,5,"hello",std::bitset<16>(377),42);
	return 0;
}