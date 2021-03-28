#include "estado.h"

Estado::Estado()
{
    for (unsigned long i = 0; i<this->areaCriticaOcupada.size(); i++)
        this->areaCriticaOcupada[i] = -1;
}
