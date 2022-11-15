//
//  main.cpp
//  Bookstore
//
//  Created by Jedidiah Uchenna on 03.02.2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>          //for exit(1)
#include <iomanip>

struct transac{
    
};

struct review_transacs{
    transac element;
    double avg_sales;
};

void read_database(std::vector <transac>& );
void create_database_file();
void app_interface(std::vector <transac>& );
void view_transactions(std::vector <transac>);
void write_to_database(std::vector <transac>&);
void view_total_rev_avg(std::vector <transac>);
std::vector <transac> unify_ISBN(std::vector <transac>); //to compute total number of copies sold and total revenue from a book
std::vector <review_transacs> calculate_review(std::vector <transac>); //to compute the average sales price.
void delete_transactions(std::vector <transac>&);
void edit_transactions(std::vector <transac>&);
void save_transactions(std::vector <transac>);

void transac_empty_error_message(){
    std::cout << "invalid option chosen\n";
}

int main() {
    
    
    std::vector <transac> v_transactions;
    read_database(v_transactions);
    app_interface(v_transactions);
    
    return 0;
}

void read_database(std::vector <transac>& v_transactions){
    
    std::ifstream fin;
    fin.open ("transac_database.txt");
    if(fin.fail()){
        std::cout << "opening database file failed\n Press any key to exit or C to create new database if this is the first time you are using this app: ";
        char create_database = '0';
        std::cin >> create_database;
        if(create_database == 'c'|| create_database == 'C'){
            create_database_file();
            return;
        }
        else exit(1);
    }

    while(!fin.eof()){

        transac temp_transac;
        
        fin >> temp_transac.ISBN;
        fin >> temp_transac.no_of_books_sold;
        fin >> temp_transac.cost_of_each_book;
        
        if (temp_transac.no_of_books_sold > 0)v_transactions.push_back(temp_transac);
        
    }
    
    fin.close();
}

void create_database_file(){
    std::ofstream fout;
        fout.open ("transac_database.txt");
        if(fout.fail()){
            std::cout << "error creating database file" << std::endl;
            std::exit(1);
        }
    fout << "0 0 0";
    fout.close();
}

