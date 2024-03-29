#include <iostream>
#include <string>
#include <boost/asio.hpp>

// ProxyServer class
class ProxyServer {
public:
    ProxyServer(boost::asio::io_context& ioContext, const std::string& ircServer, int ircPort, int proxyPort)
        : ioContext_(ioContext),
          ircSocket_(ioContext),
          clientSocket_(ioContext),
          clientAcceptor_(ioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), proxyPort)),
          ircServer_(ircServer),
          ircPort_(ircPort) {}

    // Start the proxy server
    void start() {
        // Connect to the IRC server
        boost::asio::ip::tcp::resolver resolver(ioContext_);
        boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(ircServer_, std::to_string(ircPort_));
        boost::asio::async_connect(ircSocket_, endpoints,
            [this](const boost::system::error_code& ec, const boost::asio::ip::tcp::endpoint& endpoint) {
                if (!ec) {
                    readFromIRC();
                }
            });

        // Accept the client connection
        acceptClientConnection();
    }

private:
    // Accept a client connection
    void acceptClientConnection() {
        clientAcceptor_.async_accept(clientSocket_,
            [this](const boost::system::error_code& ec) {
                if (!ec) {
                    readFromClient();
                }
                acceptClientConnection();
            });
    }

    // Read from the IRC server
    void readFromIRC() {
        boost::asio::async_read_until(ircSocket_, ircBuffer_, "\r\n",
            [this](const boost::system::error_code& ec, std::size_t bytesTransferred) {
                if (!ec) {
                    std::string message(
                        boost::asio::buffers_begin(ircBuffer_.data()),
                        boost::asio::buffers_begin(ircBuffer_.data()) + bytesTransferred);
                    ircBuffer_.consume(bytesTransferred);

                    std::cout << "Received from IRC: " << message << std::endl;

                    writeToClient(message);
                    readFromIRC();
                }
            });
    }

    // Read from the client
    void readFromClient() {
        boost::asio::async_read_until(clientSocket_, clientBuffer_, "\r\n",
            [this](const boost::system::error_code& ec, std::size_t bytesTransferred) {
                if (!ec) {
                    std::string message(
                        boost::asio::buffers_begin(clientBuffer_.data()),
                        boost::asio::buffers_begin(clientBuffer_.data()) + bytesTransferred);
                    clientBuffer_.consume(bytesTransferred);

                    std::cout << "Received from client: " << message << std::endl;

                    writeToIRC(message); // Forward the message to the IRC server

                    readFromClient();
                }
            });
    }


    // Write to the IRC server
    void writeToIRC(const std::string& message) {
        boost::asio::async_write(ircSocket_, boost::asio::buffer(message),
            [this, message](const boost::system::error_code& ec, std::size_t bytesTransferred) {
                if (!ec) {
                    std::cout << "Sent to IRC: " << message << std::endl;
                    // Perform any necessary actions after the message is sent
                } else {
                    // Handle the error condition, if needed
                    std::cout << "Error sending to IRC: " << ec.message() << std::endl;
                }
            });
    }


    // Write to the client
    void writeToClient(const std::string& message) {
        boost::asio::async_write(clientSocket_, boost::asio::buffer(message),
            [this, message](const boost::system::error_code& ec, std::size_t /*bytesTransferred*/) {
                if (!ec) {
                    std::cout << "Sent to client: " << message << std::endl;
                }
            });
    }

private:
    boost::asio::io_context& ioContext_;
    boost::asio::ip::tcp::socket ircSocket_;
    boost::asio::ip::tcp::socket clientSocket_;
    boost::asio::ip::tcp::acceptor clientAcceptor_;
    boost::asio::streambuf ircBuffer_;
    boost::asio::streambuf clientBuffer_;
    std::string ircServer_;
    int ircPort_;
};

int main() {
    boost::asio::io_context ioContext;

    // Create a proxy server and start it
    ProxyServer proxyServer(ioContext, "127.0.0.1", 5052, 8080);  // Specify the IRC address, IRC port, and proxy port
    proxyServer.start();

    // Run the IO context
    ioContext.run();

    return 0;
}
