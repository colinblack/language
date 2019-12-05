#include <sys/socket.h> //socket listen bind                                     
#include <arpa/inet.h> // sockaddr head                                                                                                                                                                   
#include <string.h>  //memset and strlen head                                       
#include <sys/socket.h> //socket listen bind                                        
#include <iostream>                                                                 
#include <time.h>                                                                   
#include <stdio.h>                                                                  
#include <unistd.h>
                                                                                    
#define MAXLINE 4096                                                                
#define LISTENQ 1024                                                                
                                                                                    
using namespace std;                                                                
                                                                                    
int main(int argc, char ** argv)                                                    
{                                                                                   
    int listenfd, connfd;                                                           
    socklen_t len;                                                                  
    struct sockaddr_in servaddr, cliaddr;                                           
    char buff[MAXLINE];                                                             
    time_t ticks;                                                                   
    listenfd = socket(AF_INET, SOCK_STREAM, 0);                                     
    memset(&servaddr, 0, sizeof(servaddr));                                         
    servaddr.sin_family = AF_INET;                                                  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);                                   
    servaddr.sin_port = htons(10000);                                               
                                                                                    
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));                 
    int ret = listen(listenfd,LISTENQ);                                             
    cout << "go to listen" <<ret<< endl;                                            
    for(; ;)                                                                        
    {                                                                               
        len=sizeof(cliaddr);                                                        
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);               
        cout << "connfd = " << connfd << inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)) << endl;
        sleep(20);                                                                  
        ticks = time(NULL);                                                         
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));                   
        write(connfd, buff, strlen(buff));                                          
        cout << "write date ok" << endl;                                            
        sleep(20);                                                                  
        close(connfd);                                                              
    } 
    return 0;                                                                    
}    

