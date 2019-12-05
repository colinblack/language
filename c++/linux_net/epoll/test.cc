#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>

int main()
{
	int epfd,nfds;
　　struct epoll_event ev,events[5]; //ev用于注册事件，数组用于返回要处理的事件
　　epfd = epoll_create(1); //只需要监听一个描述符——标准输入
　　ev.data.fd = STDIN_FILENO;
　　ev.events = EPOLLIN|EPOLLET; //监听读状态同时设置ET模式	

}


