
#ifndef chair_hpp
#define chair_hpp

#include <stdio.h>
#include "father_furniture.hpp"

class chair:public furniture{
    private:
        std::string curve;
    public:
        chair(std::string, int, double, std::string);
        chair();
        void set_curve(std::string);
        std::string get_curve();
        double price();
        char currency();
};

#endif /* chair_hpp */
