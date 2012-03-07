/* 
 * File:   NetworkCom.h
 * Author: Nathan Hansen
 *
 * Created on March 7, 2012, 11:46 AM
 */

#ifndef NETWORKCOM_H
#define	NETWORKCOM_H
/**
 * Defines a namespace for basic networking communication with one client. This will handle creation of sockets and provide a low level listening implementation.
 */
namespace Network {

#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "event.h"
    
    class NetworkCom {
    public:
        /**
         * Fires if we have lost connection
         */
        event LostConnection;
        /**
         * Fires if a "valid" message was received.
         */
        event MessageReceived;
        /**
         * Fires if an invalid message was received.
         */
        event InvalidResponse;
        NetworkCom(char delimeter, std::map *argumentParamMapping);
        NetworkCom(const NetworkCom& orig);
        virtual ~NetworkCom();
        
        /**
         * Send a message to the client. Does not check the validity of the message.
         * @param message the message to send. 
         */
        void operator << (std::string &message) {
            inputStream << message;
        }
        /**
         * Constructs a Message for a given argument.
         * @param argument the argument to use
         * @param ... The following parameters for the argument. Strings must be in char* format.
         * @return If the argument is to short this will return NULL if it is too long, the extra items are ignored.
         */
        std::string ConstructMessage(std::string &argument,  ...);
        
    private:
        std::stringstream inputStream;
        std::stringstream outputStream;
        /**
         * Contains the mapping of an argument to a parameter count.
         */
        std::map<std::string, int>* arguments;
        
        /**
         * The Delimeter between messages.
         */
        char delim;
    };
}
#endif	/* NETWORKCOM_H */

