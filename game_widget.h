#ifndef GAME_WIDGET_H
#define GAME_WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QLabel>
#include <QString>
#include <QParallelAnimationGroup>
#include <QApplication>
#include <QDesktopWidget>
#include "game_view.h"
class game_widget : public QWidget
{
    Q_OBJECT
public:
    explicit game_widget(QWidget *parent = 0);
    void init();
    void mapchoice();
    int DL;//难度等级


signals:
    void back_menu_signal();
public slots:
    void plane_death();

private:
    QLabel *lab1;
    QLabel *lab2;
//    QLabel *faillabel;
    game_view *easygame;
    QPropertyAnimation *Animation1;
    QPropertyAnimation *Animation2;
    QParallelAnimationGroup *group;

};

#endif // GAME_WIDGET_H
