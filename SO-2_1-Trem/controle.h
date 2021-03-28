#ifndef CONTROLE_H
#define CONTROLE_H

#include "util.h"
#include "estado.h"
#include <QMutex>

class Controle
{
public:

    QMutex mutex;

    Controle(Estado* estado);

    //Verifica se há uma colisão na coordenada dada considerando as dimensões dos trens
    //ID é o identificador do trem que quer fazer o movimento
    //retorna true para sim e false pra não
    bool colisaoTrem(int ID, int x, int y);
    bool colisaoTrem(int ID, Coordenada coordTremMovendo);

    //Verifica se há uma colisão com um nó, considerando que o trilho tem um tamanho máximo de Trem::TAMANHO_MAXIMO
    //blocoX e blocoY são as coordenadas do ponto para que se quer mover
    //tamanhoBloco é a dimensão do trem que quer fazer o movimento
    //PontoX e pontoY é o ponto central de um nó na malha ferroviária
    bool colisaoNo(int blocoX, int blocoY, int tamBloco, int pontoX, int pontoY);
    bool colisaoNo(Coordenada cBloco, int tamBloco, Coordenada c);

    //Testa se existe uma área crítica na coordenada
    //ID é o identificador do trem que quer fazer o movimento
    //Retorna o ID da área crítica ou -1 se não existe área na coordenada dada
    int testeAreaCritica(int ID, int x, int y);
    int testeAreaCritica(int ID, Coordenada coordenada);

private:
    Estado* estado;
};

#endif // CONTROLE_H
