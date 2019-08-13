#include "enemy_plane.h"

enemy_plane::enemy_plane(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{
     xpos_speed=2+qrand()%3;
     ypos_speed=2+qrand()%3;

     setPos(200,-300);
     blood=mytype-98;
}

void enemy_plane::advance(int phase)
{
    static int i=0;

    if(mapToScene(0,0).y()>=706)
    {
        setPos(40+qrand()%350,-300);
        ypos_speed=2+qrand()%3;
    }
    else if(mapToScene(0,0).x()<=0||mapToScene(0,0).x()>360)
    {
        this->xpos_speed=-(xpos_speed);
    }


    this->setPos(mapToScene(xpos_speed,ypos_speed));//mapToScene(0,0)返回目标当前的位置 每个定时器时间想X和Y移动的距离

    while(i++%20==0)
    {
        this->creatbullet();
    }
}
void enemy_plane::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//重写用来绘制item内容
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//重新绘制
    if(this->collidingItems().count()>0)
    {
        my_plane *myplane;
        myplane=(my_plane *)(collidingItems().first());
        if(myplane->cType<=4)
           {
            qDebug()<<"sssss";
            myplane->blood=0;
           }
    }
    if(blood<=0)
    {
         enemydeath *enemy_death=new enemydeath("images/DeathBlast/7.png",sence,ENEMYBOOM1) ;
         enemy_death->setPos(mapToScene(0,0));
         qDebug()<<"sssss";

         delete enemy_death;
         delete this;
    }
}

void enemy_plane::creatbullet()
{
    enemy_bullet *enemybullet=new enemy_bullet("images/bullet/bullet-105.png",sence,ENEMYBOOM1);
    enemybullet->setPos(mapToScene(0,0));
}



