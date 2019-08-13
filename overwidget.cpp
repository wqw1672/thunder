#include "overwidget.h"
#include <QSqlDatabase>

#include <QSqlQuery>
#include <QSqlError>
#include <QtSql>
extern char *user_id;

overwidget::overwidget(QWidget *parent) :
    QWidget(parent)
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("mysql.db");
    database.setUserName("admin");
    database.setPassword("123456");
    if(!database.open())
    {
        qDebug() << database.lastError();//打印错误信息
    }
    else
    {
        QString create_sql = "create table user(GRADE int primary key,NAME char(20))";
        QSqlQuery sql_query;

        sql_query.prepare(create_sql);
        if(!sql_query.exec())
        {
            qDebug()<< sql_query.lastError();
        }
        else
        {
            qDebug()<< "create success!";
        }

        if(the_grade>0)
        {
            QString insert_sql = "insert into user vaules(?,?)";
            qDebug()<<"22222";

            QVariantList ints;
            ints<<the_grade;
            QVariantList names;
            names<<user_id;
            sql_query.prepare(insert_sql);

            sql_query.addBindValue(ints);
            sql_query.addBindValue(names);
            if(!sql_query.exec())
            {
                qDebug()<<"111111";
                qDebug()<< sql_query.lastError();
            }
            else
            {
                qDebug()<< "insert success!";
            }
        }
    }



    QString test="分数为";
    QString number=QString::number(the_grade,10);
    faillabel=new QLabel(this);
    faillabel->setPixmap(QPixmap("images/Common/General_Bg1.png"));
    faillabel->show();
    faillabel->move(0,200);
     QPushButton *showgrade=new QPushButton(this);
     showgrade->setGeometry(20,400,150,45);
      showgrade->setStyleSheet("QPushButton{border-image: url(images/btn/ranklist1.png);}"
                            "QPushButton:hover{border-image: url(images/btn/ranklist.png);}"
                            "QPushButton:pressed{border-image: url(images/btn/ranklist2.png);}");
      test.append(number);
      QFont font;
      font.setPointSize(16); // 设置字号
      QLabel *grade_show=new QLabel(this);
      grade_show->setText(test);
       grade_show->move(110,320);
       grade_show->setStyleSheet("color:yellow;");
      grade_show->setFont(font);

      QPushButton *backmenu=new QPushButton(this);
      backmenu->setGeometry(220,400,150,45);
      backmenu->setStyleSheet("QPushButton{border-image: url(images/btn/back1.png);}"
                            "QPushButton:hover{border-image: url(images/btn/back.png);}"
                            "QPushButton:pressed{border-image: url(images/btn/back2.png);}");
      connect(backmenu,SIGNAL(clicked()),this,SLOT(back_menu()));
}

void overwidget::back_menu()
{
    emit menuuback();
}
