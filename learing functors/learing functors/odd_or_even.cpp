//
//  odd_or_even.cpp
//  learing functors
//
//  Created by Jedidiah Uchenna on 20.01.2022.
//

#include "odd_or_even.hpp"

odd_or_even_test::odd_or_even_test(){
    is_range = false;
}
odd_or_even_test::odd_or_even_test(int start_range, int end_range):start_range(start_range),end_range(end_range){
    is_range = true;
}
