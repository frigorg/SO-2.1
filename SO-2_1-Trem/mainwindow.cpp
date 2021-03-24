#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listaTrem[0] = new Trem(0,78,78);
    listaTrem[1] = new Trem(1,323,78);
    listaTrem[2] = new Trem(2,568,78);
    listaTrem[3] = new Trem(3,202,322);
    listaTrem[4] = new Trem(4,448,322);

    for(int i = 0; i<5; i++)
        connect(listaTrem[i],SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::podeMover(int x, int y){
    bool resultado = true;
    for(int i = 0; i<5; i++){
        int tremTam = listaTrem[i]->getTamanhoTrem();
        int tremx = listaTrem[i]->getCoordenadas().first;
        int tremy = listaTrem[i]->getCoordenadas().second;
        if (x >= tremx && x <= tremx+tremTam)
            return false;
        if (y >= tremy && y <= tremy+tremTam)
            return false;
   }
}

void MainWindow::updateInterface(int id, int x, int y){
    int tamanho = 50;
    switch(id){
    case 0:
        tamanho = listaTrem[0]->getTamanhoTrem();
        ui->trem1->setGeometry(x,y,tamanho,tamanho);
        break;
    case 1:
        tamanho = listaTrem[1]->getTamanhoTrem();
        ui->trem2->setGeometry(x,y,tamanho,tamanho);
        break;
    case 2:
        tamanho = listaTrem[2]->getTamanhoTrem();
        ui->trem3->setGeometry(x,y,tamanho,tamanho);
        break;
    case 3:
        tamanho = listaTrem[3]->getTamanhoTrem();
        ui->trem4->setGeometry(x,y,tamanho,tamanho);
        break;
    case 4:
        tamanho = listaTrem[4]->getTamanhoTrem();
        ui->trem5->setGeometry(x,y,tamanho,tamanho);
        break;
    default:
        break;
    }
}

void MainWindow::on_btncomecar_clicked()
{
    for(int i = 0; i<5; i++)
        listaTrem[i]->start();
}

void MainWindow::on_btnparar_clicked()
{
    for(int i = 0; i<5; i++)
        listaTrem[i]->terminate();
}

void MainWindow::on_controle1_sliderReleased()
{
        listaTrem[0]->setVelocidade(ui->controle1->value());
}

void MainWindow::on_controle2_sliderReleased()
{
        listaTrem[1]->setVelocidade(ui->controle2->value());
}

void MainWindow::on_controle3_sliderReleased()
{
        listaTrem[2]->setVelocidade(ui->controle3->value());
}

void MainWindow::on_controle4_sliderReleased()
{
        listaTrem[3]->setVelocidade(ui->controle4->value());
}

void MainWindow::on_controle5_sliderReleased()
{
        listaTrem[4]->setVelocidade(ui->controle5->value());
}
