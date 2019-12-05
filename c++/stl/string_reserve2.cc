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
	ss = "dddddd  ";
	ss.resize(10);

	string ss1 = "aaaaa";
	string ss2 = "bbbbb";
	string ss3 = "ccccc";
	string ss4 = "ddddd";
	string ss5 = "eeeee";
	
	
	m["ss"] = ss;
	m["ss1"] = ss1; 
	m["ss2"] = ss2; 
	m["ss3"] = ss3; 
	m["ss4"] = ss4; 
	m["ss5"] = ss5; 

	string res;
	for(auto& e : m)
		res += e.first + '=' + e.second;

	std::cout << res << std::endl;
	return 0;
}
