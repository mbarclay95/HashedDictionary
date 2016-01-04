/* Main file that shows that all my functions work
 *
 * @author Michael Barclay
 * @version Homework 6
 * @date 03/26/15
 * @file main.cpp
 */
#include <iostream>
#include "Entry.h"
#include "HashedDictionary.h"
#include "HashedEntry.h"
using namespace std;

main()
{
    cout<< "Adds the name Michael to the dictionary: ";
    HashedDictionary h1;
    KeyType key = 1000;
    ItemType name = "Michael";
    h1.add(key,name);
    cout << h1.getItem(key) << endl;
    cout << "Adds another name John to same index: ";
    KeyType key1 = 1101;
    ItemType name1 = "John";
    h1.add(key1,name1);
    cout << h1.getItem(key1) << endl;
    cout << "Removes Michael" << endl;
    h1.remove(key);
    cout << "Shows that Michael is not there: ";
    cout << h1.getItem(key) << endl;
    cout << "Shows that John is still there: ";
    cout << h1.getItem(key1) << endl;
    //tests contains function
    if(h1.contains(key1))
        cout << "John is still there" << endl;
    //tests clear function
    h1.clear();
    cout << "Dictionary cleared" << endl;
    cout << h1.getItem(key1) << endl;
    return 0;
}
