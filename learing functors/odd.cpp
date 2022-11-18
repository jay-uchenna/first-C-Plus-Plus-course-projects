//
//  odd.cpp
//  learing functors
//
//  Created by Jedidiah Uchenna on 20.01.2022.
//

#include "odd.hpp"

odd::odd():odd_or_even_test(){
    
}
odd::odd(int start_range, int end_range):odd_or_even_test(start_range, end_range){
    
}
bool odd::operator()(int val){
    if (!this->is_range)
    {
        return (val % 2) != 0;
    }
    else{
        if(val >= start_range && val <= end_range && (val % 2) != 0){
            return true;
        }
        else
        {
            return false;
        }
    }
}
