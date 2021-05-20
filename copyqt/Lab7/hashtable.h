#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "list.h"
#include "list.cpp"
#include "QString"

class HashTable
{
public:
    HashTable();
    int hashKey(int key);
    int doubleHashKey(int key, int n);
    void add(int key, QString data);
    void deleting(int key);
    Node<QString> *find(int key);

    List<QString> table[11];
};

#endif // HASHTABLE_H
