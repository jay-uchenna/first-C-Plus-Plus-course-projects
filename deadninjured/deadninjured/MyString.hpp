//
//  MyString.hpp
//  deadninjured
//
//  Created by Jedidiah Uchenna on 09.09.2022.
//

#ifndef MyString_hpp
#define MyString_hpp

class MyString
{
public:
    MyString(unsigned short int);
    MyString();
    void setMyString(char *);
    char * getMyString();
    unsigned short int getMyStringLength();
    unsigned short int getMyStringSize();
    MyString operator=(MyString );
private:
    char * myString;
    unsigned short int length;
    unsigned short int size;
};


#endif /* MyString_hpp */
