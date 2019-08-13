#include "enemy_bullet.h"

enemy_bullet::enemy_bullet(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{
     this->speed_x=qrand()%10;
     this->speed_y=-10+qrand()%20;
    if(this->speed_y<=4&&this->speed_y>=-4)
      this->speed_y=10;
}
void enemy_bullet::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//重写用来绘制item内容
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//重新绘制
    if(this->collidingItems().count()>0)
    {
        my_plane *myplane;
        myplane=(my_plane *)(collidingItems().first());
        if(myplane->cType<=4)
           {
            qDebug()<<"444444";
            docolliding();
        }
    }

}
void  enemy_bullet::docolliding()
{
    enemybomb *enemy_bomb=new enemybomb("images/DeathBlast/3.png",sence,MYBOOM);
    enemy_bomb->setPos(mapToScene(0,0));

    delete this;

}
void enemy_bullet::advance(int phase)
{
    if(mapToScene(0,0).y()<0||mapToScene(0,0).y()>706||mapToScene(0,0).x()<0||mapToScene(0,0).x()>400)
    {
        delete this;
    }
    else
    {
        this->setPos(mapToScene(speed_x,speed_y));



    }
}
