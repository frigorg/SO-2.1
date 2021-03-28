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

bool Controle::colisaoNo(int blocoX, int blocoY, int tamBloco, int pontoX, int pontoY){
    Coordenada c1;
    c1.x = blocoX;
    c1.y = blocoY;
    Coordenada c2;
    c2.x = pontoX;
    c2.y = pontoY;
    return this->colisaoNo(c1,tamBloco,c2);
}

bool Controle::colisaoNo(Coordenada cBloco, int tamBloco, Coordenada cPonto){
    int tamMaximoTrem = estado->listaTrens[0].second;

    cPonto.x = cPonto.x - (tamMaximoTrem/2);
    cPonto.y = cPonto.y - (tamMaximoTrem/2);

    if (((cBloco.x >= cPonto.x) && (cBloco.x <= cPonto.x + tamMaximoTrem) &&
        (cBloco.y >= cPonto.y) && (cBloco.y <= cPonto.y + tamMaximoTrem)) ||
        ((cBloco.x + tamBloco >= cPonto.x) && (cBloco.x + tamBloco  <= cPonto.x + tamMaximoTrem) &&
        (cBloco.y + tamBloco  >= cPonto.y) && (cBloco.y + tamBloco  <= cPonto.y + tamMaximoTrem)))
        return true;

    return false;

}

int Controle::testeAreaCritica(int ID, int x, int y){
    Coordenada c;
    c.x = x;
    c.y = y;
    return this->testeAreaCritica(ID, c);
}

int Controle::testeAreaCritica(int ID, Coordenada coordenada){

    for (unsigned long i = 0; i < this->estado->listaSegmentosTrilho.size(); i++){
        Segmento s = estado->listaSegmentosTrilho[i].second;
        if (this->colisaoNo(coordenada, estado->listaTrens[ID].second, s.p1))
            return s.id;
        if (this->colisaoNo(coordenada, estado->listaTrens[ID].second, s.p2))
            return s.id;
    }
    return -1;
}
