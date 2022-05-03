//
// Created by Ferdinand on 5/2/2022.
//

/* Two socket types
 * Stream sockets:   SOCK_STREAM
 * Datagram sockets: SOCK_DGRAM

    Datagram sockets are connectionless

    Stream sockets provide reliable two-way connection communication streams.
    "1","2" > "1","2"
    The data will also be error free

    You can use telnet to create a stream socket.
    e.g.
    > telnet
    telnet> open google.com 80
    (enter twice)

    Stream sockets use TCP to make sure data arrives sequentially and error-free

    Datagram sockets use UDP. They do not require that you maintain an open connection.
    Generally used if TCP is not available or if a few dropped packets is not bad.
    (Error-free protocols can still be written as wrappers over UDP as underlying protocol)

    Layered network model:
    Application layer (telnet, ftp)
    Host-To-Host Transport layer (UDP,TCP)
    Internet layer (IP and routing)
    Network Access layer (Ethernet, wi-fi)
 */

int main() {


    return 0;
}

