//
//  main.cpp
//  CAPITALsmallAlphabets
//
//  Created by Jedidiah Uchenna on 12.02.2021.
//

#include <iostream>

using namespace std;

int main(){

bool check;

do {
    check = false;
    char characterInput;
    cout << "enter a letter(press a non alphabet to exit): ";
    cin >> characterInput;

    if (characterInput >= 65 && characterInput <= 90){
        cout << "small letter " << characterInput << " is ";
        characterInput +=32;
        check = true;
    }

    else if (characterInput >= 97 && characterInput <=122) {
        cout << "capital letter " << characterInput << " is ";
        characterInput -=32;
        check = true;
    }
    if (check == true){
        cout << characterInput << endl;
    }
}
while (check == true);

    return 0;
}

