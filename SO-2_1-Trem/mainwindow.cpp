#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,78,78);
    trem2 = new Trem(2,323,78);
    trem3 = new Trem(3,568,78);
    trem4 = new Trem(4,202,322);
    trem5 = new Trem(5,448,322);

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1:
        ui->trem1->setGeometry(x,y,50,50);
        break;
    case 2:
        ui->trem2->setGeometry(x,y,50,50);
        break;
    case 3:
        ui->trem3->setGeometry(x,y,50,50);
        break;
    case 4:
        ui->trem4->setGeometry(x,y,50,50);
        break;
    case 5:
        ui->trem5->setGeometry(x,y,50,50);
        break;
    default:
        break;
    }
}

void MainWindow::on_btncomecar_clicked()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::on_btnparar_clicked()
{
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();
}

void MainWindow::on_controle1_sliderReleased()
{
        trem1->setVelocidade(ui->controle1->value());
}

void MainWindow::on_controle2_sliderReleased()
{
        trem2->setVelocidade(ui->controle2->value());
}

void MainWindow::on_controle3_sliderReleased()
{
        trem3->setVelocidade(ui->controle3->value());
}

void MainWindow::on_controle4_sliderReleased()
{
        trem4->setVelocidade(ui->controle4->value());
}

void MainWindow::on_controle5_sliderReleased()
{
        trem5->setVelocidade(ui->controle5->value());
}
