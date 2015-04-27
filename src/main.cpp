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

int main() {
	int enteredValue;
		welcome();
		cin >> enteredValue;
		switch(enteredValue){
				case 1:
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
