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


private:
	string forename;
	string surname;
	string email;
	string phone_number;

public:
	PhoneEntry *next;
	PhoneEntry *previous;

	PhoneEntry();
	PhoneEntry(string forename);
	PhoneEntry(string forename, string surname);
	PhoneEntry(string forename, string surname, string email);
	PhoneEntry(string forename, string surname, string email, string phone_number);

	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getForename() const;
	void setForename(const string& forename);
	const string& getPhoneNumber() const;
	void setPhoneNumber(const string& phoneNumber);
	const string& getSurname() const;
	void setSurname(const string& surname);
	string getFullname();
	void print_entry();
	void print(PhoneEntry *head);

	friend class PhoneBook;
	friend class Iterator;
};



#endif /* PHONEENTRY_H_ */
