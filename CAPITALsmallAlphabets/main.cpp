#include <iostream>

using namespace std;

int main(){

bool check;

do {
    check = false;
    char characterInput;
    cout << "enter an alphabet (press a non alphabet to exit): ";
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

