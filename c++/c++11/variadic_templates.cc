#include <iostream>
#include <bitset>

void print()  //处理最后情况
{
}

template <class T, class... Types>

//个数随意， 且类型随意
//1
void print(const T& firstArg, const Types&... args)
{
	std::cout << firstArg << std::endl;
	std::cout << "args" << sizeof...(args) << std::endl;
	print(args...); //递归
}

//2
template <class... Types>
void print(const Types&... args)
{

}

//1,2两个模板能同时并存

int main()
{
	
	print(7,5,"hello",std::bitset<16>(377),42);
	return 0;
}