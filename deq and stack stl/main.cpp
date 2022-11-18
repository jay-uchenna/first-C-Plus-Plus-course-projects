#include <iostream>
#include <deque>
#include <stack>
#include <string>
#include <array>

class check_brackets{
    private:
        const std::string test_string;
        std::stack <char> my_stack;
        std::array <const char,6> bracks = {'(', '[', '{', ')', ']', '}'};
    public:
        check_brackets(std::string& test_string):test_string(test_string){
    }
    bool check_brack(){
        for (std::string::const_iterator it = test_string.begin(); it != test_string.end(); it++)
        {
            if( *it == bracks[0] ||  *it == bracks[1] || *it == bracks[2])
            {
                my_stack.push(*it);
            }
            
            else if( *it == bracks[3] ||  *it == bracks[4] || *it == bracks[5])
            {
                int temp = 3;
                while(*it != bracks[temp]) temp++;
                if( my_stack.empty() || my_stack.top() != bracks[temp-3]) return false;
                my_stack.pop();
            }
        }
        if (my_stack.empty())return true;
        else return false;
    }
 
};

int main(int argc, const char * argv[]) {
    
    std::cout << "enter a maths statement: ";
    
    std::string math_word;
    std::getline( std::cin, math_word);
    
    check_brackets testing(math_word);
    
    if(testing.check_brack()) std::cout << "correct expression\n";
    else std::cout << "incorrect expression\n";
    
    return 0;
}
