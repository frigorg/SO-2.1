#ifndef UTIL_H
#define UTIL_H

struct Coordenada {
    int x;
    int y;
};

struct Segmento {
    int id;
    Coordenada p1;
    Coordenada p2;
};

enum Direcao {
    NORTE,
    LESTE,
    SUL,
    OESTE
};

#endif // UTIL_H
