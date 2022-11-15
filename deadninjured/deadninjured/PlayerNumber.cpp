//
//  PlayerNumber.cpp
//  deadninjured
//
//  Created by Jedidiah Uchenna on 04.09.2022.
//

#include "PlayerNumber.hpp"

PlayerNumber::PlayerNumber(int lengthOfMyNumber)
{
    this->lengthOfMyNumber = lengthOfMyNumber;
    this->myNumberArr = new int[this->lengthOfMyNumber];
    this->hashArr = new int [10];
    for(int i=0; i < 10; i++) hashArr[i] = 0;
}
PlayerNumber::~PlayerNumber()
{
    delete [] this->myNumberArr;
    delete [] this->hashArr;
}
int * PlayerNumber::getPlayerNumber()
{
    return this->myNumberArr;
}
void PlayerNumber::setPlayerNumber(int* myNumber)
{
    for(int i=0; i < this->lengthOfMyNumber; i++) this->myNumberArr[i] = myNumber[i];
}
int PlayerNumber::compareWithOpponetNumber(int* yourCallArr)
{
    int * tempYourCallArr = new int [this->lengthOfMyNumber];
    for(int i = 0; i < this->lengthOfMyNumber; i++) tempYourCallArr[i] = yourCallArr[i];
    int varForDeadandInj = 0;
    for(int i = 0; i < this->lengthOfMyNumber; i++) hashArr[myNumberArr[i]]++;
    for(int i = 0; i < this->lengthOfMyNumber; i++)
    {
        if (tempYourCallArr[i] == this->myNumberArr[i])
        {
            varForDeadandInj += 10;
            hashArr[myNumberArr[i]]--;
            tempYourCallArr[i] = -1;
        }
    }
    for(int i = 0; i < this->lengthOfMyNumber; i++)
    {
        if(tempYourCallArr[i] == -1) continue;
        else if (hashArr[tempYourCallArr[i]] > 0)
        {
            varForDeadandInj++;
            hashArr[tempYourCallArr[i]]--;
        }
    }
    
    delete [] tempYourCallArr;
    return varForDeadandInj;
}
int PlayerNumber::getLengthOfMyNumber()
{
    return this->lengthOfMyNumber;
}
