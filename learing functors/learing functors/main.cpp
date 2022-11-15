//
//  main.cpp
//  learing functors
//
//  Created by Jedidiah Uchenna on 20.01.2022.
//

#include <iostream>
#include <vector>
#include <list>
#include "even.hpp"
#include "odd.hpp"



void print(int val){
    std::cout << val << " ";
}
template <typename Iterator>
void print_contanier(Iterator start,Iterator end){
    for(;start != end; start++){
        std::cout << *start << " ";
    }
}
template <class Iterator,typename T>
int get_count(Iterator start, Iterator end, T criteria)
    {
        int count = 0;
        for(; start != end; start++){
            if (criteria (*start))
            {
                print(*start);
                count++;
            }
        }
        return count;
    }

int main(int argc, const char * argv[]) {
    std::list <int> test1 {1,2,3,4,5,6,7,9,10};
    /*
    int num_of = get_count(test1.begin(), test1.end(), even());
    
    long int num_of1 = count_if (test1.begin(), test1.end(), even());
     std::cout << "\n" << num_of << "\n";
     std::cout << num_of1 << "\n";
     */
    print_contanier(test1.begin(), test1.end());
    std::cout << "\n";
    //template <typename T>
    std::list<int>::iterator it = remove_if(test1.begin(), test1.end(), odd());
    
    test1.erase(it,test1.end());
    print_contanier(test1.begin(), test1.end());
    std::cout << "\n";
    
    std::string my_name { "Uchenna Jay"};
    transform(my_name.begin(), my_name.end(), my_name.begin(), ::toupper);
    
    for_each(test1.begin(), test1.end(), print);
    
    std::cout << "\n" << my_name << "\n";
    
    
    return 0;
}
