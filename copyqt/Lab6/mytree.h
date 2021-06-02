#ifndef MYTREE_H
#define MYTREE_H
#include "bintree.h"

#include <QList>


template<class T>
class MyTree: public BinTree<T>
{
public:
    MyTree();
    Node<T> *findAverage();
};

#endif // MYTREE_H
