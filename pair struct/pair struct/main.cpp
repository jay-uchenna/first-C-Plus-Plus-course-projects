//
//  main.cpp
//  pair struct
//
//  Created by Jedidiah Uchenna on 21.01.2022.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::pair <int,char> test1;
    test1.first = 10;
    test1.second = 't';
    std::cout << test1.second << " " << test1.first << "\n";
    return 0;
}
