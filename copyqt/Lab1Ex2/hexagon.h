#ifndef HEXAGON_H
#define HEXAGON_H

#include <QPainter>
#include<QBrush>
#include<QtMath>
#include<QPolygon>

#include "figure.h"



class Hexagon:public Figure
{
    int catA=200;
public:
    Hexagon();
    Hexagon(int x,int y, int a);

    void setAcat(int changeAside);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float perimetr();
    float square();

    QRectF boundingRect() const;
    QPolygon hexagon;
};

#endif // HEXAGON_H
