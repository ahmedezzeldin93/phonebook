/*
 * main.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: ahmed
 */
#include<iostream>
#include "PhoneEntry.h"
#include "PhoneBook.h"

using namespace std;

void welcome(){
	cout << "Hello This is My PhoneBook!!" << endl << "-- MENU --" << endl;
	cout << "1. to add new entry." << endl;
	cout << "2. to delete existing entry." << endl;
	cout << "3. to search by name." << endl;
	cout << "4. to search by number." << endl;
	cout << "5. to sort by name." << endl;
	cout << "6. to sort by number." << endl;
	cout << "Choose: ";
}

void add_new_entry(){
	string forename;
	string surname;
	string email;
	string phone_number;
	PhoneBook *phone_book = new PhoneBook();
	string temp_answer ;
	do{
		cout << "Do you want to create a new phone entry? (y/n) " << endl;
		cin >> temp_answer;
		if (temp_answer == "n"){
			cout << "Byebye " << endl;
			return;
		}
        PhoneEntry *phone_entry = new PhoneEntry();
        cout << "Please enter your forename: " << endl;
        cin>>forename;
        cout << "Please enter your surname: " << endl;
        cin>>surname;
        cout << "Please enter your email: " << endl;
        cin>>email;
        cout << "Please enter your phone number: " << endl;
        cin>>phone_number;
        phone_entry->setForename(forename);
        phone_entry->setSurname(surname);
        phone_entry->setEmail(email);
        phone_entry->setPhoneNumber(phone_number);
        phone_book->add_entry(phone_entry);
    	}while (temp_answer=="y");
	}


int main() {
	int enteredValue;
		welcome();
		cin >> enteredValue;
		switch(enteredValue){
				case 1:
					add_new_entry();
					break;
				case 2:
				break;
				case 3:
				break;
				case 4:
				break;
				case 5:
				break;
				case 6:
				break;
			}
	return 0;
}
