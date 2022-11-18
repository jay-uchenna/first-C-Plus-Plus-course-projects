
#include "table.hpp"
//#include "father_furniture.hpp"

table::table(std::string material, int length, double width, int num_of_legs):furniture(material, length, width),num_of_legs(num_of_legs){};
table::table():table("wood", 1, 1, 4){};
int table::get_num_of_legs(){
    if(furniture::area() < 200) return 4;
    else return 6;
}
char table::currency(){
    return 'N';
}
bool table::is_imported(){
    return true;
}


