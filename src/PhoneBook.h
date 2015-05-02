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

public:
	PhoneEntry *head;
	PhoneEntry *tail;
	int count;


	PhoneBook();
	PhoneBook(PhoneEntry *phone_entry);
	void print_all();
	void print_all(PhoneEntry *phone_entry);
	void print_all_entries();
	void add_entry(PhoneEntry *phone_entry);
	void delete_entry(PhoneEntry *phone_entry);
	PhoneEntry* search_by_name(string name);
	PhoneEntry* search_by_number(string number);

	PhoneEntry* merge(PhoneEntry *first, PhoneEntry *second);
	void swap(int *A, int *B);
	PhoneEntry* split(PhoneEntry *head);
	PhoneEntry* MergeSort(PhoneEntry* head);


	PhoneEntry* sort_by_name(PhoneEntry* h);
	PhoneEntry* sort_by_number(PhoneEntry* h);


	Iterator begin();
	Iterator end();
	const PhoneEntry*& getHead() const;
	void setHead(const PhoneEntry*& head);
	const PhoneEntry*& getTail() const;
	void setTail(const PhoneEntry*& tail);
};




#endif /* PHONEBOOK_H_ */
