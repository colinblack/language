#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>


void sigint_handler(int signo)
{
    printf("sigint_handler, pid: %d\n", getpid());
}

int main()
{
    signal(SIGALRM, sigint_handler);
    alarm(5);

    int ret = fork();
    if(ret < 0)
    {
    	perror("fork error:");
    	exit(EXIT_FAILURE);
    }
    else if(ret == 0)
    {
        signal(SIGALRM, sigint_handler);
        alarm(5);
        while(1);
    }
    else
    {
    	wait(NULL);
    }

    return 0;
}
