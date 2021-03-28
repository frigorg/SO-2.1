#ifndef TREM_H
#define TREM_H

#include <QThread>
#include "util.h"
#include "controle.h"

class Trem: public QThread{
 Q_OBJECT
public:
    static const int TAMANHO_MAXIMO = 50;
    static const int VELOCIDADE_MINIMA = 5000;

    Trem(int,int,int,Direcao,float,Controle*);
    void run();
    void setVelocidade(int valor);
    int getTamanho();
    Coordenada getCoordenadas();
    void setDirecao(Direcao direcao);


signals:
    void updateGUI(int,int,int);

private:
    int ID;
    int x;
    int y;
    float velocidade;
    Direcao direcao;
    int const TAMANHO_TREM = 20;
    Controle* controle;

    void movimentoHorario(int x, int y);

    void fimDoMovimento();
};

#endif // TREM_H
