#include "node.h"
template<class T>
Node<T>::Node()
{

}

template<class T>
Node<T>::Node(int key, T data, Node *pNext)
{
    this->key = key;
    this->pNext = pNext;
    this->data = data;
}
