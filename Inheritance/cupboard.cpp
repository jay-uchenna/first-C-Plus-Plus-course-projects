
#include "cupboard.hpp"

cupboard::cupboard(std::string material, int length, double width, int num_of_doors):furniture(material, length, width),num_of_doors(num_of_doors){};
cupboard::cupboard():cupboard("wood", 1, 1, 4){};
void cupboard::set_num_of_doors(int num_of_doors){
    this->num_of_doors = num_of_doors;
}
int cupboard::get_num_of_doors()const{
    return this->num_of_doors;
}
double cupboard::price()const{
    return furniture::price() * 2;
}
char cupboard::currency(){
    return 'e';
}
