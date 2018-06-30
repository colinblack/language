#include <iostream>


int main()
{
	int array[2][3] = { 1, 2, 3, 4, 5, 6 };
	int(*p)[3] = array;

	std::cout << **(p + 1) << std::endl;   //Êı×éÖ¸Õë

	char* array1[] = { "hello", "world", "hehe" };
	char** p1 = array1;
	

	std::cout << *(p + 1) << std::endl;


	return 0;
}