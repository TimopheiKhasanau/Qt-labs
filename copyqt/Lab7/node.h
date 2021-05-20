#ifndef NODE_H
#define NODE_H

 template<class T>
class Node
{
public:
    Node();
    Node(int key ,T data=T(), Node* pNext = nullptr );
    Node* pNext;
    T data;
    int key;
};

#endif // NODE_H
