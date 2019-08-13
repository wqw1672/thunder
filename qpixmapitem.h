#ifndef QPIXMAPITEM_H
#define QPIXMAPITEM_H


#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>
#include <QPainter>
#include <QPixmap>

#define MYPLANE1 0
#define MYPLANE2 1
#define MYPLANE3 2
#define MYPLANE4 3

#define MYBULLET 5
#define MYBOOM 6
#define ENEMYBOOM1 10
#define ENEMY1 101
#define ENEMY2 102
#define ENEMY3 103

//定义一个图元基类；继承于QGraphicsItem
class qpixmapitem :public QGraphicsItem
{
//把所有图元加入到一个场景,支持碰撞检测,边缘检测,重绘图元
public:
    qpixmapitem(const QString &fileName,QGraphicsScene *sence,int type);
    QRectF boundingRect() const;//边缘检测
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cType;
protected:
    QPixmap pixmap;
    QGraphicsScene *sence;
};
#endif // QPIXMAPITEM_H
