#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include <QPainter>
#include<QBrush>

class Rectangle:public Figure
{

    int aside = 100, bside= 100;
public:
    Rectangle();
    Rectangle(int x, int y, int a, int b);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setAside(int changeAside);
    void setBside(int changeBside);
    float perimetr();
    float square();
    QRectF boundingRect() const;
};

#endif // RECTANGLE_H
