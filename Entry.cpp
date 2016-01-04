/* Implements the functions to create an entry with an item and a key
 *
 * @author Michael Barclay
 * @version Homework 6
 * @date 03/26/15
 * @file Entry.cpp
 */
#include "Entry.h"

Entry::Entry(){}

Entry::Entry(KeyType &Key, ItemType &newItem):searchKey(Key),item(newItem)
{
}

Entry::~Entry(){}

ItemType Entry::getItem() const
{
    return item;
}

KeyType Entry::getKey() const
{
    return searchKey;
}

void Entry::setItem(const ItemType& newItem)
{
    item = newItem;
}

void Entry::setKey(const KeyType &Key)
{
    searchKey = Key;
}
