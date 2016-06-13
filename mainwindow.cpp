#include "mainwindow.h"
#include <QDesktopWidget>
#include <QScreen>
#include "ui_mainwindow.h"

Surface g_surface(100, 100);
//std::mutex g_mtx;

void MainWindow::okClickBtn()
{
//    QString * str = new QString;
////    current_iter++;
//    str->append("Iteration = ");
//    str->append(QString::number(iterations));
//    ui->iteration->setText(* str);

//    delete str;
//    ui->graph_adsorption->graph(0)->setData(g_surface.all_time, g_surface.concentration);
//    ui->graph_adsorption->replot();

//    QPainter pix;
//    pix.begin(ui->centralWidget);
//    qDebug() << parentWidget();
//    qDebug() << this;
//    pix.setPen(QPen(Qt::red));
//    unsigned int n = 6;
//    for(size_t i = 0; i < n; i++)
//    {
//        qreal fAngle = 2 * 3.14 * i / n;
//        qreal x = 50 + cos(fAngle) * 40;
//        qreal y = 50 + sin(fAngle) * 40;
//        pix.drawPoint(QPointF(x, y));
//    }
//    pix.end();
//    ui->centralWidget->layout()->addWidget(lbl(pix));
//    pix.set
}

void MainWindow::SaveClickBtn()
{
    QString fileName = QFileDialog::getSaveFileName(0, tr("Сохранить файл"), "."); //см 459 для добавления фильтра по расширениям файлов
    qDebug() << fileName << " saved!";
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wgt = new QPaintWidget(&g_surface, this);
    timer = new QTimer(this);
    connect(timer, SIGNAL( timeout() ), this, SLOT(updateGraph()) );
    timer->start(0);
//    qDebug() << ui->centralWidget->layout();
//    ui->horizontalLayout->addWidget(wgt);
//    ui->label_2->setText(QString::number(g_surface.get_all_free_nodes()));
//    ui->Kadsoption->text()
    ui->Kadsoption->setText(ui->Kadsoption->text() + QString::number(g_surface.get_element_by_common_index(0)->k_adsorpion));
    ui->Kmigration->setText(ui->Kmigration->text() + QString::number(g_surface.get_element_by_common_index(0)->k_migration));
    ui->v0 ->setText(ui->v0 ->text() + QString::number(g_surface.get_element_by_common_index(0)->V_0));
    ui->v01->setText(ui->v01->text() + QString::number(g_surface.get_element_by_common_index(0)->V_0_1));
    ui->v02->setText(ui->v02->text() + QString::number(g_surface.get_element_by_common_index(0)->V_0_2));
    ui->v10->setText(ui->v10->text() + QString::number(g_surface.get_element_by_common_index(0)->V_1_0));
    ui->v11->setText(ui->v11->text() + QString::number(g_surface.get_element_by_common_index(0)->V_1_1));
    ui->v12->setText(ui->v12->text() + QString::number(g_surface.get_element_by_common_index(0)->V_1_2));
    ui->v20->setText(ui->v20->text() + QString::number(g_surface.get_element_by_common_index(0)->V_2_0));
    ui->v21->setText(ui->v21->text() + QString::number(g_surface.get_element_by_common_index(0)->V_2_1));
    ui->v22->setText(ui->v22->text() + QString::number(g_surface.get_element_by_common_index(0)->V_2_2));
    ui->e0 ->setText(ui->e0 ->text() + QString::number(g_surface.get_element_by_common_index(0)->E_0));
    ui->e01->setText(ui->e01->text() + QString::number(g_surface.get_element_by_common_index(0)->E_0_1));
    ui->e02->setText(ui->e02->text() + QString::number(g_surface.get_element_by_common_index(0)->E_0_2));
    ui->e10->setText(ui->e10->text() + QString::number(g_surface.get_element_by_common_index(0)->E_1_0));
    ui->e11->setText(ui->e11->text() + QString::number(g_surface.get_element_by_common_index(0)->E_1_1));
    ui->e12->setText(ui->e12->text() + QString::number(g_surface.get_element_by_common_index(0)->E_1_2));
    ui->e20->setText(ui->e20->text() + QString::number(g_surface.get_element_by_common_index(0)->E_2_0));
    ui->e21->setText(ui->e21->text() + QString::number(g_surface.get_element_by_common_index(0)->E_2_1));
    ui->e22->setText(ui->e22->text() + QString::number(g_surface.get_element_by_common_index(0)->E_2_2));
    ui->widget->layout()->addWidget(wgt);
    ui->graph_adsorption->clearGraphs();
    ui->graph_adsorption->addGraph();
    ui->graph_adsorption->graph(0)->setPen(QPen(Qt::blue));
    ui->graph_adsorption->graph(0)->setName("График адсорбции");
    ui->graph_adsorption->yAxis->setRange(0, 1.05);
    ui->graph_adsorption->yAxis->setAutoTickStep(false);
    ui->graph_adsorption->yAxis->setTickStep(0.1);
//    ui->graph_adsorption->xAxis->setRange(0, 10);
    ui->graph_adsorption->xAxis->setAutoTickStep(false);
    ui->graph_adsorption->xAxis->setTickStep(1);
    ui->graph_adsorption->yAxis->setLabel("Концентрация");
    ui->graph_adsorption->xAxis->setLabel("Время");
    ui->graph_adsorption->graph(0)->setData(g_surface.all_time, g_surface.concentration);
//    ui->xEdit->setText(QString::number(90));

//    wgt->show();
//    ui->centralWidget->layout()->addWidget(wgt);
}

