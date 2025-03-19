#include <thread>

// lib headers
#include "lib/socket.hpp"


// costants
#define PORT 8080
#define STREAM_MAX 1024


// client thread
void client_message(int const client_socket)
{
    // message declaration
    char buffer[STREAM_MAX] = {0};
    int message_lenght;
    std::string response = "Hello, from the server! You have send me the message --> ";

    // receive and send message
    message_lenght = recv(client_socket, buffer, sizeof(buffer), 0);
    if (message_lenght > 0) {
        std::cout << "Message from client: " << buffer << std::endl;

        // send the response
        response += buffer;
        send(client_socket, response.c_str(), response.length(), 0);
    }

    // close the client socket
    close(client_socket);
    std::cout << "\nClient disconnected!\n" << std::endl;

    // exit thread
    return;
}


// main
int main()
{
    // socket declaration
    int server_fd = -1, client_socket = -1;

    // address declaration
    struct sockaddr_in listen_addr;
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    
    // create a socket (IPv4 / TCP)
    server_fd = socket_create(AF_INET, SOCK_STREAM, 0);
    
    // identify this server
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(PORT);

    // bind the socket to the port
    socket_bind( server_fd, (struct sockaddr*)&listen_addr, sizeof(listen_addr), PORT);

    // listen for a client connection (max 5 simultaneously)
    socket_listen(server_fd, 5);
    std::cout << "Server listening on port 8080..." << std::endl;

    // listening loop
    while(true) {
        // accept client connection
        client_socket = socket_accept(server_fd, (struct sockaddr*)&client_addr, &addrlen);
        if(client_socket < 0) {
            continue;
        }
        std::cout << "\nClient connected!\n" << std::endl;

        // handle the new client
        std::thread client_thread(client_message, client_socket);
        client_thread.detach();
    }

    // close the server
    close(server_fd);    

    // exit
    return 0;
}