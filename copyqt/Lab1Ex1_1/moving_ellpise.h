#ifndef MOVING_ELLPISE_H
#define MOVING_ELLPISE_H
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QColor>
#include<QPainter>


class Moving_ellpise: public QGraphicsEllipseItem
{
public:
    Moving_ellpise(int xpos);
        Moving_ellpise();

    void advance(int phase);
    int w =rand()%100+20;
    int l=rand()%200+20;
    int op=w;


    int speed= rand()%5+1;
};

#endif // MOVING_ELLPISE_H
