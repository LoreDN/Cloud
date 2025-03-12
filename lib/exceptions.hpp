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
void test_socket(int socket);


// Test 1 ----- Test Socket_Error exceptions
void test_socket(int socket)
{
    // exception handling
    if(socket == 1)
    {
        throw Socket_Error("Socket creation failed!!!");
    }

    // exit
    return;
}