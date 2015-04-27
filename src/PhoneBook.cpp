//============================================================================
// Name        : PhoneBook.cpp
// Author      : Ezz&Deed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PhoneBook.h"
#include "PhoneEntry.h"

using namespace std;

PhoneBook::PhoneBook() {
	head = NULL;
	tail = NULL;
}

void PhoneBook::add_entry(PhoneEntry *phone_entry){
	phone_entry->next = head;
	head = phone_entry;
}

PhoneEntry* PhoneBook::search_by_name(string name){
	PhoneEntry *temp = head;
	while(temp->next != NULL){
		if(temp->getPhoneNumber()== name)
			return temp;
		temp= temp->next;
	}
	cout << "Not found" << endl;
	return NULL;
}

PhoneEntry* PhoneBook::search_by_number(string number){
	PhoneEntry *temp = head;
	while(temp->next != NULL){
		if(temp->getPhoneNumber()== number)
			return temp;
		temp= temp->next;
	}
	cout << "Not found" << endl;
	return NULL;
}
