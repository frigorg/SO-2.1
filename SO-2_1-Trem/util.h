#ifndef UTIL_H
#define UTIL_H

struct Coordenada {
    int x;
    int y;
};

struct Bloco{
    Coordenada vertice;
    int altura;
    int comprimento;
};

enum Direcao {
    NORTE,
    LESTE,
    SUL,
    OESTE
};

#endif // UTIL_H
