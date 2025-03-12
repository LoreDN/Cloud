#include <iostream>
#include <sys/socket.h>


// main
int main()
{
    // create a socket (IPv4 / TCP)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1)
    {
        std::cerr << "Socket creation failed!!!" << std::endl;
    }

    // exit
    return 0;
}





