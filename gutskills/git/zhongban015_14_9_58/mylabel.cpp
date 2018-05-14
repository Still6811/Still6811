#include "mylabel.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
mylabel::mylabel(QWidget *parent) : QLabel(parent)
{
    connect(this,SIGNAL(clicked()),this,SLOT(onClicket()));
}
void mylabel::mouseReleaseEvent(QMouseEvent *event)
{

    x2=event->x()-x1;
    y2=event->y()-y1;
   // qDebug()<<x1<<"y1="<<y1;
    update();
}
void mylabel::mousePressEvent(QMouseEvent *event) {
    x1=event->x();
    y1=event->y();
    if (event->button() == Qt::RightButton) {

    }
    update();
   //QLabel::mousePressEvent(event);
}

void mylabel::paintEvent(QPaintEvent *event)
{

    QLabel::paintEvent(event);
    QPainter painter(this);
    QPen pen;       //设置画笔，颜色、宽度
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    if(x2>0)
    {
    painter.drawRect(x1,y1,x2,y2);
    selectRect=QRect(x1,y1,x2,y2);
    emit clicked();
    }
   // emit clicked();
   // update();
}
//可以在这里向mainwindow主窗体发送Qstring类型的字符串
void mylabel::onClicket()
{
    emit sendData(selectRect);
}
