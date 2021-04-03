#ifndef PENTAGON_H
#define PENTAGON_H
#include <QPainter>
#include<QBrush>
#include<QtMath>
#include<QPolygon>
#include "figure.h"


class Pentagon:public Figure
{
    int catA=200;
public:
    Pentagon();
    Pentagon(int x,int y, int a);

    void setAcat(int changeAside);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float perimetr();
    float square();
    QRectF boundingRect() const;
    QPolygon pentagon;

};


#endif // PENTAGON_H
