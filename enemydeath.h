#ifndef ENEMYDEATH_H
#define ENEMYDEATH_H

#include"qpixmapitem.h"
extern int the_grade;
class enemydeath:public qpixmapitem
{
public:
    enemydeath(const QString &fileName,QGraphicsScene *sence,int mytype);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);//重写用来绘制item内容
    void advance(int phase);
};
#endif // ENEMYDEATH_H
