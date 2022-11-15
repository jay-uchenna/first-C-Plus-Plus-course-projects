//
//  main.cpp
//  deadninjured
//
//  Created by Jedidiah Uchenna on 14.07.2022.
//

#include <iostream>
#include "PlayerNumber.hpp"


int main(int argc, const char * argv[])
{
     int my[]{5,5,5,0,4,5,3,5,2,5,8};
    int you[]{5,5,5,0,4,5,3,5,2,5,8};
    PlayerNumber T(11);
    T.setPlayerNumber(my);
    int a = T.compareWithOpponetNumber(you);
    if((a%10) != 4) std::cout << a/10 << " dead ";
    if((a/10) != 4) std::cout << a%10 << " injured";
    std::cout << "\n";
    return 0;
}
