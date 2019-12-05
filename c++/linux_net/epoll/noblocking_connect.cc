#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>              
#include <sys/epoll.h>
#include <sys/socket.h>  
#include <sys/wait.h>  
#include <netinet/in.h>  
#include <netinet/tcp.h>  
#include <sys/epoll.h>  
#include <sys/sendfile.h>  
#include <sys/stat.h>  
#include <string.h>  
#include <fcntl.h>  



#define NUM 1

void setnonblocking(int sockfd) {  
    int opts;  
  
    opts = fcntl(sockfd, F_GETFL,0);  
    if(opts < 0) {  
        perror("fcntl(F_GETFL)\n");  
        exit(1);  
    }  
    opts = (opts | O_NONBLOCK);  
    if(fcntl(sockfd, F_SETFL, opts) < 0) {  
        perror("fcntl(F_SETFL)\n");  
        exit(1);  
    }  
}  
  

int main()
{
	int sockfd[NUM] = {0};	
	
	int epfd = epoll_create(NUM);
	if (epfd == -1) {  
        perror("epoll_create");  
        exit(EXIT_FAILURE);  
    }  
	
	const char* ip = "192.168.100.252";
	struct sockaddr_in server_address;
	//bzero( &server_address, sizeof( server_address ) );
 	memset(&server_address, 0, sizeof (server_address));
	server_address.sin_family = AF_INET;
//	inet_pton( AF_INET, ip, &server_address.sin_addr );
	server_address.sin_addr.s_addr = inet_addr(ip);
	server_address.sin_port = htons(8080);
	for(int i = 0; i < NUM; ++i)
	{

		sockfd[i] = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd[i] < 0)
		{
			perror("create socket error");
			exit(1);
		}
      	setnonblocking(sockfd[i]);            
		
		struct epoll_event ev;
		ev.events = EPOLLOUT|EPOLLIN; 
		ev.data.fd = sockfd[i];
		
		if (epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd[i], &ev) == -1) {  
        	perror("epoll_ctl: listen_sock");  
        	exit(EXIT_FAILURE);  
    	}  
		
		int ret = connect(sockfd[i], (struct sockaddr* )&server_address, sizeof(struct sockaddr));
		if(ret  < 0)
		{
			if(errno == EINPROGRESS)
				break;
			else
			{
					printf("connect: i: %d, fd: %d, errno: %d, %s \n", i, sockfd[i], errno, strerror(errno));
				
				exit(1);
			}
		}
	}

//	sleep(5);
	int epoll_size = 0;
	struct epoll_event  events[NUM];	
	
	int err = 0;
	socklen_t len = sizeof(err);
	int ret = 0;
	while(1)
	{
		epoll_size = epoll_wait(epfd, events, NUM, -1);	
		if(epoll_size == -1)
		{
			perror("epoll wait error");
			exit(1);
		}	

		for(int i = 0; i < epoll_size; ++i)
		{
			int event = events[i].events;
			if(event & EPOLLOUT) 			
			{
				int fd = events[i].data.fd;				
				//int ret = connect(fd, (struct sockaddr* )&server_address, sizeof(struct sockaddr));
				//printf("connected fd: %d, ret: %d \n", fd, ret);
				/*if(ret < 0)
				{
					if(errno == EINPROGRESS)
               			 break;
					else
					{
						printf("connect: fd: %d, errno: %d, %s \n", fd, errno, strerror(errno));
						
					}
				}
				*/
				char buf[255] = {0};
				memcpy(buf, "hello world \n", sizeof(buf));
				if(-1 == write(fd, buf, sizeof(buf)))
				{
					perror("write failed");
				}
			}
			if(event & EPOLLERR) 			
			{
				int fd = events[i].data.fd;				
				ret = getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &len);					
				printf("EPOLLERR:  ret: %d, errno:  %s \n", ret, strerror(errno));
			}
			if(event & EPOLLIN) 			
			{
				int fd = events[i].data.fd;				
//				ret = getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &len);					
//				printf("EPOLLIN:  ret: %d, errno:  %s \n", ret, strerror(errno));
				char buf[255] = {0};
				if(-1 == read(fd, buf, sizeof(buf)))
				{
					perror("read error");
				}
				printf("%s", buf);

			}

		}		
				
	}

	return 0;
}

