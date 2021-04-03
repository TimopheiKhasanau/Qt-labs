#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include <QPainter>
#include<QBrush>
#include<QtMath>
#include<QPolygon>


class Triangle:public Figure
{
    int catA=200;

public:
    Triangle();
    Triangle(int x,int y, int a);

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
     void setAcat(int changeAside);
     float perimetr();
     float square();

     QRectF boundingRect() const;
     QPolygon triangle;

};

#endif // TRIANGLE_H
