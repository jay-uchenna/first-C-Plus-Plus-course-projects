
#include <iostream>
#include <string>
#include <map>

bool comparator(int left, int right){
    return left > right;
}


int main() {
    std::map<int, std::string,bool(*)(int, int)> students(comparator);
    
 
    students[2] = "Linda Ikeji";
  
    
    students.insert({3, "D Man"});

    
    students.insert(std::pair<int, std::string>(4, "Lincon Nav"));
    std::pair<std::map<int,std::string>::iterator,bool> test1 = students.insert(std::pair<int, std::string>(4, "Man them"));
    
    std::cout << test1.first->first << " " << test1.first->second << " " << test1.second << "\n";
    
    std::map<int, std::string>::iterator itr_map = students.begin();
    std::cout << itr_map->second << "\n";
    itr_map++;
    std::cout << itr_map->second << "\n";
    itr_map++;
    std::cout << itr_map->second << "\n";
    itr_map++;
    std::cout << itr_map->second << "\n";
    
    return 0;
}
