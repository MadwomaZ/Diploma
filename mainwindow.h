#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QMovie>
#include <QGraphicsObject>
//#include <QPainter>
#include "qpaintwidget.h"
#include </home/madwomaz/Coding/Diplom_model_poverchnosty_oop/surface.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
//    QPixmap * gr = new QPixmap;
//    QMovie * move = new QMovie(qobject_cast() );
//    QObject obj = new
    Surface * s;
public:
    void okClickBtn();
    void SaveClickBtn();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::MainWindow *ui;
    QPaintWidget *wgt;

//    unsigned int current_iter = wgt->getStage();
signals:

};

#endif // MAINWINDOW_H
