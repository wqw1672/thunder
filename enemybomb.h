#ifndef ENEMYBOMB_H
#define ENEMYBOMB_H

#include"qpixmapitem.h"

class enemybomb:public qpixmapitem
{
public:
    enemybomb(const QString &fileName,QGraphicsScene *sence,int mytype);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);//��д��������item����
    void advance(int phase);
};
#endif // ENEMYBOMB_H
