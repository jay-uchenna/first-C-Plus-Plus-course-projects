//
//  main.cpp
//  StringTest2
//
//  Created by Jedidiah Uchenna on 12.02.2021.
//

#include <iostream>
#include <string>
#include <sstream>

using  namespace std;

int main(){
    string test1, test2, test3;

    cout << "Enter sentence: ";
    getline(cin, test1);

    cout << "Enter word to be replaced: ";
    getline(cin, test2);

    cout << "Enter replacing word: ";
    getline(cin, test3);

    string::size_type positionIndex = test1.find( test2);

    while( positionIndex != string::npos){
          test1.replace(positionIndex, test2.length(), test3); // testing .replace
          positionIndex = test1.find( test2, positionIndex+1);
    }
    
    cout << test1 << endl;

    string play = test1.substr(0, test1.size()-1); // testing .substr

    cout << play << endl;

    return 0;
}
