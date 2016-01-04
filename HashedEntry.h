/* The class file for the functions that create a hashed
 * entry.
 *
 * @author Michael Barclay
 * @version Homework 6
 * @date 03/26/15
 * @file HashedEntry.h
 */
#include "Entry.h"
#ifndef HASHEDENTRY_H
#define HASHEDENTRY_H

class HashedEntry: public Entry //child class of entry
{
public:
    HashedEntry(); //constructor
    HashedEntry(KeyType Key, ItemType newItem); //constructor with parameters key and item
    HashedEntry(KeyType Key, ItemType newItem, HashedEntry *nextEntryPtr); //constructor with parameters key and item
    void setNext(HashedEntry *nextEntryPtr); //sets where the nextptr is pointing to
    HashedEntry *getNext() const; //returns where nextptr is pointing to
private:
    HashedEntry *nextPtr; // points to the next hashed entry
};

#endif
