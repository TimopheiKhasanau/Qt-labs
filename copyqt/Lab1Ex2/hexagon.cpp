#include "hexagon.h"


Hexagon::Hexagon(int x, int y, int a):Figure(x,y)
{
    catA=a;
}

void Hexagon::setAcat(int changeAside)
{
    catA=changeAside;
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    hexagon<<(QPoint(0,-catA))<<QPoint(qCos(0.523599)*catA,-catA/2)<<QPoint(qCos(0.523599)*catA,catA/2)
    <<QPoint(0,catA)<<QPoint(-qCos(0.523599)*catA,catA/2)<<QPoint(-qCos(0.523599)*catA,-catA/2);
    painter->drawPolygon(hexagon);
}

float Hexagon::perimetr()
{
    return (6*catA);
}

float Hexagon::square()
{
    return(3*qPow(catA,2)*qSqrt(3)/2);

}

QRectF Hexagon::boundingRect() const
{
    return QRectF(xpos-catA/2,ypos-catA/2,3*catA,3*catA);
}
