#ifndef GRUPOS_H
#define GRUPOS_H
#include "jugadores.h"
#include <iostream>
#include <fstream>
using namespace std;

struct grupos{//nuevo
    string nombre_grupo;
    grupos *sig;
    jugador *grupo_jugador;
};




#endif 