#include "game_choice.h"
int plane_flag=0;
extern int the_grade;

game_choice::game_choice(QWidget *parent) :
    QWidget(parent)
{
    the_grade=0;
    this->setFixedSize(400,706);
    palette_reg=new QPalette;

    palette_reg->setBrush(QPalette::Background,QBrush(QPixmap("images/Scene/Map_10.jpg")));//ÓÃ±ÊË¢À´ÉèÖÃ±³¾°
    this->setPalette(*palette_reg);
    this->setWindowFlags(Qt::CustomizeWindowHint);

    perplane=new QPushButton(this);
    perplane->setGeometry(20,200,47,73);
    perplane->setStyleSheet("QPushButton{border-image: url(./images/MainUI/MainUI_Arrow_L_Btn_Down.png);}"
                              "QPushButton:hover{border-image: url(./images/MainUI/MainUI_Arrow_L_Btn_Up.png);}"
                              "QPushButton:pressed{border-image: url(./images/MainUI/MainUI_Arrow_L_Btn_Up2.png);}");
    connect(perplane,SIGNAL(clicked()),this,SLOT(pre_plane()));

    nextplane=new QPushButton(this);
    nextplane->setGeometry(333,200,47,73);
    nextplane->setStyleSheet("QPushButton{border-image: url(./images/MainUI/MainUI_Arrow_R_Btn_Down.png);}"
                              "QPushButton:hover{border-image: url(./images/MainUI/MainUI_Arrow_R_Btn_Up.png);}"
                              "QPushButton:pressed{border-image: url(./images/MainUI/MainUI_Arrow_R_Btn_Up2.png);}");


    connect(nextplane,SIGNAL(clicked()),this,SLOT(next_plane()));

    planeFinal_str="QLabel{border-image:url(images/myplane/myplane1.png);}";

    lab1=new QLabel(this);
    lab1->setGeometry(125,120,150,158);
    lab1->setStyleSheet(planeFinal_str);



    backmenubtn=new QPushButton(this);
    backmenubtn->setGeometry(0,633,149,41);
    backmenubtn->setStyleSheet("QPushButton{border-image: url(./images/btn/back1.png);}"
                              "QPushButton:hover{border-image: url(./images/btn/back.png);}"
                              "QPushButton:pressed{border-image: url(./images/btn/back2.png);}");

    connect(backmenubtn,SIGNAL(clicked()),this,SLOT(back_menu()));




    entereasybtn=new QPushButton(this);
    entereasybtn->setGeometry(227,400,173,64);
    entereasybtn->setStyleSheet("QPushButton{border-image: url(./images/level/Lv_Eazy.png);}"
                              "QPushButton:hover{border-image: url(./images/level/Lv_Eazy_Down.png);}"
                              "QPushButton:pressed{border-image: url(./images/level/Lv_Eazy_Up.png);}");

    connect(entereasybtn,SIGNAL(clicked()),this,SLOT(enter_easy_game()));


    entercombtn=new QPushButton(this);
    entercombtn->setGeometry(227,500,173,64);
    entercombtn->setStyleSheet("QPushButton{border-image: url(./images/level/Lv_Normal.png);}"
                              "QPushButton:hover{border-image: url(./images/level/Lv_Normal_Down.png);}"
                              "QPushButton:pressed{border-image: url(./images/level/Lv_Normal_Up.png);}");

    connect(entercombtn,SIGNAL(clicked()),this,SLOT(enter_com_game()));


    enterhardbtn=new QPushButton(this);
    enterhardbtn->setGeometry(227,600,173,64);
    enterhardbtn->setStyleSheet("QPushButton{border-image: url(./images/level/Lv_Hard.png);}"
                              "QPushButton:hover{border-image: url(./images/level/Lv_Hard_Down.png);}"
                              "QPushButton:pressed{border-image: url(./images/level/Lv_Hard_Up.png);}");

    connect(enterhardbtn,SIGNAL(clicked()),this,SLOT(enter_hard_game()));



    //lab1->setAttribute(Qt::WA_TranslucentBackground);

//    QLabel *lab3;
//    Animation1= new QPropertyAnimation(lab1,"geometry",this);
//    Animation1->setDuration(10000);
//    Animation1->setStartValue(QRect(0, 0, widget_w, widget_h));
//    Animation1->setEndValue(QRect(0, widget_h, widget_w, widget_h));

//    Animation1->setKeyValueAt(0,QRect(100,100,150,220));
//    Animation1->setKeyValueAt(1,QRect(100,100,150,220));

//    group = new QParallelAnimationGroup();
//    group->addAnimation(Animation1);
    //group->addAnimation(Animation2);
//    group->addAnimation(Animation3);
//    group->addAnimation(Animation4);
//    group->start();
//    group->setLoopCount(-1);
}
void game_choice::next_plane()
{
    QString plane_str1="QLabel{border-image:url(images/myplane/myplane1.png);}";

    QString  plane_str2="QLabel{border-image:url(images/myplane/myplane2.png);}";

    QString plane_str3="QLabel{border-image:url(images/myplane/myplane3.png);}";

    QString   plane_str4="QLabel{border-image:url(images/myplane/myplane4.png);}";

plane_flag++;
if(plane_flag>3)
   plane_flag=0;
    switch(plane_flag)
    {
       case 1:
          planeFinal_str=plane_str2;
          break;
        case 2:
           planeFinal_str=plane_str3;
           break;
        case 3:
           planeFinal_str=plane_str4;
           break;
        case 0:
           planeFinal_str=plane_str1;
           break;
    }

     lab1->setGeometry(125,120,150,158);
     lab1->setStyleSheet(planeFinal_str);
}
void game_choice::pre_plane()
{
    QString plane_str1="QLabel{border-image:url(images/myplane/myplane1.png);}";

  QString  plane_str2="QLabel{border-image:url(images/myplane/myplane2.png);}";

    QString plane_str3="QLabel{border-image:url(images/myplane/myplane3.png);}";

QString   plane_str4="QLabel{border-image:url(images/myplane/myplane4.png);}";

plane_flag--;
if(plane_flag<0)
   plane_flag=3;
    switch(plane_flag)
    {
        case 1:
       planeFinal_str=plane_str2;
       break;
     case 2:
        planeFinal_str=plane_str3;
        break;
     case 3:
        planeFinal_str=plane_str4;
        break;
     case 0:
        planeFinal_str=plane_str1;
        break;
    }

     lab1->setGeometry(125,120,150,158);
     lab1->setStyleSheet(planeFinal_str);
}
void game_choice::back_menu()
{
    emit backmenu();
}
void game_choice::enter_easy_game()
{
    entergame=new game_widget;
    entergame->DL=1;
    entergame->mapchoice();
    entergame->show();
    this->hide();
    connect(entergame,SIGNAL(back_menu_signal()),this,SLOT(game_to_menu()));
}
void game_choice::enter_com_game()
{
    entergame=new game_widget;
    entergame->DL=2;
    entergame->mapchoice();
    entergame->show();
    this->hide();
    connect(entergame,SIGNAL(back_menu_signal()),this,SLOT(game_to_menu()));

}

void game_choice::enter_hard_game()
{
    entergame=new game_widget;
    entergame->DL=3;
    entergame->mapchoice();
    entergame->show();
    this->hide();
    connect(entergame,SIGNAL(back_menu_signal()),this,SLOT(game_to_menu()));

}
void game_choice::game_to_menu()
{
    delete entergame;
    this->show();
}
