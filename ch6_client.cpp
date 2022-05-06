//
// Created by Ferdinand on 5/6/2022.
//

#include <sys/socket.h>
#include <netdb.h>
#include <cstring>

int main() {

    struct addrinfo hints {
        .ai_flags    =  AI_PASSIVE,
        .ai_family = AF_UNSPEC,
        .ai_socktype = SOCK_STREAM
    };

    struct addrinfo *res;

    int status = getaddrinfo("localhost","3490",&hints,&res);

    if(status == -1) {
        return -1;
    }

    auto sock = socket(res->ai_family,res->ai_socktype,res->ai_protocol);

    connect(sock,res->ai_addr,res->ai_addrlen);

    const char* msg = "test";
    send(sock,msg,strlen(msg),0);

}
