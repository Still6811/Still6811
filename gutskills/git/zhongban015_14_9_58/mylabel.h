#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>
class mylabel : public QLabel
{
    Q_OBJECT
public:  
    explicit mylabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    int x1,y1,x2,y2;
    QRect selectRect;
signals:
    void clicked();
    void sendData(QRect);
public slots:
    void onClicket();
};

#endif // MYLABEL_H
