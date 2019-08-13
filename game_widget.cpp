#include "game_widget.h"
int widget_w=400;
int widget_h=706;
int DifLeve=0;
game_widget::game_widget(QWidget *parent) :
    QWidget(parent)
{
     init();
}
void game_widget::init()
{
    this->setStyleSheet("QWidget{background-color:transparent; border:0px; color:red}");
    this->resize(widget_w, widget_h);
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

    lab1=new QLabel(this);
    lab1->setGeometry(0,0,widget_w,widget_h);
    lab1->setStyleSheet("QLabel{border-image:url(images/Scene/Map_02.jpg);}");




    Animation1= new QPropertyAnimation(lab1,"geometry",this);
    Animation1->setDuration(10000);

    Animation1->setKeyValueAt(0,QRect(0,0,widget_w,widget_h));
    Animation1->setKeyValueAt(1,QRect(0,widget_h,widget_w,widget_h));

    lab2=new QLabel(this);
   lab2->setGeometry(0,0,widget_w,widget_h);
   lab2->setStyleSheet("QLabel{border-image:url(images/Scene/Map_02.jpg);}");

   Animation2= new QPropertyAnimation(lab2,"geometry",this);
   Animation2->setDuration(10000);


   Animation2->setKeyValueAt(0,QRect(0,-widget_h,widget_w,widget_h));
   Animation2->setKeyValueAt(1,QRect(0,0,widget_w,widget_h));

   group = new QParallelAnimationGroup();
   group->addAnimation(Animation1);
   group->addAnimation(Animation2);
   qDebug()<<"333333";

   group->start();
   group->setLoopCount(-1);


}
void game_widget::mapchoice()
{
    QString plane_str1="QLabel{border-image:url(images/Scene/Map_02.jpg);}";

    QString plane_str2="QLabel{border-image:url(images/Scene/Map_03.jpg);}";

    QString plane_str3="QLabel{border-image:url(images/Scene/Map_04.jpg);}";
    qDebug()<<this->DL;
    DifLeve=this->DL;
    switch(this->DL)
    {
    case 1:
        lab1->setStyleSheet(plane_str1);
        lab2->setStyleSheet(plane_str1);
        break;
    case 2:
        lab1->setStyleSheet(plane_str2);
        lab2->setStyleSheet(plane_str2);
        break;
    case 3:
        lab1->setStyleSheet(plane_str3);
        lab2->setStyleSheet(plane_str3);
        break;
      default:break;
    }
    easygame=new game_view(this);
    connect(easygame,SIGNAL(planedeath_signals()),this,SLOT(plane_death()));

}
void game_widget::plane_death()
{
        delete easygame;

        emit back_menu_signal();
}
