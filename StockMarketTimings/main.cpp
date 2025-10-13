#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <nlohmann/json.hpp>
#include <cstdio>       /* printf, sprintf */
#include <cstdlib>     /* exit, atoi, malloc, free */
#include <openssl/ssl.h>
#include <openssl/err.h>


using json = nlohmann::json;

std::string httpGet(const std::string& url) {
    int status, sockfd;
    struct addrinfo hints, *res;
    std::string response;
    const char *hostname = "www.alphavantage.co";
    const char *port = "443";
    SSL_CTX *ctx;
    SSL *ssl;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(hostname, port, &hints, &res);
    if (status != 0) {
        std::string errorMessage = "getaddrinfo error: " + std::string(gai_strerror(status));
        freeaddrinfo(res);
        throw std::runtime_error(errorMessage);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        freeaddrinfo(res);
        throw std::runtime_error("socket error");
    }

    // Attempt to connect (blocking)
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        freeaddrinfo(res);
        close(sockfd);
        throw std::runtime_error("connect error: " + std::string(strerror(errno))); // Include errno
    }
    freeaddrinfo(res);

    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    // Create a new SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        close(sockfd);
        ERR_print_errors_fp(stderr);
        throw std::runtime_error("SSL_CTX_new error");
    }

     // Create a new SSL connection with the socket
    ssl = SSL_new(ctx);
    if (!ssl) {
        SSL_CTX_free(ctx);
        close(sockfd);
        ERR_print_errors_fp(stderr);
        throw std::runtime_error("SSL_new error");
    }

    SSL_set_fd(ssl, sockfd);

    // Perform SSL/TLS handshake
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        throw std::runtime_error("SSL_connect error");
    }
    // Construct the HTTP GET request
    std::string request = "GET /query?function=MARKET_STATUS&apikey=S8BS1N4ZOI2CWLXU HTTP/1.1\r\n"
                          "Host: www.alphavantage.co\r\n"
                          "Connection: close\r\n\r\n";

    // Send the request
    if (SSL_write(ssl, request.c_str(), request.size()) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        throw std::runtime_error("SSL_write error");
    }

    // Receive the response
    char buffer[4096];
    ssize_t bytesReceived;
    std::stringstream ss;
    while ((bytesReceived = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesReceived] = '\0';
        ss << buffer;
    }
    if (bytesReceived < 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sockfd);
        throw std::runtime_error("SSL_read error");
    }
    response = ss.str();

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return response;
}

int main() {
    try {



        std::cout << "Market flow" << std::endl;
        std::string response = httpGet("https://www.alphavantage.co/query?function=MARKET_STATUS&apikey=S8BS1N4ZOI2CWLXU");
        std::cout << response << std::endl;

        json data = json::parse(response);
        std::cout << data.dump(4) << std::endl;
        if (data.find("market") != data.end()) {
            std::cout << "Market: " << data["market"] << std::endl;
        }
        else {
            std::cout << "Market data not found" << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

