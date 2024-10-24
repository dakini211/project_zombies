#ifndef JUGADORES_H
#define JUGADORES_H
#include "accesorios.h"
#include "armas.h"
#include <iostream>
#include <fstream>
using namespace std;

struct jugador{
    string nombre;
    int salud=100; /*La salud en este caso es la vida y siempre inicializa con 100 según el PDF*/    
    int afectacion=0; /*Afectacion viene siendo los daños que resive el jugador*/
    float reduccion_dano=0.00;
    arma*arma_jugador;
    accesorio*accesorio_jugador;    
    jugador *prox;
};

jugador *crear_soldado(string nom, int sald, int afect){
    jugador *nuevo_jugador =new jugador;
    nuevo_jugador->nombre=nom;
    nuevo_jugador->salud=sald;
    nuevo_jugador->afectacion=afect;
    nuevo_jugador->prox=NULL;
    nuevo_jugador->arma_jugador=NULL;
    nuevo_jugador->accesorio_jugador=NULL;
    return nuevo_jugador;    
}

bool lista_vacia_jugador(jugador *soldado){
    return soldado==NULL;
}
int pedir_vida()
{
    int vida;
    cout<<"escriba cantidad de vida:  ";
    cin>>vida;
    return vida;
}
int pedir_reduccion_dano()
{
    int red_dano;
    cout<<"modificador de reduccion ";
    cin>>red_dano;
    return red_dano;
}
string pedir_nombre_soldado()
{
    string nombre;
    cout<<"escriba nombre del soldado ";
    cin>>nombre;
    return nombre;
}
void insertar_ultimo_jugador(jugador**soldado)
{
    jugador*nueva_soldado=crear_soldado(pedir_nombre_soldado(),pedir_vida(),pedir_reduccion_dano());
    if(lista_vacia_jugador(*soldado))
    {
        (*soldado)=nueva_soldado;
    }
    else{
        jugador*mover=(*soldado);
        while(mover->prox!=NULL)
        {
            mover=mover->prox;
        }
        mover->prox=nueva_soldado;
    }
}

void mostrarListaJugador(jugador *lista){
   // Mostrar lista de estudiantes solamente
   jugador *mover;

   if (!lista_vacia_jugador(lista)){
       mover = lista;
      cout<<"Soldado "<<endl;
      while (mover != NULL)
        {
           cout <<" Nombre: "<<mover->nombre <<" ";
           cout <<" salud: "<<mover->salud <<" ";
           cout <<" reduccion: "<<mover->reduccion_dano <<endl;
           mover = mover->prox;
         }

   }  
  else
     cout<<"No existen estudiantes inscritos"<<endl;
}

void mostrarListaJugador_armas_accesorios(jugador *lista)
{
    jugador *mover;arma*mover2;accesorio*mover3;

   if (!lista_vacia_jugador(lista)){
      mover = lista;
      cout<<"Lista de Estudiantes: "<<endl;
      while (mover != NULL)
        {
           cout <<" Nombre: "<<mover->nombre <<" ";
           cout <<" salud: "<<mover->salud <<" ";
           cout <<" reduccion: "<<mover->reduccion_dano <<endl;
           cout <<"-------------------------------------------->"<<endl;
           mover2=mover->arma_jugador;//a mover 2 le paso la lista de arma del jugador
           if(mover2!=NULL)
           {
            while(mover2!=NULL)
                {
                    cout<<endl<<"arma y propiedades"<<endl;
                    cout<<"arma: "<<mover2->nombre_arma<<endl;
                    cout<<"tipo de arma: "<<mover2->tipo_arma<<endl;
                    cout<<"arma: "<<mover2->dano<<endl;
                    cout <<"-------------------------------------------->"<<endl;
                    mover2=mover2->sgte;
                }
           }
           else{
             cout<<"arma no disponible"<<endl;
             cout <<"-------------------------------------------->"<<endl;
           }           
           mover3=mover->accesorio_jugador;//a mover 3 le paso la lista de accesorio del jugador
           if(mover3!=NULL)
           {
             while(mover3!=NULL)
                {
                    cout<<endl<<"accesorios y propiedades"<<endl;
                    cout<<"nombre: "<<mover3->nombre<<endl;
                    cout<<"tipo: "<<mover3->tipo<<endl;
                    cout<<"modificador de daño: "<<mover3->modificador_dano<<endl;
                    cout<<"modificador de vida: "<<mover3->modificador_vida<<endl;
                    cout<<"reduccion al daño: "<<mover3->modificador_reduccion_dao<<endl;
                    cout <<"-------------------------------------------->"<<endl;
                    mover3=mover3->prox;
                }
           }
           else{
            cout<<"accesorio no disponible"<<endl;
            cout <<"-------------------------------------------->"<<endl;
           }           
           mover = mover->prox;
         }

   }  

}

