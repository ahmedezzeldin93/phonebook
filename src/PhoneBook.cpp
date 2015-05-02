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
#include <string>
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
	count=0;
}

/*
PhoneBook::PhoneBook(PhoneEntry *phone_entry) {
	head = phone_entry;
	head->previous = NULL;
	tail = new PhoneEntry;
	Iterator pos;
		pos = this->begin();
		for(; !pos.equals(this->end()); pos.operator ++()){
			tail->next;
		}
}
*/


void PhoneBook::add_entry(PhoneEntry *phone_entry){
	phone_entry->previous =tail->previous;
	phone_entry->next = tail;
	tail->previous-> next = phone_entry;
	tail->previous = phone_entry;
	count++;
}

void PhoneBook::delete_entry(PhoneEntry *phone_entry){
	phone_entry->previous->next = phone_entry->next;
	phone_entry->next->previous = phone_entry->previous;
	delete phone_entry;
	count--;
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
	ofstream outFile("phonebook.txt", ios::out);
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

PhoneEntry* PhoneBook::merge(PhoneEntry *first, PhoneEntry *second)
{
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    // Pick the smaller value
    if (first->getPhoneNumber() < second->getPhoneNumber())
    {
        first->next = merge(first->next,second);
        first->next->previous = first;
        first->previous = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->previous = second;
        second->previous= NULL;
        return second;
    }
}

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

PhoneEntry *PhoneBook::split(PhoneEntry *head)
{
    PhoneEntry *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    PhoneEntry *temp = slow->next;
    slow->next = NULL;
    return temp;
}

PhoneEntry* PhoneBook::MergeSort(PhoneEntry* head)
{
  if (!head || !head->next)
        return head;
    PhoneEntry *second = split(head);

    // Recur for left and right halves
    head = MergeSort(head);
    second = MergeSort(second);

    // Merge the two sorted halves
    return merge(head,second);
}

PhoneEntry* PhoneBook::sort_by_number(PhoneEntry* h){
	return this->MergeSort(h);
}
