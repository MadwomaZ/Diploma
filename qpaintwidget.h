#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include </home/madwomaz/Coding/Diplom_model_poverchnosty_oop/node.h>
#include <mutex>

//extern std::mutex g_mtx;
extern unsigned int iterations;

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QPaintWidget(Surface *s_, QWidget *parent = 0);
    int getStage() {return stage;}
public slots:
    void updateSurface();
    void drawSurface();

protected:
    QTimer timer;
    void paintEvent(QPaintEvent */*, Surface *s*/);
private:
    Surface *s;
    int stage;
//    bool selectPen(Surface * s);
};

#endif // QPAINTWIDGET_H
