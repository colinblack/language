#include <iostream>
#include <memory>

class A
{



};

int main()
{
	
	std::unique_ptr<A> p(A());
 
	auto p1 = std::move(p);

	if(p == nullptr)
		std::cout << "p is null" << std::endl;

	if(p1 == nullptr)
		std::cout << "p1 is null" << std::endl;

	return 0;
}

