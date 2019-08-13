#include "tableview.h"

tableview::tableview(QWidget *parent) :
    QWidget(parent)
{
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/4);
    this->setFixedSize(500,765);
    this->setWindowTitle("雷霆战机");
    this->setWindowFlags(Qt::CustomizeWindowHint);//去边框

    palette=new QPalette;

    palette->setBrush(QPalette::Background,QBrush(QPixmap("images/widget/Bag_Bg.png")));//用笔刷来设置背景
    this->setPalette(*palette);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("mysql.db");
    database.setUserName("admin");
    database.setPassword("123456");
    if(!database.open())
    {
        qDebug()<<"111111";
        qDebug() << database.lastError();//打印错误信息
    }
    else
    {
        QString create_sql = "create table user(GRADE int primary key,NAME char(20))";
        QSqlQuery sql_query;
        qDebug()<<"22222";

        sql_query.prepare(create_sql);
        if(!sql_query.exec())
        {
            qDebug()<< sql_query.lastError();
        }
        else
        {
            qDebug()<< "create success!";
        }

      }
    QFont font;
    font.setPointSize(16); // 设置字号




    listname=new QLabel(this);
    listname->setText("排行榜");
    listname->setStyleSheet("color:yellow;");
    listname->setFont(font);
    listname->move(230,50);


    username=new QLabel(this);
    username->setText("名称");
    username->setStyleSheet("color:yellow;");
    username->setFont(font);
    username->move(50,100);

    number=new QLabel(this);
    number->setText("排名");
    number->setStyleSheet("color:yellow;");
    number->setFont(font);
    number->move(200,100);


    mygrade=new QLabel(this);
    mygrade->setText("分数");
    mygrade->setStyleSheet("color:yellow;");
    mygrade->setFont(font);
    mygrade->move(350,100);


    backbtn=new QPushButton(this);
    backbtn->setGeometry(400,100,45,45);
    backbtn->setStyleSheet("QPushButton{border-image: url(images/btn/sz_back1.png);}"
                              "QPushButton:hover{border-image: url(images/btn/sz_back2.png);}"
                              "QPushButton:pressed{border-image: url(images/btn/sz_back1.png);}");
    connect(backbtn,SIGNAL(clicked()),this,SLOT(back_choice()));

}

void tableview::back_choice()
{
    emit back_signals();
}
