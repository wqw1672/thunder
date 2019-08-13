#include "game_view.h"
extern int widget_w ;
extern int widget_h ;
int the_grade;
game_view::game_view(QWidget *parent) :
    QGraphicsView(parent)
{
        init();
}
void game_view::init()
{
    char myplanepic[50];
    this->resize(widget_w,widget_h);
    this->setStyleSheet("QWidget(background-color:red,border:0px;color:red)");
    sence = new QGraphicsScene();
    sence->setSceneRect(0,0,widget_w,widget_h);//跟view 坐标一样
    this->setScene(sence);
    sprintf(myplanepic,"images/myplane/myplane%d.png",plane_flag+1);
    myplane1 =new my_plane(myplanepic,sence,plane_flag);
    myplane1->setPos(this->width()/2,this->height());
    timer=new QTimer(this);

    connect(timer,SIGNAL(timeout()),sence,SLOT(advance()));
    timer->start(50);

    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(enemy_count()));
    timer1->start(1000);

    planedeathtime=new QTimer(this);
    connect(planedeathtime,SIGNAL(timeout()),this,SLOT(ifplanedeath()));
    planedeathtime->start(1000);

    //connect(myplane1,SIGNAL(planedeath()),this,SLOT(plane_death()))
}


void game_view::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"biubiubiu";
    mybullet *my_bullet=new mybullet("images/bullet/wingman6-1-1.png",sence,MYBULLET);
    my_bullet->setPos(myplane1->x(),myplane1->y());
}




void game_view::keyPressEvent(QKeyEvent *event)
{
    int distance = 10;
    switch(event->key())
    {
        //按方向键
    case Qt::Key_Left:
//        qDebug()<<"left";
        if(myplane1->pos().x()>0)
        myplane1->setPos(mapToScene(myplane1->pos().x()-distance,myplane1->pos().y()));

        break;

    case Qt::Key_Down:
//        qDebug()<<"down";
        if(myplane1->pos().y()<widget_h)
        myplane1->setPos(mapToScene(myplane1->pos().x(),myplane1->pos().y()+distance));

        break;

    case Qt::Key_Right:
//        qDebug()<<"right";
        if(myplane1->pos().x()<widget_w-44)
        myplane1->setPos(mapToScene(myplane1->pos().x()+distance,myplane1->pos().y()));
        break;

    case Qt::Key_Up:
//        qDebug()<<"up";
        if(myplane1->pos().y()>50)
        myplane1->setPos(mapToScene(myplane1->pos().x(),myplane1->pos().y()-distance));
        break;


//    case Qt::Key_Space:
//        qDebug()<<"Key_Space";
//        my_bullet_launch_sound->play();
//        my_bullets.append(new  myBulletItem("MyPlane/images/bullet/bullet-126.png",scene));
//        my_bullets.back()->setPos(myPlane->x()+36,myPlane->y()-80);
//        break;

    case Qt::Key_P:
           qDebug()<<"PPPPPP";
           stopAllTimer();
           //弹出消息框，可让程序卡在这
            QMessageBox::information(this,"暂停","当前游戏已暂停,点击OK继续游戏！");
            startAllTimer();

        break;



    }
}
void game_view::enemy_count()
{
    qDebug()<<"asdfs";
    static int i=20;
    int x=0;
    char enemyname[50];
    qDebug()<<DifLeve;
        switch(DifLeve)
        {
             case 1:
            {
             x=qrand()%2;
             sprintf(enemyname,"images/enemy1/enemy%d.png",x+1);
             enemy_plane *enplanesome=new enemy_plane(enemyname,this->sence,ENEMY1+DifLeve);
             break;
             }
            case 2:
            {
            x=qrand()%3;
            sprintf(enemyname,"images/enemy1/enemy%d.png",x+1);
            enemy_plane *enplanesome1=new enemy_plane(enemyname,this->sence,ENEMY1+DifLeve);
            break;
            }
            case 3:
            {
            x=qrand()%4;
            sprintf(enemyname,"images/enemy1/enemy%d.png",x+1);
            enemy_plane *enplanesome2=new enemy_plane(enemyname,this->sence,ENEMY1+DifLeve);
            break;
            }
        }
     i--;
     if(i==0)
     {
         sprintf(enemyname,"images/enemy1/BOSS%d.png",DifLeve);
         enemyboss=new enemy_plane(enemyname,this->sence,ENEMY1+DifLeve+5);
         timer1->stop();
     }

}
void game_view::ifplanedeath()
{

    if(this->myplane1->blood<=0)
    {
        timer->stop();
        timer1->stop();
        planedeathtime->stop();
        myplane1->hide();
        mydeath *my_death=new mydeath("images/DeathBlast/7.png",sence,ENEMYBOOM1) ;
        my_death->setPos(myplane1->mapToScene(0,0));
        gameover=new overwidget(this);
        gameover->show();
        connect(gameover,SIGNAL(menuuback()),this,SLOT(send_back()));
    }

}
void game_view::send_back()
{
    emit planedeath_signals();
}
void game_view::stopAllTimer()
{
    timer->stop();
    timer1->stop();

    planedeathtime->stop();


}

void game_view::startAllTimer()
{
    timer->start(50);
    timer1->start(1000);

    planedeathtime->start(1000);
}
