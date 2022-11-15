//
//  main.cpp
//  mic
//
//  Created by Jedidiah Uchenna on 21.07.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int get_number_of_digits( int );
int sovle_for_amstrong_no(int , int);
bool check_for_amstrong_no(int );


int main(){
    
    int a = 0, b = 0;
    cout << "enter a range of numbers to find armstrong numbers between them: \n";
    cout << "enter first numnber: ";
    cin >> a;
    cout << "enter second numnber: ";
    cin >> b;

    if (a > b) swap(a, b);
    
    int i = 0, temp = a;
    while (a <= b){
        bool c = check_for_amstrong_no(a);
        if (c) {
            cout << a << " ";
            i++;
        }
        a++;
    }

    if (i == 0) cout << "there are no armstrong numbers btw " << temp << " and " << b;

    cout << "\n";

    return 0;
}

bool check_for_amstrong_no(int a){

    int b = get_number_of_digits(a);
    int c = sovle_for_amstrong_no(a, b);

    if( a == c) return true;
    else return false;
}

int get_number_of_digits( int a){
    int i = 0;
    for( ; a >= 1; i++){
         a /= 10;
    }
    return i;
}

int sovle_for_amstrong_no( int a, int b){
    int d = 0;
    for(int i = 0, c = 0 ; a >= 1; i++){
         c = a % 10;
         d += pow(c,b);
         a /= 10;
    }
    return d;
}
