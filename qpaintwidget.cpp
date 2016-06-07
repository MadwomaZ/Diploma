#include "qpaintwidget.h"

QPaintWidget::QPaintWidget(Surface *s_, QWidget *parent) : QWidget(parent), timer(this), s(s_), stage(0)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateSurface()));
//    connect(&stage, SIGNAL(changevalue()), this, SLOT()
//    parent->connect(&stage, SIGNAL(timer.timeout()), this, SLOT(updateSurface());
    timer.start(10);
}

#define POINT_GAP 3.0
void QPaintWidget::drawSurface()
{
 //   std::cout << "draw start" << std::endl;
  //  g_mtx.lock();
    //    std::cout << "in paint event" << std::endl;
        static const int pointsize = 3;
        QPainter pix(this);
        const qreal tan30 = 0.5;//tan(M_PI / 6.0);
    //    std::cout << "tan=" << tan30 << std::endl;
        qreal max_x = (s->get_number_of_nodes_in_x() /*- 1*/) * POINT_GAP;
        for (size_t i = 0; i < s->get_number_of_nodes_in_y(); i++)
        {
            for (size_t j = 0; j < s->get_number_of_nodes_in_x(); j++)
            {
                Surface::host_state current_state = s->get_element_in_surface(i, j)->get_node_state();
                if (current_state == s->do_not_use)
                {
                    pix.setPen(QPen(Qt::black, pointsize));
                }
                else
                {
                    pix.setPen(QPen(Qt::black, pointsize));
                }
                if (current_state == s->substance1)
                {
                    pix.setPen(QPen(Qt::white, pointsize));
                }
//                if (s->get_element_in_surface(i, j)->get_node_state() == s->substance2)
//                {
//                    pix.setPen(QPen(Qt::blue, pointsize));
//                }

                qreal x = 4 + POINT_GAP * tan30 * (qreal)j + i * POINT_GAP;
                qreal y = 4 + j * POINT_GAP;
    //            if (i == 0)
    //                std::cout << x << " " << y << std::endl;
                if (x <= max_x)
                {
    //                std::cout << "[" << i << " " << j << "]" << x << " " << y << " maxx=" << max_x << std::endl;
                    pix.drawPoint(x, y);
                } else {
                    pix.drawPoint(x - max_x, y);
                }

                //if (j == 0 && i == s->get_number_of_nodes_in_x() - 1)
                //{
                //    max_x = x;
    //                std::cout <<"max x = " << max_x << std::endl;
                //}
            }
        }
}

void QPaintWidget::updateSurface()
{
//    std::cout << "animate call! stage = " << stage << std::endl;

//    switch (stage)
//    {
//    case 0:
//        break;
//    case 1:
//    {
////        s->initial_distribution(10, s->substance1);
////        s->get_element_by_common_index(15)->set_node_state(1);
//        break;
//    }
//    case 2:
//    default:
////        s->selection_process_for_surface();
////        s->get_element_by_common_index(15)->migration();
////        s->selection_process_for_node();
////        s->adsorption(s->substance2);
////        s->desorption();
////        s->migration(); //Рисовать каждые 100-1000
//        break;
//    }
//    std::cout << stage << std::endl;
//    drawSurface();
    if (iterations % 100 == 0 || iterations == 1)
//    if (stage % 100 == 0 || stage == 1)
        QWidget::update();
//    ++stage;
/*    if (stage == 3)
        stage = 0;*/
}

void QPaintWidget::paintEvent(QPaintEvent */*, Surface * s*/)
{
   // std::cout << "in paintEvent" << std::endl;

   drawSurface();
}
