// lib headers
#include "lib/socket.hpp"


// costants
#define PORT 8080
#define STREAM_MAX 1024


int main()
{
    // socket declaration
    int client_socket = -1;

    // address declaration
    char server_ip[] = "000.000.000.000";
    struct sockaddr_in server_addr;

    // message declaration
    char buffer[STREAM_MAX] = {0};
    int message_length;


    // set Windows sockets
    #ifdef _WIN32

        WSADATA wsa;
        WSAStartup(MAKEWORD(2,2), &wsa);

    #endif

    // create a socket (IPv4 / TCP)
    client_socket = socket_create(AF_INET, SOCK_STREAM, 0);

    // identify the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    std::cout << "\nInsert the Server IPv4 address: ";
    std::cin >> server_ip;
    
    server_address(AF_INET, server_ip, &server_addr.sin_addr);

    // connect to the server
    server_connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // create the message to send
    std::cin.ignore();
    std::cout << "Create the message to send:" << std::endl;
    std::cin.getline(buffer, STREAM_MAX);

    // send and receive message
    send(client_socket, buffer, sizeof(buffer), 0);
    message_length = recv(client_socket, buffer, sizeof(buffer), 0);
    if (message_length > 0) {     
        std::cout << "Message from server: " << buffer << std::endl;
    }

    // close the socket
    closesocket(client_socket);

    // close Windows sockets
    #ifdef _WIN32

        WSACleanup();

    #endif

    // exit
    return 0;
}