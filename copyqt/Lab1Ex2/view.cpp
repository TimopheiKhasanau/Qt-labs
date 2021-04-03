#include "view.h"



view::view(QWidget *widg):QGraphicsView(widg)
{

}

void view::addFigure(Figure *figure)
{
    figures.append(figure);
    selected_figure=figure;
}

void view::mousePressEvent(QMouseEvent *event)
{
    QPointF pos = event->localPos();
    if(search_point==nullptr)
    {
        search_point=scene()->addRect(0,0,5,5);
        search_point->hide();
    }

    search_point->setPos(pos.x()-1, pos.y()-1);
    for (int i = 0; i < figures.size() ; i++ )
    {
     if(search_point->collidesWithItem(figures[i]))
     {
         selected_figure = figures[i];
         selected_figure->setTransformOriginPoint(selected_figure->mapFromScene(pos));
         break;
     }
    }
}



Figure *view::getSelFig()
{
    return selected_figure;
}
