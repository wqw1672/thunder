#ifndef MENU_UI_H
#define MENU_UI_H

#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QApplication>
#include <QDesktopWidget>
#include "game_widget.h"
#include "game_choice.h"
#include <Phonon/VideoPlayer>
#include <phonon/MediaObject>
#include "tableview.h"
class menu_ui : public QWidget
{
    Q_OBJECT
public:
    explicit menu_ui(QWidget *parent = 0);
    ~menu_ui();
private:
    QPalette *palette_reg;
    QPushButton *begin_game;
    QPushButton *setting;
    QPushButton *helpexplain;
    QPushButton *ranklist;
    QPushButton *exitbtn;
    tableview *list;

   // game_widget *gamewidget;

    game_choice *gamechoice;
signals:
    void gameSignal();
public slots:
    void send_back_signal();
    void gamebegin();
    void  back_menu();
    void list_show();
    void menu_show_back();
   void set_show();
};

#endif // MENU_UI_H
