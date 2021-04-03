#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsObject>
#include <QKeyEvent>
#include <QPainter>
#include<QGraphicsSceneMouseEvent>



class Figure:public QGraphicsObject
{
public:
    Figure();
    Figure(int x, int y);
 int xpos=500,ypos=500;
 int area=0;
 int perim=0;

 QPoint getCenter();
 virtual float perimetr();
 virtual float square();


protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

};






#endif // FIGURE_H
