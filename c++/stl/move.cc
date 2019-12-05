#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>

using std::vector;
using std::list;
using std::unordered_map;


class A
{
public:
	A(){std::cout << "construct" << std::endl;}
	A(const A& obj){std::cout << "copy construct" << std::endl;}

};


int main()
{
	vector<int> v1(10, 9);	
	vector<int> v2(std::move(v1));	

	list<int> l1{1, 2, 3, 4, 5};
	list<int> l2(std::move(l1));

	//std::cout << l1.empty() << " " << l2.size() << std::endl;

	//std::cout << v1.size() <<  " " <<  v2.size() << std::endl;
	A a;
	unordered_map<unsigned, A> m;
	//m.insert(std::make_pair(1, std::move(a)));

	vector<A> v;
	v.push_back(a);	

	return 0;
}
