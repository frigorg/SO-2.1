#include "controle.h"

Controle::Controle(Estado* estado){
    this->estado = estado;
}

bool Controle::colisaoTrem(int ID, int x, int y){
    Coordenada c;
    c.x = x;
    c.y = y;
    return this->colisaoTrem(ID, c);
}

bool Controle::colisaoTrem(int ID, Coordenada coordTremMovendo){
    for (unsigned long i = 0; i < estado->listaTrens.size(); i++){
        if ((int)i != ID){
           Coordenada coordTremTeste = estado->listaTrens[i].first;
           int tamTremTeste = estado->listaTrens[i].second;

           int tamTremMovendo = estado->listaTrens[ID].second;

            if (((coordTremMovendo.x >= coordTremTeste.x) && (coordTremMovendo.x <= coordTremTeste.x + tamTremTeste) &&
                (coordTremMovendo.y >= coordTremTeste.y) && (coordTremMovendo.y <= coordTremTeste.y + tamTremTeste)) ||
                ((coordTremMovendo.x + tamTremMovendo >= coordTremTeste.x) && (coordTremMovendo.x + tamTremMovendo  <= coordTremTeste.x + tamTremTeste) &&
                (coordTremMovendo.y + tamTremMovendo  >= coordTremTeste.y) && (coordTremMovendo.y + tamTremMovendo  <= coordTremTeste.y + tamTremTeste)))
                return true;
        }
    }
   return false;
}

bool Controle::colisaoBlocos(int altura1, int comprimento1, Coordenada c1, int altura2, int comprimento2, Coordenada c2){
    Bloco b1;
    b1.altura = altura1;
    b1.comprimento = comprimento1;
    b1.vertice = c1;
    Bloco b2;
    b2.altura = altura2;
    b2.comprimento = comprimento2;
    b2.vertice = c2;
    return this->colisaoBlocos(b1,b2);
}

bool Controle::colisaoBlocos(Bloco bloco1, Bloco bloco2){

    if (((bloco1.vertice.x >= bloco2.vertice.x && bloco1.vertice.x <= (bloco2.vertice.x + bloco2.comprimento)) &&
       (bloco1.vertice.y >= bloco2.vertice.y && bloco1.vertice.y <= (bloco2.vertice.y + bloco2.altura))) ||
       (((bloco1.vertice.x + bloco1.comprimento) >= bloco2.vertice.x && (bloco1.vertice.x + bloco1.comprimento) <= (bloco2.vertice.x + bloco2.comprimento)) &&
       ((bloco1.vertice.y + bloco1.altura) >= bloco2.vertice.y && (bloco1.vertice.y + bloco1.altura) <= (bloco2.vertice.y + bloco2.altura))))
           return true;

    return false;
}

void Controle::testeAreaCritica(int ID, int x, int y){
    Coordenada c;
    c.x = x;
    c.y = y;
    return this->testeAreaCritica(ID, c);
}

void Controle::testeAreaCritica(int ID, Coordenada coordenada){

    std::array<int,7> areaCritica = {0,0,0,0,0,0,0};

    for (unsigned long i = 0; i < this->estado->listaBlocosAreaCritica.size(); i++){
        Bloco b = estado->listaBlocosAreaCritica[i];
        Bloco t;
        t.altura = estado->listaTrens[ID].second;
        t.comprimento= estado->listaTrens[ID].second;
        t.vertice = coordenada;
        if(this->colisaoBlocos(t,b))
            areaCritica[i] = 1;
    }

   for (int i=0; i<7; i++)
       if (areaCritica[i])
           this->acessoAreaCritica(i,ID);
       else
           this->liberarAreaCritica(i,ID);

}

void Controle::acessoAreaCritica(int index, int ID){
    if (this->estado->areaCriticaOcupada[index] == ID)
        return;
    else{
        this->estado->travas[index].lock();
        this->estado->areaCriticaOcupada[index] = ID;
    }
}

void Controle::liberarAreaCritica(int index, int ID){
    if (this->estado->areaCriticaOcupada[index] == ID){
        this->estado->areaCriticaOcupada[index] = -1;
        this->estado->travas[index].unlock();
    }

}
