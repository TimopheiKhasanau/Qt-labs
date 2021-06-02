#include "bintree.h"

template<class T>
BinTree<T>::BinTree()
{
    apex = nullptr;
    amount = 0;
}

template<class T>
void BinTree<T>::add(int key ,T data)
{
    if(apex == nullptr)
    {
        apex = new Node<T>(data, key);
    }
    else
    {
        Node<T> *proto = apex;
         Node<T> *octa = proto;
        int crit =0;
        while(proto != nullptr)
        {
            if(proto->key < key)
            {
                octa = proto;
                proto = proto->pRight;
                crit =1;
            }
            else if(proto->key > key)
            {
                octa = proto;
                proto = proto->pLeft;
                crit =2;
            }
            else
            {
                return;
            }
        }
        proto = new Node<T>(data, key);
        switch (crit)
        {
        case 1:
            octa->pRight = proto;
            break;
        case 2:
             octa->pLeft = proto;
            break;
        }
    }
    amount++;
}

template<class T>
void BinTree<T>::delSubTree(Node<T> *promo)
{

    if (promo!= nullptr)
    {
        Node<T> *prev = specFind(promo->key);
        delSubTree(promo->pRight);
        delSubTree(promo->pLeft);
        promo = delSubApex(promo->key);


    }
}

template<class T>
 Node<T> * BinTree<T>::delSubApex(int key)
{
    int saveKey = 0;
    T param;
    Node<T> *prev = specFind(key);
    Node<T> *proto = findSubApex(key);
    if(proto == nullptr)
    {
        return proto;
    }

    if(proto->pLeft == nullptr && proto->pRight == nullptr)
    {
        if(prev!= nullptr)
        {
            if(prev->key > proto->key)
            {
                prev->pLeft = nullptr;
            }
            else
            {
                prev->pRight = nullptr;
            }
        }
        delete proto;
        proto = nullptr;
        if(prev == nullptr)
        {
            apex = proto;
        }
    }
    else if(proto->pLeft == nullptr)
    {
        if(prev == nullptr)
        {
            apex = proto->pRight;
        }
        else
        {
            if(prev->key > proto->key)
            {
                prev->pLeft = proto->pRight;
            }
            else
            {
                prev->pRight = proto->pRight;
            }
        }
        delete proto;
        proto = nullptr;
    }
    else if(proto->pRight == nullptr)
    {
        if(prev == nullptr)
        {
            apex = proto->pRight;
        }
        else
        {
            if(prev->key > proto->key)
            {
                prev->pLeft = proto->pLeft;
            }
            else
            {
                prev->pRight = proto->pLeft;
            }
        }
        delete proto;
        proto = nullptr;
    }
    else
    {
         Node<T> *octa = proto->pRight;
         saveKey = octa->key;
          param  = octa->data;
         while(octa->pLeft != nullptr )
         {
             octa = octa->pLeft;
             saveKey = octa->key;
              param  = octa->data;
         }
         octa = delSubApex(saveKey);
         proto->key = saveKey;
         proto->data = param;

         if(prev == nullptr)
         {
             apex = proto;
         }
    }
    return proto;
}

template<class T>
void BinTree<T>::preorderTraversal(Node<T> *proto)
{
    if(proto != nullptr)
    {
        leafs.push_back(proto);
        preorderTraversal(proto->pLeft);
        preorderTraversal(proto->pRight);
    }
}

template<class T>
void BinTree<T>::postorderTraversal(Node<T> *proto)
{
    if(proto != nullptr)
    {
       postorderTraversal(proto->pLeft);
       postorderTraversal(proto->pRight);
        leafs.push_back(proto);
    }
}

template<class T>
Node<T> *BinTree<T>::findSubApex(int key)
{
    Node<T> *proto = apex;
    while(proto != nullptr && proto->key != key)
    {
        if(proto->key <key)
        {
            proto = proto->pRight;
        }
        else if(proto->key > key)
        {
            proto = proto->pLeft;
        }
    }
    return proto;
}

template<class T>
Node<T> *BinTree<T>::specFind(int key)
{
    Node<T> *proto = apex, *prev = nullptr;
    while(proto != nullptr && proto->key != key)
    {
        prev = proto;
        if(proto->key <key)
        {
            proto = proto->pRight;
        }
        else if(proto->key > key)
        {
            proto = proto->pLeft;
        }
    }
    return prev;
}



