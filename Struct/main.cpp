
#include <iostream>


struct Rectangle{

public:
    //Rectangle(int lent, int high): lenght(lent), height(high){};
    int lenght;
    int height;


};

int main(int argc, const char * argv[]) {
    
    Rectangle first = {10, 20};
    std::cout << first.lenght << "\n";
    std::cout << first.height << "\n";
    
    int arr[2] = {2,5};
    std::cout << arr[0] << "\n";
    std::cout << arr[1] << "\n";

    return 0;
}
