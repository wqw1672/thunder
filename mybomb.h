#ifndef MYBOMB_H
#define MYBOMB_H

#include"qpixmapitem.h"
#include "enemy_plane.h"


class mybomb:public qpixmapitem
{
public:
    mybomb(const QString &fileName,QGraphicsScene *sence,int mytype);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);//��д��������item����
    void advance(int phase);
    void  docolliding();
};

#endif // MYBOMB_H
