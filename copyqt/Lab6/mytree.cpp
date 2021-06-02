#include "mytree.h"

template<class T>
MyTree<T>::MyTree():BinTree<T> ()
{

}

template<class T>
Node<T> *MyTree<T>::findAverage()
{
   Node<T> *end, *prev;
   Node<T> *start = this->shareApex();
   while(start != nullptr)
   {
       end = start;
       start = start->pLeft;
   }
   double aver = end->key;
  start = this->shareApex();
   while(start != nullptr)
   {
       end = start;
       start = start->pRight;
   }
   aver = (aver +end->key)/2 ;

   start = this->shareApex();
   end = start;
   while(start != nullptr)
   {
       prev = start;
       if(aver == prev->key)
       {
           end = start;
           break;
       }
       else if(aver > prev->key)
       {
           start = start->pRight;

           if(end->key< aver && end->key < prev->key)
           {
               end = prev;
           }
           else if(end->key> aver && end->key - aver < aver - prev->key)
           {
               end = prev;
           }
       }
        else if(aver< prev->key)
       {
           start = start->pLeft;
           if(end->key> aver && end->key > prev->key)
           {
               end = prev;
           }
           else if(end->key< aver && aver - end->key  > prev->key - aver)
           {
               end = prev;
           }
       }

   }
   return end;
}
