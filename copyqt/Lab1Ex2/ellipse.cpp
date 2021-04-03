#include "ellipse.h"

Ellipse::Ellipse(int x, int y, int rA, int rB):Figure(x,y)
{
    adiam=rA;
    bdiam=rB;

}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawEllipse( xpos, ypos, adiam, bdiam);
}

void Ellipse::setAdiam(int changeAside)
{
    adiam=changeAside;
}

void Ellipse::setBdiam(int changeBside)
{
    bdiam=changeBside;
}

float Ellipse::perimetr()
{
    perim=2*(adiam+bdiam);
    return perim;
}

float Ellipse::square()
{
    area=Pi*adiam*bdiam/2;
    return area;
}

QRectF Ellipse::boundingRect() const
{
    return QRectF(xpos, ypos, adiam, bdiam);
}
