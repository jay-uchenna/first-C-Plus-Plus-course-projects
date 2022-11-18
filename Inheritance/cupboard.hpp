
#ifndef cupboard_hpp
#define cupboard_hpp

#include <stdio.h>
#include "father_furniture.hpp"

class cupboard:public furniture{
    private:
        int num_of_doors;
    public:
        cupboard(std::string, int, double, int);
        cupboard();
        void set_num_of_doors(int);
        int get_num_of_doors()const;
        double price()const;
        char currency();
};


#endif /* cupboard_hpp */
