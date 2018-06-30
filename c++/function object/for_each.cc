#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<stdlib.h>
using namespace std;

 vector<int> i_data;

 template <class T>
class func
{
public:
	
	void operator()(const T &c)
	{
		  i_data.push_back(c-'0');
	}

};

int main(void)
{
	char data[] = { '4','7','9','10','2','3','7' };
	int len = sizeof(data) / sizeof(data[0]);

	for_each(data, data+len,func<char>());
	sort(i_data.begin(), i_data.end(), greater<int>());


	vector<int>::iterator it = i_data.begin();
	for (; it != i_data.end(); ++it)
		cout << *it << endl;

	system("pause");
	return 0;
}