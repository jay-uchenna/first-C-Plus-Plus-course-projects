//
//  odd.hpp
//  learing functors
//
//  Created by Jedidiah Uchenna on 20.01.2022.
//

#ifndef odd_hpp
#define odd_hpp

#include <stdio.h>
#include "odd_or_even.hpp"

class odd:public odd_or_even_test{
    public:
        odd();
        odd(int, int);
        bool operator()(int);
};

#endif /* odd_hpp */
