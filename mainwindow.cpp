#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName();
    if(path.isEmpty())
    {
        return;
    }

    QImage img(path);

//    QLabel *labellist[9];

    labellist[0] = ui->label_0;
    labellist[1] = ui->label_1;
    labellist[2] = ui->label_2;
    labellist[3] = ui->label_3;
    labellist[4] = ui->label_4;
    labellist[5] = ui->label_5;
    labellist[6] = ui->label_6;
    labellist[7] = ui->label_7;
    labellist[8] = ui->label_8;

    for(int i =0;i<9;i++)
    {
        qDebug()<<labellist[i]->text();
    }
    int x = 0;
    int y = 0;

    int wid = img.width() / 3;
    int hei = img.height() / 3;
    QImage temp;
    int xi = 0;
    for(int i = 0; i < 9; i++)
    {
        temp = img.copy(x, y, wid, hei);
        labellist[i]->setPixmap(QPixmap::fromImage(temp));
        x += wid;
        xi++;
        if(xi == 3)
        {
            xi = 0;
            y += hei;
            x = 0;
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    for(int i = 0; i < 9; i++)
    {
        QString path = QFileDialog::getSaveFileName(this, tr("Save Image"),"",tr("Images (*.png *.bmp *.jpg"));
        if(path.isEmpty())
        {
            return;
        }

        labellist[i]->pixmap()->save(path);

    }

}
