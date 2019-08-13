#ifndef LOGIN_WIDGET_H
#define LOGIN_WIDGET_H

#include <QtGui/QWidget>
#include <QApplication>
#include <QtNetwork>
#include <QTcpSocket>
#include <QPalette>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include "reg_ui.h"
#include <QDesktopWidget>
#include <QTimer>
#include <QDebug>
#include <QByteArray>
#include <Phonon/VideoPlayer>
#include <phonon/MediaObject>
#include "menu_ui.h"
extern QString ip;
extern int duankou;

class login_widget : public QWidget
{
    Q_OBJECT

public:
    login_widget(QWidget *parent = 0);
    ~login_widget();
    struct STU
    {
        char name[25];
        char passwd[25];
    }message;
    struct pub_head
    {
        int head;
    }ithead;

private:

    QPalette *palette;
    QPushButton *loginbtn;
    QPushButton *regbtn;
    QPushButton *exibtn;
    QLineEdit *user_edit;
    QLineEdit *pwd_edit;
    reg_ui *regui;
    menu_ui *menuui;
    QTimer *timer;
    QMessageBox * msgBox;

    //    QTcpSocket *tcpclient;

private slots:
    void reg_new();
    void login_slot();
    void exit_slot();
    void returnmain_Slot();
    void gameback_slot();
  //  void readback();
    void onTimeout();
signals:
    void backeslots();
};


#endif // LOGIN_WIDGET_H
