#include <iostream>
#include <map>
#include <vector>

using namespace std;

void func(vector<int>& v)
{
	int a = 1,  b = 1, c = 1, d= 1;
	int* e = new int(1);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(*e);
	delete e;
}


int main()
{
	int a = 1, b = 1, c= 1, d= 1, e = 1, f= 1 ;

	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
/*
	for(auto& e: m)
	{
		std::cout << e.first << " " << e.second << std::endl;
	}
*/
/*
	a = 2;	
	for(auto& e: v)
	{
		std::cout << e << std::endl;
	}
	const int& g = f;
	f = 3;
	std::cout << g << std::endl;
*/
	vector<int> v1;
	func(v1);

	for(auto& e:v1)	
	{
		std::cout << e << std::endl;
	}


	return 0;
}
