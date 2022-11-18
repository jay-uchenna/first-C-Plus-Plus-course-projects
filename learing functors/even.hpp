//
//  even.hpp
//  learing functors
//
//  Created by Jedidiah Uchenna on 20.01.2022.
//

#ifndef even_hpp
#define even_hpp

#include <stdio.h>
#include "odd_or_even.hpp"

class even:public odd_or_even_test{
    public:
        even();
        even(int, int);
        bool operator()(int);
};

#endif /* even_hpp */
