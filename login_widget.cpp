#include "login_widget.h"
extern QTcpSocket *tcpclient ;
char *user_id;
int imusic=0;
QSound *music;
login_widget::login_widget(QWidget *parent)
    : QWidget(parent)
{
    QDebug qDebug();
    regui=new reg_ui;
    menuui =new menu_ui;
    timer=new QTimer(this);
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/4);
    this->setFixedSize(648,584);
    this->setWindowTitle("雷霆战机");
    this->setWindowFlags(Qt::CustomizeWindowHint);//去边框

     palette=new QPalette;

    palette->setBrush(QPalette::Background,QBrush(QPixmap("images/widget/bg_login.png")));//用笔刷来设置背景
    this->setPalette(*palette);

    loginbtn=new QPushButton(this);
    loginbtn->setGeometry(100,450,150,45);
    loginbtn->setStyleSheet("QPushButton{border-image: url(images/btn/login1.png);}"
                              "QPushButton:hover{border-image: url(images/btn/login.png);}"
                              "QPushButton:pressed{border-image: url(images/btn/login2.png);}");





    regbtn=new QPushButton(this);
    regbtn->setIcon(QIcon("images/btn/timg.jpg"));
    regbtn->setIconSize(QSize(150,45));
    regbtn->setFocusPolicy(Qt::NoFocus);//去除黑虚框
    regbtn->setFlat(true); //背景白框去除

    regbtn->move(400,450);
    //去除点击按钮后出现的白色部分
    regbtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");


    exibtn=new QPushButton(this);
    exibtn->setIcon(QIcon("images/btn/sz_back1.png"));
    exibtn->setIconSize(QSize(45,45));
    exibtn->setFocusPolicy(Qt::NoFocus);//去除黑虚框
    exibtn->setFlat(true); //背景白框去除
    //去除点击按钮后出现的白色部分
    exibtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    exibtn->move(550,100);

    user_edit=new QLineEdit("",this);
    user_edit->setGeometry(270,270,275,45);
    user_edit->setPlaceholderText("请输入用户名");
    user_edit->setStyleSheet("font-size:28px;borde:1px;background-color:rgba(0,0,0,0)");
    user_edit->setMaxLength(12);
//    user_edit->setParent(parent);

    pwd_edit=new QLineEdit("",this);
    pwd_edit->setEchoMode(QLineEdit::Password);
    pwd_edit->setGeometry(270,320,275,45);
    pwd_edit->setPlaceholderText("请输入密码");
    pwd_edit->setStyleSheet("font-size:28px;borde:1px;background-color:rgba(0,0,0,0)");
    pwd_edit->setValidator(new QIntValidator(0,99999999,this));
    pwd_edit->setMaxLength(8);



//    pwd_edit->setParent(parent);

//    user_edit=new QLineEdit(this);

//    pwd_edit=new QLineEdit(this);

    connect(regbtn,SIGNAL(clicked()),this,SLOT(reg_new()));

    connect(exibtn,SIGNAL(clicked()),this,SLOT(exit_slot()));

    connect(regui,SIGNAL(regSignal()),this,SLOT(returnmain_Slot()));

    connect(menuui,SIGNAL(gameSignal()),this,SLOT(gameback_slot()));

    connect(loginbtn,SIGNAL(clicked()),this,SLOT(login_slot()));

  //  connect(tcpclient,SIGNAL(readyRead()),this,SLOT(readback()));

    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));

}

login_widget::~login_widget()
{

}
void login_widget::reg_new()
{
//    tcpclient =new QTcpSocket(this);    //初始化socket
////    tcpclient->abort(); //终止之前的连接，重置套接字
//    this->tcpclient->connectToHost("192.168.43.36",6666);
//      this->hide();
    timer->stop();

    regui->show();
    this->hide();

}
void login_widget::login_slot()
{
    char buff[1024];
    ithead.head=1;
    memcpy(buff,&ithead,sizeof(struct pub_head));//检测头部
    strcpy(message.name,user_edit->text().toStdString().c_str());//用户名
    strcpy(message.passwd,pwd_edit->text().toStdString().c_str());//用户名
    memcpy(buff+sizeof(struct pub_head),&message,sizeof(struct STU));




    tcpclient->connectToHost(ip,duankou);
    tcpclient->write(buff,sizeof(struct STU)+sizeof(struct pub_head));
    timer->start(1000);

}
void login_widget::gameback_slot()
{
    this->show();
    menuui->hide();
}

void login_widget::exit_slot()
{
    emit backeslots();
}
void login_widget::returnmain_Slot()
{

    this->show();
    regui->hide();

}

void login_widget::onTimeout()
{
    char *ch;
    ch=tcpclient->readAll().data();
    qDebug()<<ch;
    //qDebug()<<"22222222";
    if(strcmp(ch,"1")==0)
    {
         QString buff=user_edit->text().toStdString().data();
         QByteArray a=buff.toUtf8();

        user_id=a.data();
        qDebug()<<user_id;


          if(imusic==0)
            {
              music = new QSound("images/bgm1.wav");
              music->setLoops(-1);
              music->play();

            }

            menuui->show();
            this->hide();
    }
    else if(strcmp(ch,"2")==0)
    {
        msgBox=new QMessageBox(this);
        msgBox->setText("你输入账号或密码错误");
        msgBox->exec();
    }
    else if(strcmp(ch,"3")==0)
    {
        msgBox=new QMessageBox(this);
        msgBox->setText("你输入账号或密码错误");
        msgBox->exec();
    }

}
