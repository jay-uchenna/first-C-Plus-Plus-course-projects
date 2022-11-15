//
//  main.cpp
//  StringBookstore
//
//  Created by Jedidiah Uchenna on 12.02.2021.
//

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

string useIfNoInput();
string enterInput();
string inputHolder(int , long , int, double);
void display( string, string, string, string);
int findMaxLenght( string);
int numberOfInputs( string);
string tempDisplay( string, string, string, string, int, int (&)[3], int = 0);

int main(){

    cout << "Press i to input or c to calculate or any key to exit: ";
    char inputValue;
    cin >> inputValue;
    string inputString;
    
    if (inputValue == 'c' || inputValue == 'C'){
       inputString = useIfNoInput();
    }

    else if (inputValue == 'i' || inputValue == 'I'){
        inputString = enterInput();
    }

    string ISBN, ammontSold, numberOfSales, costOfEachBook;
    istringstream tempStream(inputString); // this is used to break
    string temp;
    
   while ( tempStream >> temp){
        numberOfSales.append(temp);
        numberOfSales.push_back(' ');
        tempStream >> temp;
        ISBN.append(temp);
        ISBN.push_back(' ');
        tempStream >> temp;
        ammontSold.append(temp);
        ammontSold.push_back(' ');
        tempStream >> temp;
        costOfEachBook.append(temp);
        costOfEachBook.push_back(' ');
    }

    int noOfInputs = numberOfInputs(numberOfSales);
    display( numberOfSales, ISBN, ammontSold, costOfEachBook);
    
    string Holderrr;
    ifstream remember;
    remember.open("youAlreadyKnow.txt");


    while (!remember.eof()){
    getline(remember, Holderrr);
    cout << Holderrr << endl;
    }
    remember.close();
    return 0;
}

string useIfNoInput(){
    int arrayLenght;
    srand(time(0));
    do{
    arrayLenght = rand() % 10;
    }while(arrayLenght == 0);
    
    long ISBN [arrayLenght];
    int ammontSold [arrayLenght];
    double costOfEachBook [arrayLenght];
    string allInputs;

    for (int i = 0; i < arrayLenght; i++){

    ISBN [i] = rand();
    ammontSold [i] = rand() % 20;
    if (ammontSold[i] == 0){
        i--;
        continue;
    }
    costOfEachBook [i] = (rand() % 1000) / 100.0;
    allInputs = allInputs.append( inputHolder( i+1, ISBN[i], ammontSold[i], costOfEachBook[i]));
    }
    
return allInputs;
}

string enterInput(){
    int ammontSold, numberOfSales = 0;
    long ISBN;
    double costOfEachBook;
    char enterSale;
    string allInputs;
        
    do{
        cout << "enter book's ISBN (int): ";
        cin >> ISBN;
        cout << "enter number of copies sold:  ";
        cin >> ammontSold;
        if ( ammontSold == 0){
            cout << "0 sales is not possible, press x to exit or any key to try again: ";
            cin >> enterSale;
            continue;
        }
        cout << "enter cost of each: ";
        cin >> costOfEachBook;
        numberOfSales++;
        allInputs = allInputs.append( inputHolder( numberOfSales, ISBN, ammontSold, costOfEachBook));

        cout << "press x to exit or any key to try again: ";
        cin >> enterSale;

    } while (enterSale != 'x');
    return allInputs;

}
string inputHolder(int numberOfSales, long ISBN, int ammontSold, double costOfEachBook){
    string inPuts; // holds inputed ISBN, no. of sales, cost of each book
    ostringstream temp;
    temp << numberOfSales << " " << ISBN << " " << ammontSold << " " << costOfEachBook << " ";
    return inPuts = temp.str();
}

