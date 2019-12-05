#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define MAX_CON 5000


int main()
{
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0)
	{
		perror("create socket error");
		exit(1);
	}

	sockaddr_in local;
	bzero(&local, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = inet_addr("192.168.100.252");
    local.sin_port = htons(8080);

	if(bind(listenfd, (struct sockaddr *) &local, sizeof(local)) < 0) {
		perror("bind\n");
		exit(1);
    }

	listen(listenfd, 1);

	int epoll_fd = epoll_create(MAX_CON);
	if(-1 == epoll_fd)
	{
		printf("create epoll error: %s \n", strerror(errno));
		exit(1);
	}
	epoll_event ev;
	ev.data.fd = listenfd;
	ev.events = EPOLLIN;
	if(-1 == epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listenfd, &ev))
	{
		printf("epoll ctl error: %s \n", strerror(errno));
		exit(1);
	}

	epoll_event events[MAX_CON];

	while(1)
	{
		int ready_num = epoll_wait(epoll_fd, events,MAX_CON, -1);
		if(ready_num == -1)
		{
			printf("[epoll_wait] error: %s \n", strerror(errno));
			exit(1);
		}
		for(int i = 0; i < ready_num; ++i)
		{
			auto event = events[i].events;
			if(event & (EPOLLERR | EPOLLHUP))
			{
				//连接断开
				perror("connect broken \n");
				//移除
				close(events[i].data.fd);
				continue;
			}
			if(event & EPOLLIN)
			{
				if(events[i].data.fd == listenfd)
				{
					sockaddr_in addr;
					socklen_t len = sizeof(addr);
					int sockfd = accept(listenfd, (sockaddr*)&addr, &len);
					if(sockfd == -1)
					{
						printf("[accept] error: %s \n", strerror(errno));
						exit(1);
					}
					epoll_event e;	
					e.data.fd = sockfd;
					e.events = EPOLLIN|EPOLLOUT; 
					if(-1 == epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sockfd, &e))
					{
						printf("epoll ctl error: %s \n", strerror(errno));
						exit(1);
					}
				}
				else
				{
					char buf[256] = {0};
					ssize_t  count = read(events[i].data.fd, buf, sizeof(buf));					
					if(count == -1)
					{
						printf("read error: %s \n", strerror(errno));
						exit(1);
					}
					else if(count == 0)
					{
						printf("socket %d closed \n", events[i].data.fd);
						close(events[i].data.fd);
					}
					else
					{
						if(write(1, buf, count) == -1)
						{
							perror("writ error");
							exit(1);
						}
/*
						epoll_event e;	
						e.data.fd = events[i].data.fd;
						e.events = EPOLLOUT; 
						if(-1 == epoll_ctl(epoll_fd, EPOLL_CTL_ADD, events[i].data.fd, &e))
						{
							printf("epoll ctl error: %s \n", strerror(errno));
							exit(1);
						}
*/
					}
				}
			}
            else if(event & EPOLLOUT && events[i].data.fd != listenfd)
            {
                char buf[255] = {0};
                memcpy(buf, "hehe \n", sizeof(buf));
				printf("write event");
                if(-1 == write(events[i].data.fd, buf, sizeof(buf)))                                                                                                                                                    
                {
                    perror("write failed");
                }
/*
                epoll_event e;	
                e.data.fd = events[i].data.fd;
                e.events = EPOLLIN; 
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, events[i].data.fd, &e);
*/
            }

		}
	}



	return 0;
}
