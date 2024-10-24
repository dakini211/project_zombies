#ifndef GRUPOS_H
#define GRUPOS_H
#include "jugadores.h"
#include <iostream>
#include <fstream>
using namespace std;

struct grupo{
    string nombre_grupo;
    jugador *grupo_jugador;
    grupo *prox;
    
};

grupo *crear(string nombre)
{
    grupo *nuevo_grupo=new grupo;
    nuevo_grupo->nombre_grupo=nombre;
    nuevo_grupo->grupo_jugador=NULL;
    nuevo_grupo->prox=NULL;
    return nuevo_grupo;
}




#endif 