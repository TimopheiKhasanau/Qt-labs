#include "figure.h"
#include <QPainter>



Figure::Figure(int x,int y):QGraphicsObject(0)
{
    xpos=x;
    ypos=y;
}


void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}


void Figure::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
}

float Figure::perimetr()
{

}
float Figure::square()
{

}

QPoint Figure::getCenter()
{
    return QPoint(xpos,ypos);

}




