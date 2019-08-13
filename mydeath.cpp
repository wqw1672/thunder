#include "mydeath.h"

mydeath::mydeath(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{

}
void mydeath::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//重写用来绘制item内容
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//重新绘制
}

void mydeath::advance(int phase)//只要符合要求会全部调用场景里的advance 并且先后顺序随机
{
    //    this->hide();

  delete this;
}
