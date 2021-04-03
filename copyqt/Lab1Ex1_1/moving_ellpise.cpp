#include "moving_ellpise.h"

Moving_ellpise::Moving_ellpise(int xpos):QGraphicsEllipseItem(0)
{

    setRect(0,0,w,l);
    int x =rand()%(xpos-w);
    int y =600-l;
    setPos(x,y);


}

void Moving_ellpise::advance(int phase)
{
    if(phase)
    {
        moveBy(0,-speed);


        if(pos().ry()<-30)
        {
            delete this;
        }
    }

}
