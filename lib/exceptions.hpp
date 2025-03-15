#pragma once
#include <iostream>


// Root ----- abstract class Exception
class Exception {

    protected:

        // error message attribute
        std::string message;

    public:

        // constructor
        Exception(std::string msg) : message(msg) {}

        // method 1 ----- print error message
        virtual void print() = 0;
};


// Exception 1 ----- Socket_Error
class Socket_Error : public Exception {

    public:
        
        // constructor
        Socket_Error(std::string message) : Exception(message) {}

        // method 1 ----- print error message
        void print() override
        {
            std::cerr << Exception::message << std::endl;

            // exit
            return;
        }
};


// prototypes
void test_socket_create(int const socket);
void test_socket_bind(int const bind, int const port);
void test_socket_listen(int const listen);
void test_socket_accept(int const socket);
void test_server_address(int const connection);
void test_server_connect(int const connection);


// Test 1 ----- Test Socket_Error exception in creating a socket
void test_socket_create(int const socket)
{
    // exception handling
    if(socket == -1)
    {
        throw Socket_Error("Socket creation failed!!!");
    }

    // exit
    return;
}


// Test 2 ----- Test Socket_Error exception in binding a socket to a port
void test_socket_bind(int const bind, int const port)
{
    // exception handling
    if(bind < 0)
    {
        throw Socket_Error("Binding to port " + std::to_string(port) + " failed!!!");
    }

    // exit
    return;
}


// Test 3 ----- Test Socket_Error exception in listening for a client connection
void test_socket_listen(int const listen)
{
    // exception handling
    if(listen < 0)
    {
        throw Socket_Error("Listening failed!!!");
    }

    // exit
    return;
}


// Test 4 ----- Test Socket_Error exception in accepting a client connection
void test_socket_accept(int const socket)
{
    // exception handling
    if(socket < 0)
    {
        throw Socket_Error("The client connection has not been accepted!!!");
    }

    // exit
    return;
}


// Test 5 ----- Test Socket_Error exception in finding a server
void test_server_address(int const connection)
{
    // exception handling
    if(connection <= 0)
    {
        throw Socket_Error("The Address of the server is not correct!!!");
    }

    // exit
    return;
}

// Test 6 ----- Test Socket_Error exception in connecting to a server
void test_server_connect(int const connection)
{
    // exception handling
    if(connection < 0)
    {
        throw Socket_Error("Connection to the server has failed!!!");
    }

    // exit
    return;
}