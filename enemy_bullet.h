#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

#include "qpixmapitem.h"
#include "my_plane.h"
#include "enemybomb.h"
class enemy_bullet :public qpixmapitem
{
public:
    enemy_bullet(const QString &fileName,QGraphicsScene *sence,int mytype);//¿‡–Õ
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void docolliding();
private:
    int speed_x;
    int speed_y;
};

#endif // ENEMY_BULLET_H
