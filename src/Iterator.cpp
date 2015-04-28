/*
 * Iterator.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: ahmed
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <assert.h>
#include "PhoneEntry.h"
#include "PhoneBook.h"
#include "Iterator.h"

Iterator::Iterator(){
	position = NULL;
	tail = NULL;
}

Iterator::Iterator(PhoneEntry *n){
	position = n;
	tail = NULL;
}

void Iterator::next(){
	assert(position != NULL);
	position = position->next;
}

void Iterator::previous(){
	if(position == NULL){
		position = tail;
	}
	else{
		position = position->previous;
		assert(position != NULL);
	}
}

bool Iterator::equals(Iterator b) const{
	return position == b.position;
}

void Iterator::print(){
	cout << setfill('-') << setw(25) << "-" << endl;
	cout << "Name: " << this->position->getFullname()<< endl;
	cout << "Number :" << this->position->getPhoneNumber() << endl;
	cout << "Email: " << this->position->getEmail()<< endl;
	cout << setfill('-') << setw(25) << "-" << endl;
}

string Iterator::print_entry(){
	string entry_string;
	entry_string = this->position->getFullname() + " - "
					+ this->position->getPhoneNumber() + " - "
					+ this->position->getEmail();
	return entry_string;
}

Iterator& Iterator::operator++(){
	position = position->next;
	return *this;
}
