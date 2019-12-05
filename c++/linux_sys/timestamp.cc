#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <time.h>



bool IsSunday(uint32_t ts){
        time_t tTimes = (time_t)ts;

            struct tm tmNow;   //定义tm类型
                localtime_r(&tTimes, &tmNow);
                std::cout << tmNow.tm_wday << std::endl;

                    return tmNow.tm_wday == 0 ? true : false;
}

unsigned GetHourTime(unsigned times){
    time_t tTimes = (time_t)times;

    struct tm tmNow;   //定义tm类型
    localtime_r(&tTimes, &tmNow);

    tmNow.tm_isdst = 0;
    tmNow.tm_min = 0;
    tmNow.tm_sec = 0;
    tmNow.tm_hour = 0;

    return (unsigned)mktime(&tmNow);
}



int main(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::cout << tv.tv_sec  << std::endl; 

    uint32_t time =  tv.tv_sec;
    time_t t = (time_t)time;
    
    struct tm tmNow;   //定义tm类型
    localtime_r(&t, &tmNow);
    std::cout << tmNow.tm_hour << std::endl;
    
    IsSunday(1565452800);
    std::cout << GetHourTime(time) << std::endl;

    return 0;
}

