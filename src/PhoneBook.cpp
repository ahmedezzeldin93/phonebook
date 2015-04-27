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
