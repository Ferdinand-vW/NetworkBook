//
// Created by Ferdinand on 5/9/2022.
//

/*
 * Blocking
 *
 * Various functions block; accept and recv.
 * Initially a socket is set to be blocking by the kernel. To make a non-blocking socket you need to call fcntl();
 * fcntl(sockfd, F_SETFL, 0_NONBLOCK);
 *
 * This allows you to poll the socket for information. However, this form of polling is bad since it puts the program in a busy-wait.
 *
 * Poll() - Synchronous I/O Multiplexing
 *
 * Monitor a bunch of sockets at once and then handle the ones that have data ready. Make kernel tell us when data is ready.
 * We will keep an array of struct pollfds  with information about which socket descriptors we want to monitor and what events to monitor for.
 * The OS will block on the poll() call until one of those events occurs or user-specified timeout.
 *
 * int poll(struct pollfd fds[], nfds_t  nfds, int timeout);
 * fds is the array of information (=sockets to monitor for what), nfds  is the number of elements in the array and timeout is in milliseconds.
 * It returns the number of elements in the array that have had an event occur.
 *
 struct pollfd {
    int fd; // socket descriptor
    short events; // bit map of events we're  interested in
    short revents; //  when poll()  returns, bitmap of events that occurred.
 }
 *
 * Events field is bitwise-OR of the following:
 * POLLIN : Alert me when data is ready to recv() on this socket
 * POLLOUT: Alert me when I can send() data to this socket without blocking.
 *
 * After poll returns, check revents field to see if POLLIN or POLLOUT is set.
 *
 * Make sure array has enough space in array or realloc if necessary to add new file descriptors.
 * To delete, copy last in array over the to be deleted one and then decrease count passed to poll.
 *
 *
 * select() gives you the ability to monitor several sockets at the same time. Tells which are ready for reading,writing and which have raised exceptions.
 * int select(int numfds,, fd_set *readfds, fd_set *writefds,  fd_set *exceptfds, struct timeval *timeout);
 *
 * (select is just a more inefficient version of poll and should be avoided)
 */