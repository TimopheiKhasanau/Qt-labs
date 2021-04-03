#include "triangle.h"



Triangle::Triangle(int x, int y, int a):Figure(x,y)
{
    catA=a;

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//   x3=qCos(angle)*catB;
//   y3=qSin(angle)*catB;
//    triangle<<(QPoint(-catA,0))<<QPoint(-x3,y3)<<QPoint(catA,0);
   //triangle<<(QPoint(0,0))<<QPoint(20,50)<<QPoint(-40,90);
   // painter->setBrush(Qt::black);
    triangle<<(QPoint(-catA/2,0))<<QPoint(+catA/2,0)<<QPoint(0,catA*qSqrt(3)/2);

     painter->setPen(20);
    painter->drawPolygon(triangle);
}

void Triangle::setAcat(int changeAside)
{
   catA=changeAside;
}



float Triangle::perimetr()
{
    return (catA*3);
}

float Triangle::square()
{
    return(qPow(catA,2)*qSqrt(3)/4);
}

QRectF Triangle::boundingRect() const
{
    return QRectF(xpos, ypos, 4*catA,4*catA);
}



