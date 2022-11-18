
#include "chair.hpp"
//#include "father_furniture.hpp"


chair::chair(std::string material, int length, double width, std::string curve):furniture(material, length, width),curve(curve){};
chair::chair():chair("wood", 1, 1, "basic"){};
void chair::set_curve(std::string){
    
}
std::string chair::get_curve(){
    return this->curve;
}
double chair::price(){
    double chair_price = furniture::price();
    chair_price += 400;
    return chair_price;
}
char chair::currency(){
    return '$';
}

