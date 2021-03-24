#ifndef TREM_H
#define TREM_H

#include <QThread>

class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int);
    void run();
    void setVelocidade(int valor);
    int getTamanhoTrem();
    std::pair<int,int> getCoordenadas();

signals:
    void updateGUI(int,int,int);

private:
   int ID;
   int x;
   int y;
   float velocidade;
   int const TAMANHO_QUADRADO = 245;
   int const VELOCIDADE_MINIMA = 5000;
   int const TAMANHO_TREM = 50;

   void checarLimitesQuadrado(int qx, int qy, int tamanhoQuadrado);
};

#endif // TREM_H
