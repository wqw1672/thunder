#include "mydeath.h"

mydeath::mydeath(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{

}
void mydeath::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//��д��������item����
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//���»���
}

void mydeath::advance(int phase)//ֻҪ����Ҫ���ȫ�����ó������advance �����Ⱥ�˳�����
{
    //    this->hide();

  delete this;
}
