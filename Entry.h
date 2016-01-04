/* The class file that has the functions for creating an entry
 *
 * @author Michael Barclay
 * @version Homework 6
 * @date 03/26/15
 * @file Entry.h
 */
#include <string>
#ifndef ENTRY_H
#define ENTRY_H

typedef int KeyType; //changes KeyType to int
typedef std::string ItemType; //changes ItemType to string

class Entry
{
protected:
    ItemType item; //stores the item
    KeyType searchKey; //stores the key
    void setKey (const KeyType &Key); //sets key

public:
    Entry(); //constructor
    Entry(KeyType &Key, ItemType &newItem); //constructor with parameters key and item
    ~Entry(); //destructor
    ItemType getItem() const; //returns item
    KeyType getKey() const; //returns key
    void setItem(const ItemType &newItem); //sets Item
};

#endif
