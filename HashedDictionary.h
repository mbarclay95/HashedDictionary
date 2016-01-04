/* The class file for all the functions that control the
 * hashed dictionary
 *
 * @author Michael Barclay
 * @version Homework 6
 * @date 03/26/15
 * @file HashedDictionary.h
 */
#include "HashedEntry.h"
#ifndef HASHEDDICTIONARY_H
#define HASHEDDICTIONARY_H

class HashedDictionary
{
private:
    HashedEntry *hashTable[101]; //the hash table where all the items are stored
    int itemCount; //number of items in the dictionary
    int hashTableSize; //number indexes being used in the dictionary
    static const int DEFAULT_SIZE = 101; //the size of the dictionary
    int hashFunc(KeyType searchKey); //the hash function

public:
    HashedDictionary(); //constructor
    ~HashedDictionary(); //destructor
    bool isEmpty() const; //checks if dictionary is empty
    int getNumberOfItems() const; //returns number of items in dictionary
    bool add(const KeyType & Key, const ItemType & newItem); //adds an item with a key to the dictionary
    bool remove(const KeyType & Key); //removes the item with that specific
    void clear(); //clears the whole dictionary
    ItemType getItem(KeyType & Key); //gets the item linked with the specific key
    bool contains(KeyType & Key); // returns true if the item with the specific key is in the dictionary
};

#endif
