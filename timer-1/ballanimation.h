#ifndef BALLANIMATION_H
#define BALLANIMATION_H
#include <QGraphicsScene>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsItem>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void setOrigin(const QPoint &origin);
    void addToOrigin(const QPoint &origin);
    void collision();


signals:

public slots:
    void paintEvent(QPaintEvent* event);

private:
    QPoint m_origin;
};

#endif // BALLANIMATION_H
