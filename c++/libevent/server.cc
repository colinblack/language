#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <err.h>
#include <unistd.h>  
#include "ev.h"

static int server_port = 8000;
  
struct ev_loop *loop;
typedef struct {
    int fd;
    ev_io ev_read;
} client_t;
  
ev_io ev_accept;
  
static int usr_num;
static void incr_usr_num() {
    usr_num ++;
    printf("online user %d\n", usr_num);
}
  
static void dec_usr_num() {
    usr_num --;
  
    printf("~online user %d\n", usr_num);
}
  
static void free_res(struct ev_loop *loop, ev_io *ws);
  
int setnonblock(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0)
        return flags;
  
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) < 0)
        return -1;
  
    return 0;
}
  


  
static void read_cb(struct ev_loop *loop, ev_io *w, int revents) {
    client_t *client = (client_t* )w->data;
    int r = 0;
    char rbuff[1024];
    if (revents & EV_READ) {
        r = read(client->fd, &rbuff, 1024);
    }
  
    if (EV_ERROR & revents) {
        fprintf(stderr, "error event in read\n");
        free_res(loop, w);
        return ;
    }
  
    if (r < 0) {
        fprintf(stderr, "read error\n");
        ev_io_stop(EV_A_ w);
        free_res(loop, w);
        return;
    }
  
    if (r == 0) {
        fprintf(stderr, "client disconnected.\n");
        ev_io_stop(EV_A_ w);
        free_res(loop, w);
        return;
    }
  
    incr_usr_num();
}
  
static void accept_cb(struct ev_loop *loop, ev_io *w, int revents) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(w->fd, (struct sockaddr *) &client_addr, &client_len);
    if (client_fd == -1) {
        fprintf(stderr, "the client_fd is NULL !\n");
        return;
    }
  
    client_t *client = (client_t* )malloc(sizeof(client_t));
    client->fd = client_fd;
    if (setnonblock(client->fd) < 0)
        err(1, "failed to set client socket to non-blocking");
  
    client->ev_read.data = client;
  
    ev_io_init(&client->ev_read, read_cb, client->fd, EV_READ);
    ev_io_start(loop, &client->ev_read);
}
 
 
int main(int argc, char* const argv[]) {
    int ch;
    while ((ch = getopt(argc, argv, "p:")) != -1) {
        switch (ch) {
        case 'p':
            server_port = atoi(optarg);
            break;
        }
    }
  
    printf("start free -m is \n");
    system("free -m");
    loop = ev_default_loop(0);
    struct sockaddr_in listen_addr;
    int reuseaddr_on = 1;
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
        err(1, "listen failed");
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_on, sizeof(reuseaddr_on)) == -1)
        err(1, "setsockopt failed");
  
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(server_port);
  
    if (bind(listen_fd, (struct sockaddr *) &listen_addr, sizeof(listen_addr)) < 0)
        err(1, "bind failed");
    if (listen(listen_fd, 5) < 0)
        err(1, "listen failed");
    if (setnonblock(listen_fd) < 0)
        err(1, "failed to set server socket to non-blocking");
  
    ev_io_init(&ev_accept, accept_cb, listen_fd, EV_READ);
    ev_io_start(loop, &ev_accept);
    ev_loop(loop, 0);
  
    return 0;
}
  
static void free_res(struct ev_loop *loop, ev_io *w) {
    dec_usr_num();
    client_t *client = (client_t* )w->data;
    if (client == NULL) {
        fprintf(stderr, "the client is NULL !!!!!!");
        return;
    }
  
    ev_io_stop(loop, &client->ev_read);
  
    close(client->fd);
  
    free(client);
}