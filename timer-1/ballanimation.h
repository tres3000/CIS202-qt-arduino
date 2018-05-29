#ifndef BALLANIMATION_H
#define BALLANIMATION_H
#include <QPaintEvent>
#include <QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QDebug>
#include<QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void setOrigin(const QPoint &origin);
    void addToOrigin(const QPoint &origin);
    void setMove(int mv_x, int mv_y);
    void cDetect(int mv_x, int mv_y);
    int randomGen_x();
    int randomGen_y();

signals:

public slots:
    void paintEvent(QPaintEvent* event);

private:
    QPoint m_origin;
    int xMod = 1;
    int yMod = 1;
};

#endif // BALLANIMATION_H
