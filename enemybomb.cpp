#include "enemybomb.h"


enemybomb::enemybomb(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{
}
void enemybomb::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//��д��������item����
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//���»���
}

void enemybomb::advance(int phase)//ֻҪ����Ҫ���ȫ�����ó������advance �����Ⱥ�˳�����
{
    //    this->hide();

  delete this;
}
