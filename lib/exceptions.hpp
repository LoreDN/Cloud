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
void test_socket_creation(int const socket);
void test_socket_bind(int const bind, int const port);
void test_socket_listen(int const listen);
void test_socket_accept(int const socket);


// Test 1 ----- Test Socket_Error exception in creating
void test_socket_creation(int const socket)
{
    // exception handling
    if(socket == 1)
    {
        throw Socket_Error("Socket creation failed!!!");
    }

    // exit
    return;
}


// Test 2 ----- Test Socket_Error exception in binding
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


// Test 3 ----- Test Socket_Error exception in listening
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


// Test 4 ----- Test Socket_Error exception in accepting
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