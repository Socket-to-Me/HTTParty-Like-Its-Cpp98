#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

class Connection {

private:

    int _sd;

public:

    Connection(int sd);
    void send_message(const std::string& message);
    std::string receive_message(const int buffer_size);
    void close(void);

};

#endif
