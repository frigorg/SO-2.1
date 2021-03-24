#include "trem.h"

#include <QtCore>
#include <math.h>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 4000;
}

void Trem::setVelocidade(int valor){
   //this->velocidade = pow(10, valor/1351.727641516); //inverso da log
   this->velocidade = pow((valor+1)/70.710678119,2); //inverso da raiz
   //this->velocidade = valor; //linear
}

int Trem::getTamanhoTrem() {
    return this->TAMANHO_TREM;
}

std::pair<int,int> Trem::getCoordenadas(){
    return std::pair<int,int>(this->x, this->y);
}

void Trem::run(){
    while(true){
        switch(ID){
        case 0:     //Trem 0
            checarLimitesQuadrado(78, 78, TAMANHO_QUADRADO);
            break;
        case 1:     //Trem 1
            checarLimitesQuadrado(323, 78, TAMANHO_QUADRADO);
            break;
        case 2:     //Trem 2
            checarLimitesQuadrado(568, 78, TAMANHO_QUADRADO);
            break;
        case 3:     //Trem 3
            checarLimitesQuadrado(202, 322, TAMANHO_QUADRADO);
            break;
        case 4:     //Trem 4
            checarLimitesQuadrado(448, 322, TAMANHO_QUADRADO);
            break;
        default:
            break;
        }
    }
}

// Calcula o movimento do trem para que ocorra dentro de um quandrado
// A coordenada (qx,qy) indica o vértice noroeste do quadrado
// tamanhoQuadrado é o tamanho do lado do quadrado
void Trem::checarLimitesQuadrado(int qx, int qy, int tamanhoQuadrado){
    if (this->velocidade < VELOCIDADE_MINIMA){
            if (this->y == qy && this->x < (qx + tamanhoQuadrado))
                this->x+=1;
            else if (this->x == (qx + tamanhoQuadrado) && this->y < (qy + tamanhoQuadrado))
                this->y+=1;
            else if (this->x > qx && y == (qy + tamanhoQuadrado))
                this->x-=1;
            else if (this->y > qy && this->x == qx)
                this->y-=1;
            emit updateGUI(this->ID, this->x, this->y);
            usleep(velocidade);
    }else{
            usleep(velocidade);
    }

}
