#include "pentagon.h"


Pentagon::Pentagon(int x, int y, int a):Figure(x,y)
{
    catA=a;
}

void Pentagon::setAcat(int changeAside)
{
    catA=changeAside;
}

void Pentagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pentagon<<(QPoint(-catA/2,0))<<QPoint(+catA/2,0)
    <<QPoint((catA/2)+(qCos(1.25664)*catA),qSin(1.25664)*catA)
    <<QPoint(0,1.538842*catA)<<QPoint(-((catA/2)+(qCos(1.25664)*catA)),qSin(1.25664)*catA);
    painter->drawPolygon(pentagon);
}

float Pentagon::perimetr()
{
    return (5*catA);
}

float Pentagon::square()
{
    return (5*qPow(catA,2)/(4*qSqrt(5-2*qSqrt(5))));
}

QRectF Pentagon::boundingRect() const
{
    return QRectF(xpos-catA/2,ypos,3*catA,3*catA);
}
