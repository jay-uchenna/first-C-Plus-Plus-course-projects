#include <iostream>
#include <cmath>

using namespace std;

void swap( int &, int &);
void FactorsOf (int );

int main()
{

  cout << "Press 'f' for factors or 'p' for primes in a range: ";
  char FactorsOrPrimeRange;
  cin>> FactorsOrPrimeRange;
  switch ( FactorsOrPrimeRange ) {
  case 'f':
  case 'F':
  {
   int InputNumber;
   cout<<"enter a number and see its factors: ";
   cin>>InputNumber;
   FactorsOf (InputNumber);
  }
  break;
  case 'P':
  case 'p':
  {
  cout<<"enter 2 numbers to find the prime numbers between them"<<endl;
  int FirstNumber, SecondNumber;
  cout<<"enter first number: ";
  cin>>FirstNumber;
  cout<<"enter second number: ";
  cin>>SecondNumber;
  if (FirstNumber>SecondNumber){
    swap (FirstNumber, SecondNumber);
  }
  if (FirstNumber==0)FirstNumber++;

    
    int numberOfPrimes {0};
  
   
   for(int RangeTester=FirstNumber;RangeTester<=SecondNumber;RangeTester++){
        int numberOfFactors{0};
        for(int FactorTester=2;FactorTester<=sqrt(RangeTester);FactorTester++){
                
            if(RangeTester%FactorTester==0){
               numberOfFactors++;
             break;
               }
        }
        if((numberOfFactors == 0)&&(RangeTester!=1)){
      cout<<" "<<RangeTester<<" ";
        numberOfPrimes++;
        }
    }
    if(numberOfPrimes==0){
      cout<<"there are no primes between " <<FirstNumber<<" and "<<SecondNumber<<endl;
    }
    else{
      cout<<" are the primes between " <<FirstNumber<<" and "<<SecondNumber<<endl;
    }
  }
  break;
  default:
  {
  cout << "you haven't entered a valid key, ";
  }
 }
  cout << "press 't' to try again or any key to exit: ";
  char TryAgain;
  cin >> TryAgain;
  switch (TryAgain){
    case 't':
    case 'T':
    main();
  }
  return 0;
}

void FactorsOf(int InputNumber)
{
  double SqrtOfInputNumber = sqrt (InputNumber);
  for (int Factori = 1; Factori <= SqrtOfInputNumber; Factori++ ){
    int FactorTest = InputNumber % Factori;
    if (FactorTest == 0){
      cout<<Factori<<" ";
      int Factorii = InputNumber / Factori;
      if (Factori == Factorii) continue;
      cout<< Factorii <<" ";
    }
  }
  cout << endl;
}


void swap(int &FirstNumber, int &SecondNumber)
{
  int temp=FirstNumber;
    FirstNumber=SecondNumber;
    SecondNumber=temp;
}

















