#include "qpixmapitem.h"


qpixmapitem::qpixmapitem(const QString &fileName,QGraphicsScene *sence,int type)
{
    this->pixmap = fileName;
    this->sence = sence;
    this->cType=type;
    sence->addItem(this);
}
//±ßÔµ¼ì²â
QRectF qpixmapitem::boundingRect() const
{
    return QRectF(QPointF(0,0),this->pixmap.size());
}
void qpixmapitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,this->pixmap);
}
