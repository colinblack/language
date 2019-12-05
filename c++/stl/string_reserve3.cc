#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>


using namespace std;


int main()
{
	map<string, string> m;
	string ss;
	ss = "dddddd\0\0\0";

	for(int i = 0; i < ss.size(); ++i)
	{
		printf("%c ", ss[i]);
	}
	std::cout << std::endl;	

	//std::cout << ss << std::endl;

	ss.resize(64);
	m["cpOrderNumber"] = ss;
	m["notifyUrl"] = "hello";
	//m.insert({"cpOrderNumber", ss});
	//m.insert({"notifyUrl", "hello"});
	//m.insert({"orderAmount", "9800.00"});
	//m.insert({"orderDesc", "消耗1元人民币可获得首充礼包"});
	//m.insert({"orderTime", "20190114024614"});
	//m.insert({"orderTitle", "首充礼包"});
	//m.insert({"packageName", "game.tywyh5.rpk"});
	//m.insert({"version", "1.0.0"});

	string s="";	

	for(auto& e:m)
	{
		s += e.first + "=" + e.second + "&";
	}

    std::cout << s.size() << "  " << s.capacity() << std::endl;
    std::cout << s.c_str() << std::endl;

	char arr[] = "\0";	
	std::cout << strlen(arr) << std::endl;

	std::cout << "=======================" << std::endl;
	string sss = "dbhd_1";

	
	return 0;
}
