#include "mybullet.h"


mybullet::mybullet(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{

}
void mybullet::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//重写用来绘制item内容
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//重新绘制
    if(this->collidingItems().count()>0)
    {
        enemy_plane *enemyplane;
        enemyplane=(enemy_plane *)(collidingItems().first());
        if(enemyplane->cType>=100)
           {
            qDebug()<<"11111";
            docolliding();
        }
    }
}
void  mybullet::docolliding()
{
    mybomb *my_bomb=new mybomb("images/DeathBlast/2.png",sence,MYBOOM);
    my_bomb->setPos(mapToScene(0,0));

    delete this;
//    Qfishnet *net=new Qfishnet("IMAGE/net2.png",this->scence);
//    net->setPos(mapToScene(0,0));
//    delete this;
}
void mybullet::advance(int phase)
{
    if(mapToScene(0,0).y()<0)
    {
        delete this;
    }

    else
    {
        this->setPos(mapToScene(0,-20));

    }
}