template<class T>
Node<T> *BinTree<T>::shareApex()
{
    return apex;
}

template<class T>
int BinTree<T>::getSize()
{
    return amount;
}

template<class T>
QList<Node<T> *> BinTree<T>::preTravList()
{
    leafs.clear();
    preorderTraversal(apex);
    return leafs;
}

template<class T>
QList<Node<T> *> BinTree<T>::postTravList()
{
    leafs.clear();
    postorderTraversal(apex);
    return leafs;
}

template<class T>
QList<Node<T> *> BinTree<T>::inTravList()
{
    leafs.clear();
    inorderTraversal(apex);
    return leafs;
}

template<class T>
void BinTree<T>::Balancing(Node<T> *prev, Node<T> *promo)
{
    coeffOfBalance( apex);
    int turn = 0;
    if(prev != nullptr && prev->pRight == promo)
    {
        turn =2;
    }
    else if( prev != nullptr && prev->pLeft == promo)
    {
        turn =1;
    }
    if(!Bal(promo))
    {
        if(promo->pLeft == nullptr && ((promo->pRight)->pRight != nullptr || (promo->pRight)->pLeft != nullptr))
        {
            Balancing(promo, promo->pRight);
            Node<T> *right = promo->pRight;
            if(!Bal(promo))
            {
                if( (promo->pRight)->pLeft != nullptr &&
                        (((promo->pRight)->pLeft)->pLeft != nullptr || ((promo->pRight)->pLeft)->pRight != nullptr))
                {
                    leftTurn2(prev, promo, turn);
                }
                else
                {
                  leftTurn(prev, promo, turn);
                }
                coeffOfBalance( apex);
                Balancing(prev, right);
            }
        }
        else if (promo->pRight == nullptr && ((promo->pLeft)->pRight != nullptr || (promo->pLeft)->pLeft != nullptr))
        {
            Balancing(promo, promo->pLeft);
            Node<T> *left = promo->pLeft;
            if(!Bal(promo))
            {
                if((promo->pLeft)->pRight != nullptr &&
                        (((promo->pLeft)->pRight)->pLeft != nullptr || ((promo->pLeft)->pRight)->pRight != nullptr) )
                {
                    rightTurn2(prev, promo, turn);
                }
                else
                {
                  rightTurn(prev, promo, turn);
                }
                coeffOfBalance( apex);
                Balancing(prev, left);
            }
        }
        else if(promo->pLeft != nullptr && promo->pRight !=nullptr)
        {
            if((promo->pLeft)->balance - (promo->pRight)->balance >1)
            {
                Balancing(promo, promo->pLeft);
                Node<T> *left = promo->pLeft;
                if(!Bal(promo))
                {
                    if((promo->pLeft)->pRight != nullptr &&
                            (((promo->pLeft)->pRight)->pLeft != nullptr || ((promo->pLeft)->pRight)->pRight != nullptr))
                    {
                        rightTurn2(prev, promo, turn);
                    }
                    else
                    {
                      rightTurn(prev, promo, turn);
                    }
                    coeffOfBalance( apex);
                    Balancing(prev, left);
                }
            }
            else if((promo->pRight)->balance - (promo->pLeft)->balance >1)
            {
                Balancing(promo, promo->pRight);
                Node<T> *right = promo->pRight;
                if(!Bal(promo))
                {
                    if( (promo->pRight)->pLeft != nullptr &&
                            (((promo->pRight)->pLeft)->pLeft != nullptr || ((promo->pRight)->pLeft)->pRight != nullptr))
                    {

                        leftTurn2(prev, promo, turn);
                    }
                    else
                    {
                      leftTurn(prev, promo, turn);
                    }
                    coeffOfBalance( apex);
                    Balancing(prev, right);
                }
            }
            else
            {
                 Balancing(promo, promo->pRight);
                Balancing(promo, promo->pLeft);
            }
        }
    }
}

