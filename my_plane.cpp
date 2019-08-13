#include "my_plane.h"


my_plane::my_plane(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{
     blood=3+mytype;
}

QRectF my_plane::boundingRect() const
{
    return QRectF(-33,-88,66,88);
}
void my_plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//virual
{
    painter->drawPixmap(-33,-88,this->pixmap);
}
