#include "mybomb.h"

mybomb::mybomb(const QString &fileName,QGraphicsScene *sence,int mytype)
    :qpixmapitem(fileName, sence,mytype)
{
}
void mybomb::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)//重写用来绘制item内容
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);//重新绘制
    if(this->collidingItems().count()>0)
    {
        enemy_plane *enemyplane;
        enemyplane=(enemy_plane *)(collidingItems().first());
        if(enemyplane->cType>=90)
           {
            qDebug()<<"33333";
            enemyplane->blood-=1;
            docolliding();
        }
    }
}

void mybomb::advance(int phase)//只要符合要求会全部调用场景里的advance 并且先后顺序随机
{
    //    this->hide();


    delete this;
}
void  mybomb::docolliding()
{
    mybomb *my_bomb=new mybomb("images/DeathBlast/2.png",sence,MYBOOM);
    my_bomb->setPos(mapToScene(0,0));

    delete this;
//    Qfishnet *net=new Qfishnet("IMAGE/net2.png",this->scence);
//    net->setPos(mapToScene(0,0));
//    delete this;
}
