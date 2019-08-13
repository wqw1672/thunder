#include "enemydeath.h"

enemydeath::enemydeath(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{
    the_grade+=10;
    qDebug()<<the_grade;

}
void enemydeath::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//重写用来绘制item内容
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//重新绘制
}

void enemydeath::advance(int phase)//只要符合要求会全部调用场景里的advance 并且先后顺序随机
{
    //    this->hide();

  delete this;
}