void app_interface(std::vector <transac>& v_transactions){
    
    for( ; ; ){
         std::cout << "\nyou have " << v_transactions.size() << " transaction(s)" << std::endl
         << "Press" << std::endl
        
         << "1. to add new transactions\n";
        if ( v_transactions.size() > 0){
         std::cout << "2. to view transactions\n"
         << "3. to view total revenue and average sales price\n"
         << "4. to delete a transaction\n"
         << "5. to edit a transaction\n"
         << "6. to save\n"
         << "7. to delete all saved transactions\n";
        }
         std::cout << "0. to exit\n";

    
         char chosen_option = '0';
         std::cout << "your option: ";
         std::cin >> chosen_option;
    
         switch (chosen_option){
             case '1': write_to_database(v_transactions);
                 break;
             case '2': {
                 if (v_transactions.size() > 0) view_transactions(v_transactions);
                 else transac_empty_error_message();
                 break;
                 }
             case '3': {
                 if (v_transactions.size() > 0) view_total_rev_avg(v_transactions);
                 else transac_empty_error_message();
                 break;
                 }
            case '4': {
                if (v_transactions.size() > 0) delete_transactions(v_transactions);
                else transac_empty_error_message();
                break;
                }
                 break;
            case '5': {
                if (v_transactions.size() > 0) edit_transactions(v_transactions);
                else transac_empty_error_message();
                break;
                }
                 break;
             case '6': {
                 if (v_transactions.size() > 0) save_transactions(v_transactions);
                 else transac_empty_error_message();
                 break;
                 }
                 break;
            
            case '7': {
                 std::cout << "are you sure you want to DELETE ALL in the data base?\npress Y to delete or any key to go back to menu: ";
                 char delete_choice;
                 std::cin >> delete_choice;
                 if (delete_choice == 'Y'|| delete_choice == 'y') create_database_file();
                 break;
                 }
            case '0': return;
                 
             default: transac_empty_error_message();
        
          }
    }

}
void view_transactions(std::vector <transac> display_transaactions){
    std::cout << '\n';
    const int lth_of_no = 13, lth_of_ISBN = 17, lth_of_books_sold = 13, lth_of_cost = 20;
    
    std::cout.width(lth_of_no); std::cout << std::left << "Transac no.";
    std::cout.width(lth_of_ISBN); std::cout  << std::left << "ISBN";
    std::cout.width(lth_of_books_sold); std::cout  << std::right <<  "copies sold";
    std::cout.width(lth_of_cost); std::cout << std::setprecision(2)  << std::right << std::fixed << "cost of each(rub)" << std::endl;
    
    std::cout.fill('-');
    std::cout.width (lth_of_no + lth_of_ISBN + lth_of_books_sold + lth_of_cost);
    std::cout << "-" << std::endl;
    std::cout.fill(' ');
    
    for(int i = 0; i < display_transaactions.size(); i++){
        std::cout.width(lth_of_no); std::cout << std::left << i+1;
        std::cout.width(lth_of_ISBN); std::cout  << std::left << display_transaactions[i].ISBN;
        std::cout.width(lth_of_books_sold); std::cout  << std::right <<  display_transaactions[i].no_of_books_sold;
        std::cout.width(lth_of_cost); std::cout << std::setprecision(2)  << std::right << std::fixed << display_transaactions[i].cost_of_each_book << std::endl;
    }
    
}
void write_to_database(std::vector <transac>& v_transactions){
    char exit_write = 'a';
    std::string error_popup = "invalid input, press any key to try again or X to go to options menu\n ...";
    
    while (exit_write != 'x'){
        transac v_temp_transaction;
        std::string temp_ISBN;
        std::cout << "enter ISBN (Should be a string without spaces): ";
        /*std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        getline(std::cin, temp_ISBN);*/
        std::cin >> temp_ISBN;
        // LATER HERE SHOULD BE AN ISBN CHECK
        
        int temp_no_of_books_sold;
        do{
            std::cout << "enter number of books sold: ";
            std::cin >> temp_no_of_books_sold;
            if (temp_no_of_books_sold <= 0){
                
                std::cout << error_popup;
                std::cin >> exit_write;
                if (exit_write == 'x' || exit_write == 'x') return;
                else continue;
            }
            exit_write = 'c';
        }while(exit_write != 'c');
    
        double temp_cost_of_each_book;
        do{
            std::cout << "enter cost of a copy: ";
            std::cin >> temp_cost_of_each_book;
            if (temp_cost_of_each_book < 0){
                std::cout << error_popup;
                std::cin >> exit_write;
                if (exit_write == 'x' || exit_write == 'x') return;
                else continue;
            }
        exit_write = 'c';
        }while(exit_write != 'c');
    
        v_temp_transaction.ISBN = temp_ISBN;
        v_temp_transaction.no_of_books_sold = temp_no_of_books_sold;
        v_temp_transaction.cost_of_each_book = temp_cost_of_each_book;
    
        v_transactions.push_back(v_temp_transaction);
    
        std::cout << "press any key to add another transaction or X to go to options menu: ";
        std::cin >> exit_write;
        if (exit_write == 'X') exit_write = 'x';
    }
}
void view_total_rev_avg(std::vector <transac> v_transactions){
    
    std::vector <review_transacs> v_sales_review;
    
    v_sales_review = calculate_review(v_transactions);
    
    std::cout << "size of v_sales_review: " << v_sales_review.size() << "\n";
    
    std::cout << '\n';
    const int lth_of_no = 13, lth_of_ISBN = 17, lth_of_books_sold = 20, lth_of_cost = 22;
    
    std::cout.width(lth_of_no); std::cout << std::left << "Book";
    std::cout.width(lth_of_ISBN); std::cout  << std::left << "ISBN";
    std::cout.width(lth_of_books_sold); std::cout  << std::right <<  "total copies sold";
    std::cout.width(lth_of_cost); std::cout << std::setprecision(2)  << std::right << std::fixed << "total revenue(rub)";
    std::cout.width(lth_of_cost); std::cout << std::setprecision(2)  << std::right << std::fixed << "average cost(rub)" << std::endl;
    
    std::cout.fill('-');
    std::cout.width (lth_of_no + lth_of_ISBN + lth_of_books_sold + (2 * lth_of_cost));
    std::cout << "-" << std::endl;
    std::cout.fill(' ');
    
    for(int i = 0; i < v_sales_review.size(); i++){
        std::cout.width(lth_of_no); std::cout << std::left << i+1;
        std::cout.width(lth_of_ISBN); std::cout  << std::left << v_sales_review[i].element.ISBN;
        std::cout.width(lth_of_books_sold); std::cout << std::right <<  v_sales_review[i].element.no_of_books_sold;
        std::cout.width(lth_of_cost); std::cout << std::setprecision(2)  << std::right << std::fixed << v_sales_review[i].element.cost_of_each_book;
        std::cout.width(lth_of_cost); std::cout << std::setprecision(2)  << std::right << std::fixed << v_sales_review[i].avg_sales << std::endl;
    }
    
    
}

std::vector <review_transacs> calculate_review(std::vector <transac> v_transactions){
    
    std::vector <transac> v_trans_unified = unify_ISBN(v_transactions);
    
    std::cout << "size of unified " << v_trans_unified.size() << "\n";

    std::vector <review_transacs> v_sales_review;

    for(int i = 0; i < v_trans_unified.size(); i++){
        review_transacs temp;
        
        temp.element.ISBN = v_trans_unified[i].ISBN;
        temp.element.no_of_books_sold = v_trans_unified[i].no_of_books_sold;
        temp.element.cost_of_each_book = v_trans_unified[i].cost_of_each_book;
        temp.avg_sales = v_trans_unified[i].cost_of_each_book / v_trans_unified[i].no_of_books_sold;
        v_sales_review.push_back(temp);
    }
    
    std::cout << "size of unified " << v_sales_review.size() << "\n";
        
    
    return v_sales_review;
}

