#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::okClickBtn()
{
    QString * str = new QString;
//    current_iter++;
    str->append("Iteration = ");
    str->append(QString::number(wgt->getStage()));
    ui->label->setText(* str);

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
    s = new Surface(7, 7);
    wgt = new QPaintWidget(s, this);
//    qDebug() << ui->centralWidget->layout();
//    ui->horizontalLayout->addWidget(wgt);
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
