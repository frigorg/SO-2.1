#ifndef ESTADO_H
#define ESTADO_H

#include "util.h"
#include <deque>
#include <array>
#include <QMutex>

class Estado
{
public:
    Estado();

    //
    std::deque<Bloco> listaBlocosAreaCritica;

    //Armazena as coordenadas dos trens e seus tamanhos
    std::deque<std::pair<Coordenada,int>> listaTrens;

    std::array<int,7> areaCriticaOcupada;
    std::array<QMutex,7> travas;

};

#endif // ESTADO_H
