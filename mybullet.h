#ifndef MYBULLET_H
#define MYBULLET_H

#include "qpixmapitem.h"
#include "enemy_plane.h"
#include "mybomb.h"


class mybullet :public qpixmapitem
{
public:
    mybullet(const QString &fileName,QGraphicsScene *sence,int mytype);//¿‡–Õ
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void docolliding();
};

#endif // MYBULLET_H
