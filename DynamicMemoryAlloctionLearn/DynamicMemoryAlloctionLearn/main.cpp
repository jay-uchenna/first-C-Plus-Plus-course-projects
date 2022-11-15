//
//  main.cpp
//  DynamicMemoryAlloctionLearn
//
//  Created by Jedidiah Uchenna on 12.02.2021.
//

#include <iostream>

using namespace  std;

int* final_array_func(int &);
int* new_array( int, int);
int* add_to_arry(int *, int *, int, int);

void sum_and_print_inputs(int *, int);


int main() {

    int total_number_of_input = 0;

    int *needed_array;

    needed_array = final_array_func(total_number_of_input);
    sum_and_print_inputs(needed_array, total_number_of_input);

    delete [] needed_array;

    return 0;
}

int* final_array_func(int &total_number_of_input){

    char exit = 'o';
    bool first = true;
    int *main_array;
 
    do{
       
        cout << "how many inputs do you want to enter: ";
        int number_of_input;
        cin >> number_of_input;

        if (first == true){

            main_array = new_array( number_of_input, total_number_of_input);

        }
        else{

            int *p = new_array( number_of_input, total_number_of_input);
            main_array = add_to_arry(main_array, p, total_number_of_input, number_of_input);

        }
        total_number_of_input += number_of_input;
        cout << "press x to exit or any key to repeat: ";
        cin >> exit;

        int i = 0;
        first = false;

    } while(exit != 'x');

    return main_array;

}



int* new_array( int number_of_new_elements, int total_number_of_input){

    int *array_to_add = new int [number_of_new_elements];
    int i = 0, j = total_number_of_input + 1;
    while( i < number_of_new_elements){
        cout << "enter input " << j << ": ";
        cin >> array_to_add[i];
        i++;
        j++;
    }
    return array_to_add;
}

int* add_to_arry(int *old_array, int *new_array,int old_length,int new_length){
    
    int * joined_array = new int [old_length + new_length];

    for (int i = 0; i < old_length; i++){

        joined_array[i] = old_array[i];
    }
    for (int i = old_length, j = 0; i < old_length + new_length; i++, j++){

        joined_array[i] = new_array[j];
    }
    delete [] old_array;
    delete [] new_array;
     
    return joined_array;
}

void sum_and_print_inputs(int *inputs, int array_length){
 
    int i = 0, j = 0;
    while(i < array_length-1){
    j += inputs[i];
    cout << inputs[i] << ", ";
    i++;
    }
    j += inputs[i];
    cout << inputs[i] << " sum of numbers equals " << j << endl;

}
