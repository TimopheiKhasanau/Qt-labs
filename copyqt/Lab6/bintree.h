#ifndef BINTREE_H
#define BINTREE_H
#include "node.h"
#include "node.cpp"

#include <QList>

template<class T>
class BinTree
{
    friend class Node<T>;
public:
        BinTree();
    void add(int key, T data);
    void delSubTree(Node<T> *promo);
    Node<T> *delSubApex(int key);

    Node<T> *findSubApex(int key);
      Node<T> *specFind(int key);
    Node<T> *shareApex();
    int getSize();
    QList<Node<T> *> preTravList();
    QList<Node<T> *> postTravList();
    QList<Node<T> *> inTravList();
    void Balancing(Node<T> *prev = nullptr, Node<T> *promo = nullptr);
private: 
    int Bal(Node<T> *promo);
    int coeffOfBalance(Node<T> *promo);
    void rightTurn2(Node<T> *prev, Node<T> *promo, int turn);
    void leftTurn2(Node<T> *prev, Node<T> *promo, int turn);
    void rightTurn(Node<T> *prev, Node<T> *promo, int turn);
    void leftTurn(Node<T> *prev, Node<T> *promo, int turn);
    void inorderTraversal(Node<T> *proto);
    void preorderTraversal(Node<T> *proto);
    void postorderTraversal(Node<T> *proto);

 int amount;
 Node<T>  *apex = nullptr;
 QList<Node<T>*> leafs;
};

#endif // BINTREE_H
