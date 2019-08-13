#ifndef REG_UI_H
#define REG_UI_H

#include <QWidget>
#include <QtGui/QWidget>
#include <QtNetwork>
#include <QTcpSocket>
#include <QPalette>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTime>
#include <QIntValidator>
class reg_ui : public QWidget
{
    Q_OBJECT

public:
    explicit reg_ui(QWidget *parent = 0);
    ~reg_ui();
    struct STU
    {
        char name[25];
        char username[25];
        char passwd[25];
        char answer[25];
    }message;
    struct pub_head
    {
        int head;
    }ithead;
private:
    QPalette *palette_reg;
    QPushButton *yesbtn;
    QPushButton *retbtn;
    QPushButton *exitbtn;
    QLineEdit *username_edit;
    QLineEdit *userpwd_edit;
    QLineEdit *gamename_edit;
    QLineEdit *pwdagain_edit;
    QLineEdit *answer_edit;
    QLineEdit *question_edit;
    QMessageBox * newmessage;
    QTimer *timer;
    QLabel *question_label;

public slots:
    void time_on();
//    QTcpSocket *tcpclient;

private slots:
    void yes_slot();
    void ret_slot();
    void exit_reg_slot();
    void backSignal();//槽函数，用来发送返回信号

signals:
    void regSignal();//自定义的返回信号，用来发送给父窗口
};

#endif // WIDGET_H
