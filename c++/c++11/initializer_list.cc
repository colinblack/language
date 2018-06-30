#include <iostream>


void print(std::initializer_list<int> vals)
{
	for (auto i: vals)
	{
		std::cout << i << std::endl;
	}

}

int main()
{
	print({1,2,3,4,5});
	return 0;
}