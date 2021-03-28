#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->estado = new Estado();

    Controle* controle = new Controle(this->estado);

    this->listaTrens.push_back(new Trem(0,78,78,Direcao::LESTE,4000.00,controle));
    this->listaTrens.push_back(new Trem(1,323,78,Direcao::LESTE,4000.00,controle));
    this->listaTrens.push_back(new Trem(2,568,78,Direcao::LESTE,4000.00,controle));
    this->listaTrens.push_back(new Trem(3,202,323,Direcao::LESTE,4000.00,controle));
    this->listaTrens.push_back(new Trem(4,447,323,Direcao::LESTE,4000.00,controle));

    for (int i = 0; i < 5; i++)
        connect(listaTrens[i],SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    popularEstadoTrens();
    popularSegmentos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y){
    int tamanho = 50;
    switch(id){
    case 0:
        tamanho = listaTrens[0]->getTamanho();
        ui->trem1->setGeometry(x,y,tamanho,tamanho);
        this->atualizarEstadoTrem(0);
        break;
    case 1:
        tamanho = listaTrens[1]->getTamanho();
        ui->trem2->setGeometry(x,y,tamanho,tamanho);
        this->atualizarEstadoTrem(1);
        break;
    case 2:
        tamanho = listaTrens[2]->getTamanho();
        ui->trem3->setGeometry(x,y,tamanho,tamanho);
        this->atualizarEstadoTrem(2);
        break;
    case 3:
        tamanho = listaTrens[3]->getTamanho();
        ui->trem4->setGeometry(x,y,tamanho,tamanho);
        this->atualizarEstadoTrem(3);
        break;
    case 4:
        tamanho = listaTrens[4]->getTamanho();
        ui->trem5->setGeometry(x,y,tamanho,tamanho);
        this->atualizarEstadoTrem(4);
        break;
    default:
        break;
    }
}

void MainWindow::on_btncomecar_clicked()
{
    for (std::deque<Trem*>::iterator it = listaTrens.begin();
         it != listaTrens.end();
         it++)
        (*it)->start();
}

void MainWindow::on_btnparar_clicked()
{
    for (std::deque<Trem*>::iterator it = listaTrens.begin();
         it != listaTrens.end();
         it++)
        (*it)->terminate();
}

float MainWindow::transformarValor(int entrada){
   //return pow(10, entrada/1351.727641516); //inverso da log
   return pow((entrada+1)/70.710678119,2); //inverso da raiz
   //return entrada; //linear
}

void MainWindow::on_controle1_sliderReleased()
{
    this->listaTrens[0]->setVelocidade(this->transformarValor(ui->controle1->value()));
}

void MainWindow::on_controle2_sliderReleased()
{
    this->listaTrens[1]->setVelocidade(this->transformarValor(ui->controle2->value()));
}

void MainWindow::on_controle3_sliderReleased()
{
    this->listaTrens[2]->setVelocidade(this->transformarValor(ui->controle3->value()));
}

void MainWindow::on_controle4_sliderReleased()
{
    this->listaTrens[3]->setVelocidade(this->transformarValor(ui->controle4->value()));
}

void MainWindow::on_controle5_sliderReleased()
{
    this->listaTrens[4]->setVelocidade(this->transformarValor(ui->controle5->value()));
}

void MainWindow::popularEstadoTrens(){
    std::pair<Coordenada,int> par;
    for (int i = 0; i < 5; i++){
        par.first = this->listaTrens[i]->getCoordenadas();
        par.second = this->listaTrens[i]->getTamanho();
        this->estado->listaTrens.push_back(par);
    }
}

void MainWindow::popularSegmentos(){
    Segmento s;
    Coordenada c;
    s.id = 1;
    c.x = 323;
    c.y = 78;
    s.p1 = c;
    c.x = 323;
    c.y = 323;
    s.p2 = c;
    this->estado->listaSegmentosTrilho.push_back(std::pair<int, Segmento>(-1,s));
    s.id = 2;
    c.x = 568;
    c.y = 78;
    s.p1 = c;
    c.x = 568;
    c.y = 323;
    s.p2 = c;
    this->estado->listaSegmentosTrilho.push_back(std::pair<int, Segmento>(-1,s));
    s.id = 3;
    c.x = 202;
    c.y = 323;
    s.p1 = c;
    c.x = 323;
    c.y = 323;
    s.p2 = c;
    this->estado->listaSegmentosTrilho.push_back(std::pair<int, Segmento>(-1,s));
    s.id = 4;
    c.x = 323;
    c.y = 323;
    s.p1 = c;
    c.x = 447;
    c.y = 323;
    s.p2 = c;
    this->estado->listaSegmentosTrilho.push_back(std::pair<int, Segmento>(-1,s));
    s.id = 5;
    c.x = 447;
    c.y = 323;
    s.p1 = c;
    c.x = 568;
    c.y = 323;
    s.p2 = c;
    this->estado->listaSegmentosTrilho.push_back(std::pair<int, Segmento>(-1,s));
    s.id = 6;
    c.x = 568;
    c.y = 323;
    s.p1 = c;
    c.x = 692;
    c.y = 323;
    s.p2 = c;
    this->estado->listaSegmentosTrilho.push_back(std::pair<int, Segmento>(-1,s));
    s.id = 7;
    c.x = 447;
    c.y = 323;
    s.p1 = c;
    c.x = 447;
    c.y = 568;
    s.p2 = c;
    this->estado->listaSegmentosTrilho.push_back(std::pair<int, Segmento>(-1,s));
}

void MainWindow::atualizarEstadoTrem(int index){
    this->estado->listaTrens[index].first = this->listaTrens[index]->getCoordenadas();
    this->estado->listaTrens[index].second = this->listaTrens[index]->getTamanho();
}

