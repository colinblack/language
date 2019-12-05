#include <iostream>

class A
{
protected:
	A(){std::cout << "A construct" << std::endl;}
public:
	A(const A& obj){std::cout << "A copy construct" << std::endl;}

};

class B : public A
{
public:
	B(){std::cout << "B construct" << std::endl;}
	//B(const B& obj){std::cout << "B copy construct" << std::endl;}

};


int main()
{
	B b;
	B b1 = b;
}
