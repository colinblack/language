#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <algorithm>

struct item{
	int i,j;
item(int a, int b) : i(a) , j(b){}
item(const item& a)
{
	i = a.i;
	j = a.j;
}
item& operator=(const item& a)
{
	i = a.i;
	j = a.j;

	return *this;
}
};

 
int main() 
{
	std::vector<item> a;
	auto ita = a.begin();
	std::vector<item> b;
	auto itb = b.begin();
	std::swap(ita, itb);	


//	v.insert(a);
//	v.insert(item(3,4));
//	v.insert(item(5,6));
 
   // auto vi = v.begin();
 
//    std::advance(vi, 2);
/*
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		it->i = 2;
	}
 */
  //  std::cout << *vi << '\n';
}
