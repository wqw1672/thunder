#include "tableview.h"

tableview::tableview(QWidget *parent) :
    QWidget(parent)
{
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/4);
    this->setFixedSize(500,765);
    this->setWindowTitle("����ս��");
    this->setWindowFlags(Qt::CustomizeWindowHint);//ȥ�߿�

    palette=new QPalette;

    palette->setBrush(QPalette::Background,QBrush(QPixmap("images/widget/Bag_Bg.png")));//�ñ�ˢ�����ñ���
    this->setPalette(*palette);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("mysql.db");
    database.setUserName("admin");
    database.setPassword("123456");
    if(!database.open())
    {
        qDebug()<<"111111";
        qDebug() << database.lastError();//��ӡ������Ϣ
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
    font.setPointSize(16); // �����ֺ�




    listname=new QLabel(this);
    listname->setText("���а�");
    listname->setStyleSheet("color:yellow;");
    listname->setFont(font);
    listname->move(230,50);


    username=new QLabel(this);
    username->setText("����");
    username->setStyleSheet("color:yellow;");
    username->setFont(font);
    username->move(50,100);

    number=new QLabel(this);
    number->setText("����");
    number->setStyleSheet("color:yellow;");
    number->setFont(font);
    number->move(200,100);


    mygrade=new QLabel(this);
    mygrade->setText("����");
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