jugador *buscar_jugador(jugador *lisita_jugador,string nombre)
{
    jugador *mover=lisita_jugador;bool encontrado=false;
    if(lista_vacia_jugador(lisita_jugador)){
        return NULL;
    }
    else{
        while(mover!=NULL and encontrado==false)
        {
            if(mover->nombre==nombre)
            {
                encontrado=true;
            }
            else{
                mover=mover->prox;
            }
        
        }
    return mover;
    }   
}
void agregar_arma_soldado(jugador**lista_soldados)
{
    arma*arma_nueva=NULL;
    jugador*soldado_actual=NULL;
    string nombre;
    cout<<"elija nombre de jugador a buscar: ";
    cin>>nombre;
    soldado_actual=buscar_jugador(*lista_soldados,nombre);
    if(soldado_actual==NULL)
    {
        cout<<"soldado no encontrado"<<endl;        
    }
    else{
        insertar_ultimo_armas(&arma_nueva);
        (soldado_actual)->arma_jugador=arma_nueva;
    }
}

void agregar_accesorio_soldado(jugador**lista_soldados)
{
    accesorio*accesorio_nuevo=NULL;
    jugador*soldado_actual=NULL;
    string nombre;
    cout<<"elija nombre de jugador a buscar: ";
    cin>>nombre;
    soldado_actual=buscar_jugador(*lista_soldados,nombre);
    if(soldado_actual==NULL)
    {
        cout<<"soldado no encontrado"<<endl;        
    }
    else{
        //insertar_ultimo_accesorio(&accesorio_nuevo);
        //(soldado_actual)->arma_jugador=arma_nueva;
    }
}

void eliminar_jugador(jugador**lista_soldado,string nombre)
{
    jugador*anterior=NULL;jugador*actual=NULL;
    arma*borrar_arma=NULL;
    accesorio*borrar_accesorio=NULL;
    if(lista_vacia_jugador(*lista_soldado))
    {
        cout<<"No hay soldados a eliminar"<<endl;
        return;
    }
    else{
        actual=(*lista_soldado);
        while(actual!=NULL and actual->nombre!=nombre )
        {
            anterior=actual;
            actual=actual->prox;
        }
        if(actual==NULL)
        {
            cout<<"Soldado no encontrado"<<endl;
            return;
        }
        else{
            borrar_accesorio=actual->accesorio_jugador;
            borrar_arma=actual->arma_jugador;
            if(actual==(*lista_soldado))
            {
                (*lista_soldado)=(*lista_soldado)->prox;
            }
            else{
                anterior->prox=actual->prox;
                if(borrar_accesorio!=NULL)
                {
                    accesorio*aux=borrar_accesorio;
                    while(aux!=NULL)
                    {
                        borrar_accesorio=borrar_accesorio->prox;
                        delete aux;
                        aux=borrar_accesorio;
                    }
                    
                }
                if(borrar_arma!=NULL)
                {
                    arma*aux=borrar_arma;
                    while(aux!=NULL)
                    {
                        borrar_arma=borrar_arma->sgte;
                        delete aux;
                        aux=borrar_arma;
                    }                    
                }
                
            }
            delete actual;
        }
    }
}





#endif 