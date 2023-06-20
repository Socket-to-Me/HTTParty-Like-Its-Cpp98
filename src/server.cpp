#include "server.hpp"

// -- S I N G L E T O N  I N S T A N C E --------------------------------------

const std::string irc::server::_networkname = "httparty.like.its.98";

/* singleton instance */
irc::server irc::server::_instance = irc::server();

/* get singleton instance */
irc::server &irc::server::instance(void)
{
    // return singleton instance
    return _instance;
}

// -- P R I V A T E  C O N S T R U C T O R S ----------------------------------

/* default constructor */
irc::server::server(void)
{
    // TODO
}

/* copy constructor */
irc::server::server(const server &server)
{
    // TODO
}

/* destructor */
irc::server::~server(void)
{
    // TODO
}

// -- P U B L I C  M E T H O D S ----------------------------------------------

/* start server */
void irc::server::start(const std::string &ip, int port)
{

    setupSocket(ip, port);
    addPollfd(_socket);

    while (true)
    {

        // pollCount = # fds where events were detected
        // (ptr to array of pollfd strcuts, # elem in array, timeout of 60s)
        int pollCount = poll(&_pollfds[0], _pollfds.size(), 60000);

        if (pollCount == -1)
        {
            std::cout << "Poll error" << std::endl;
            exit(1);
        }
        else if (pollCount == 0)
        {
            std::cout << "Poll timed out" << std::endl;
            continue;
        }

        // check server socket for new connections
        acceptNewConnection();

        // check client sockets for new events
        handleActiveConnections();
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &(hint.sin_addr));

    if (bind(_socket, (sockaddr *)&hint, sizeof(hint)) == -1)
    {
        std::cout << "Failed to bind to IP/Port.\n";
        return;
    }

    if (listen(_socket, SOMAXCONN) == -1)
    {
        std::cout << "Failed to listen.\n";
        return;
    }

    acceptNewConnection();

    // return true;
}

/* stop server */
void irc::server::stop(void)
{

    std::vector<struct pollfd>::iterator iter = _pollfds.begin();
    typedef std::vector<irc::connection>::size_type conn_size;

    // FUCK IT
    for (std::vector<irc::connection>::size_type x = 0; x < _connections.size(); ++x)
    {
        _connections[x].close();
    }

    _connections.clear();

    while (iter != _pollfds.end())
    {

        close(iter->fd);
    }

    (void)_pollfds.empty();
}

/* restart server */
void irc::server::restart(void)
{
    // TODO
}

/* subscribe client */
void irc::server::subscribe(const irc::connection &conn)
{
    // TODO
}

/* unsubscribe client */
void irc::server::unsubscribe(const irc::connection &conn)
{
    // TODO
}

/* send message to one client */
void irc::server::send(irc::connection &conn, const std::string &message)
{
}

/* send message to all clients */
void irc::server::broadcast(const std::string &message)
{
    // TODO
}

// -- P R I V A T E  M E T H O D S ----------------------------------------------

/* setup socket */
void irc::server::setupSocket(const std::string &ip, int port)
{

    _socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1)
    {
        std::cout << "Failed to create socket." << std::endl;
        // throw std::exception("Failed to create socket.");
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &(hint.sin_addr));

    if (bind(_socket, (sockaddr *)&hint, sizeof(hint)) == -1)
    {
        std::cout << "Failed to bind to IP/Port." << std::endl;
        // throw std::exception("Failed to bind to IP/Port.");
    }

    if (listen(_socket, SOMAXCONN) == -1)
    {
        std::cout << "Failed to listen." << std::endl;
        // throw std::exception("Failed to listen.");
    }
}

/* add new fd to back of pollfds vector */
void irc::server::addPollfd(int fd)
{
    if (fd != -1)
    {
        pollfd pfd;

        pfd.fd = fd;
        pfd.events = POLLIN;
        pfd.revents = 0;

        _pollfds.push_back(pfd);
    }
    else
    {
        std::cout << "Not a valid socket to build pollfd." << std::endl;
        // throw std::exception("Not a valid socket to build pollfd.");
    }
}

