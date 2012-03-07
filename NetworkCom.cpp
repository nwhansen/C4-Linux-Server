/* 
 * File:   NetworkCom.cpp
 * Author: Nathan Hansen
 * 
 * Created on March 7, 2012, 11:46 AM
 */

#include "NetworkCom.h"

using namespace Network;

NetworkCom::NetworkCom(char delimeter, std::map *argumentParamMapping) {
    //Ok lets check to see if all is well.
    if (argumentParamMapping == 0)
        throw 0; //Crash the program.
    this->delim = delimeter;
    this->arguments = argumentParamMapping;
}

std::string NetworkCom::ConstructMessage(std::string& argument, ...) {
    //Get the arg count from the map
    std::map<std::string, int>::iterator loc = arguments->find(argument);
    if (loc == arguments->end()) //Didn't find the element
        return NULL;
    int argC = loc->second;
    va_list args;
    va_start(args, argument);
    std::stringstream message;
    message << argument << this->delim;
    std::string param;
    for (int i = 0; i < argC; i++) {
        param = va_arg(args, char*);
        if (param == NULL) {
            return NULL; //Invalid number of arguments
        }
        message << param << this->delim;
    }
    return message.str();
}