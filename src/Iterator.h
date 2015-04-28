/*
 * Iterator.h
 *
 *  Created on: Apr 28, 2015
 *      Author: ahmed
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "PhoneEntry.h"
#include "PhoneBook.h"

class Iterator
{
private:
   PhoneEntry* position;
   PhoneEntry* tail;

public:
   Iterator();
   Iterator(PhoneEntry *n);
   void next();
   void previous();
   void print();
   string print_entry();

   bool equals(Iterator b) const;
   Iterator& operator++();

   friend class PhoneBook;
};





#endif /* ITERATOR_H_ */
