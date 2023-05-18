#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

int main() {
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Failed to create socket.\n";
        return 1;
    }

    // Set up the server address
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5000);  // Replace with the server's port number
    inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr));  // Replace with the server's IP address

    // Connect to the server
    if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to connect to the server.\n";
        close(clientSocket);
        return 1;
    }

    // Send a message to the server
    std::string message = "Hello, server!";
    int bytesSent = send(clientSocket, message.c_str(), message.size(), 0);
    if (bytesSent == -1) {
        std::cerr << "Failed to send message.\n";
        close(clientSocket);
        return 1;
    }

    // Close the connection
    close(clientSocket);

    return 0;
}
