/*
 * thread.cc
 *
 *  Created on: 2019年2月20日
 *      Author: colin
 */

#include <pthread.h>
#include <iostream>
#include <cstdio>
#include <unistd.h>


void* func(void* argc)
{
	int num = *(int*)argc;
	std::cout << "child thread "<< std::endl;
	sleep(100);
}


int main()
{
	pthread_t tid[10];
	for(int i = 0; i < 10; ++i)
	{
		pthread_create(&tid[i], NULL, func, (void*)&i);
	}


	for(int i = 0; i < 10; ++i)
	{
		pthread_join(tid[i], NULL);
	}
	
	while(1);
	return 0;
}




