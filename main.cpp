#include "mainwindow.h"
#include <QApplication>
#include <thread>

bool volatile g_run = true;

void worker()
{
    int x = 0;
    while (g_run && (++x < 1000000))
    {
      //  g_mtx.lock();
        g_surface.selection_process_for_node();
      //  g_mtx.unlock();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Surface s(14, 14);
//    cout << "Инициализация: " << endl;
//    w.s.
//    w.s.initial_distribution(8,1);
    w.show();

    std::thread t(worker);

    int ret = a.exec();
    g_run = false;
    t.join();
    return ret;
}