template<class T>
int BinTree<T>::Bal(Node<T> *promo)
{
    if(promo->pRight == nullptr && promo->pLeft == nullptr)
    {
        return 1;
    }
    else if(promo->pLeft == nullptr && (promo->pRight)->pRight == nullptr && (promo->pRight)->pLeft == nullptr)
    {
        return 1;
    }
    else if(promo->pRight == nullptr && (promo->pLeft)->pRight == nullptr && (promo->pLeft)->pLeft == nullptr)
    {
        return 1;
    }
    else if(promo->pLeft != nullptr && promo->pRight != nullptr &&
            (abs((promo->pLeft)->balance - (promo->pRight)->balance) ==1 || (promo->pRight)->balance - (promo->pLeft)->balance == 0)
            && Bal(promo->pRight) == 1 && Bal(promo->pLeft) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template<class T>
int BinTree<T>::coeffOfBalance(Node<T> *promo)
{
    int left = 0, right = 0;
    if(promo != nullptr)
    {
        if(promo->pLeft != nullptr)
        {
            (promo->pLeft)->balance = coeffOfBalance(promo->pLeft);
            left = (promo->pLeft)->balance;
        }
        if(promo->pRight != nullptr)
        {
            (promo->pRight)->balance =  coeffOfBalance(promo->pRight);
            right = (promo->pRight)->balance;
        }

        if(left >= right)
        {
            promo->balance = 1 +  left;
            return promo->balance;
        }
        else
        {
            promo->balance = 1 +  right;
            return promo->balance;
        }
    }
    else
    {
        return 0;
    }
}

template<class T>
void BinTree<T>::leftTurn2(Node<T> *prev, Node<T> *promo, int turn)
{
    if(promo == nullptr || promo->pRight == nullptr || (promo->pRight)-> pLeft == nullptr )
    {
        return;
    }
    else
    {
        Node<T> *right = promo->pRight;
        Node<T> *left;
        while(right != nullptr)
        {
            left = right;
            right = right->pLeft;
        }
        left->pLeft = promo;
        if(turn == 1 && prev != nullptr)
        {
            prev->pLeft = promo->pRight;
        }
        else if(turn == 2 && prev != nullptr)
        {
            prev->pRight =promo->pRight;
        }
        else
        {
            apex = promo->pRight;
        }
        promo->pRight = nullptr;
    }
}

template<class T>
void BinTree<T>::rightTurn2(Node<T> *prev, Node<T> *promo, int turn)
{
    if(promo == nullptr || promo->pLeft == nullptr || (promo->pLeft)->pRight == nullptr)
    {
        return;
    }
    else
    {
        Node<T> *left = promo->pLeft;
        Node<T> *right;
        while(left != nullptr)
        {
            right = left;
            left = left->pRight;
        }
        right->pRight = promo;

        if(turn == 1 && prev != nullptr)
        {
            prev->pLeft = promo->pLeft;
        }
        else if(turn == 2 && prev != nullptr)
        {
            prev->pRight = promo->pLeft;
        }
        else
        {
            apex = promo->pLeft;
        }
        promo->pLeft = nullptr;
    }
}

template<class T>
void BinTree<T>::rightTurn(Node<T> *prev, Node<T> *promo, int turn)
{
    if(promo == nullptr || promo->pLeft == nullptr )
    {
        return;
    }
    else
    {
        Node<T> *left = promo->pLeft;
        Node<T> *leftright = left->pRight;
        promo->pLeft = leftright;
        left->pRight = promo;

        if(turn == 1 && prev != nullptr)
        {
            prev->pLeft = left;
        }
        else if(turn == 2 && prev != nullptr)
        {
            prev->pRight = left;
        }
        else
        {
            apex = left;
        }
    }
}

template<class T>
void BinTree<T>::leftTurn(Node<T> *prev, Node<T> *promo, int turn)
{
    if(promo == nullptr || promo->pRight == nullptr )
    {
        return;
    }
    else
    {
        Node<T> *right = promo->pRight;
        Node<T> *rightleft = right->pLeft;
        promo->pRight = rightleft;
        right->pLeft = promo;
        if(turn == 1 && prev != nullptr)
        {
            prev->pLeft = right;
        }
        else if(turn == 2 && prev != nullptr)
        {
            prev->pRight = right;
        }
        else
        {
            apex = right;
        }
    }
}

template<class T>
void BinTree<T>::inorderTraversal(Node<T> *proto)
{
    if(proto != nullptr)
    {
        inorderTraversal(proto->pLeft);
        leafs.push_back(proto);
        inorderTraversal(proto->pRight);
    }

}
