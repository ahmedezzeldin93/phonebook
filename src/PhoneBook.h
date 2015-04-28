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

	PhoneBook();
	void print_all();
	void print_all_entries();
	void add_entry(PhoneEntry *phone_entry);
	void delete_entry(PhoneEntry *phone_entry);
	PhoneEntry* search_by_name(string name);
	PhoneEntry* search_by_number(string number);

	PhoneEntry* SortedMerge(PhoneEntry* a, PhoneEntry* b);
	void FrontBackSplit(PhoneEntry* source, PhoneEntry** frontRef, PhoneEntry** backRef);
	void MergeSort(PhoneEntry** headRef);

	void sort_by_name(PhoneEntry** h);
	void sort_by_number();


	Iterator begin();
	Iterator end();
	const PhoneEntry*& getHead() const;
	void setHead(const PhoneEntry*& head);
	const PhoneEntry*& getTail() const;
	void setTail(const PhoneEntry*& tail);
};




#endif /* PHONEBOOK_H_ */
