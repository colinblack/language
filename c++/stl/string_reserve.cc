#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <cstdio>


using namespace std;


int main()
{
	map<string, string> m;
	string ss;
	ss = "dddddd\0\0\0dajdkj";

	std::cout << ss << std::endl;
	std::cout << "===============================" << std::endl;

	std::cout << ss.c_str() << " " << ss.size() << " " <<  ss.capacity() << std::endl;
	//ss.reserve(20);
	ss.resize(20);

	std::cout << ss.c_str() << " " << ss.size() << " " <<  ss.capacity() << std::endl;
	
	ss += "xxxddd";
	for(auto& e : ss)
	{
	 	printf("0x%x ", e);	
	}
	std::cout << ss.c_str() << " " << ss.size() << " " <<  ss.capacity() << std::endl;



	return 0;
}
