/* 
 * File:   Server.h
 * Author: Nathan Hansen
 *
 * Created on March 7, 2012, 10:22 AM
 */

#ifndef SERVER_H
#define	SERVER_H


//NameSpace for the C4Server
namespace C4Server {
#include <stdlib.h>
#include <set>
#include "Player.h"

    /**
     * Server Class handles and manages connections for the C4. Will Substantiate and destroy games and players.
     */
    class Server {
    public:
        Server();
        Server(const Server& orig);
        virtual ~Server();
    private:
        //A collection of sockets that have not been authenticated.
    };
}
#endif	/* SERVER_H */