MainWindow::~MainWindow()
{
    wgt->deleteLater();
    delete ui;
}

void MainWindow::on_buttonBox_clicked(QAbstractButton *button)
{
    if (ui->buttonBox->standardButton(button) == QDialogButtonBox::Ok)
    {
        ui->buttonBox->accepted();
//        qDebug() << "pressed OK";
//        okClickBtn();
    } else if (ui->buttonBox->standardButton(button) == QDialogButtonBox::Save)
    {
        qDebug() << "pressed Save";
        SaveClickBtn();
    }
}

void MainWindow::updateGraph()
{
    ui->iterations->setText(QString::number(g_iterations));
//    ui->graph_adsorption->graph(0)->setData(g_surface.all_time, g_surface.concentration);
//    ui->graph_adsorption->xAxis->setRange(0, *(g_surface.all_time.end() - 1));
    ui->concentration->setText(QString::number(*(g_surface.concentration.end() - 1)));
//    ui->all_time->setText(QString::number(*(g_surface.all_time.end() - 1)));
    if (g_iterations == 1e6 || *(g_surface.concentration.end() - 1) >= 1)
    {
        timer->stop();
    }
    QString file_name = QString::number(g_surface.get_number_of_nodes_in_x()) +
                        "x" + QString::number(g_surface.get_number_of_nodes_in_x()) +
                        "_ad-" + QString::number(g_surface.get_element_in_surface(0, 0)->k_adsorpion) +
                        "_mig-" + QString::number(g_surface.get_element_in_surface(0, 0)->k_migration) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_0) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_0_1) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_0_2) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_1_0) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_1_1) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_1_2) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_2_0) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_2_1) +
                        "_" + QString::number(g_surface.get_element_in_surface(0, 0)->E_2_2);


    if (!QFile::exists(file_name + "_10percent") &&
       (*(g_surface.concentration.end() - 1) - fmod((*(g_surface.concentration.end() - 1)),  0.1) == 0.10))
    {
        QPixmap pic = ui->general_tab->grab();//->grabWindow(ui->general_tab->winId());
        pic.save(file_name + "_10percent", "PNG");
        std::cout << "10\n";
    }

    if (!QFile::exists(file_name + "_30percent") &&
       (*(g_surface.concentration.end() - 1) - fmod((*(g_surface.concentration.end() - 1)),  0.3) == 0.30))
    {
//        QPixmap pic = QApplication::primaryScreen()->grabWindow(ui->general_tab->winId());
        QPixmap pic = ui->general_tab->grab();
        pic.save(file_name + "_30percent", "PNG");
    }

    if (!QFile::exists(file_name + "_50percent") &&
       (*(g_surface.concentration.end() - 1) - fmod((*(g_surface.concentration.end() - 1)),  0.5) == 0.50))
    {
//        QPixmap pic = QApplication::primaryScreen()->grabWindow(ui->general_tab->winId());
        QPixmap pic = ui->general_tab->grab();
        pic.save(file_name + "_50percent", "PNG");
    }

    if (!QFile::exists(file_name + "_70percent") &&
       (*(g_surface.concentration.end() - 1) - fmod((*(g_surface.concentration.end() - 1)),  0.7) == 0.70))
    {
//        QPixmap pic = QApplication::primaryScreen()->grabWindow(ui->general_tab->winId());
        QPixmap pic = ui->general_tab->grab();
        pic.save(file_name + "_70percent", "PNG");
    }

    if (!QFile::exists(file_name + "_90percent") &&
       (*(g_surface.concentration.end() - 1) - fmod((*(g_surface.concentration.end() - 1)),  0.9) == 0.90))
    {
//        QPixmap pic = QApplication::primaryScreen()->grabWindow(ui->general_tab->winId());
        QPixmap pic = ui->general_tab->grab();
        pic.save(file_name + "_90percent", "PNG");
    }
}
