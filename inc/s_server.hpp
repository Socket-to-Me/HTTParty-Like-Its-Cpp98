#ifndef SERVER_HEADER
#define SERVER_HEADER

#include "connection.hpp"

namespace IRC {

    class Server {

    private:

        int serverSocket;
        std::vector<IRC::Connection> connections;

    public:

        Server();
        bool start(const std::string& ipAddress, int port);
        void acceptConnections();
        void handleNewConnection(IRC::Connection& connection);
        void stop();

    };
}

#endif
