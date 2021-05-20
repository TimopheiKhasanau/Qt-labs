#include "list.h"

template<class T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

template<class T>
void List<T>::pushBack(int key,T data)
{
    if(head == nullptr)
    {
        head = new Node<T>(key, data);
    }
    else
    {
        Node<T>* elem = this->head;

        while(elem->pNext != nullptr)
        {
            elem = elem->pNext;
        }
        elem->pNext = new Node<T>(key, data);
    }
    size++;
}

template<class T>
void List<T>::removeAt(int index)
{
    index=index - 1;
    if( index == 0 )
    {
        popFront();
    }
    else
    {
        Node<T>* prev = this->head;
        for(int i =0; i < index-1; i++ )
        {
            if(prev->pNext == nullptr)
            {
                break;
            }
            prev = prev->pNext;
        }
        Node<T>* del = prev->pNext;

        if(index != 0 && prev->pNext!= nullptr)
        {
             prev->pNext = del->pNext;
        }
        delete del;
        size=size - 1;
        if(size ==0)
        {
            head = nullptr;
        }
    }
}

template<class T>
Node<T> *List<T>::transportHead()
{
    return head;
}

template<class T>
void List<T>::popFront()
{
    Node<T>* proto = head;
    head = head->pNext;
    delete proto;
    size--;
}

template<class T>
void List<T>::clearList()
{
    while(size)
    {
        popFront();
    }
}


template<class T>
int List<T>::getSize()
{
    return size;
}


//template<class T>
// T *List<T>::operator[](const int index)
// {
//     int counter = 0;
//     Node<T>* proto =this->head;

//     while(proto != nullptr)
//     {
//         if(counter == index)
//         {
//             return proto->data;
//         }
//         proto = proto->pNext;
//         counter++;
//     }
// }

