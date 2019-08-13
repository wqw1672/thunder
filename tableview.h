#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QtSql>
#include <QLabel>
#include <QPushButton>
class tableview : public QWidget
{
    Q_OBJECT
public:
    explicit tableview(QWidget *parent = 0);

signals:
    void back_signals();
public slots:
    void back_choice();
private:
    QPalette *palette;
    QLabel *username;
    QLabel *number;
    QLabel *mygrade;
    QLabel *listname;
   QPushButton *backbtn;
};

#endif // TABLEVIEW_H
