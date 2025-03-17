// lib headers
#include </home/lorenzo/cloud/lib/socket.hpp>


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
    client_socket = socket_create(AF_INET, SOCK_STREAM, 0);

    // identify the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    server_address(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // connect to the server
    server_connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // create the message to send
    std::cout << "Create the message to send:" << std::endl;
    std::cin.getline(buffer, STREAM_MAX);

    // send and receive message
    send(client_socket, buffer, sizeof(buffer), 0);
    message_length = read(client_socket, buffer, sizeof(buffer));
    if (message_length > 0) {     
        std::cout << "Message from server: " << buffer << std::endl;
    }

    // close the socket
    close(client_socket);

    // exit
    return 0;
}