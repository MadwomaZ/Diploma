#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QAbstractButton>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QMovie>
#include <QGraphicsObject>
#include "qpaintwidget.h"
#include <surface.h>

extern Surface g_surface;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *timer;
public:
    void okClickBtn();
    void SaveClickBtn();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void updateGraph();
private:
    Ui::MainWindow *ui;
    QPaintWidget *wgt;
};

#endif // MAINWINDOW_H
