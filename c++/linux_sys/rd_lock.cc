#include<stdio.h>
#include<unistd.h>
#include<malloc.h>
#include<stdlib.h>
#include<pthread.h>
#include<string>
#include<string.h>
#include<time.h>
#include<sys/time.h>

int time()
{
/*
	time_t timep;
	struct tm *p; 
	time(&timep); 
	p = localtime(&timep);
	char buf[20]= {0};
	sprintf(buf, "%d-%d-%d %d:%d:%d", (1900 + p->tm_year), ( 1 + p->tm_mon), p->tm_mday,  (p->tm_hour), p->tm_min, p->tm_sec);
*/
	 struct timeval tv; 
	 gettimeofday(&tv, NULL);
	 return tv.tv_usec;
}

pthread_rwlock_t rwlock;//声明读写锁
int count;
//写者线程的入口函数
void*route_write(void*arg)
{
    int i=*(int*)arg;//i是写者线程的编号
    free(arg);
    while(count < 3){
		printf("time: %d, thread%d try write \n", time(), i);
        int t=count;
        //加锁
        pthread_rwlock_wrlock(&rwlock);
        printf("time: %d, route_write:%d,%#x,count=%d,++count=%d\n",time(), i,\
                pthread_self(),t,++count);
		int j = 0;
		while(j++ < 100000000)
			;
        //解锁
        pthread_rwlock_unlock(&rwlock);
    }
}
//读者线程的入口函数
void*route_read(void*arg)
{
    int i=*(int*)arg;//i是读者线程的编号
    free(arg);
	printf("time: %d, thread%d try read \n", time(), i);
    while(count < 3){
        //加锁
        pthread_rwlock_rdlock(&rwlock);
//        printf("time: %d, route_read:%d,%#x,count=%d\n",time(), i,pthread_self(),count);
        //解锁
        pthread_rwlock_unlock(&rwlock);
    }
}
int main()
{
    int i=0;
    //初始化读写锁
    pthread_rwlock_init(&rwlock,NULL);
    pthread_t tid[8];
    //创建3个写者线程
    for(i=0;i<3;i++){
        int*p=(int*)malloc(sizeof(int));
        *p=i;
        pthread_create(&tid[i],NULL,route_write,(void*)p);
    }
    //创建3个读者线程
    for(i=0;i<5;i++){
        int*p=(int*)malloc(sizeof(int));
        *p=i;
        pthread_create(&tid[i+3],NULL,route_read,(void*)p);
    }
    //主线程等待新创建的线程
    for(i=0;i<8;i++)
        pthread_join(tid[i],NULL);
    //销毁读写锁
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
