#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int a, int b):Figure(x,y)
{
    aside=a;
    bside=b;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


   painter->drawRect( xpos, ypos, aside, bside);

}

void Rectangle::setAside(int changeAside)
{
    aside=changeAside;
}

void Rectangle::setBside(int changeBside)
{
    bside=changeBside;
}

float Rectangle::perimetr()
{
    perim=aside*bside;
    return perim;


}

float Rectangle::square()
{
    area=2*(aside+bside);
    return area;
}



QRectF Rectangle::boundingRect() const
{
    return QRectF( xpos, ypos, aside, bside);
}
