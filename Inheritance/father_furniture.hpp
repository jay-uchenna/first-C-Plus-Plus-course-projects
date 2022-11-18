
#ifndef father_furniture_hpp
#define father_furniture_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class furniture{
    private:
        std::string material;
    protected:
        int length;
        double width;
    public:
        furniture(std::string , int , double );
        //urniture():furniture("wood", 1, 1){};
        double area();
        std::string get_name()const;
        void set_name(std::string);
        virtual double price()const;
        virtual char currency() = 0;
};
    
    
    

#endif /* father_furniture_hpp */
