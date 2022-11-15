//
//  main.cpp
//  palindrome_ckeck
//
//  Created by Jedidiah Uchenna on 02.03.2021.
//

#include <iostream>
#include <string>



bool palindrome_ckeck(std::string );

int main(){

    std::string a_word;
    std::cout << "enter a word: ";
    std::cin >> a_word;
    
    bool is_a_palindrome = palindrome_ckeck(a_word);

    if(is_a_palindrome) std::cout << a_word << " is a palindrome\n";
    else std::cout << a_word << " is not a palindrome\n";

    return 0;

}

bool palindrome_ckeck(std::string a_word){

    if (a_word.front() != a_word.back() && a_word.length() > 1) return false;
    else if (a_word.length() <= 1) return true;
    else {
           a_word.pop_back();
           a_word.erase(a_word.begin());
           return palindrome_ckeck(a_word);
         }
}
