#ifndef MYDEATH_H
#define MYDEATH_H

#include"qpixmapitem.h"

class mydeath:public qpixmapitem
{
public:
    mydeath(const QString &fileName,QGraphicsScene *sence,int mytype);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);//重写用来绘制item内容
    void advance(int phase);
};
#endif // MYDEATH_H
