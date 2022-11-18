#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

struct even{
    bool operator()(int var)
    {
        if (var%2 == 0)
        {
            std::cout << var << " ";
            return true;
        }
        else return false;
    }
};
template <typename T>
    void print(T& container){
    for(char i: container){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
class testing{
    public:
    int& mult;
    testing(int &mult):mult(mult){
        //this->mult = mult;
    }
        void operator()(int val){
            mult += (val);
        }
};

int main(int argc, const char * argv[]) {
    /*
    std::vector<int> list_nums{1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99};
    std::cout << count_if(list_nums.begin(), list_nums.end(), even()) << "\n";
    
    int add_me = 5, minus_me = 1;
    
    transform(list_nums.begin(), list_nums.end(), list_nums.begin(), [=](int num)->int{
        return num + add_me - minus_me;
    });
    int mult = 1;
    for_each(list_nums.begin(), list_nums.end(),testing(mult));
    
    std::cout << mult << "\n";
    */
    
    /*
    std::string tony{"Tony's gbola is very BIG"};
    print(tony);
     
    
    std::vector <std::string> dibia {"come home", "go", "otumopko people of Osun"};
    print(dibia);
    */
    
    std::list<char> a;
    a.resize(11);
    srand((unsigned int)time(0));
    generate(a.begin(),a.end(), []()->int{
        int a = 0;
        while(!((a >= 65 && a <= 90)||(a >= 97 && a <= 122))){
                a = rand() % 123;
            }
        //std::cout << a << " ";
        return a;
        });
    //std::cout << "\n";
    
    print(a);
    std::cout << "\n";
    a.sort(std::less<int>());

    print(a);
    
    
    
    return 0;
}
