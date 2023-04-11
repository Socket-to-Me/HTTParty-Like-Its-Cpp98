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
