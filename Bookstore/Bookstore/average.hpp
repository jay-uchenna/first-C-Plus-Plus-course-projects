//
//  average.hpp
//  Bookstore
//
//  Created by Jedidiah Uchenna on 08.12.2021.
//

#ifndef average_hpp
#define average_hpp


#include "bookstore.hpp"

class review_transacs: public transac{
    private:
        double avg_sales;
    public:
        review_transacs(std::string ISBN, int total_no_of_books_sold, double sum_cost_of_each_book);
       
        transac get_elements();
        void set_elements(std::string ISBN, int total_no_of_books_sold, double sum_cost_of_each_book);
        double get_avg_sales();
        //void set_get_avg_sales();
        //bool get_element_changed();
        //void set_element_changed();
};
#endif /* average_hpp */
