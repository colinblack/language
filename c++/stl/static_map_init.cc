#include <iostream>
#include <map>

using namespace std;

map<int, int> b;

class A{
public:
		int func() ;
public:
		const static   map<int, int> a ; 
//		static  int a;

}; 

const  map<int, int> A::a = {{1, 2}}; 



//   int A::a = 1;

int main()
{
	A demo;	
   cout <<  A::a.at(1) << endl;

	return 0;
}
