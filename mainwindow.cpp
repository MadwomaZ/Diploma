#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::okClickBtn()
{
    QString * str = new QString;
//    current_iter++;
    str->append("Iteration = ");
    str->append(QString::number(wgt->getStage()));
    ui->iteration->setText(* str);

    delete str;
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
    s = new Surface(100, 100);
    wgt = new QPaintWidget(s, this);
//    qDebug() << ui->centralWidget->layout();
//    ui->horizontalLayout->addWidget(wgt);
//    ui->label_2->setText(QString::number(s->get_all_free_nodes()));
//    ui->Kadsoption->text()
    ui->Kadsoption->setText(ui->Kadsoption->text() + QString::number(s->get_element_by_common_index(0)->k_adsorpion));
    ui->Kmigration->setText(ui->Kmigration->text() + QString::number(s->get_element_by_common_index(0)->k_migration));
    ui->v0 ->setText(ui->v0 ->text() + QString::number(s->get_element_by_common_index(0)->V_0));
    ui->v01->setText(ui->v01->text() + QString::number(s->get_element_by_common_index(0)->V_0_1));
    ui->v02->setText(ui->v02->text() + QString::number(s->get_element_by_common_index(0)->V_0_2));
    ui->v10->setText(ui->v10->text() + QString::number(s->get_element_by_common_index(0)->V_1_0));
    ui->v11->setText(ui->v11->text() + QString::number(s->get_element_by_common_index(0)->V_1_1));
    ui->v12->setText(ui->v12->text() + QString::number(s->get_element_by_common_index(0)->V_1_2));
    ui->v20->setText(ui->v20->text() + QString::number(s->get_element_by_common_index(0)->V_2_0));
    ui->v21->setText(ui->v21->text() + QString::number(s->get_element_by_common_index(0)->V_2_1));
    ui->v22->setText(ui->v22->text() + QString::number(s->get_element_by_common_index(0)->V_2_2));
    ui->widget->layout()->addWidget(wgt);
//    ui->xEdit->setText(QString::number(90));

//    wgt->show();
//    ui->centralWidget->layout()->addWidget(wgt);
}

MainWindow::~MainWindow()
{
    wgt->deleteLater();
    delete s;
    delete ui;
}

void MainWindow::on_buttonBox_clicked(QAbstractButton *button)
{
    if (ui->buttonBox->standardButton(button) == QDialogButtonBox::Ok)
    {
//        qDebug() << "pressed OK";
        okClickBtn();
    } else if (ui->buttonBox->standardButton(button) == QDialogButtonBox::Save)
    {
        qDebug() << "pressed Save";
        SaveClickBtn();
    }
}
