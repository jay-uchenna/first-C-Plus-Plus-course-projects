//
//  main.cpp
//  Primorial
//
//  Created by Jedidiah Uchenna on 12.02.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

bool PrimeTest(long );


int main()
{
  cout << "Enter a number to find the nth series of Primorial prime: ";
  int PrimorialNum;
  cin >> PrimorialNum;
  PrimorialNum--;
  int inputNumber = 0, sound = 0;
  while (inputNumber <= PrimorialNum){
  long ResultPrimorial = 1;
  bool Primetester;
  switch (inputNumber){
    case 0: break;
    default: for(int i = 2, j =1; j <= sound; i++){
         Primetester = PrimeTest( i);
         if (Primetester == 1){
          ResultPrimorial *= i;
          j++;

         }
    }
}
Primetester = PrimeTest (ResultPrimorial-1);
if (Primetester == 1 && ResultPrimorial > 2) {
  cout << ResultPrimorial-1 << " ";
  if (inputNumber == PrimorialNum) break;
  inputNumber++;
}
Primetester = PrimeTest (ResultPrimorial+1);
if (Primetester == 1) {
  cout << ResultPrimorial+1 << " ";
  inputNumber++;
}
sound++;
}
cout << endl;
  return 0;
}

bool PrimeTest(long PrimeCheck){
  for (long i = 2; i <= sqrt(PrimeCheck); i++){
    if (PrimeCheck%i == 0){
      return false;
          }
    }
    return true;
  
}
