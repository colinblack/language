#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;
using std::pair;

void test_insert(map<string, int>& m)
{
	pair<string, int> tmp(string("number5"), 5);
	m.insert(tmp);

}


void test_look(map<string, int>& m)
{
	for (auto i : m)
	{
		//i.first = "number3"; 不能改变键值
		i.second = 6; //可以修改实值
		std::cout << i.first << " " << i.second << std::endl;

	}
}

int main()
{
	map<string, int> m;
	m["number1"] = 1;
	m["number2"] = 2;
	m["number3"] = 3;
	m["number4"] = 4;
	test_insert(m);
	//std::cout << m.size() << std::endl;
	test_look(m);

	
	return 0;
}