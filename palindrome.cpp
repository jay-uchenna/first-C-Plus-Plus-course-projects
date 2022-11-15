

#include <iostream>
#include <string>


std::string enter_a_word(); 
bool palindrome_ckeck(std::string );

int main(){

    std::string a_word = enter_a_word();
	    
  	bool is_a_palindrome = palindrome_ckeck(a_word);

	if(is_a_palindrome) std::cout << a_word << " is a palindrome\n";
	else std::cout << a_word << " is not a palindrome\n";

	return 0;

} 

std::string enter_a_word(){

	std::string a_word;
	std::cout << "enter a word: ";
	std::cin.clear(); 
    std::cin.ignore(INT_MAX, '\n');
	std::cin >> a_word;
	if(std::cin.fail()){
		std::cout << "please no spaces, press x to exit or any other key to try again: ";
		char x;
		std::cin >>x;
		if (x == 'x' || x == 'X') exit(1);
		else return enter_a_word();
	}
	else return a_word;
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

