#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// lib headers
#include </home/lorenzo/cloud/lib/exceptions.hpp>


// prototypes
int socket_create(int __domain, int __type, int __protocol);
void socket_bind(int __fd, const sockaddr *__addr, socklen_t __len, int const PORT);
void socket_listen(int __fd, int __n);
int socket_accept(int __fd, sockaddr *__restrict__ __addr, socklen_t *__restrict__ __addr_len);
void server_address(int __as, const char *__restrict__ __cp, void *__restrict__ __buf);


// 1 ----- Create a socket
int socket_create(int __domain, int __type, int __protocol)
{
    // socket declaration
    int new_socket = -1;

    // create the socket
    try {

        new_socket = socket(__domain, __type, __protocol);
        test_socket_create(new_socket);

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // exit
    return new_socket;
}


// 2 ----- Bind a socket to a port
void socket_bind(int __fd, const sockaddr *__addr, socklen_t __len, int const PORT)
{
    // bind the socket
    try {
        
        test_socket_bind( bind(__fd, __addr, __len) , PORT);

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // exit
    return;
}


// 3 ----- Listen for client connections
void socket_listen(int __fd, int __n)
{
    // listen
    try {

        test_socket_listen(listen(__fd, __n));

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // exit
    return;
}


// 4 ----- Accept client connection
int socket_accept(int __fd, sockaddr *__restrict__ __addr, socklen_t *__restrict__ __addr_len)
{
    // socket declaration
    int client_socket;

    try {

        client_socket = accept(__fd, __addr, __addr_len);
        test_socket_accept(client_socket);

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // exit
    return client_socket;
}


// 5 ----- Get the address of a server
void server_address(int __as, const char *__restrict__ __cp, void *__restrict__ __buf)
{
    // get server address
    try {

        test_server_address(inet_pton(__as, __cp, __buf));

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // exit
    return;
}


// 6 ----- Connect to a server
void server_connect(int __fd, const sockaddr *__addr, socklen_t __len)
{
    // connect to the server
    try {

        test_server_connect(connect(__fd, __addr, __len));

    } catch(Socket_Error &error) {

        // error handling
        error.print();

        // exit
        exit(-1);
    }

    // exit
    return;
}