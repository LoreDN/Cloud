#include <iostream>
#include <sys/socket.h>


// costants
#define PORT 8080
#define STREAM_MAX 1024


int main() {

    // socket declaration
    int client_socket = -1;
    //struct sockaddr_in server_addr;
    char buffer[STREAM_MAX] = {0};

    // create a socket (IPv4 / TCP)
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        std::cerr << "Socket creation failed!!!" << std::endl;
        return -1;
    }

    // exit
    return 0;
}
