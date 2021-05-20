#include "hashtable.h"

HashTable::HashTable()
{

}

int HashTable::hashKey(int key)
{
    key = key % 11;
    return key;
}

int HashTable::doubleHashKey(int key, int n)
{
    int proto = hashKey(key);
    key = (key % 7) + 1;
    return hashKey(proto + n*key);
}

void HashTable::add(int key, QString data)
{
    int hashkey = hashKey(key);
    int n =1;
    int number;
    int prevSize =0;
    bool coef = false;
    Node <QString>*proto;


    if(table[hashkey].transportHead() == nullptr)
    {
        table[hashkey].pushBack(key, data);
    }
    else
    {
        while(!coef)
        {
            hashkey = doubleHashKey(key, n);
            if(table[hashkey].transportHead() == nullptr)
            {
                 table[hashkey].pushBack(key, data);
                 coef = true;
            }
            else
            {
                if(prevSize == 0 || prevSize > table[hashkey].getSize())
                {
                     prevSize = table[hashkey].getSize();
                      number = hashkey;
                }
                else
                {
                     table[number].pushBack(key, data);
                     coef = true;
                }
                n++;
            }
        }
    }
}

void HashTable::deleting(int key)
{
    bool run = true, finded = false;
    int n =1;
    int index = 0;
    int hashkey = hashKey(key);
    Node<QString>* proto = table[hashkey].transportHead();
    while(run)
    {
        if(proto == nullptr)
        {
            run = false;
        }
        else if(proto->key == key)
        {
            run = false;
            finded = true;
        }
        else
        {
            proto = proto->pNext;
            index++;
        }
    }
    if( !finded )
    {
        run = true;
        index = 0;
        while(run)
        {
             index = 0;
            hashkey = doubleHashKey(key, n);
            proto = table[hashkey].transportHead();
            for(int i = 0; i < table[hashkey].getSize(); i++)
            {
                if(proto->key == key)
                {
                    run = false;
                }
                else
                {
                      proto = proto->pNext;
                      index++;
                }
            }
            n++;
        }
    }
    if(proto != nullptr)
    {
        index++;
        table[hashkey].removeAt(index);
    }
}

Node<QString> *HashTable::find(int key)
{
    bool run = true, finded = false;
    int n =1;
    int hashkey = hashKey(key);
    Node<QString>* proto = table[hashkey].transportHead();
    while(run)
    {
        if(proto == nullptr)
        {
            run = false;
        }
        else if(proto->key == key)
        {
            run = false;
            finded = true;
        }
        else
        {
            proto = proto->pNext;
        }
    }
    if( !finded )
    {
        run = true;
        while(run)
        {
            hashkey = doubleHashKey(key, n);
            proto = table[hashkey].transportHead();
            for(int i = 0; i < table[hashkey].getSize(); i++)
            {
                if(proto->key == key)
                {
                    run = false;
                }
                else
                {
                      proto = proto->pNext;
                }
            }
            if(n > 5)
            {
                run = false;
                proto = nullptr;
            }
            n++;
        }
    }
    return proto;
}
