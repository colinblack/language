//看信号量是一个函数指针问题
//http://blog.chinaunix.net/uid-27213819-id-3971416.html


#include <stdio.h>



typedef void* (*Func)(void*);

typedef struct Data{
	int a;
	float b;
}Data_t;

void* func(Data_t* var)
{
	printf("int func \n");
	return NULL;
}

int  main()
{
	Func p = (void*)func; //注意此处转换
	Data_t var;
	p(&var);

	return 0;
}