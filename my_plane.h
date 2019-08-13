#ifndef MY_PLANE_H
#define MY_PLANE_H

#include "qpixmapitem.h"
#include "mydeath.h"


class my_plane :public qpixmapitem
{
public:
    my_plane(const QString &fileName,QGraphicsScene *sence,int mytype);//¿‡–Õ
    QRectF boundingRect() const;//±ﬂ‘µºÏ≤‚
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int blood;

};

#endif // MY_PLANE_H
