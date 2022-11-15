//
//  bookstore.hpp
//  firstcpp
//
//  Created by Jedidiah Uchenna on 21.10.2021.
//  Copyright © 2021 Jedidiah Uchenna. All rights reserved.
//

#ifndef bookstore_hpp
#define bookstore_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>          //for exit(1)
#include <iomanip>


class bookstore{
    std::string ISBN;
    int no_of_books_sold;
    double cost_of_each_book;
};

#endif /* bookstore_hpp */
