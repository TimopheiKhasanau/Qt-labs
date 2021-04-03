#ifndef LIST_H
#define LIST_H
#include <node.h>
#include<node.cpp>

template<class T>
class List
{
public:
    List();
    void pushBack(T data);
    void removeAt( int index);
    Node<T>* transportHead();
    void popFront();
    int getSize();
  T *operator[](int index);

private:
    Node<T>* head;
    int size, delcoef = 0;
};

#endif // LIST_H
