#include <iostream>
int i = 6;

int& get()
{
	return i;
}


int main()
{
	int* a = &get();
	std::cout << *a << std::endl;
	return 0;
}
