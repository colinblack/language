#include <iostream>
#include <string>
#include <vector>
#include <utility> 

using namespace std;


class mystring
{
public:
	string mstr;
 
	mystring(){}
	mystring(const char* a) : mstr(a){}
	mystring(const mystring &str) :mstr(std::move(str.mstr)){std::cout << "copy construct " << std::endl;}
 
	mystring& operator=(mystring&& rhs)//<span style="font-size:18px;">移动赋值运算符</span>
	{
		if (this == &rhs)
			return *this;
		mstr = std::move(rhs.mstr);
		std::cout << "copy operator" << std::endl;
		return *this;
	}
};

int main()
{
	vector<int> n = {-3,9,-6,3,8,7 };
	vector<mystring> sfrom = { mystring("a"), mystring("b"), mystring("c") };
	vector<mystring> sto(3);
	move(sfrom.begin(), sfrom.end(), sto.begin());//<span style="font-size:18px;">移动算法</span>
	for (auto &t : sto)
		cout << t.mstr << "\t";
	cout << endl;
 
	for (auto &t : sfrom)
		cout << t.mstr << "\t";
	cout << endl;

	return 0;
}
