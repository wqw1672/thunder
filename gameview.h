#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QResizeEvent>


class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameView(QGraphicsView *parent = 0);
    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);
private:
    QGraphicsScene *scence;

    void resizeEvent(QResizeEvent *event);//重写绘图事件，虚函数,绘图事件内部调用，会在重绘的时候自动调用

signals:

public slots:

};
#endif // GAMEVIEW_H
