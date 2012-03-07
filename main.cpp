/* 
 * File:   main.cpp
 * Author: Nathan Hansen
 *
 * Created on March 7, 2012, 9:44 AM
 */

#include <cstdlib>

using namespace std;

#define RUN_SUCCESSFULL 0 
#define INVALID_PARAMETERS 1 
#define UNABLE_TO_START_SERVER 2 

struct params;
/**
 * 
 * The Main part of the server. It will start from the command line accepting arguments that determine listening port, timeout for a client ect.
 * @param argc
 * @param argv
 * @return Result of the sever
 */
static int main(int argc, char** argv) {

    return RUN_SUCCESSFULL;
}

struct params {
//Hard limit for the max clients. Make it even so that everybody should be paired.
#define MAX_CLIENTS 50
    //Lets do this
    int port;
    int timeout;
    int max_clients;
    
};