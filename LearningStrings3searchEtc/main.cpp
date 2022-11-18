#include <iostream>
#include <string>

using  namespace std;

int main(){
    
    string testString, falseCall;
    cout << "Enter a line: ";
    getline( cin, testString);
    falseCall = testString;

    string finalString;
    finalString.clear();

    while(testString.length() > 0){
    finalString.push_back(testString.back());
    testString.pop_back();
    }

    finalString.append(falseCall);
    finalString.insert( 10, falseCall);

    cout << finalString << endl;

    string milk, b;
    cout << "Enter what you want to search: ";
    getline( cin, milk);
    
    string::size_type indexHolder = finalString.find( milk);
    int occurance{1};
    while( indexHolder != string::npos){
        if ( occurance%10 == 1 && occurance != 11) b = "st";
        else if ( occurance%10 == 2 && occurance != 12) b = "nd";
        else if ( occurance%10 == 3 && occurance != 13) b = "rd";
        else b = "th";

        cout << "The " << occurance << b << " occurance of " << milk << " is at " << indexHolder << endl;
        indexHolder = finalString.find( milk, indexHolder + 1);
        occurance++;
    }

    string honey;
    cout << "Enter what you want to search: ";
    getline( cin, honey);
    
    string::size_type indexx = finalString.find_first_of( honey);
    occurance = 1;
    while( indexx != string::npos){
        if ( occurance%10 == 1 && occurance%100 != 11) b = "st";
        else if ( occurance%10 == 2 && occurance%100 != 12) b = "nd";
        else if ( occurance%10 == 3 && occurance%100 != 13) b = "rd";
        else b = "th";

        cout << "The " << occurance << b << " occurance of " << finalString [indexx] << " is at " << indexx << endl;
        indexx = finalString.find_first_of( honey, indexx + 1);
        occurance++;
    }


    return 0;
}
