//
//  dosage_check.hpp
//  ClassTest
//
//  Created by Jedidiah Uchenna on 27.02.2021.
//

#ifndef DOSAGE_CHECK_HH
#define DOSAGE_CHECK_HH

#include <iostream>


class dosage_check{
    private:
        char name_of_drug;
        int total_doze;
        double doze_per_dar;
    public:
        dosage_check();
        dosage_check(char d);
        dosage_check(char d, int e);
        dosage_check(double f);
        dosage_check(int a);
        dosage_check(char d, int e, double f);
        void no_remaining();
        char show_drug() const;
        int get_remaining() const;
    
};

#endif /* dosage_check_hpp */
