//
//  main.cpp
//  forward_list
//
//  Created by Jedidiah Uchenna on 21.01.2022.
//

#include <iostream>
#include <algorithm>
#include <forward_list>
#include <string>
#include <vector>
#include <array>

template <class T>
void display(T& lst){
    for(typename T::iterator it = lst.begin(); it != lst.end(); it++ ){
        std::cout << *it << ", ";
    }
    std::cout << "\n";
}

int main(int argc, const char * argv[]) {
    std::forward_list<int> lst(6, 100);
    display(lst);
    
    lst.push_front(311);
    display(lst);
    
    lst.insert_after(lst.begin(), 311);
    display(lst);
    
    lst.insert_after(lst.before_begin(), 3, 211);
    display(lst);
    
    std::vector<int> vect_test(4, 0);
    
    std::forward_list<int>::iterator it = lst.insert_after(++lst.begin(), vect_test.begin(),vect_test.end());
    display(lst);
    
    lst.insert_after(it, 8888);
    display(lst);
    
    lst.reverse();
    display(lst);
    
    lst.erase_after(it, lst.end());
    display(lst);
    
    std::array<int, 8> learn_arr;
    
    learn_arr.fill(0);
    display(learn_arr);
    
    learn_arr.at(3) = 50;
    display(learn_arr);
    
    char love[10] = {'*'};
    int arrSize = sizeof(love)/sizeof(love[0]);
    for(int i = 0 ; i < arrSize; i++) {
        std::cout << love[i] << " " ;
    }
    
    std::cout << "\n";
    
    return 0;
}
