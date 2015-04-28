//============================================================================
// Name        : PhoneBook.cpp
// Author      : Ezz&Deed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "PhoneBook.h"
#include "PhoneEntry.h"
#include "Iterator.h"

using namespace std;

PhoneBook::PhoneBook() {
	head = new PhoneEntry;
	tail = new PhoneEntry;
	head->next = tail;
	tail->previous = head;
	head->previous = NULL;
}

void PhoneBook::add_entry(PhoneEntry *phone_entry){
	phone_entry->previous =tail->previous;
	phone_entry->next = tail;
	tail->previous-> next = phone_entry;
	tail->previous = phone_entry;
}

void PhoneBook::delete_entry(PhoneEntry *phone_entry){
	phone_entry->previous->next = phone_entry->next;
	phone_entry->next->previous = phone_entry->previous;
	delete phone_entry;
}

Iterator PhoneBook::begin(){
	Iterator iter;
	iter.position = head->next;
	iter.tail = tail;
	return iter;
}

Iterator PhoneBook::end(){
	Iterator iter;
	iter.position = tail;
	iter.tail = tail;
	return iter;
}

void PhoneBook::print_all(){
	Iterator pos;
	pos = this->begin();
	for(; !pos.equals(this->end()); pos.operator ++()){
		pos.print();
	}
}

void PhoneBook::print_all_entries(){
	ofstream outFile("/home/ahmed/phonebook.txt", ios::out);
	Iterator pos;
	pos = this->begin();
	for(; !pos.equals(this->end()); pos.operator ++()){
		outFile << pos.print_entry() << endl;
	}
	outFile.close();
}

PhoneEntry* PhoneBook::search_by_name(string name){
	PhoneEntry *temp = head;
	while(temp->next != NULL){
		if(temp->getForename()== name){
			temp->print_entry();
			return temp;
		}
		temp= temp->next;
	}
	cout << "Not found" << endl;
	return NULL;
}

PhoneEntry* PhoneBook::search_by_number(string number){
	PhoneEntry *temp = head;
	while(temp->next != NULL){
		if(temp->getPhoneNumber()== number){
			temp->print_entry();
			return temp;
		}
		temp= temp->next;
	}
	cout << "Not found" << endl;
	return NULL;
}
