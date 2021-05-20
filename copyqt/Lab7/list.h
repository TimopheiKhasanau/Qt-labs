#ifndef LIST_H
#define LIST_H
#include <node.h>
#include<node.cpp>


template<class T>
class List
{
public:
    List();
    void pushBack(int key, T data);
    void removeAt( int index);
    Node<T>* transportHead();
    void popFront();
    void clearList();
    int getSize();
private:
    Node<T>* head = nullptr;
    int size=0;
};

#endif // LIST_H
