
#ifndef table_hpp
#define table_hpp

#include <stdio.h>
#include "father_furniture.hpp"
#include "imported.hpp"

class table:public furniture, public imported{
    private:
        int num_of_legs;
    public:
        table(std::string, int, double, int);
        table();
        int get_num_of_legs();
        char currency();
        bool is_imported();
};


#endif /* table_hpp */
