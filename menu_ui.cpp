#include "menu_ui.h"
extern int imusic;
extern QSound *music;
menu_ui::menu_ui(QWidget *parent) :
    QWidget(parent)
{
    gamechoice=new game_choice;
    list=new tableview;

    this->setFixedSize(400,706);
    palette_reg=new QPalette;

    palette_reg->setBrush(QPalette::Background,QBrush(QPixmap("images/Scene/Map_09.jpg")));//用笔刷来设置背景
    this->setPalette(*palette_reg);
    this->setWindowFlags(Qt::CustomizeWindowHint);

    begin_game=new QPushButton(this);
    begin_game->setGeometry(125,200,150,45);
    begin_game->setStyleSheet("QPushButton{border-image: url(./images/btn/startgame1.png);}"
                              "QPushButton:hover{border-image: url(./images/btn/startgame.png);}"
                              "QPushButton:pressed{border-image: url(./images/btn/startgame2.png);}");

//    begin_game->setIconSize(QSize(150,45));
//    begin_game->setFocusPolicy(Qt::NoFocus);//去除黑虚框
//    begin_game->setFlat(true); //背景白框去除
//    begin_game->move(300,400);
//    //去除点击按钮后出现的白色部分
//    begin_game->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    connect(begin_game,SIGNAL(clicked()),this,SLOT(gamebegin()));




//    exitbtn->setIcon(QIcon("images/btn/sz_back1.png"));
//    exitbtn->setIconSize(QSize(150,45));
//    exitbtn->setFocusPolicy(Qt::NoFocus);//去除黑虚框
//    exitbtn->setFlat(true); //背景白框去除
//    exitbtn->move(300,100);
//    //去除点击按钮后出现的白色部分
//    exitbtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");

    setting =new QPushButton(this);
    setting->setGeometry(125,300,150,45);
    setting->setStyleSheet("QPushButton{border-image: url(./images/btn/setup1.png);}"
                              "QPushButton:hover{border-image: url(./images/btn/setup.png);}"
                              "QPushButton:pressed{border-image: url(./images/btn/setup2.png);}");

    helpexplain =new QPushButton(this);
    helpexplain->setGeometry(125,400,150,45);
    helpexplain->setStyleSheet("QPushButton{border-image: url(./images/btn/help2.png);}"
                              "QPushButton:hover{border-image: url(./images/btn/help1.png);}"
                              "QPushButton:pressed{border-image: url(./images/btn/help3.png);}");

    ranklist =new QPushButton(this);
    ranklist->setGeometry(125,500,150,45);
    ranklist->setStyleSheet("QPushButton{border-image: url(./images/btn/ranklist1.png);}"
                              "QPushButton:hover{border-image: url(./images/btn/ranklist.png);}"
                              "QPushButton:pressed{border-image: url(./images/btn/ranklist2.png);}");

    exitbtn=new QPushButton(this);
    exitbtn->setGeometry(125,600,150,45);
    exitbtn->setStyleSheet("QPushButton{border-image: url(./images/btn/exit1.png);}"
                              "QPushButton:hover{border-image: url(./images/btn/exit2.png);}"
                              "QPushButton:pressed{border-image: url(./images/btn/exit2.png);}");
    connect(exitbtn,SIGNAL(clicked()),this,SLOT(send_back_signal()));

    connect(gamechoice,SIGNAL(backmenu()),this,SLOT(back_menu()));

    connect(ranklist,SIGNAL(clicked()),this,SLOT(list_show()));

    connect(setting,SIGNAL(clicked()),this,SLOT(set_show()));


    connect(list,SIGNAL(back_signals()),this,SLOT(menu_show_back()));

    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/4);

}
void menu_ui::send_back_signal()
{
    emit gameSignal();
}
void menu_ui::gamebegin()
{
    this->hide();
//    gameview= new game_view;
//    gameview->show();
 //   gamewidget=new game_widget;
  //  gamewidget->show();

    gamechoice->show();

}
menu_ui::~menu_ui()
{
    delete palette_reg;
    delete begin_game;

    delete exitbtn;

    delete gamechoice;


}
void menu_ui::back_menu()
{
    gamechoice->hide();
    this->show();
}
void menu_ui::list_show()
{
    this->hide();
    list->show();

}
void menu_ui::menu_show_back()
{
    list->hide();
    this->show();
}
void menu_ui::set_show()
{
    if(imusic==0)
    {
    imusic=1;
    music->stop();
    }
    else if(imusic==1)
    {
        imusic=0;
      music->play();
    }
}
