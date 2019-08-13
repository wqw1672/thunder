#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QApplication>
#include <QtNetwork>
#include <QTcpSocket>
#include <QPalette>
#include <QDebug>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QLabel>
#include "login_widget.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    int login_if;
    QTimer *timer;
    QPalette *palette;
    QLabel *ip_label;
    QLabel *port_label;
    QPushButton *loginbtn;
    QPushButton *exibtn;
    QPushButton *anybodybtn;
    QLineEdit *user_edit;
    QLineEdit *pwd_edit;
    login_widget *loginui;
    QMessageBox *msgBox;
    QByteArray array;
private slots:
    void login_slot();
    void exit_slot();
    void returnmain_Slot();
    void connect_success();
    void tourist();
};

#endif // WIDGET_H
