#include "enemydeath.h"

enemydeath::enemydeath(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{
    the_grade+=10;
    qDebug()<<the_grade;

}
void enemydeath::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//��д��������item����
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//���»���
}

void enemydeath::advance(int phase)//ֻҪ����Ҫ���ȫ�����ó������advance �����Ⱥ�˳�����
{
    //    this->hide();

  delete this;
}
