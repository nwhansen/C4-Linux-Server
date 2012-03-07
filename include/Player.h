/* 
 * File:   Player.h
 * Author: Nathan Hansen
 *
 * Created on March 7, 2012, 10:35 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

namespace C4Server {
#include <string>
#include "event.h"
    class Player {
    public:
        event ListenMessage;
        Player();
        Player(const Player& orig);
        void SendMove(int column, int row);
        virtual ~Player();
    private:
        std::string Name;
        //The socket of the player is on.
        
    };


}
#endif	/* PLAYER_H */

