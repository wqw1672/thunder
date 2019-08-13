#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QTime>
#include <QLabel>
#include "my_plane.h"
#include "enemy_plane.h"
#include "mybullet.h"
#include "mydeath.h"
#include "overwidget.h"

extern int plane_flag;
extern int DifLeve;
class game_view : public QGraphicsView
{
    Q_OBJECT
public:
    explicit game_view(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void init();
    void stopAllTimer();
    void startAllTimer();

signals:
   void planedeath_signals();
public slots:
    void enemy_count();
    void ifplanedeath();
    void send_back();
private:
    QGraphicsScene *sence;
    my_plane *myplane1;
    enemy_plane *enemyboss;
    QTimer *timer;
    QTimer *timer1;
    QTimer *planedeathtime;
    overwidget *gameover;

};

#endif // GAME_VIEW_H
