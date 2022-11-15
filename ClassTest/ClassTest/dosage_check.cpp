//
//  dosage_check.cpp
//  ClassTest
//
//  Created by Jedidiah Uchenna on 27.02.2021.
//

#include "dosage_check.hh"

dosage_check::dosage_check(){
    name_of_drug = 'e';
    total_doze = 100;
    doze_per_dar = 2.5;
}
dosage_check::dosage_check(char d){
    name_of_drug = d;
    total_doze = 100;
    doze_per_dar = 2.5;
}
dosage_check::dosage_check(char d, int e){
   name_of_drug = d;
   total_doze = e;
   doze_per_dar = 2.5;
}
dosage_check::dosage_check(double f){
    name_of_drug = 'a';
    total_doze = 40;
    doze_per_dar = f;
}
dosage_check::dosage_check(int a){
    name_of_drug = 'v';
    total_doze = a;
    doze_per_dar = 3.5;
}
void dosage_check::no_remaining(){
    total_doze -= doze_per_dar;
}

dosage_check::dosage_check(char d, int e, double f){
   name_of_drug = d;
   total_doze = e;
   doze_per_dar = f;
}
char dosage_check::show_drug() const{
   return name_of_drug;
}
int dosage_check::get_remaining() const{
   return this ->total_doze;
}
