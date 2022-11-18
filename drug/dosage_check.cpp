#include "dosage_check.h"

dosage_check::dosage_check(char d, int e, double f){
   name_of_drug = d;
   total_doze = e;
   doze_per_dar = f;
}
char dosage_check::show_drug() const{
   return name_of_drug;
}
int dosage_check::get_remaining() const{
   return this->total_doze;
}
