#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "hashtable.h"

class MyHashTable: public HashTable
{
public:
    MyHashTable();
    MyHashTable *lessThanKey(int key);
    MyHashTable *moreThanKey(int key);
};

#endif // MYHASHTABLE_H
