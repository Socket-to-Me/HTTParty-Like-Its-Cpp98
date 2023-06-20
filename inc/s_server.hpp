#ifndef SERVER_HEADER
#define SERVER_HEADER

#include "connection.hpp"

namespace irc {

    class Server {

    private:

        int serverSocket;
        std::vector<irc::Connection> connections;

    public:

        Server();
        bool start(const std::string& ipAddress, int port);
        void acceptConnections();
        void handleNewConnection(irc::Connection& connection);
        void stop();

    };
}

#endif
