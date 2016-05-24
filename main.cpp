#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Surface s(14, 14);
//    cout << "Инициализация: " << endl;
//    w.s.
//    w.s.initial_distribution(8,1);
    w.show();

    return a.exec();
}
