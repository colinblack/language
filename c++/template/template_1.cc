#include <iostream>
#include <cstdlib>


template <class T1>
T1 *CreateObj()
{
    T1 *p = (T1*)malloc(sizeof(T1)); 
    return p;
}


int main(){
	
	int* p = CreateObj<int>();
	return 0;
}
