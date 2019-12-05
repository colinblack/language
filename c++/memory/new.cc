#include <iostream>
#include <cstdlib>

char memory[256] = {0};
std::size_t  pos = 0;

class Foo
{
public:
	Foo(int a):a_(a){}
	void* operator new(std::size_t count);

	int a_;
};

void* Foo::operator new(std::size_t count)
{
	std::cout << count << std::endl;
/*
 	if(pos >= 256)
		throw std::bad_alloc();
	std::cout << count << std::endl;
	pos += count;
	return (void*)(memory+pos);	
*/
//	Foo* p = (Foo*)malloc(count);
//	return p;
	return NULL;
}


int main()
{

	Foo* A[64]; 
	for(int i = 0; i < 64; ++i)
	{
		A[i] = new Foo(1);
	}
	

	return 0;
}
