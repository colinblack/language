#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	map<unsigned, unsigned>	userMap{{1, 0}, {2, 1}, {3, 2}, {4, 1}, {5, 4}};
	std::for_each(userMap.begin(), userMap.end(), [&](map<unsigned, unsigned>::reference it){
		if(it.second == 1)
		{
			userMap.erase(it.first);
		}
	});	
	for(auto &e :userMap)
	{
		std::cout << e.first << "  " << e.second << std::endl;
	}

	return 0;
}
