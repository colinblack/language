//客户端
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>


int main()
{
    int client_sockfd;
    int len;
    struct sockaddr_in address;//服务器端网络地址结构体
     int result;
    char ch = 'A';
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);//建立客户端socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.100.252");
    address.sin_port = htons(8888);

    socklen_t res_len;
    int nZero= 2048;
    if(setsockopt(client_sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&nZero, sizeof(nZero)) < 0)
    {
    	perror("setsockopt:");
    	close(client_sockfd);
    	return -1;
    }
    int res = 0;
    res_len = sizeof(res);
    if(getsockopt(client_sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&res, &res_len) < 0)
    {
    	perror("getsockopt:");
    	close(client_sockfd);
    	return -1;
    }

    printf("sendbuf: %d, %d \n", res, res_len);

    len = sizeof(address);
    result = connect(client_sockfd, (struct sockaddr *)&address, len);
    if(result == -1)
    {
         perror("oops: client2");
         exit(1);
    }
    else
    {
    	printf("connet: %d", result);
    }
    //第一次读写
    write(client_sockfd, &ch, 1);
    read(client_sockfd, &ch, 1);
    printf("the first time: char from server = %c\n", ch);
    sleep(5);

    //第二次读写
    write(client_sockfd, &ch, 1);
    read(client_sockfd, &ch, 1);
    printf("the second time: char from server = %c\n", ch);

    close(client_sockfd);

    return 0;
}
