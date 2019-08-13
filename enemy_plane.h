#ifndef ENEMY_PLANE_H
#define ENEMY_PLANE_H

#include "qpixmapitem.h"
#include "enemy_bullet.h"
#include "enemydeath.h"

class enemy_plane :public qpixmapitem
{
public:
    enemy_plane(const QString &fileName,QGraphicsScene *sence,int mytype);//¿‡–Õ
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void creatbullet();
    int xpos_speed;
    int ypos_speed;
    int blood;

};

#endif // ENEMY_PLANE_H