void display( string numberOfSales, string ISBN, string ammontSold, string costOfEachBook){
    int maxLengntnOs = findMaxLenght( numberOfSales);
    int maxLengntISBN = findMaxLenght( ISBN);
    int maxLengntaS = findMaxLenght( ammontSold);
    int maxLengntcOeB = findMaxLenght( costOfEachBook);

    ofstream nigeria;
    nigeria.open ("youAlreadyKnow.txt");

    if ( nigeria.fail()){
        cout << "could not creat file" << endl;
        exit(1);
    }
    
    string headingOfTable = "no. of Transaction | ISBN no. | no. of books sold | Cost of each";
    
    int arrForColumnStart [3];
    string::size_type index = headingOfTable.find('|');
    arrForColumnStart [0] = index;
    index = headingOfTable.find('|', index + 1);
    arrForColumnStart [1] = index;
    index = headingOfTable.find('|', index + 1);
    arrForColumnStart [2] = index;

    if( maxLengntnOs < arrForColumnStart[0]) maxLengntnOs = arrForColumnStart[0];
    if( maxLengntISBN < arrForColumnStart[1] - arrForColumnStart[0]) maxLengntISBN = arrForColumnStart[1] - arrForColumnStart[0];
    if( maxLengntaS < arrForColumnStart[2] - arrForColumnStart[1]) maxLengntaS = arrForColumnStart[2] - arrForColumnStart[1];
    if( maxLengntcOeB < headingOfTable.length() - arrForColumnStart[2]) maxLengntcOeB = headingOfTable.length() - arrForColumnStart[2];

    arrForColumnStart [0] = maxLengntnOs;
    arrForColumnStart [1] = maxLengntnOs + maxLengntISBN;
    arrForColumnStart [2] = maxLengntnOs + maxLengntISBN + maxLengntaS;

    arrForColumnStart [1] += 4;
    arrForColumnStart [2] +=4;
    
    string headingOfTable1 = "no. of Transaction", headingOfTable2 = "| ISBN no.", headingOfTable3 = "| no. of books sold", headingOfTable4 = "| Cost of each";
    cout << tempDisplay( headingOfTable1, headingOfTable2, headingOfTable3, headingOfTable4, maxLengntcOeB, arrForColumnStart) << endl;
    nigeria << tempDisplay( headingOfTable1, headingOfTable2, headingOfTable3, headingOfTable4, maxLengntcOeB, arrForColumnStart) << endl;
    
        arrForColumnStart[2] += 2;
        arrForColumnStart[1] += 2;
        arrForColumnStart[0] += 2;
        

    string tempStr1, tempStr2, tempStr3, tempStr4;
    istringstream issDispaly1(numberOfSales), issDispaly2(ISBN), issDispaly3(ammontSold), issDispaly4(costOfEachBook);
    while (issDispaly1 >> tempStr1 && issDispaly2 >> tempStr2 && issDispaly3 >> tempStr3 && issDispaly4 >> tempStr4){
        int startHere = arrForColumnStart[0] - (tempStr1.length()+ 4);
        cout << tempDisplay( tempStr1, tempStr2, tempStr3, tempStr4, maxLengntcOeB, arrForColumnStart, startHere) << endl;
        nigeria << tempDisplay( tempStr1, tempStr2, tempStr3, tempStr4, maxLengntcOeB, arrForColumnStart, startHere) << endl;
    }
nigeria.close();
}
int findMaxLenght( string tempStr){
    int temp1 {0}, temp2 {0}, differenceT2T1{0};
    string::size_type index = tempStr.find(' ');
    while ( index != string::npos){
       temp2 = index;
       if(differenceT2T1 < temp2 - temp1) differenceT2T1 = temp2 - temp1;
       temp1 = temp2;
       index = tempStr.find(' ', index + 1);
    }
    return differenceT2T1;
}

int numberOfInputs( string inputString){

    istringstream forLastinString(inputString);
    int numberOfSales = 0;
    while ( forLastinString >> numberOfSales){};
    return numberOfSales;
}
string tempDisplay( string tempStr1, string tempStr2, string tempStr3, string tempStr4,int maxLengntcOeB, int (&arrForColumnStart)[3], int startHere){
    string strOutDisplay;
    strOutDisplay.append(arrForColumnStart[2] + maxLengntcOeB+2, ' ');
    strOutDisplay.insert(startHere,tempStr1);
    strOutDisplay.insert(arrForColumnStart[0],tempStr2);
    strOutDisplay.insert(arrForColumnStart[1],tempStr3);
    strOutDisplay.insert(arrForColumnStart[2],tempStr4);
    return strOutDisplay;
}




