#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include<utility>
#include <iterator>
#include <vector>
using namespace std;
int main()
{

int a = 6;	
set<unsigned> on;
on.insert(1);
on.insert(2);
on.insert(3);

set<unsigned> in;
std::for_each(on.begin(), on.end(), [&](unsigned n){
	in.insert(n);
});

for(auto it = in.rbegin(); it != in.rend(); ++it)
{
	std::cout << std::distance(it, in.rend()) << std::endl;
}
vector<int> v;
v.push_back(1);

//std::advance(v.begin(), 1);

	return 0;
}

