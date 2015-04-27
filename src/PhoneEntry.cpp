/*
 * PhoneEntry.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: ahmed
 */

#include <iostream>
#include "PhoneEntry.h"

using namespace std;

PhoneEntry::PhoneEntry(){
	this->forename = "No Name";
	this->surname = "No Name";
	this->email = "No email";
	this->phone_number = "No Number";
	next = NULL;
	previous = NULL;
}

PhoneEntry::PhoneEntry(string forename){
	this->forename = forename;
	this->surname = "No Name";
	this->email = "No Name";
	this->phone_number = "No Name";
	next = NULL;
	previous = NULL;
}

PhoneEntry::PhoneEntry(string forename, string surname){
	this->forename = forename;
	this->surname = surname;
	this->email = "No Name";
	this->phone_number = "No Name";
	next = NULL;
	previous = NULL;
}

PhoneEntry::PhoneEntry(string forename, string surname, string email){
	this->forename = forename;
	this->surname = surname;
	this->email = email;
	this->phone_number = "No Name";
	next = NULL;
	previous = NULL;
}

PhoneEntry::PhoneEntry(string forename, string surname, string email, string phone_number){
	this->forename = forename;
	this->surname = surname;
	this->email = email;
	this->phone_number = phone_number;
	next = NULL;
	previous = NULL;
}

const string& PhoneEntry::getEmail() const {
	return email;
}

void PhoneEntry::setEmail(const string& email) {
	this->email = email;
}

const string& PhoneEntry::getForename() const {
	return forename;
}

void PhoneEntry::setForename(const string& forename) {
	this->forename = forename;
}

const string& PhoneEntry::getPhoneNumber() const {
	return phone_number;
}

void PhoneEntry::setPhoneNumber(const string& phoneNumber) {
	phone_number = phoneNumber;
}

const string& PhoneEntry::getSurname() const {
	return surname;
}

void PhoneEntry::setSurname(const string& surname) {
	this->surname = surname;
}
