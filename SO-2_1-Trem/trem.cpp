#include "trem.h"

#include <QtCore>
#include <math.h>

//Construtor
Trem::Trem(int ID, int x, int y, Direcao direcao, float velocidade, Controle* controle){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->direcao = direcao;
    this->velocidade = velocidade;
    this->controle = controle;
}

void Trem::setVelocidade(int valor){
   this->velocidade = valor;
}

int Trem::getTamanho() {
    return this->TAMANHO_TREM;
}

void Trem::setDirecao(Direcao direcao) {
    this->direcao = direcao;
}

Coordenada Trem::getCoordenadas(){
    Coordenada coordenada;
    coordenada.x = this->x;
    coordenada.y = this->y;
    return coordenada;
}

//Inicia a thread
void Trem::run(){
    while(true){

        switch(this->direcao){
        case Direcao::NORTE:
            this->movimentoHorario(this->x,this->y-1);
            this->fimDoMovimento();
            break;
        case Direcao::LESTE:
            this->movimentoHorario(this->x+1,this->y);
            this->fimDoMovimento();
            break;
        case Direcao::SUL:
            this->movimentoHorario(this->x,this->y+1);
            this->fimDoMovimento();
            break;
        case Direcao::OESTE:
            this->movimentoHorario(this->x-1,this->y);
            this->fimDoMovimento();
            break;
        default:
            break;
        }
    }
}

//Sempre que encontrar um nó no trilho irá seguir o sentido horário
//Se encontrar outro trem, irá parar
void Trem::movimentoHorario(int x, int y){

    if (this->controle->testeAreaCritica(this->ID,x,y) == -1)
        return;

    if (this->velocidade >= Trem::VELOCIDADE_MINIMA)
        return;

    if(this->controle->colisaoTrem(this->ID,x,y))
        return;

    switch(this->ID){
    case 0:
        if (x == 78 && y == 78 ){
            this->direcao = Direcao::LESTE;
        }
        if (x == 323 && y == 78 ){
            this->direcao = Direcao::SUL;
        }
        if (x == 323 && y == 323){
            this->direcao = Direcao::OESTE;
        }
        if (x == 78 && y == 323){
            this->direcao = Direcao::NORTE;
        }
        break;
    case 1:
        if (x == 323 && y == 78 ){
            this->direcao = Direcao::LESTE;
        }
        if (x == 568 && y == 78 ){
            this->direcao = Direcao::SUL;
        }
        if (x == 568 && y == 323){
            this->direcao = Direcao::OESTE;
        }
        if (x == 323 && y == 323){
            this->direcao = Direcao::NORTE;
        }
        break;
    case 2:
        if (x == 568 && y == 78){
            this->direcao = Direcao::LESTE;
        }
        if (x == 813 && y == 78 ){
            this->direcao = Direcao::SUL;
        }
        if (x == 813 && y == 323){
            this->direcao = Direcao::OESTE;
        }
        if (x == 568 && y == 323){
            this->direcao = Direcao::NORTE;
        }
        break;
    case 3:
        if (x == 202 && y == 323 ){
            this->direcao = Direcao::LESTE;
        }
        if (x == 447 && y == 323 ){
            this->direcao = Direcao::SUL;
        }
        if (x == 447 && y == 568){
            this->direcao = Direcao::OESTE;
        }
        if (x == 202 && y == 568){
            this->direcao = Direcao::NORTE;
        }
        break;
    case 4:
        if (x == 447 && y == 323 ){
            this->direcao = Direcao::LESTE;
        }
        if (x == 692 && y == 323 ){
            this->direcao = Direcao::SUL;
        }
        if (x == 692 && y == 568){
            this->direcao = Direcao::OESTE;
        }
        if (x == 447 && y == 568){
            this->direcao = Direcao::NORTE;
        }
        break;
    default:
        break;
    }

    this->x = x;
    this->y = y;
}

//Emite a mensagem para atualizar a tela e espera.
void Trem::fimDoMovimento(){
    emit updateGUI(this->ID, this->x, this->y);
    usleep(velocidade);
}
