/*如果将互斥锁属性的类型设置为PTHREAD_MUTEX_RECURSIVE，则同一个线程可以多次进入临界区*/

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
pthread_mutex_t mutex;
pthread_mutexattr_t attr;

void* func(void* arg){
	if(*(char*)arg == '\0') return NULL;
	pthread_mutex_lock(&mutex);
	char* str = (char*)arg;
	while(*str != '\0'){
		fputc(*str, stdout);
		str++;
	}
	fputc('\n', stdout);
	func((char*)arg+1);
	pthread_mutex_unlock(&mutex);
	return NULL;
}
int main(){
	int ret;
	if(( ret = pthread_mutexattr_init(&attr)) != 0){
		fprintf(stderr, "create mutex attribute error. msg:%s", strerror(ret));
		exit(1);
	}
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex, NULL);
	pthread_t p1, p2;
	char str1[8], str2[8];
	sprintf(str1, "abcdefg");
	sprintf(str2, "1234567");
	if((ret = pthread_create(&p1, NULL, func, str1)) != 0){
		fprintf(stderr, "create thread error. msg:%s", strerror(ret));
		exit(1);
	}
	if((ret = pthread_create(&p2, NULL, func, str2)) != 0){
		fprintf(stderr, "create thread error. msg:%s", strerror(ret));
		exit(1);
	}
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
}
