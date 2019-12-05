#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include<utility>
using namespace std;
int main()
{

int a = 6;	
set<unsigned> on;
std::map<int, int> m1{ { 1, 2 }, { 3, 4 } ,{2, 1}, {4, 1}, {5, 1}, {6,1}};
std::for_each(m1.begin(), m1.end(), [&](set<unsigned> on){
  // if(a.first == 3) m1.erase(a.first);
  // cout << a.first << endl;
});
if(1)
{
std::for_each(on.begin(), on.end(), [&](unsigned v){
	cout << v << " " << a << endl;
});
}
	return 0;
}

