#include <iostream>
#include <typeinfo>
#include <map>
using namespace std;

int main()
{
	map<int, int > a;
	map<int , int>& b = a;
	auto c = b;
	int d = 0;
	std::cout <<  typeid(d).name() << std::endl;

	auto& e = b;
	e.begin();	
	return 0;
}
