#include "server.hpp"
#include "connection.hpp"

irc::Server::Server()
: serverSocket(-1) {
    return;
}

bool irc::Server::start(const std::string& ipAddress, int port) {

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cout << "Failed to create socket.\n";
        return false;
    }

    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &(hint.sin_addr));

    if (bind(serverSocket, (sockaddr*)&hint, sizeof(hint)) == -1) {
        std::cout << "Failed to bind to IP/Port.\n";
        return false;
    }

    if (listen(serverSocket, SOMAXCONN) == -1) {
        std::cout << "Failed to listen.\n";
        return false;
    }

    return true;
}

void irc::Server::acceptConnections() {

    while (true) {

        sockaddr_in client{};
        socklen_t clientSize = sizeof(client);
        int clientSocket = accept(serverSocket, (sockaddr*)&client, &clientSize);
        if (clientSocket == -1) {
            std::cout << "Failed to accept client connection.\n";
            continue;
        }

        irc::Connection connection(clientSocket);
        connections.push_back(connection);

        // Handle the new client connection
        handleNewConnection(connection);
}
}

void irc::Server::handleNewConnection(irc::Connection& connection) {

    // Implement your logic to handle the new client connection
    std::cout << "New client connected. Socket: " << connection.get_sd() << "\n";

    // Example: Send a welcome message to the client
    connection.send_message("Welcome to the server!");

    // Example: Receive and process incoming messages from the client
    std::string message = connection.receive_message(1024);
    std::cout << "Received message: " << message << "\n";
}

void irc::Server::stop() {

    for (auto& connection : connections) {
        connection.close();
    }
    connections.clear();

    if (serverSocket != -1) {
        ::close(serverSocket);
        serverSocket = -1;
    }
}
