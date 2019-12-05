#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>



int main(){
    pid_t pid = fork();
    if(pid == 0){
        while(1);
        printf("child process");
    }else if(pid > 0){
        printf("parent process");
    }else{
        printf("error");
        exit(-1);
    }

    wait(NULL);

    return 0;
}
