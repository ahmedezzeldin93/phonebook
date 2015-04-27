/*
 * PhoneEntry.h
 *
 *  Created on: Apr 27, 2015
 *      Author: ahmed
 */
#include <iostream>

using namespace std;

#ifndef PHONEENTRY_H_
#define PHONEENTRY_H_

class PhoneEntry{

public:

	string forename;
	string surname;
	string email;
	string phone_number;

	PhoneEntry *next;
	PhoneEntry *previous;

	PhoneEntry();
	PhoneEntry(string forename);
	PhoneEntry(string forename, string surname);
	PhoneEntry(string forename, string surname, string email);
	PhoneEntry(string forename, string surname, string email, string phone_number);

	friend class PhoneBook;
};



#endif /* PHONEENTRY_H_ */
