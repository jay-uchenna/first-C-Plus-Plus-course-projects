//
//  main.cpp
//  deq and stack stl
//
//  Created by Jedidiah Uchenna on 21.01.2022.
//

#include <iostream>
#include <deque>
#include <stack>
#include <string>
#include <array>

class check_brackets{
    private:
        std::string& test_string;
        std::stack <char> my_stack;
        std::array <char,6> bracks = {'(', '[', '{', ')', ']', '}'};
    public:
        check_brackets(std::string& test_string):test_string(test_string){
    }
    bool check_brack(){
        std::string::iterator it;
        std::string::iterator it_h = test_string.begin();
        int next_attempt = 0;
        bool first_attempt = true;
        do{
            it = std::find_first_of(it_h + next_attempt, test_string.end(), bracks.begin(),
                                        bracks.end());
            std::cout << *it << "\n";
            if(*it == bracks[3] || *it == bracks[4] || *it == bracks[5]){
                if (my_stack.size()==0) {
                    std::cout << "1\n";
                    return false;
                }
                else if((*it == bracks[3] && my_stack.top() == bracks[0])
                        ||(*it == bracks[4] && my_stack.top() == bracks[1])
                        ||(*it == bracks[5] && my_stack.top() == bracks[2])) {
                    std::cout << "2\n";
                    my_stack.pop();
                }
                else{
                    std::cout << "3\n";
                    return false;
                }
            }
            else if(*it == bracks[0] || *it == bracks[1] || *it == bracks[2]){
                std::cout << "4\n";
                my_stack.push(*it);
            }
            if(first_attempt){
                std::cout << "5\n";
                next_attempt = 1;
                first_attempt = false;
            }
            it_h = it;
        }while(it != test_string.end());
        
        if (my_stack.size()==0){
            std::cout << "6\n";
            return true;
        }
        else {
            std::cout << "7\n";
            return false;
        }
    }
 
};

int main(int argc, const char * argv[]) {
    
    std::cout << "enter a maths statement: ";
    
    std::string word_test;
    std::getline( std::cin, word_test);
    
    check_brackets testing(word_test);
    
    if(testing.check_brack()) std::cout << "correct expression\n";
    else std::cout << "incorrect expression\n";
    
    return 0;
}
