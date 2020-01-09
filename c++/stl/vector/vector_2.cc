#include <iostream>
#include <vector>


class A{
public:
	A(){std::cout << "construct" << std::endl;}
	A(const A& obj){std::cout << "copy construct" << std::endl;}
};

std::vector<A> func()
{
	std::vector<A> a;
	a.push_back(A());
	
	return a;
}
void func2(std::vector<A>& a)
{
	a.push_back(A());
}

int main()
{
	std::vector<A> a;
	func2(a);	

	return 0;
}
