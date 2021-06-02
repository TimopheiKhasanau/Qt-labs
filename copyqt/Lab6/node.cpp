#include "node.h"

template<class T>
Node<T>::Node()
{

}

template<class T>
Node<T>::Node(T data,  int key, Node *pRight, Node* pLeft)
{
    this->pRight = pRight;
    this->data = data;
    this->pLeft = pLeft;
    this->key = key;
}
