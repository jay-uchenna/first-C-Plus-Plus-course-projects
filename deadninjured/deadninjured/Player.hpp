//
//  Player.hpp
//  deadninjured
//
//  Created by Jedidiah Uchenna on 09.09.2022.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

class Player
{
    Player(int );
    Player();
    void setPlayerID(int );
    int getPlayerID();
    char * getPlayerName();
    void getPlayerName(char* );
private:
    int playerID;
    char * playerName;
};

#endif /* Player_hpp */
