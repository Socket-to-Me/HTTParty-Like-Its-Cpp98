#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <poll.h>

namespace IRC {

    class Connection {

        private:

            const struct pollfd& _pfd;

        public:

            Connection(const struct pollfd& pfd);
        
            bool    	hasEventOccured(void);
            ssize_t    	send(const std::string& message);
            ssize_t		receive(char* buffer, int buffer_size);
            void        close(void);
            int         getfd(void);

    };

}

#endif



