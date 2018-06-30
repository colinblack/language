#include <iostream>
#include <vector>
#define CASE 2

using std::vector;


void test_insert();
void test_erase();
void swap();  


int main()
{
//	test_insert();
	//test_erase();
	swap();
	return 0;
}

void swap()
{
	vector<int> v(10,10);
	std::cout << v.capacity() << std::endl;
	vector<int>().swap(v); //free内存

	std::cout << v.capacity() << std::endl;

}


void test_insert()
{
	//case1
#if(CASE == 1)
	vector<int> test;
	//vector<int>::iterator it = test.begin();
	auto it = test.begin();
	test.insert(it + 1, 2, 2); //error 如果vector在插入之前没 有元素, iterator 要从begin开始
	std::cout << test.size() << std::endl;

#elif(CASE == 2)	
	//case2
	vector<int> test2(2,2);
	auto it = test2.begin(); 
	test2.insert(it + 1, 2, 2);//1
//	std::cout << *it << std::endl; //error 此处it已经无效 
	/*for (auto i : test2)
		std::cout << i << std::endl;*/

	auto it2 = test2.begin();
	test2.insert(it2, 2, 2);  //2
	
	auto it3 = test2.begin();
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	test2.insert(it3, array, array + 10);  //3
//	std::cout << test2.capacity() << std::endl;


	auto it4 = test2.begin();
	std::initializer_list<int> l = {1,2,3,4};
	test2.insert(it4, l);    //4


	//5 右值引用

	// http://www.cplusplus.com/reference/vector/vector/insert/
#endif	
}



void test_erase()
{
	vector<int> test3(10,10);
	auto it = test3.begin();
	test3.erase(it, it+3);   //1 erase 不改变容量
     
	const std::string& a = "hello world";
}