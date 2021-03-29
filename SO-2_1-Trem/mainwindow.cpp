#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->estado = new Estado();

    Controle* controle = new Controle(this->estado);

    this->listaTrens.push_back(new Trem(0,78,200,Direcao::NORTE,9000.00,controle));
    this->listaTrens.push_back(new Trem(1,447,78,Direcao::LESTE,4000.00,controle));
    this->listaTrens.push_back(new Trem(2,813,200,Direcao::SUL,9000.00,controle));
    this->listaTrens.push_back(new Trem(3,320,568,Direcao::OESTE,4000.00,controle));
    this->listaTrens.push_back(new Trem(4,570,568,Direcao::OESTE,4000.00,controle));

    for (int i = 0; i < 5; i++)
        connect(listaTrens[i],SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    popularEstadoTrens();
    popularBlocosAreaCritica();
    verificarAreaCritica();
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

void MainWindow::popularBlocosAreaCritica(){
    Bloco b;
    Coordenada c;
    //0
    b.altura = 265;
    b.comprimento = 24;
    c.x = 321;
    c.y = 78;
    b.vertice = c;
    this->estado->listaBlocosAreaCritica.push_back(b);
    //1
    b.altura = 265;
    b.comprimento = 24;
    c.x = 566;
    c.y = 78;
    b.vertice = c;
    this->estado->listaBlocosAreaCritica.push_back(b);
    //2
    b.altura = 24;
    b.comprimento = 145;
    c.x = 200;
    c.y = 321;
    b.vertice = c;
    this->estado->listaBlocosAreaCritica.push_back(b);
    //3
    b.altura = 24;
    b.comprimento = 148;
    c.x = 321;
    c.y = 321;
    b.vertice = c;
    this->estado->listaBlocosAreaCritica.push_back(b);
    //4
    b.altura = 24;
    b.comprimento = 145;
    c.x = 445;
    c.y = 321;
    b.vertice = c;
    this->estado->listaBlocosAreaCritica.push_back(b);
    //5
    b.altura = 24;
    b.comprimento = 148;
    c.x = 566;
    c.y = 321;
    b.vertice = c;
    this->estado->listaBlocosAreaCritica.push_back(b);
    //6
    b.altura = 265;
    b.comprimento = 24;
    c.x = 445;
    c.y = 323;
    b.vertice = c;
    this->estado->listaBlocosAreaCritica.push_back(b);
}

void MainWindow::atualizarEstadoTrem(int index){
    this->estado->listaTrens[index].first = this->listaTrens[index]->getCoordenadas();
    this->estado->listaTrens[index].second = this->listaTrens[index]->getTamanho();
}

void MainWindow::verificarAreaCritica(){
    this->estado->areaCriticaOcupada[0] = 1;
    this->estado->areaCriticaOcupada[1] = 2;
    this->estado->areaCriticaOcupada[2] = 3;
    this->estado->areaCriticaOcupada[3] = 4;
    this->estado->areaCriticaOcupada[4] = 4;
    this->estado->areaCriticaOcupada[5] = -1;
    this->estado->areaCriticaOcupada[6] = 4;

}
