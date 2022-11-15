//
//  average.cpp
//  Bookstore
//
//  Created by Jedidiah Uchenna on 08.12.2021.
//

#include "average.hpp"


review_transacs::review_transacs : public transac( ISBN, total_no_of_books_sold, sum_cost_of_each_book){

    this->avg_sales = (double)sum_cost_of_each_book / total_no_of_books_sold;
    //element_changed = false;
}

    void review_transacs::set_elements(std::string ISBN, int total_no_of_books_sold, double sum_cost_of_each_book){
    this -> avg_sales = 2;//(double)sum_cost_of_each_book/total_no_of_books_sold;
}
//what to return
transac review_transacs::get_elements(){
    return thi;
}

double review_transacs::get_avg_sales(){
        return this->avg_sales;
    }


 /*
    if(this-> temp_ISBN != ISBN){
        
    };
    this -> elements.no_of_books_sold = no_of_books_sold;
    this -> elements.cost_of_each_book = cost_of_each_book;
    this->avg_sales = (double)sum_cost_of_each_book / total_no_of_books_sold;
}
*/


//void set_get_avg_sales();
//bool get_element_changed();
//void set_element_changed();
