#include "baloon.h"

Baloon::Baloon(int xpos):Moving_ellpise(xpos)
{
    QColor color = QColor(rand()%255,rand()%255,rand()%255);
    setBrush(color);
    QGraphicsLineItem *line= new QGraphicsLineItem(w/2, l, w/2, 2*l);
        line->setParentItem(this);




}
void Baloon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    delete this;
}

void Baloon::deleting()
{

    delete this;
}






