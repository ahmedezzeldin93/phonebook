/*
 * PhoneBook.h
 *
 *  Created on: Apr 27, 2015
 *      Author: ahmed
 */

using namespace std;

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "PhoneEntry.h"
#include "Iterator.h"

class PhoneBook{


private:
	PhoneEntry *head;
	PhoneEntry *tail;

public:

	PhoneBook();
	void print_all();
	void print_all_entries();
	void add_entry(PhoneEntry *phone_entry);
	void delete_entry(PhoneEntry *phone_entry);
	PhoneEntry* search_by_name(string name);
	PhoneEntry* search_by_number(string number);
	void sort_by_name();
	void sort_by_number();

	Iterator begin();
	Iterator end();
};




#endif /* PHONEBOOK_H_ */
