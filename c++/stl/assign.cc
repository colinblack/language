#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	unsigned short int  a[10] = 
	{
		1,1,1,1,1,1,1,1,1,1
	};
	string str;
	str.assign(reinterpret_cast<char*>(a), 20);
	for(auto & i : str)	
		printf("%x ", i);
	return 0;
}
