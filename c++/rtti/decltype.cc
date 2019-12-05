/*
 * decltype.cc
 *
 *  Created on: 2019年1月23日
 *      Author: colin
 */
#include <iostream>
#include <typeinfo>
#include <vector>

class A
{
public:
	virtual ~A(){}
	virtual void func(){}


};



class B : public A
{
public:
	virtual ~B(){}
	virtual void func(){}
};


int main()
{

	std::vector<A*> v;
	v.push_back(new B);
//	std::cout << typeid(*p).name()<< std::endl;
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		printf("%s", typeid(**it).name());
	}


	return 0;
}
