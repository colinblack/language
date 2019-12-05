/*
 * server.cc
 *
 *  Created on: 2018年8月25日
 *      Author: cp
 */

//SIGPIPE 信号测试
//当客户端关闭链接，如果服务端仍然发送数据，则会产生次信号

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>


void func(int var)
{
	printf("pipe error \n");
}




int main()
{
	int listenFd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenFd < 0)
	{
		printf("socket error: %d \n", errno);
	}
	int on =1;
	setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	sockaddr_in addr, clientAddr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	int ret = 0;
	ret = bind(listenFd, reinterpret_cast<const sockaddr*>(&addr), sizeof(addr));
	if(ret < 0)
	{
		printf("bind error: %s \n", strerror(errno));
	}


	ret = listen(listenFd, 1);
	if(ret < 0)
	{
		printf("listen error: %d \n", errno);
	}


	const char buf[20] = "hello world\n";
	socklen_t	clientLen = sizeof(clientAddr);
	signal(SIGPIPE, func);

    int clientFd = 0;

	clientFd = accept(listenFd, reinterpret_cast<sockaddr*>(&clientAddr), &clientLen);
	if(-1 != clientFd)
	{
        int cnt = 0;
        while(cnt++ < 15)
        {
		  int ret = write(clientFd, buf, sizeof(buf));
          printf("write: %s, ret=%d \n", strerror(errno), ret);
          sleep(1);
        }
	}
    sleep(70);

    ret = close(clientFd);
    printf("close: %s, ret: %d \n", strerror(errno), ret);
//	read(clientFd, buf, sizeof(buf));
//	printf("buf: %s \n", buf);
//	while(1)
//	{
//		write(clientFd, buf, sizeof(buf));
//		sleep(2);
	//	memset(buf, 0 , sizeof(buf));
//	}


}
