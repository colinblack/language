#include <iostream>
#include <pthread.h>
#include <cstdio>
#include <unistd.h>
#include <exception>
#include <stdexcept>

void* output(void* arg)
{
    int* p = (int*)arg;
    std::cout << *p << std::endl;
    sleep(2);
     throw std::runtime_error("error");
}

int main()
{
    try
    {
        pthread_t pid;
        int i = 6;
        pthread_create(&pid, NULL,  output, &i);        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    getchar();
    return 0;
}