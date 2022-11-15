//
//  main.cpp
//  TimeApp
//
//  Created by Jedidiah Uchenna on 12.02.2021.
//

#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){

  

int hour;
int min;
int secs;
int handler;
        handler=time(0)%86400;
        hour=handler/3600;
        min=(handler-(hour*3600))/60;
        secs=(handler-(hour*3600))%60;
        hour+=3;
for (int i= 0; i<20; ){
            cout.fill(' ');
            cout.width(25);
            cout<<"time now: "<< setfill ('0') << setw (2)<<hour<<":"
            <<setfill ('0') << setw (2)<<min<<":"
            <<setfill ('0') << setw (2)<<secs
            <<'\r'<<flush;
        
        this_thread::sleep_for (chrono::seconds(1));

        secs++;
        if(secs>59){
          secs=0;
          min++;
          if(min>59){
            min=0;
            hour++;
            if(hour>23) hour=00;
          }
        }

     }

  return 0;
}
