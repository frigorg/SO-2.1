#ifndef ESTADO_H
#define ESTADO_H

#include "util.h"
#include <deque>

class Estado
{
public:
    Estado();

    //Armazena o trem que está usando o segmento e o próprio segmento
    std::deque<std::pair<int,Segmento>> listaSegmentosTrilho;

    //Armazena as coordenadas dos trens e seus tamanhos
    std::deque<std::pair<Coordenada,int>> listaTrens;

    int areaCritica1;
    int areaCritica2;
    int areaCritica3;
    int areaCritica4;
    int areaCritica5;
    int areaCritica6;
    int areaCritica7;
};

#endif // ESTADO_H
