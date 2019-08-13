#include "widget.h"
QTcpSocket *tcpclient =new QTcpSocket;    //初始化socket
 QString ip;
 int duankou;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDebug qDebug();

    login_if=0;

   // timer = new QTimer(this);
    loginui=new login_widget;
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/4);
    this->setFixedSize(540,391);
    this->setWindowTitle("雷霆战机");
    this->setWindowFlags(Qt::CustomizeWindowHint);//去边框

    ip_label = new QLabel(this);

    port_label = new QLabel(this);


     palette=new QPalette;

    palette->setBrush(QPalette::Background,QBrush(QPixmap("images/Common/Buyplane_Bg.png")));//用笔刷来设置背景
    this->setPalette(*palette);

    loginbtn=new QPushButton(this);
    loginbtn->setGeometry(100,300,150,45);
    loginbtn->setStyleSheet("QPushButton{border-image: url(images/btn/OK1.png);}"
                              "QPushButton:hover{border-image: url(images/btn/OK.png);}"
                              "QPushButton:pressed{border-image: url(images/btn/OK1.png);}");

    exibtn=new QPushButton(this);
    exibtn->setGeometry(400,100,45,45);
    exibtn->setStyleSheet("QPushButton{border-image: url(images/btn/sz_back1.png);}"
                              "QPushButton:hover{border-image: url(images/btn/sz_back2.png);}"
                              "QPushButton:pressed{border-image: url(images/btn/sz_back1.png);}");



    anybodybtn=new QPushButton(this);
    anybodybtn->setGeometry(350,300,150,45);
    anybodybtn->setStyleSheet("QPushButton{border-image: url(images/btn/loginsome.png);}"
                              "QPushButton:hover{border-image: url(images/btn/loginsome1.png);}"
                              "QPushButton:pressed{border-image: url(images/btn/loginsome2.png);}");



    user_edit=new QLineEdit(this);
    user_edit->move(100,100);
    user_edit->setPlaceholderText("please input ip");

    pwd_edit=new QLineEdit(this);
    pwd_edit->move(100,200);
    pwd_edit->setPlaceholderText("please input port");


    connect(anybodybtn,SIGNAL(clicked()),this,SLOT(tourist()));

    connect(exibtn,SIGNAL(clicked()),this,SLOT(exit_slot()));

    connect(loginui,SIGNAL(backeslots()),this,SLOT(returnmain_Slot()));

    connect(loginbtn,SIGNAL(clicked()),this,SLOT(login_slot()));

    connect(tcpclient,SIGNAL(connected()),this,SLOT(connect_success()));


    //connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));


}

Widget::~Widget()
{
    delete palette;
    delete ip_label;
    delete port_label;
    delete loginbtn;
    delete exibtn;
    delete user_edit;
    delete pwd_edit;
    delete loginui;
    delete msgBox;
}


void Widget::login_slot()
{

    tcpclient->connectToHost(user_edit->text(),pwd_edit->text().toInt());
    ip=user_edit->text();
    duankou=pwd_edit->text().toInt();
    // tcpclient->connectToHost("192.168.43.36",6666);

    if(tcpclient->waitForConnected(1000)==true)
    {
            loginui->show();
            this->hide();
     }
     else
    {
        msgBox=new QMessageBox(this);
        msgBox->setText("你输入的IP地址有误");
        msgBox->exec();
    }
 //   tcpclient->write("1root]123456#sda]");
}

void Widget::exit_slot()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"提示","你确定要退出游戏吗？",QMessageBox::Yes,QMessageBox::No))
    {
        this->close();
    }
}

void Widget::returnmain_Slot()
{
  this->show();
  loginui->hide();
  tcpclient->close();
}

void Widget::connect_success()
{
    login_if=1;
    qDebug()<<"连接成功";
}
void Widget::tourist()
{

}

