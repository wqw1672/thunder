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

    void resizeEvent(QResizeEvent *event);//��д��ͼ�¼����麯��,��ͼ�¼��ڲ����ã������ػ��ʱ���Զ�����

signals:

public slots:

};
#endif // GAMEVIEW_H
