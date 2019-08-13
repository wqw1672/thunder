#ifndef OVERWIDGET_H
#define OVERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
extern int the_grade;

class overwidget : public QWidget
{
    Q_OBJECT
public:
    explicit overwidget(QWidget *parent = 0);

signals:
    void menuuback();
public slots:
    void back_menu();
private:
    QLabel *faillabel;
    QPushButton *backmenu;
    QPushButton *showgrade;
};

#endif // OVERWIDGET_H
