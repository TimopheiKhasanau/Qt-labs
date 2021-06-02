#ifndef NODE_H
#define NODE_H

 template<class T>
class Node
{
public:
    Node();
    Node(T data=T(),  int key =0, Node* pRight = nullptr, Node* pLeft = nullptr );
    Node* pRight;
    Node *pLeft;
    T data;
    int balance = 1;
    int key;

};

#endif // NODE_H
