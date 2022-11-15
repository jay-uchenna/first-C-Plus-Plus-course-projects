//
//  father_furniture.cpp
//  Inheritance
//
//  Created by Jedidiah Uchenna on 06.01.2022.
//

#include "father_furniture.hpp"
#include <string>
#include <iostream>


furniture::furniture(std::string material, int length, double width){
    this->material = material;
    this->length = length;
    this->width = width;
}
double furniture::area(){
    return (double)this->length * this->width;
}
std::string furniture::get_name()const{
    return material;
}
void furniture::set_name(std::string material){
    this->material = material;
}
double furniture::price()const{
    if (material == "wood"){
        return 0.5 * this->length - this->width;
    }
    else{
        return 3 * this->length + this->width;
    }
}

