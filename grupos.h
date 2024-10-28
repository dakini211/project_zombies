#ifndef GRUPOS_H
#define GRUPOS_H
#include "jugadores.h"
#include <iostream>
#include <fstream>
using namespace std;

struct grupo{
    string nombre_grupo;    
    jugador *grupo_jugador;
    int numero_miembros;
    grupo *prox;
    
};
bool listaVaciaGrupo(grupo *grupos)
{
    return grupos==NULL;
}


grupo *crear_grupo(string nombre)
{
    grupo *nuevo_grupo=new grupo;
    nuevo_grupo->nombre_grupo=nombre;
    nuevo_grupo->numero_miembros=0;
    nuevo_grupo->grupo_jugador=NULL;
    nuevo_grupo->prox=NULL;
    return nuevo_grupo;
}

string pedir_nombre_grupo()
{
    string nombre;
    cout<<"escribir nombre de grupo: ";
    cin>>nombre;
    return nombre;
}

void mostrar_grupos(grupo*lista_grupo)
{
   
    if(listaVaciaGrupo(lista_grupo))
    {
        cout<<"no hay grupos creados";
        return;
    }
    else{
         grupo*mover=lista_grupo;
         cout<<endl;
         while(mover!=NULL){
            cout<<"[Grupo: "<<mover->nombre_grupo<<"; numero de jugadores: "<< mover->numero_miembros<<"]->";
            mover=mover->prox;
        }
         cout<<"Operativos\n\n";

    }
}
void mostrar_grupo_integrantes(grupo*lista_grupo){
   
    if(listaVaciaGrupo(lista_grupo))
    {
        cout<<"no hay grupos creados"<<endl;
        return;
    }
    else if (lista_vacia_jugador((lista_grupo->grupo_jugador)))
    {
        cout<<"no hay jugadores"<<endl;
        return;
    }  
    
    else{
        grupo*mover=lista_grupo;jugador*soldado=NULL;
        while(mover!=NULL)
         {
            soldado=mover->grupo_jugador;
            mostrarListaJugador_armas_accesorios(soldado);
            mover=mover->prox;
         }
    }
}

void insertar_ultimo_grupos(grupo **lista_grupo)
{
    
    int cantidad;
    cout<<"Inserte la cantidad de Grupos: ";
    cin>>cantidad;
    for(int i=0;i<cantidad;i++)
    {
        grupo*nuevo_grupo=crear_grupo(pedir_nombre_grupo());        
       if(listaVaciaGrupo(*lista_grupo))
       {
        (*lista_grupo)=nuevo_grupo;
        
       }
       else{
        grupo*mover=(*lista_grupo);
        while(mover->prox!=NULL)
        {
            mover=mover->prox;
        }
        mover->prox=nuevo_grupo;
       }
    }
    

}

grupo *buscar_grupo(grupo*lista_grupo,string nombre)
{
    grupo*mover=lista_grupo; bool encontrado=false;
    if(listaVaciaGrupo(lista_grupo))
    {
        cout<<"No hay grupos disponibles"<<endl;
        return NULL;        
    }
    else{
        while(mover!=NULL && encontrado==false)
        {
            if(mover->nombre_grupo==nombre)
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

void insertar_soldado_grupo(grupo**lista_grupo)
{
    string nombre;
    cout<<"escriba nombre del grupo a insertar soldados: ";
    cin>>nombre;
    grupo*grupo_actual=buscar_grupo(*lista_grupo,nombre);
    if(grupo_actual==NULL)
    {
        cout<<"grupo no encontrado"<<endl;    
    }
    else{

        int cantidad;
        cout<<"Cantidad de soldados a ingresar  en el equipo: ";
        cin>>cantidad;
        for(int i=0;i<cantidad;i++)
        {
            insertar_arma_accesorio_jugador_final_sin_ciclo_for(&(grupo_actual->grupo_jugador));
        }
        grupo_actual->numero_miembros=cantidad;
    }
}

void insertar_soldado_grupo_con_nombre(grupo**lista_grupo,string nombre)
{    
    grupo*grupo_actual=buscar_grupo(*lista_grupo,nombre);
    if(grupo_actual==NULL)
    {
        cout<<"grupo no encontrado"<<endl;    
    }
    else{

        int cantidad;
        cout<<"Cantidad de soldados a ingresar  en el equipo: ";
        cin>>cantidad;
        for(int i=0;i<cantidad;i++)
        {
            insertar_arma_accesorio_jugador_final_sin_ciclo_for(&(grupo_actual->grupo_jugador));
        }
        grupo_actual->numero_miembros=cantidad;
    }
}

void eliminar_grupo(grupo**lista_grupo,string nombre_grupo)
{
    grupo*anterior=NULL;
    jugador*borrar_jugador=NULL;
    if(listaVaciaGrupo(*lista_grupo))
    {
        cout<<"No hay grupos para eliminar"<<endl;
    }
    else{
        grupo*actual=(*lista_grupo);
        while(actual!=NULL && actual->nombre_grupo!=nombre_grupo)
        {
            anterior=actual;
            actual=actual->prox;
        }
        if(actual==NULL)
        {
            cout<<"Grupo no encontrado";
        }
        else{
            borrar_jugador=actual->grupo_jugador;
            if(actual==(*lista_grupo))
            {
                (*lista_grupo)=(*lista_grupo)->prox;
            }
            else{
                anterior->prox=actual->prox;
                jugador*aux=borrar_jugador;
                if(borrar_jugador!=NULL)
                {
                    while(aux!=NULL)
                    {
                        borrar_jugador=borrar_jugador->prox;
                        delete aux;
                        aux=borrar_jugador;                    
                    }

                }                
                
            }
            delete actual;
        }
    }
}

void modificar_grupo(grupo ** lista_grupo)
{
    string nombre_grupo;
    cout<<"Ingrese nombre de grupo a modificar: ";
    cin>>nombre_grupo;   
    grupo*grupo_actual=buscar_grupo(*lista_grupo,nombre_grupo);
    if(grupo_actual==NULL)
    {
        cout<<"grupo no encontrado";
    }
    else{
        char opcion;
        while(opcion!='5')
        {
            system("cls");
            cout << "Seleccione el campo a modificar:" << endl;
            cout<<"==================================================="<<"\n";
            cout<<"1. Modificar nombre del grupo"<<endl;
            cout<<"2. Insertar soldados "<<endl;
            cout<<"3. Mochila de jugador"<<endl;
            cout<<"4. Mostrar integrantes del grupo"<<endl;
            cout<<"5. salir"<<endl;
            cout<<"==================================================="<<"\n";
            cin>>opcion;
            switch (opcion)
            {
            case '1':
                {
                    system("cls");
                    string nombre;
                    nombre=pedir_nombre_grupo();
                    grupo_actual->nombre_grupo=nombre;
                    break;
                }
             case '2':
                {
                    system("cls");
                    insertar_soldado_grupo_con_nombre(&grupo_actual, grupo_actual->nombre_grupo);
                    break;
                }
            case '3':
                {
                    system("cls");
                    modificar_soldado(&grupo_actual->grupo_jugador);
                    break;
                }
            case '4':
                {
                    system("cls");
                    mostrar_grupo_integrantes(grupo_actual);
                    system("pause");
                    break;
                }
             case '5':
                {     
                    system("cls");               
                    break;
                }
            default:
                break;

            }
        }
    }    
}


#endif 
