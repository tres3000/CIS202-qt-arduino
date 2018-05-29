#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QDebug>
#include<QWidget>
#include<QDateTime>

BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(50,50))

{
    setFixedSize(100,100);
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = origin;
}

void BallAnimation::addToOrigin(const QPoint &point)
{
    m_origin += point;
    qDebug() << "Point x: " << m_origin.x() << "\tPoint y: " << m_origin.y();
    qDebug() << "xMod: " << xMod << "\tyMod: " << yMod;
}

void BallAnimation::setMove(int mv_x, int mv_y)
{
    addToOrigin(QPoint((mv_x * xMod), (mv_y * yMod)));
    cDetect(mv_x, mv_y);
}

void BallAnimation::cDetect(int mv_x, int mv_y)
{
    if(m_origin.x() >= 90 || m_origin.x() <= 10 ||
       m_origin.y() >= 90 || m_origin.y() <= 10)
    {
        mv_x = randomGen_x();
        xMod *= -1;
        mv_y += randomGen_y();
        yMod *= -1;
    }

}

int BallAnimation::randomGen_x()
{
    int max = 3;
    int min = -1;
    //qsrand(QDateTime::currentMSecsSinceEpoch()%5000);
    int rand_x = qrand();
    rand_x %= max + min;
    return (rand_x);
}

int BallAnimation::randomGen_y()
{
    int max = 3;
    int min = -1;
    //qsrand(QDateTime::currentMSecsSinceEpoch()%5000);
    int rand_y = qrand();
    rand_y %= max + min;
    return (rand_y);
}


void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width(),height()));
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::red);
    painter.drawEllipse(m_origin,10,10);
}
