#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//嵌套锁

int a=0;
int b=0;
pthread_mutex_t mutex_b;

void *another(void* arg)
{
    pthread_mutex_lock(&mutex_b);
    printf("new_thread,got mutex_b,waiting for mutex_b 1\n");
    pthread_mutex_lock(&mutex_b);
    printf("new_thread,got mutex_b,waiting for mutex_b 2\n");
    pthread_mutex_unlock(&mutex_b);
    pthread_mutex_unlock(&mutex_b);
    pthread_exit(NULL);
}

int main()
{
    pthread_t id;
    pthread_mutex_init(&mutex_b, NULL);
    pthread_create(&id, NULL, another, NULL);


    pthread_join(id, NULL);
    pthread_mutex_destroy(&mutex_b);
    return 0;
}
