//
//  dosage_check.hpp
//  ClassTest
//
//  Created by Jedidiah Uchenna on 27.02.2021.
//

#ifndef DOSAGE_CHECK_H
#define DOSAGE_CHECK_H

#include <iostream>


class dosage_check{
    private:
        char name_of_drug;
        int total_doze;
        double doze_per_dar;
    public:
        dosage_check(){
            name_of_drug = 'e';
            total_doze = 100;
            doze_per_dar = 2.5;
        }
        dosage_check(char d){
            name_of_drug = d;
            total_doze = 100;
            doze_per_dar = 2.5;
        }
         dosage_check(char d, int e){
           name_of_drug = d;
           total_doze = e;
           doze_per_dar = 2.5;
        }
        dosage_check(double f){
            name_of_drug = 'a';
            total_doze = 40;
            doze_per_dar = f;
        }
        dosage_check(int a){
            name_of_drug = 'v';
            total_doze = a;
            doze_per_dar = 3.5;
        }
       dosage_check(char d, int e, double f);
       void no_remaining(){
            total_doze -= doze_per_dar;
       }
        char show_drug() const;
        int get_remaining() const;
    
};

#endif /* dosage_check_h */
