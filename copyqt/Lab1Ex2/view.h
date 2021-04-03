#ifndef VIEW
#define VIEW

#include "figure.h"
#include <QGraphicsView>
#include <QMouseEvent>

class view:public QGraphicsView
{
    Figure *selected_figure = nullptr;
    QList<Figure*> figures;
    QGraphicsRectItem *search_point=nullptr;
public:
    view(QWidget *widg= nullptr);
    void addFigure(Figure *figure);
    void mousePressEvent(QMouseEvent *event);
    Figure* getSelFig();
};



#endif // VIEW
