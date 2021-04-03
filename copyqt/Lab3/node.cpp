#include "node.h"
template<class T>
Node<T>::Node()
{

}

template<class T>
Node<T>::Node(T data, Node *pNext)
{
        this->pNext = pNext;
        this->data = data;
}
