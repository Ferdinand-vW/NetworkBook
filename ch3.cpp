//
// Created by Ferdinand on 5/2/2022.
//


/*
 * IP Address
 *
 * IPv4: Made up of 4 bytes. e.g. 192.0.2.111
 * Number of possible addresses is 2^32
 *
 * IPv6: Made up of 16 bytes. Usually denoted as hexadecimal. 32 hexadecimal numbers.
 * 2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551
 * Address with zeros can be compressed
 * 2001:0db8:c9d2:0012:0000:0000:0000:0051
 * 2001:db8:c9d2:12::51
 *
 * 2001:0db8:ab00:0000:0000:0000:0000:0000
 * 2001:db8:ab00::
 *
 * 0000:0000:0000:0000:0000:0000:0000:0001
 * ::1 (localhost, 127.0.0.1 for IPv4)
 *
 * SubNet
 *
 * Sometimes useful to declare part of ip address to be network portion and the remainder the host portion.
 * e.g. ip address 192.0.2.12 has network 192.0.2.0 and host 12
 *
 * Network portion is described by the netmask which you bitwise-AND with ip address to get network number out.
 * May look like this 255.255.255.0 (In this case the first 3 bytes of an ip address form the network portion)
 * Netmask must always be a number of 1s followed by a number of 0s.
 * 192.0.2.12/30 means 30bits for network
 *
 * Besides IP Address there is also port numbers that are used by TCP/UDP. 16-bit number that's like local address for connection.
 *
 * Byte Order
 * Big-Endian: Most significant bit first.
 * Small-Endian: Least significant bit first.
 *
 * Big-Endian is also called Network Byte Order.
 * Computer stores things in Host Byte Order (which can be big or small endian depending on platform)
 * Always use function to set things to network byte order.
 *
 *
 * Socket descriptor is a regular int.
 *
 * addrinfo struct is used to prep  the socket address structures. Also used in host name lookups  and service name lookups.
 * Prep the addrinfo struct and then run getaddrinfo() which will  return a pointer to a linked list of these structures.
 *
struct addrinfo {
    int ai_flags; // AI_PASSIVE, AI_CANONNAME, etc.
    int ai_family; // AF_INET, AF_INET6, AF_UNSPEC
    int ai_socktype; // SOCK_STREAM, SOCK_DGRAM
    int ai_protocol; // use 0 for "any"
    size_t ai_addrlen; // size of ai_addr in bytes
    struct sockaddr *ai_addr; // struct sockaddr_in or _in6
    char *ai_canonname; // full canonical hostname
    struct addrinfo *ai_next; // linked list, next node
};

 * Use ai_family to set IPv4 or IPv6. Can also be used IP version-agnostic with AF_UNSPEC.
 * This is a linkedlist, usually first result that worked is fine.
 *
struct sockaddr {
    unsigned short sa_family; 2 bytes
    char sa_data[14]; 14  bytes
 } // 16 bytes total
 *
 * sa_data contains destination address and port. But it's unwieldly to pack by hand.
 * struct sockaddr_in was created to be used with IPv4 which can be cast to sockaddr and vice-versa.

struct sockaddr_in {
    short int sin_family; 2 bytes
    unsigned short in sin_port; 2  bytes
    struct in_addr sin_addr; 4  bytes
    unsigned char sin_zero[8]; 8  bytes
 } // 16 bytes total

 struct in_addr {
    uint32_t s_addr;
 }

 struct sockaddr_in6 {
    u_int16_t sin6_family; 2 bytes
    u_int16_t sin6_port; 2 bytes
    u_int32_t sin6_flowinfo; 4 bytes
    struct int6_addr sin6_addr; 2 bytes
    u_int32_t sin6_scope_id; 4 bytes
 }

 struct int6_addr {
    unsigned char s6_addr[16];
 }

 *
 * There is also a structure fit for both IPv4 an IPv6

struct sockaddr_storage {
    sa_family_t ss_family;
    char __ss_pad1[_SS_PAD1SIZE]
    int64_t __ss_align;
    char __ss_pad2[_SS_PAD2SIZE];
 }

 *
 * NAT: Network Address Translation
 * Private networks, where a NAT translates public IP to private IP.
 */

#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>


int main () {
    struct sockaddr_in sa;
    struct sockaddr_in6 sa6;

    // presentation to network
    inet_pton(AF_INET,"10.12.110.57", &(sa.sin_addr));
    inet_pton(AF_INET6,"2001:db8:63b3:1::3490", &(sa6.sin6_addr));

    char ip4[INET_ADDRSTRLEN];
    char ip6[INET6_ADDRSTRLEN];
    // network to presentation
    inet_ntop(AF_INET,&(sa.sin_addr), ip4, INET_ADDRSTRLEN);
    inet_ntop(AF_INET6,&(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);

    printf("The IPv4 address is %s\n",ip4);
    printf("The IPv6 address is %s\n",ip6);

}