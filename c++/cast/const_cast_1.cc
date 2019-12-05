#include <iostream>
#include <string>
#include <cstdio>
#include <string.h>


int main()
{
	//std::string s = "hello world";
	const char* s = new char[10];
	
	char* ss = const_cast<char*>(s);
//	ss[0] = 'H';
//	ss[1] = 'E';
//	ss[2] = 'L';
/*
	for(int i = 0; i < s.size(); ++i)
	{
		std::cout << ss[i] << std::endl;
	}
*/
	
    //std::cout << s << std::endl;
	
	const int a = 5;
	int * p = const_cast<int*>(&a);
	*p = 8;
	
	std::cout << a << std::endl;
   // std::cout << "s: " << s << std::endl;
	//printf("%p, %p", ss, s.c_str());	
	return 0;
}
