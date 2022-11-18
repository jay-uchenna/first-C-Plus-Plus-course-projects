#include <iostream>
#include <string>
#include <sstream>

using  namespace std;

int main(){


    string exampleString = "40 50 600 555 54 90 55 44 68 34";

    istringstream exampleStringStream(exampleString);

    int m;

     while (exampleStringStream >> m){

           cout << "m is: " << m << endl;
           exampleStringStream >> m;
           cout << "m2 is: " << m << endl;
       }
          
    
    

    return 0;
}
