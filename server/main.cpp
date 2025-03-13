#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>


// main
int main()
{
    // create a socket (IPv4 / TCP)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1)
    {
        std::cerr << "Socket creation failed!!!" << std::endl;
    }

    // bind the socket to the port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        std::cerr << "Binding failed!!!" << std::endl;
        return -1;
    }

    // listen for a client connection
    if (listen(server_fd, 1) < 0)
    {
        std::cerr << "Listening failed!!!" << std::endl;
        return -1;
    }
    std::cout << "Server listening on port 8080..." << std::endl;

    // accept client connection
    socklen_t addrlen = sizeof(address);
    int new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    if (new_socket < 0) {
        std::cerr << "Accept failed." << std::endl;
        return -1;
    }


    // exit
    return 0;
}





