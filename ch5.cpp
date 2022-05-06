//
// Created by Ferdinand on 5/5/2022.
//


/*
int getaddrinfo(const char *node, // www.example.com or IP
                const char *service, // http or port
                const struct addrinfo *hints,
                struct addrinfo **res);
 * Result is pointer to linkedlist of results
 * Node parameter is host name to connect to or IP address
 * Service can be port like "80" or name of service which configures the right port from /etc/services, e.g. http or ftp
 * hints points to struct addrinfo that it already filled out with relevant information
 *
 *
 * Server listening on host IP Address and port 3490.
 *
 int status;
 struct addrinfo hints;
 struct addrinfo *servinfo; // will point to results

 memset(&hints, 0, sizeof hints); // make sure struct is empty
 hints.ai_family = AF_UNSPEC; // don't care if IPv4 or IPv6 is empty
 hints.ai_socktype = SOCK_STREAM; // TCP Stream sockets
 hints.ai_flags = AI_PASSIVE; // fill in my IP for me, use local host

 if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) !+ 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    exit(1);
 }
 // servinfo now points to a linked list of 1 or more struct addrinfos

 freeaddrinfo(servinfo);
 *
 *
 * Client connecting to server
int status;
struct addrinfo hints;
struct addrinfo *servinfo;
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCKS_STREAM;

status = getaddrinfo("www.example.net","3490",&hints,&servinfo);

 * Sockets
 *  int socket(int domain, int type, int protocol);
 *
int s;
struct addrinfo hints, *res;

getaddrinfo("www.example.com","http",&hints,&res); // assume we filled out hints struct already

s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

 * socket returns socket descriptor or -1 on error.
 *
 * Once you have a socket you must bind it to a port on the local machine.
 * int bind(int sockfd, struct sockaddr *my_addr, int addrlen);

struct addrinfo hints, *res;
 int sockfd;
 memset(&hints, 0, sizeof hints);
 hints.ai_famsily = AF_UNSPEC;
 hints.ai_socktype = SOCK_STREAM;
 hints.ai_flags = AI_PASSIVE; // fill in local IP

 getaddrinfo(NULL, "3490", &hints, &res);

 sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

 bind(sockfd, res->ai_addr,  res->ai_addrlen);
 * WIth AI_PASSIVE we tell program to bind to IP of the host.
 *
 * Use connect to connect to remote machine
 * int connect (int sockfd, struct sockaddr *serv_adr, int addrlen);
 *
 * Use listen to accept incoming connetions. Incoming connetions are placed in a queue.
 * int listen(sockfd, int backlog);
 *
 * Backlog is the number of allowed connections on the incoming queue.
 getaddrinfo();
 socket(); // create the socket
 bind(); // bind the socket to local ip and port
 listen(); // listen for incoming connections
 accept();

 * Accept call gets the pending connection, which returns a brand new socket file descriptor to use for this single connection.
 * The first one still listens for new incoming connections and the new one is ready for receive and sends.
 * int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
 *
 * int send (int sockfd, const void *msg, int len, int flags);
 char *msg = "Beej was here!"
 int len, bytes_sent;

 len = strlen(msg);
 bytes_sent = send(sockfd, msg, len, 0); // might not send all data, up to user to end rest of data.

 * int recv(int sockfd, void *buf, int len, int flags);
 * returns nunmber of bytes read into buffer. -1 is error, 0 means server has closed the connection.
 *
 *
 *  For datagram sockets we use sendto and recvfrom
 *  int sendto(int sockfd,  const void *msg, int len, unsigned int flags, const struct sockaddr *to, socklen_t tolen);
 *  int recvfrom(int sockfd, void *buf, int len, unsigned int flags, struct sockaddr *from, int *fromlen);
 *  Can also connect a datagram socket and use send and recv instead.
 *
 *  To close the connection on the socket descriptor:
 *  close(sockfd);
 *  This will prevent any more reads and writes to the socket. Any one on the remote end will receive an error.
 *
 *  int shutdown(int sockfd, int how) // more control on how to close the socket.
 *
 *  int getpeername(int sockfd, struct sockaddr *addr, int *addrlen); // who is socket connected to
 *
 *  int gethostname(char *hosname, size_t size); // Returns the name of the computer that your program is running on

 */