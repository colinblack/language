#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <iterator>

using std::vector;
using std::swap;

struct bb{
	int c; 
	int b;

	bb():c(0), b(0){}
	bb(int cc, int bb) : c(cc), b(bb){}
};

int main()
{
	vector<bb> a;
	a.push_back(bb(1, 0));
	a.push_back(bb(2, 0));
	a.push_back(bb(3, 4));
	a.push_back(bb(4, 5));
	a.push_back(bb(5, 6));
	a.push_back(bb(6, 7));
	a.push_back(bb(7, 8));
	a.push_back(bb(8, 9));
	a.push_back(bb(9, 0));

//    a.erase(std::remove_if(a.begin(), a.end(), [&](bb e){return e.b == 0;}), a.end());

//	while(a.size() > 5)
//	{
//		int i = rand() % a.size();	
//		swap(a[i], a.back());
//		a.pop_back();
//	}
	
	
	vector<bb> x;
	x.push_back(bb(8, 8));
	x.push_back(bb(9, 9));

	vector<bb> y;
	y.push_back(bb(10, 10));
	
//	std::copy(x.begin()+1, x.end(), std::back_inserter(y));	

	std::move(x.begin(), x.end(), y.begin());
/*
	for(auto it = a.begin(); it != a.end();)
	{
		if(it->b == 0)
		{
			it = a.erase(it);
		}
		else
		{
			++it;	
		}
	}
*/

/*	for(auto& e : y)
	{
		std::cout << e.c << " " << e.b << std::endl;
	}
*/


	for(auto it = a.begin(); it != a.end();)
	{
		if(it->b == 0)	
		{
			std::swap(*it, a.back());
			a.pop_back();
		}
		else
		{	
			++it;
		}

	}

	for(auto& e : a)
	{
		std::cout << e.c << " " << e.b << std::endl;
	}

	return 0;
}
