# BanterBot-3000

--- S T E P S ---

Define the irc Protocol: Start by understanding and defining the irc protocol specifications. Determine the format of irc messages, commands, and their parameters. This will serve as the foundation for implementing the server and handling client interactions.

Implement the Connection Class: Create the Connection class to represent individual client connections. This class should handle the low-level socket communication with clients, such as sending and receiving messages.

Implement the Server Class: Develop the Server class, responsible for managing client connections and handling events. This class should create and manage Connection objects, handle new client connections, and process incoming messages from clients.

Implement User and Channel Management: Design and implement the classes or data structures to manage users and channels. This includes storing information about connected clients, their nicknames, and the channels they have joined. Implement methods for joining, leaving, and managing channels.

Implement Authentication: Add authentication functionality to your server. Clients should be required to provide a password to connect to the server, and you should validate the password before allowing access. Consider securely storing and comparing passwords.

Implement irc Message Parsing: Create functions or classes to parse incoming irc messages. These functions should take a raw message as input and extract relevant information, such as the prefix, command, and parameters. Store the parsed information in an appropriate data structure or object.

Implement Command Validation: Develop a mechanism to validate irc commands received from clients. Verify if the command is supported and if the provided parameters are valid. Handle errors gracefully and respond to clients with appropriate error messages.

Implement Response Generation: Based on the parsed irc message and validated commands, generate appropriate responses to be sent back to clients. These responses can include success messages, error messages, or data requested by clients.

Implement Event Loop: Use the poll() (or equivalent) function to create an event loop for handling I/O operations. This loop should efficiently manage incoming connections, client messages, and other events from the server side.

Handle Operator Commands: Implement the specific commands that are available only to operators. These commands might include actions like kicking users, banning users, or managing server settings. Ensure that the appropriate authorization and validation checks are in place.

--- F U N C T I O N S ---

Define the irc Protocol:

- No specific functions are directly related to this step. It involves understanding and defining the structure and rules of irc messages and commands.

Implement the Connection Class:

- socket: Create a socket to establish communication with clients.
- close: Close the socket when the connection is terminated.
- send and recv: Use these functions to send and receive messages through the socket.

Implement the Server Class:

- socket: Create a socket to listen for incoming connections.
- bind: Bind the socket to a specific IP address and port number.
- listen: Mark the socket as passive to accept incoming connections.
- accept: Accept incoming connections on the listening socket, creating new sockets for communication with clients.
- getsockname: Retrieve the local address to which the socket is bound.

Implement User and Channel Management:

- Use appropriate data structures and classes to store information about connected clients, their nicknames, and the channels they have joined.

Implement Authentication:

- Compare the password provided by the client with the stored password using appropriate comparison functions.

Implement irc Message Parsing:

- Develop functions or classes to parse incoming irc messages, extracting relevant information such as the prefix, command, and parameters.

Implement Command Validation:

- Validate the parsed irc commands, checking if they are supported and if the provided parameters are valid.

Implement Response Generation:

- Based on the parsed and validated irc commands, generate appropriate responses to be sent back to clients using the send function.

Implement Event Loop:

- Use the poll function to create an event loop that waits for events on the sockets and handles I/O operations efficiently. This loop should manage incoming connections, client messages, and other server-side events.

Handle Operator Commands:

- Implement the specific operator commands, checking for authorization and performing the desired actions based on the received commands.



----------------------

# HTTParty-Like-Its-Cpp98
Write a HTTP server in C++ 98

RFC 7230 - HTTP/1.1 Message Syntax and Routing:
HTTP messages consist of a start-line, zero or more header fields, an empty line indicating the end of the header fields, and an optional message body.
The start-line contains the method, target URI, and HTTP version for requests, and the status code and reason phrase for responses.
HTTP uses a message-based model, where each request/response pair is considered an independent message, rather than a continuous stream of data.
HTTP supports several types of message routing, including proxying, tunneling, and redirection.

RFC 7231 - HTTP/1.1 Semantics and Content:
HTTP defines several request methods, including GET, POST, PUT, DELETE, HEAD, OPTIONS, and TRACE, each with its own semantics and usage.
HTTP response codes are grouped into five classes, based on the first digit of the code: 1xx (informational), 2xx (success), 3xx (redirection), 4xx (client error), and 5xx (server error).
The Accept-* headers allow clients to specify the media types and encodings they can handle, while the Content-* headers allow servers to specify the media type and encoding of the response.
HTTP supports content negotiation, allowing clients and servers to agree on the most appropriate representation of a resource based on the available media types and encodings.

RFC 7232 - HTTP/1.1 Conditional Requests:
HTTP supports conditional requests, which allow clients to request a resource only if it has changed since a certain date, or if it does not match a particular ETag value.
The If-Modified-Since and If-Unmodified-Since headers allow clients to specify a date/time range for the requested resource.
The If-Match and If-None-Match headers allow clients to specify an ETag value for the requested resource.
Servers can use the Last-Modified and ETag headers to indicate the date/time and entity tag for a resource, respectively.

RFC 7233 - HTTP/1.1 Range Requests:
HTTP supports range requests, which allow clients to request only a portion of a resource, rather than the entire resource.
The Range header allows clients to specify the byte range they want to retrieve, while the Content-Range header indicates the byte range returned by the server.
Range requests can be used for resuming interrupted downloads, streaming large files, and reducing network bandwidth usage.

RFC 7234 - HTTP/1.1 Caching:
HTTP supports caching, which allows clients and intermediate caches to store and reuse previously requested resources, reducing network traffic and improving performance.
Caches must follow specific rules for cache validation, freshness, and revalidation, including using the Cache-Control, Expires, and Last-Modified headers to determine when to cache and when to revalidate a resource.
HTTP defines several cache-control directives, including public, private, no-cache, no-store, and max-age, which allow servers to control caching behavior.

RFC 7235 - HTTP/1.1 Authentication:
HTTP supports several authentication mechanisms, including Basic, Digest, and Token authentication.
Authentication can be requested by servers using the WWW-Authenticate header, and provided by clients using the Authorization header.
HTTP supports both stateful and stateless authentication, depending on the mechanism used.
Servers can use access control lists (ACLs) to restrict access to resources based on authentication status.

---

An ETag (Entity Tag) is an HTTP header that is used to identify a specific version of a resource. It is a string of characters that is assigned by a web server to a particular version of a resource, such as a web page or an image.

When a client requests a resource from a server, the server includes the ETag in the response header. The client can then include the ETag in subsequent requests for the same resource. If the ETag in the subsequent request matches the ETag for the version of the resource on the server, the server can respond with a 304 Not Modified status code instead of sending the entire resource again. This can reduce bandwidth usage and improve performance.

ETags are also used to resolve conflicts in version control systems, where they can be used to track changes to a file and ensure that multiple users are not editing the same version of a file simultaneously.

---

https://forest-jewel-9bb.notion.site/e9f16f9ef91047548f6db42d67d12979?v=e2f094d0026d40cca977898b48e2c1aa&p=735724447e214ef38b677f2cfc62ab7b&pm=s

https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa

https://aosabook.org/en/v2/nginx.html
