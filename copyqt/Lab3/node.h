#ifndef NODE_H
#define NODE_H

 template<class T>
class Node
{
public:
    Node();
    Node(T data=T(), Node* pNext = nullptr );

    Node* pNext;
    T data;
};

#endif // NODE_H
