#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// lib headers
#include </home/lorenzo/cloud/lib/exceptions.hpp>


// costants
#define PORT 8080
#define STREAM_MAX 1024


// main
int main()
{
    // socket declaration
    int server_fd = -1, client_socket = -1;

    // address declaration
    struct sockaddr_in listen_addr;
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);

    // message declaration
    char buffer[STREAM_MAX] = {0};
    int message_lenght;
    
    // create a socket (IPv4 / TCP)
    try {

        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        test_socket_create(server_fd);

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }
    
    // identify this server
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(PORT);

    // bind the socket to the port
    try {

        test_socket_bind( bind(server_fd, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) , PORT);

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // listen for a client connection
    try {

        test_socket_listen(listen(server_fd, 1));

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }
    std::cout << "Server listening on port 8080..." << std::endl;

    // accept client connection
    try {

        client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen);
        test_socket_accept(client_socket);

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // receive and send message
    message_lenght = recv(client_socket, buffer, sizeof(buffer), 0);
    if (message_lenght > 0)
    {
        std::cout << "Message from client: " << buffer << std::endl;
        send(client_socket, "Hello from the server!", 22, 0);
    }

    // close the client socket
    close(client_socket);

    // close the server
    close(server_fd);

    // exit
    return 0;
}