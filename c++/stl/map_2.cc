#include <iostream>
#include <map>
#include <vector>

using namespace std;
class A{
public:
	A(){std::cout << "construct" << std::endl;}
	A(const A& obj){std::cout << "copy construct" << std::endl;}
	A& operator=(const A& obj){if(this != &obj){std::cout <<"copy operator" << std::endl;}; return *this;}
	~A(){std::cout << "destruct" << std::endl;}
};


int main()
{ 
/*eg1
	map<unsigned, A> m;

	m[1] = A();	
	m[1] = A();	
	
*/
/*eg2
	map<unsigned, vector<A>> m1;
	vector<A> a;
	a.reserve(2);
	a.push_back(A());
	a.push_back(A());

	std::cout << "\n\n";
	vector<A> b;
	b.reserve(2);

	b.push_back(A());
	b.push_back(A());

	std::cout << "\n\n";

	m1[1] = a;
	m1[1] = b;

*/
/*eg3*/
	map<unsigned, vector<A>> m2;
	vector<A> a;
	a.push_back(A());

	std::cout << "\n\n";
	vector<A> b;
	b.reserve(2);

	b.push_back(A());
	b.push_back(A());

	std::cout << "\n\n";

	m2[1] = a;
	m2[1] = b;
	while(1);
	return 0;
}
