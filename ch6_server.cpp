
//
// Created by Ferdinand on 5/6/2022.
//

#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>

int main() {

    struct addrinfo hints = {
            .ai_flags = AI_PASSIVE,
            .ai_family = AF_UNSPEC,
            .ai_socktype = SOCK_STREAM
    };

    struct addrinfo *res;

    getaddrinfo("localhost","3490",&hints,&res);

    int sock = socket(res->ai_family,res->ai_socktype,res->ai_protocol);

    struct sockaddr_in addr = {
            .sin_family = AF_INET,
            .sin_port = htons(3490),
            .sin_addr.s_addr = INADDR_ANY
    };

    bind(sock,(struct sockaddr*)&addr, sizeof addr);

    listen(sock,1);

    struct sockaddr_storage their_addr;
    socklen_t  sockSize = sizeof their_addr;
    int new_fd = accept(sock,(struct sockaddr *)&their_addr,&sockSize);
    char buf[100];
    int n = recv(new_fd,buf,sizeof buf,0);

    printf("Server received: '%s'",buf);

    close(new_fd);
    close(sock);

    freeaddrinfo(res);
}