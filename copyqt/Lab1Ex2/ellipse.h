#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QPainter>
#include<QBrush>

#include "figure.h"


class Ellipse:public Figure
{
    int adiam = 100, bdiam= 100;
    const float Pi=3.14;
public:
    Ellipse();
    Ellipse(int x, int y, int rA, int rB);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setAdiam(int changeAside);
    void setBdiam(int changeBside);
    float perimetr();
    float square();

    QRectF boundingRect() const;
};

#endif // ELLIPSE_H