std::vector <transac> unify_ISBN(std::vector <transac> v_transactions){
    
    std::vector <transac> v_trans_unified;
    for(int i = 0; i < v_transactions.size(); i++){
        int j = 0; //index manipultor for v_sales_review
        for ( ; j < v_trans_unified.size(); j++){
            if(v_transactions[i].ISBN == v_trans_unified[j].ISBN){
                
                v_trans_unified[j].no_of_books_sold += v_transactions[i].no_of_books_sold;
                v_trans_unified[j].cost_of_each_book += (v_transactions[i].cost_of_each_book * v_transactions[i].no_of_books_sold);
            
                break;
            }
            
        }
        
        if (j == v_trans_unified.size()){
            transac temp;
            
            temp.ISBN = v_transactions[i].ISBN;
            temp.no_of_books_sold = v_transactions[i].no_of_books_sold;
            temp.cost_of_each_book = v_transactions[i].cost_of_each_book * v_transactions[i].no_of_books_sold;
            
            v_trans_unified.push_back(temp);
        }
    }
        
    return v_trans_unified;
    
}
void delete_transactions(std::vector <transac>& v_transactions){
    
    view_transactions(v_transactions);
    std::cout << "for single element delete press A | for range delete press B: ";
    char delete_type;
    std::cin >> delete_type;
    if (delete_type != 'A' && delete_type != 'a' && delete_type != 'B' && delete_type != 'b'){
        transac_empty_error_message();
        return;
    }
        
    int first_element = 0, last_element = 0;
    std::cout << "enter the" << (( delete_type == 'B' || delete_type == 'b' ) ? " first " : " ") << "Transac no.: ";
    std::cin >> first_element;
    
    if (first_element > v_transactions.size() || first_element < 1){
        transac_empty_error_message();
        return;
    }
    
    if (delete_type == 'A' || delete_type == 'a') last_element = first_element;
    else {
        std::cout << "enter the end Transac no.: ";
        std::cin >> last_element;
    }
    
    if (first_element > last_element){
        transac_empty_error_message();
        return;
    }
    first_element--;
    
    v_transactions.erase(v_transactions.begin()+first_element, v_transactions.begin()+last_element);
    
}

void edit_transactions(std::vector <transac>& v_transactions){
    
    view_transactions(v_transactions);
    
    std::cout << "enter the Transac no. of the transaction you want to edit: ";
    int transac_no_to_edit = 0;
    std::cin >> transac_no_to_edit;
    
    if(transac_no_to_edit > v_transactions.size() || transac_no_to_edit < 1){
        transac_empty_error_message();
        return;
    }
    
    bool save_n_return = false;
    
    while(save_n_return == false){
        std::cout << "to edit ISBN Press 1\n"
              << "to edit copies sold Press 2\n"
              << "to edit cost of each(rub) 3\n"
              << "your option: ";
    
        int option_to_edit;
        std::cin >> option_to_edit;
        if (option_to_edit > 3 || option_to_edit < 1){
            transac_empty_error_message();
            return;
        }
        transac_no_to_edit--; //to access correct index
        option_to_edit--; //to access correct index

        if (option_to_edit == 0){
            std::string temp_ISBN;
            std::cout << "enter new ISBN: ";
            std::cin >> temp_ISBN;
            v_transactions[transac_no_to_edit].ISBN = temp_ISBN;
            
        }
        else if (option_to_edit == 1){
            int temp_copies_sold;
            std::cout << "enter new copies sold: ";
            std::cin >> temp_copies_sold;
            v_transactions[transac_no_to_edit].no_of_books_sold = temp_copies_sold;
        }
        else if (option_to_edit == 2){
            double cost_of_each;
            std::cout << "enter new cost of each(rub): ";
            std::cin >> cost_of_each;
            v_transactions[transac_no_to_edit].cost_of_each_book = cost_of_each;
            
        }
                    
        std::cout << "press any key to return to main menu or R to change another element of Transac no. " << ++transac_no_to_edit << ":";
        char return_key;
        std::cin >> return_key;
        if (return_key != 'r' && return_key != 'R') save_n_return = true;
    }
}
void save_transactions(std::vector <transac> v_transactions){
    std::ofstream fout;
        fout.open ("transac_database.txt");
        if(fout.fail()){
            std::cout << "error creating database file" << std::endl;
            std::exit(1);
        }
    
    int rec_count = 0;
    for(std::vector <transac>:: iterator it = v_transactions.begin(); it != v_transactions.end(); it++){
        fout << it->ISBN << " " << it->no_of_books_sold << " " << it->cost_of_each_book;
        rec_count++;
        if (rec_count != v_transactions.size()) fout << "\n";
    }
    fout.close();
}
