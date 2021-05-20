#include "myhashtable.h"

MyHashTable::MyHashTable():HashTable(){}

MyHashTable *MyHashTable::lessThanKey(int key)
{
    MyHashTable *less = new MyHashTable();
    Node<QString>* proto;
    for(int i = 0; i < 11; i++)
    {
        proto = this->table[i].transportHead();
        if(proto != nullptr)
        {
            for(int j = 0; j < table[i].getSize(); j++)
            {
                if(proto->key < key)
                {
                    less->add(proto->key, proto->data);
                }
                proto = proto->pNext;
            }
        }
    }
    return less;
}

MyHashTable *MyHashTable::moreThanKey(int key)
{
    MyHashTable *more = new MyHashTable();
    Node<QString>* proto;
    for(int i = 0; i < 11; i++)
    {
        proto = this->table[i].transportHead();
        if(proto != nullptr)
        {
            for(int j = 0; j < table[i].getSize(); j++)
            {
                if(proto->key > key)
                {
                    more->add(proto->key, proto->data);
                }
                proto = proto->pNext;
            }
        }
    }
    return more;
}
