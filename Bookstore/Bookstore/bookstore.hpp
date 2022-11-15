//
//  bookstore.hpp
//  Bookstore
//
//  Created by Jedidiah Uchenna on 29.10.2021.
//

#ifndef bookstore_hpp
#define bookstore_hpp

#include <iostream>
#include <string>

class transac{
     protected:
        std::string ISBN;
        int no_of_books_sold;
        double cost_of_each_book;
    
     public:
        transac(std::string ISBN, int no_of_books_sold, double cost_of_each_book);
        
        std::string get_ISBN() const;
        void set_ISBN(std::string ISBN);
        int get_no_of_books_sold() const;
        void set_no_of_books_sold(int no_of_books_sold);
        double get_cost_of_each_book() const;
        void set_cost_of_each_book(double cost_of_each_book);
};

#endif /* bookstore_hpp */
