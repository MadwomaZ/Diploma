#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include <gperftools/profiler.h>
#include <unistd.h>

bool volatile g_run = true;
unsigned int g_iterations = 0;

struct filter_in_thread_info
{
  std::thread::id pid;
};

int filter_in_thread(void *arg)
{
    filter_in_thread_info *fi = (filter_in_thread_info*)arg;
    return fi->pid == std::this_thread::get_id();
}

void worker()
{
//    filter_in_thread_info fi = {.pid = std::this_thread::get_id()};
//    ProfilerOptions po = {.filter_in_thread = filter_in_thread, .filter_in_thread_arg = &fi };
//    ProfilerStartWithOptions("cpu-prof", &po);
//    g_surface.initial_distribution(1089, Surface::substance1);
//    g_surface.initial_distribution_square();
    while (g_run && (++g_iterations < 1000000))
    {
      //  g_mtx.lock();
        g_surface.selection_process_for_node();
      //  g_mtx.unlock();
    }
//    ProfilerStop();
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
