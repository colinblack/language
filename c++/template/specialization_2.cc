//�ο�http://blog.csdn.net/gatieme/article/details/50953564

#include <iostream>
#include <cstdlib>
#include <float.h>


//����ģ���ػ�
template<class T>
bool compare(const T left, const T right)
{
	return left == right;
}

template< >
bool compare(const char* left, const char* right)
{
	std::cout << "int specialization func" << std::endl;
	return static_cast<bool>(!strcmp(left, right));
}

//��ģ���ػ�




int main()
{
	const char* str1 = "abc";
	const char* str2 = "bcd";
	compare(str1, str2);
	return 0;
}