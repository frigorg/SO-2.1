#ifndef CONTROLE_H
#define CONTROLE_H

#include "util.h"
#include "estado.h"
#include <QMutex>
#include <array>

class Controle
{
public:

    Controle(Estado* estado);

    //Verifica se há uma colisão na coordenada dada considerando as dimensões dos trens
    //ID é o identificador do trem que quer fazer o movimento
    //retorna true para sim e false pra não
    bool colisaoTrem(int ID, int x, int y);
    bool colisaoTrem(int ID, Coordenada coordTremMovendo);

    //Verifica se há colisão entre os dois blocos
    //retorna true para sim e false pra não
    bool colisaoBlocos(int altura1, int comprimento1, Coordenada c1, int altura2, int comprimento2, Coordenada c2);
    bool colisaoBlocos(Bloco bloco1, Bloco bloco2);

    //Testa se existe uma área crítica na coordenada de parâmetro e escolhe entre acessar a área, liberar o acesso ou não fazer nada
    //ID é o identificador do trem que quer fazer o movimento
    void testeAreaCritica(int ID, int x, int y);
    void testeAreaCritica(int ID, Coordenada coordenada);

    //Caso o trem já esteja na área crítica, faz nada
    //Caso o trem está entrado na área, muda o estado da área crítica para o ID do trem e fecha o mutex
    void acessoAreaCritica(int index, int ID);

    //Caso o trem não esteja em uma áera crítica, faz nada
    //Caso o trem esteja saindo de uma área crítica muda do estado da área para -1 e abre o mutex
    void liberarAreaCritica(int index, int ID);

    void checarDeadlock(int index, int ID);

private:
    Estado* estado;
};

#endif // CONTROLE_H
