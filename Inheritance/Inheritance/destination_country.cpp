//
//  destination_country.cpp
//  Inheritance
//
//  Created by Jedidiah Uchenna on 06.01.2022.
//

#include "destination_country.hpp"

std::string country::destination_country(furniture *p_furniture)const{
    if (p_furniture->currency() == '$') return "United states";
    else if (p_furniture->currency() == 'N') return "Nigeria";
    else if (p_furniture->currency() == 'e') return "Europe";
    else return "no furniture identified";
}
