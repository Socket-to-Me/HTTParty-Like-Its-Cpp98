#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <vector>

namespace IRC {

    class Connection {

    private:

        int _sd;

    public:

        Connection(int sd);
        void send_message(const std::string& message);
        std::string receive_message(const int buffer_size);
        void close(void);
        int get_sd(void);

    };

}

#endif
