#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> v;
	//v.reserve(2);
	v.resize(2);	

	#if 0 
	for(int i = 0; i < 2; ++i)
	{
		v.emplace_back(i);
		std::cout << v.back() << std::endl;
	}
	#endif	
	
	std::cout << v.size() << std::endl;

	return 0;
}

