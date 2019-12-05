#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	s.insert(10);
    s.insert(1);
	s.insert(4);
    s.insert(8);
	
	for(auto it = s.begin(); it != s.end();)
	{
		if(*it == 10)
			it = s.erase(it);		
		else
			it++;
	}
	
	for(auto& e : s)
	{
		cout << e << endl;
	}
	
	s.erase(12);

	return 0;
}
