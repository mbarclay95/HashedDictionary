/* Implements the functions that let you create and store
 * an entry with an item, a key and a pointer to the next entry
 *
 * @author Michael Barclay
 * @version Homework 6
 * @date 03/26/15
 * @file HashedEntry.cpp
 */
#include "HashedEntry.h"

HashedEntry::HashedEntry(){}

HashedEntry::HashedEntry(KeyType Key, ItemType newItem)
{
    searchKey = Key;
    item = newItem;
}

HashedEntry::HashedEntry(KeyType Key, ItemType newItem, HashedEntry *nextEntryPtr)
{
    searchKey = Key;
    item = newItem;
    nextPtr = nextEntryPtr;
}

void HashedEntry::setNext(HashedEntry *nextEntryPtr)
{
    delete nextPtr;
    nextPtr = NULL;
    nextPtr = nextEntryPtr;
}

HashedEntry *HashedEntry::getNext() const
{
    return nextPtr;
}

