#include <iostream>
#include "dosage_check.h" 

void display(const dosage_check* );

int main() {
    
    dosage_check person1, person2('h'), person3('f', 20), person4('q', 200, 5.8), person5(92), person6(92.5);
    
    display(&person1);
    
    for (int i=0; i < 5; i++){
    person1.no_remaining();
    person2.no_remaining();
    person3.no_remaining();
    person4.no_remaining();
    person5.no_remaining();
    person6.no_remaining();
    }
    
    display(&person1);
    
    return 0;
}

void display(const dosage_check* a){
    for (int i = 0; i < 6; i++)
    std::cout <<(a-i)->show_drug() << " remains " << (a-i)->get_remaining() << " dozes\n";
}