/* accept new pollfd connection */
void irc::server::acceptNewConnection(void)
{

    // check server listening socket for recent events
    if (_pollfds[0].revents & POLLIN)
    {
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);
        int clientSocket = accept(_socket, (sockaddr *)&client, &clientSize);
        if (clientSocket == -1)
        {
            std::cout << "Failed to accept client connection." << std::endl;
            // throw std::exception("Failed to accept client connection.");
        }

        addPollfd(clientSocket);
        connection conn(_pollfds.back());
        _connections.push_back(conn);

        // if (conn.receive()) {

        //     irc::message_list   msgs;
        //     irc::lexer::lex(msgs, conn.extract_message());

        //     irc::message    msg;

        //     irc::cmd_factory::cmd_maker maker = irc::cmd_factory::search(msg.getcmd());

        //     if (maker) {

        //         irc::auto_ptr<irc::cmd> cmd = maker(msg);

        //         if (cmd->evaluate() == true) {

        //             cmd->execute(conn);
        //         }
        //     }
        // }

        // conn.send(irc::numerics::rpl_welcome_001(conn));
        // conn.send(irc::numerics::rpl_yourhost_002(conn));
        // conn.send(irc::numerics::rpl_created_003(conn));

    }
}

void irc::server::handleActiveConnections(void)
{

    // iterator typedef
    typedef std::vector<connection>::iterator conn_iter;

    /* loop over all connections */
    for (conn_iter it = _connections.begin(); it != _connections.end(); ++it)
    {

        if (it->receive())
        {

            std::string msg = it->extract_message();

            std::cout << msg << std::endl;

            // irc::lexer::lex(msg);

            // ------ Connection Registration -------------------

            // --- STEP 1 - CAP message ---
            //
            // Command: CAP
            // Parameters: <subcommand> [:<capabilities>]
            //
            // --- client ---
            // CAP LS
            // --- server ---
            // CAP END
            // --- errors ---
            //
            // ----------------------------

            // --- STEP 2 - PASS message ---
            //
            // Command: PASS
            // Parameters: <password>
            //
            // --- client ---
            // PASS secretpasswordhere
            // --- server ---
            //
            // --- errors ---
            // ERR_NEEDMOREPARAMS (461)
            // ERR_ALREADYREGISTERED (462)
            // ERR_PASSWDMISMATCH (464)
            // -----------------------------

            // --- STEP 3 - NICK and USER message ---
            //
            // Command: NICK
            // Parameters: <nickname>
            //
            // --- client ---
            // NICK Wiz                         ; Requesting the new nick "Wiz".
            // :WiZ NICK Kilroy                 ; WiZ changed his nickname to Kilroy.
            // :dan-!d@localhost NICK Mamoped   ; dan- changed his nickname to Mamoped.
            // --- server ---
            //
            // --- errors ---
            // ERR_NONICKNAMEGIVEN (431)
            // ERR_ERRONEUSNICKNAME (432)
            // ERR_NICKNAMEINUSE (433)
            // ERR_NICKCOLLISION (436)
            //
            //
            // Command: USER
            // Parameters: <username> 0 * <realname>
            //
            // --- client ---
            //   USER guest 0 * :Ronnie Reagan     ; No ident server
            //                                     ; User gets registered with username "~guest" and real name "Ronnie Reagan"
            //   USER guest 0 * :Ronnie Reagan     ; Ident server gets contacted and returns the name "danp"
            //                                     ; User gets registered with username "danp" and real name "Ronnie Reagan"
            // --- server ---
            //
            // --- errors ---
            // ERR_NEEDMOREPARAMS (461)
            // ERR_ALREADYREGISTERED (462)
            // -----------------------------

            // Completion of registration process
            // server sends RPL_WELCOME (001), RPL_YOURHOST (002), RPL_CREATED (003), RPL_MYINFO (004)
            // and at least one RPL_ISUPPORT (005)

            // The server responds as though the client sent it the MOTD command, i.e. it must send either the successful Message of the Day numerics or the ERR_NOMOTD (422) numeric.

            /*
            Lexer		lexer(buffer);
            Parser		parser(lexer);

            std::vector<std::vector<Token> > cmdtbl;
            // size type typedef
            typedef std::vector<int>::size_type size_type;

            cmdtbl = parser.parse();

            for (size_type x = 0; x < cmdtbl.size(); ++x) {

                std::cout << std::endl << " --- N E W  C M D --- " << std::endl;

                for (size_type z = 0; z < cmdtbl[x].size(); ++z) {

                    Token&	token = cmdtbl[x][z];

                    std::cout << token.getType() << "=" << token.getValue() << " | ";

                    if (token.getType() == irc::COMMAND && token.getValue() == "CAP")
                    {
                        iter->send("CAP * END");
                    }
                    else if (token.getType() == irc::COMMAND && token.getValue() == "USER")
                    {
                        iter->send(":irc 001 swillis :Welcome to the irc server, swillis!\n");
                        iter->send(":irc 002 swillis :Your host is irc, running version 1.0\n");
                        iter->send(":irc 003 swillis :This server was created 29-05-2023\n");
                        iter->send(":irc 004 swillis irc 1.0 A B\r\n");
                    }
                }

            }
            */
        }
    }
}
