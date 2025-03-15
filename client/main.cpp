#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// lib headers
#include </home/lorenzo/cloud/lib/exceptions.hpp>


// costants
#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define STREAM_MAX 1024


int main() {

    // socket declaration
    int client_socket = -1;

    // address declaration
    struct sockaddr_in server_addr;

    // message declaration
    char buffer[STREAM_MAX] = {0};
    int message_length;

    // create a socket (IPv4 / TCP)
    try {

        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        test_socket_create(client_socket);

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // identify the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // get server address
    try {

        test_server_address(inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr));

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // connect to the server
    try {

        test_server_connect(connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)));

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // send and receive message
    send(client_socket, "Hello, Server!", 15, 0);
    message_length = read(client_socket, buffer, sizeof(buffer));
    if (message_length > 0)
    {     
        std::cout << "Message from server: " << buffer << std::endl;
    }

    // close the socket
    close(client_socket);

    // exit
    return 0;
}