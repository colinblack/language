#include <iostream>
#include <thread>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
 
int num = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 
int64_t get_current_timestamp()
{   
    struct timeval now = {0, 0}; 
    gettimeofday(&now, NULL);
    return now.tv_sec * 1000 * 1000 + now.tv_usec;
}
 
void thread_proc()
{
    for(int i=0; i<100000000; ++i){
        pthread_mutex_lock(&mutex);
        ++num;
        pthread_mutex_unlock(&mutex);
    }   
}
 
int main()
{
    int64_t start = get_current_timestamp();
   std::thread t1(thread_proc), t2(thread_proc);
    t1.join();
    t2.join();
    std::cout<<"num:"<<num<<std::endl;
    int64_t end = get_current_timestamp();
    std::cout<<"cost:"<<end-start<<std::endl;
 
    pthread_mutex_destroy(&mutex);    //maybe you always foget this
 
    return 0;
}

