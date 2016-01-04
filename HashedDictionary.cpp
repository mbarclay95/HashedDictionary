/* Implements the functions that control the hashed dictionary
 * for example the add and remove.
 *
 * @author Michael Barclay
 * @version Homework 6
 * @date 03/26/15
 * @file HashedDictionary.cpp
 */
#include <iostream>
using namespace std;
#include "HashedDictionary.h"

HashedDictionary::HashedDictionary()
{
    for(int i = 0 ; i < DEFAULT_SIZE ; i++) //sets all the entries in the dictionary to NULL
        hashTable[i] = NULL;
    itemCount = 0;
    hashTableSize = 0;
}

HashedDictionary::~HashedDictionary()
{
    clear();
}

int HashedDictionary::hashFunc(KeyType searchKey)
{
    return searchKey%DEFAULT_SIZE;
}

bool HashedDictionary::isEmpty() const
{
    return itemCount == 0;
}

int HashedDictionary::getNumberOfItems() const
{
    return itemCount;
}

bool HashedDictionary::add(const KeyType &Key, const ItemType &newItem)
{
    if(hashTableSize == DEFAULT_SIZE) //If the table is full returns false
        return false;
    int place = hashFunc(Key); //gets the place using the hash function
    HashedEntry *h1 = new HashedEntry(Key, newItem, NULL); //makes a now Hashed entry node
    if(hashTable[place] == NULL) // case if there are no entries at the index given
    {
        hashTable[place] = h1; //stores new item at place
        hashTableSize++;
    }
    else // case if there are already entries at the index give
    {
        HashedEntry *ptr = hashTable[place];
        while(ptr -> getNext() != NULL) //moves ptr until it gets to the last entry
        {
            ptr = ptr -> getNext();
        }
        ptr -> setNext(h1); //adds the new item onto the end
    }
    itemCount++;
    return true;
}

bool HashedDictionary::remove(const KeyType &Key)
{
    int place = hashFunc(Key);
    if(hashTable[place] == NULL) //returns false if there is nothing to remove
        return false;
    else if(hashTable[place] -> getNext() == NULL) //removes the item if it is the only item at that index
    {
        HashedEntry *ptr = hashTable[place];
        delete ptr; //deletes the item
        hashTable[place] = NULL;
    }
    else //case if there are multiple items at one index
    {
        HashedEntry *ptr = hashTable[place];
        if(hashTable[place] -> getKey() == Key) //case if the item you are removing is the first one
        {
            hashTable[place] = ptr -> getNext(); //sets the first item to next
            delete ptr; //deletes the first item
            ptr = NULL;
        }
        else //case if you are removing any other item
        {
            while(ptr -> getNext() -> getKey() != Key)
            {
                ptr = ptr -> getNext();//moves the ptr along until it finds the right key
                if(ptr == NULL) //if it does not find the key it will
                    return false;
            }
            HashedEntry *ptr1 = ptr;//sets a ptr to the entry before the one I want to delete
            ptr = ptr -> getNext();
            ptr1 -> setNext(ptr -> getNext()); //points around the entry I want to delete
            delete ptr; //deletes entry
            ptr = NULL;
        }
    }
    itemCount--;
    return true;
}

void HashedDictionary::clear()
{
    for(int i = 0 ; i < DEFAULT_SIZE ; i++)
    {
        HashedEntry *ptr = hashTable[i];
        if(hashTable[i] != NULL) //checks if there are items that need to be deleted at the index i
        {
            HashedEntry *ptr1 = ptr -> getNext();
            while(ptr1 != NULL) //goes through and deletes all the entries in the linked list at the index i
            {
                delete ptr;
                ptr = ptr1;
                ptr1 = ptr1 -> getNext();
            }
            delete ptr;
            hashTable[i] = NULL; //sets all the indexes that need to be to NULL
        }
    }
    itemCount = 0;
    hashTableSize = 0;
}

ItemType HashedDictionary::getItem(KeyType &Key)
{
    int place = hashFunc(Key);
    HashedEntry *ptr = hashTable[place];
    if(ptr == NULL) //if the index is null there is no item
        return "Item Not Found";
    else if(ptr -> getKey() == Key) //if the first item is the right one it returns it
        return ptr -> getItem();
    else
    {
        while (ptr != NULL) //iterates through the linked list
        {
            if(ptr -> getKey() == Key)//if the keys match it returns that item
                return ptr -> getItem();
            ptr = ptr -> getNext();
        }
        return "Item Not Found"; //if the key does not match with any the item cannot be found
    }
}

bool HashedDictionary::contains(KeyType &Key)
{
    ItemType key = getItem(Key); //uses the getItem function to see if the item is there
    if(key == "Item Not Found") //if the item is not found returns false
        return false;
    return true;
}
