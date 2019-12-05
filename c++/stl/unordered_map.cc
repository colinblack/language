#include <iostream>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>


using namespace std; 


std::unordered_map<int, map<int,vector<int>>> m;


vector<int>& get(int k1, int k2)
{
	return m[k1][k2];
}



int main()
{
	m[1][2].push_back(3);
	m[2][3].push_back(4);
	m[3][4].push_back(5);

	std::unordered_map<int, int> m1;
	m1.insert({1, 1});
	m1[1] = 2;

	auto it = m1.find(1);

	std::cout << "m1 " << it->first << " " << it->second << std::endl; 
	auto res = get(2, 3);

	std::cout << res.size() << std::endl;
	return 0;
}
