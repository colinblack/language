#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main()
{

	vector<int> v;
	v.resize(3);
	for(auto& e:v)	
	{
		std::cout << e << std::endl;
	}

	v.push_back(1);

	v.reserve(8);
	std::cout << v.size() << std::endl;
	for(auto& e:v)	
	{
		std::cout << e << std::endl;
	}
	return 0;
}
