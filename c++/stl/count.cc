//std::count
#include <iostream>
#include <algorithm>
#include <vector>

using std::count;  
using std::vector;

int main()
{
	vector<int> v{1,2, 3, 4, 5};		
	int cnt = count(v.begin(), v.end(), 3);
	std::cout << cnt << std::endl;

	return 0;
}
