#ifndef GAME_CHOICE_H
#define GAME_CHOICE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include "game_widget.h"
class game_choice : public QWidget
{
    Q_OBJECT
public:
    explicit game_choice(QWidget *parent = 0);
private:
    QPalette *palette_reg;
    QPushButton *perplane;
    QPushButton *nextplane;
    QPushButton *backmenubtn;
    QPushButton *entereasybtn;
    QPushButton *entercombtn;
    QPushButton *enterhardbtn;

    QLabel *lab1;
    QString planeFinal_str;
    game_widget *entergame;
    QPropertyAnimation *Animation1;
    QPropertyAnimation *Animation2;
    QPropertyAnimation *Animation3;
    QPropertyAnimation *Animation4;
    QParallelAnimationGroup *group;
signals:
    void backmenu();
//    void easygame();
//    void comgame();
//    void hardgame();
public slots:
    void next_plane();
    void pre_plane();
    void back_menu();
    void enter_easy_game();
    void enter_com_game();
    void enter_hard_game();
    void game_to_menu();
};

#endif // GAME_CHOICE_H
