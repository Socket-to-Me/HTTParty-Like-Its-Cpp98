#ifndef MAIN_HEADER
#define MAIN_HEADER

#define WEBSERV_VERSION "0.1.0"

// authorized functions :

// socket
// close
// setsockopt
// getsockname
// getprotobyname
// gethostbyname
// getaddrinfo,
// freeaddrinfo
// bind
// connect
// listen
// accept
// htons
// htonl
// ntohs
// ntohl
// inet_addr
// inet_ntoa,
// send
// recv
// signal
// lseek
// fstat
// fcntl
// poll (ou équivalent)



// -- S O C K E T S  ----------------------------------------------------------

// socket: Creates a new socket descriptor that represents a communication endpoint.
// close: Closes a socket or file descriptor, releasing associated resources.

// setsockopt: Sets options on a socket, such as setting socket-level options or modifying socket behavior.

// getsockname: Retrieves the local address to which a socket is bound.

// getprotobyname: Retrieves protocol information (such as TCP or UDP) by name.

// gethostbyname: Retrieves host information by name, such as IP address.

// getaddrinfo: Resolves a host name and service name to a set of socket addresses.
// freeaddrinfo: Frees memory allocated by the getaddrinfo function.


// -- C O N N E C T I O N S  --------------------------------------------------

// bind: Associates a socket with a specific address (IP address and port number).
// connect: Establishes a connection to a remote server using a socket.
// listen: Marks a socket as passive, enabling it to accept incoming connections.
// accept: Accepts an incoming connection on a listening socket, creating a new socket for communication with the client.


// -- C O N V E R S I O N S  --------------------------------------------------

// htons: Converts a short integer (16 bits) from host byte order to network byte order (big endian).
// htonl: Converts a long integer (32 bits) from host byte order to network byte order.
// ntohs: Converts a short integer from network byte order to host byte order.
// ntohl: Converts a long integer from network byte order to host byte order.



// inet_addr: Converts an IP address from the standard dot notation to binary form.
// inet_ntoa: Converts an IP address from binary form to the standard dot notation.


// send: Sends data through a socket.
// recv: Receives data from a socket.

// signal: Associates a signal handler with a specific signal, allowing the program to handle asynchronous events.

// lseek: Repositions the file offset of an open file.

// fstat: Retrieves information about an open file, such as its size or permissions.

// fcntl: Performs various operations on open file descriptors, such as changing file access modes or duplicating descriptors.

// poll: Waits for events on a set of file descriptors, allowing efficient handling of I/O operations and events.

// -------------------------------------------------------------------------------------------------------------------------------

// ----------- B L O C K I N G   I / O -----------

// // Set the listening socket to non-blocking mode
// int flags = fcntl(listeningSocket, F_GETFL, 0);
// fcntl(listeningSocket, F_SETFL, flags | O_NONBLOCK);

// // Create a pollfd structure for the listening socket
// struct pollfd listeningPollFd;
// listeningPollFd.fd = listeningSocket;
// listeningPollFd.events = POLLIN;

// // Use poll to check for incoming connections
// int result = poll(&listeningPollFd, 1, timeout);
// if (result > 0) {
//     if (listeningPollFd.revents & POLLIN) {
//         // There is an incoming connection, accept it
//         int newSocket = accept(listeningSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);
//         if (newSocket >= 0) {
//             // Handle the new connection
//             // ...
//         }
//     }
// }


#endif
