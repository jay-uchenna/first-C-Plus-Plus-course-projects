//
//  bookstore.cpp
//  Bookstore
//
//  Created by Jedidiah Uchenna on 29.10.2021.
//

#include "bookstore.hpp"


transac::transac(std::string ISBN, int no_of_books_sold, double cost_of_each_book){
    this -> ISBN = ISBN;
    this -> no_of_books_sold = no_of_books_sold;
    this -> cost_of_each_book = cost_of_each_book;
}

std::string transac::get_ISBN() const{
    return this->ISBN;
}
void transac::set_ISBN(std::string ISBN){
    this->ISBN = ISBN;
}
int transac::get_no_of_books_sold() const{
    return this -> no_of_books_sold;
}
void transac::set_no_of_books_sold(int no_of_books_sold){
    this -> no_of_books_sold = no_of_books_sold;
}
double transac::get_cost_of_each_book() const{
    return this -> cost_of_each_book;
}
void transac::set_cost_of_each_book(double cost_of_each_book){
    this -> cost_of_each_book = cost_of_each_book;
}
