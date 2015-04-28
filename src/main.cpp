/*
 * main.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: ahmed
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include "PhoneEntry.h"
#include "PhoneBook.h"
#include "Iterator.h"

using namespace std;

void welcome(){
	cout << setfill('-') << setw(25) << "-" << endl;
	cout << "This is My PhoneBook!!" << endl << "-- MENU --" << endl;
	cout << "1. to add new entry." << endl;
	cout << "2. to delete existing entry." << endl;
	cout << "3. to search by name." << endl;
	cout << "4. to search by number." << endl;
	cout << "5. to sort by name." << endl;
	cout << "6. to sort by number." << endl;
	cout << "7. to print all entries." << endl;
	cout << "8. to count your phone entries" << endl;
	cout << "9. to load file form disk" << endl;
	cout << "10. to save PhoneBook" << endl;
	cout << "Choose: ";
}

void add_new_entry(PhoneBook *phone_book){
	string forename;
	string surname;
	string email;
	string phone_number;
	string temp_answer ;
	do{
		cout << "Do you want to create a new phone entry? (y/n) ";
		cin >> temp_answer;
		if (temp_answer == "n"){
			cout << "Back to Menu" << endl;
			return;
		}
        PhoneEntry *phone_entry = new PhoneEntry();
        cout << "Please enter your forename: ";
        cin>>forename;
        cout << "Please enter your surname: ";
        cin>>surname;
        cout << "Please enter your email: ";
        cin>>email;
        cout << "Please enter your phone number: ";
        cin>>phone_number;
        phone_entry->setForename(forename);
        phone_entry->setSurname(surname);
        phone_entry->setEmail(email);
        phone_entry->setPhoneNumber(phone_number);
        phone_book->add_entry(phone_entry);
    	}while (temp_answer=="y");
	}


void search_by_name(PhoneBook *phone_book){
	string temp_answer;
	string name_to_search;
	do {
		cout << "Enter the name you want to search your PhoneBook: ";
		cin >> name_to_search;
		phone_book->search_by_name(name_to_search);
		cout << "Do you want to search for another number ? (y/n) ";
		cin >> temp_answer;
		if (temp_answer == "n"){
			cout << "Back to Menu" << endl;
			cout << setfill('-') << setw(25) << "-" << endl;
			return;
		}
	}while (temp_answer=="y");
}

void search_by_number(PhoneBook *phone_book){
	string temp_answer;
	string number_to_search;
	do {
		cout << "Enter the number you want to search your PhoneBook: ";
		cin >> number_to_search;
		phone_book->search_by_number(number_to_search);
		cout << "Do you want to search for another number ? (y/n) ";
		cin >> temp_answer;
		if (temp_answer == "n"){
			cout << "Back to Menu" << endl;
			cout << setfill('-') << setw(25) << "-" << endl;
			return;
		}
	}while (temp_answer=="y");
}

void delete_entry(PhoneBook *phone_book){
	string temp_answer;
	string name_to_delete;
	do {
		cout << "Enter the name you want to delete from your PhoneBook: ";
		cin >> name_to_delete;
		PhoneEntry *phone_entry_to_delete = phone_book->search_by_name(name_to_delete);
		phone_book->delete_entry(phone_entry_to_delete);
		cout << "Do you want to Delete for another number ? (y/n) ";
		cin >> temp_answer;
		if (temp_answer == "n"){
			cout << "Byebye " << endl;
			cout << setfill('-') << setw(25) << "-" << endl;
			return;
		}
	}while (temp_answer=="y");
}

void save_phonebook(PhoneBook *phone_book){
	phone_book->print_all_entries();
}

void sort_by_name(PhoneBook *phone_book){
	PhoneEntry *phone_entry;
	phone_book->sort_by_name(&phone_entry);
}

int main() {
	int enteredValue;
		PhoneBook *phone_book = new PhoneBook();
		while(true){
			welcome();
			cin >> enteredValue;
			switch(enteredValue){
					case 1:
						add_new_entry(phone_book);
						break;
					case 2:
						delete_entry(phone_book);
						break;
					case 3:
						search_by_name(phone_book);
						break;
					case 4:
						search_by_number(phone_book);
						break;
					case 5:
						sort_by_name(phone_book);
						break;
					case 6:
						break;
					case 7:
						phone_book->print_all();
						break;
					case 8:
						break;
					case 9:
						break;
					case 10:
						save_phonebook(phone_book);
						break;
			}
		}
	return 0;
}
