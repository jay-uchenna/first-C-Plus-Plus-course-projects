//
//  GamePlay.hpp
//  deadninjured
//
//  Created by Jedidiah Uchenna on 05.09.2022.
//

#ifndef GamePlay_hpp
#define GamePlay_hpp

#include <stdio.h>
#include "PlayerNumber.hpp"

class GamePlay
{
public:
    GamePlay();
    bool startGame();
    void playGame();
    
private:
    bool repeatNumbers;
    int lengthOfNumbers;
};

#endif /* GamePlay_hpp */
