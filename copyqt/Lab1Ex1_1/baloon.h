#ifndef BALOON_H
#define BALOON_H
#include "moving_ellpise.h"
#include <QGraphicsLineItem>


class Baloon: public Moving_ellpise
{
public:
    Baloon();
    Baloon(int xpos);

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void deleting();
};


#endif // BALOON_H
