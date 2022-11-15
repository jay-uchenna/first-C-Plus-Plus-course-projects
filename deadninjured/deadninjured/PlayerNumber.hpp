//
//  PlayerNumber.hpp
//  deadninjured
//
//  Created by Jedidiah Uchenna on 04.09.2022.
//

#ifndef PlayerNumber_hpp
#define PlayerNumber_hpp

class PlayerNumber
{
public:
    PlayerNumber(int );
    ~PlayerNumber();
    int * getPlayerNumber();
    void setPlayerNumber(int *);
    int compareWithOpponetNumber(int * );
    int getLengthOfMyNumber();
private:
    int * myNumberArr;
    int lengthOfMyNumber;
    int * hashArr;
};

#endif /* PlayerNumber_hpp */
