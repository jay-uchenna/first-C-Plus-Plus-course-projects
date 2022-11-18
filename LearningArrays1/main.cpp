#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int size_array {100};
int rowsize(int = size_array);
int columnsize(int = size_array);

int main(){
 
    int jeb[size_array][size_array];
    cout << "Programme to view a 2D array with 100 as max row & column" << endl;
    cout << "Enter row size less than 100: ";
    int Row_Size = rowsize();
    
    cout << "Enter column size less than 100: ";
    int Column_Size = columnsize();
    
    srand(time(0));
    for(int i = 0; i < Row_Size; i++){
        for(int j = 0; j < Column_Size; j++){
         jeb[i][j] = rand() % 99;
        }
    }
    
    char RepeatKey {0};
    int  MyRow, MyColumn;
    do{
        cout << "Enter a value for any given element of the Array" << endl;

        cout << "value row: ";
        MyRow = rowsize(Row_Size - 1);

        cout << "value column: ";
        MyColumn = columnsize(Column_Size - 1);

        cout << "now enter element value: ";
        cin >> jeb [MyRow] [MyColumn];

        cout << "Press r to change another value in the array or any key to view the array: ";
        cin >> RepeatKey;
    }
    while (RepeatKey == 'r');

    for(int i = 0; i < Row_Size; i++){
        for(int j = 0; j < Column_Size; j++){
         cout << setfill ('0') << setw (2) << jeb[i][j] << " ";
        }
        cout << endl;
    }

return 0;
}
int rowsize(int RowMax){
    int firstN {1};
    if (RowMax != size_array ) firstN = 0;
    int Row_Size;
    cin >> Row_Size;
    if (Row_Size < firstN || Row_Size > RowMax){
    cout << "Please enter a valid Row between " << firstN << " and " << RowMax << ": ";
    Row_Size = rowsize(RowMax);
    }
    return Row_Size;
}
int columnsize(int ColumnMax){
    int firstN {1};
    if (ColumnMax != size_array ) firstN = 0;
    int Column_Size;
    cin >> Column_Size;
    if (Column_Size < firstN || Column_Size > ColumnMax){
    cout << "Please enter a valid column between " << firstN << " and " << ColumnMax << ": ";
    Column_Size = columnsize(ColumnMax);
    }
    return Column_Size;

}
