#ifndef JUGADORES_H
#define JUGADORES_H
#include "accesorios.h"
#include "armas.h"
#include <iostream>
#include <fstream>
using namespace std;
/*-------------------- STRUCT,CREACION Y LISTA_VACIA------------------*/
struct jugador{
    string nombre;
    int salud=100; /*La salud en este caso es la vida y siempre inicializa con 100 según el PDF*/    
    //int afectacion=0; /*Afectacion viene siendo los daños que resive el jugador*//no se si ponerlo
    int reduccion_dano=0;
    arma*arma_jugador;
    accesorio*accesorio_jugador;    
    jugador *prox;
};

jugador *crear_soldado(int reduccion_dano, int sald, string nom){
    jugador *nuevo_jugador =new jugador;
    nuevo_jugador->nombre=nom;
    nuevo_jugador->salud=sald;
    nuevo_jugador->reduccion_dano=reduccion_dano;
    nuevo_jugador->prox=NULL;
    nuevo_jugador->arma_jugador=NULL;
    nuevo_jugador->accesorio_jugador=NULL;
    return nuevo_jugador;    
}

bool lista_vacia_jugador(jugador *soldado){
    return soldado==NULL;
}
/*-------------------- FUNCIONES PEDIR  ------------------*/
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
/*-------------------- FUNCION INSERTAR ------------------*/
void insertar_ultimo_jugador(jugador**soldado)
{
    jugador*nueva_soldado=crear_soldado(pedir_reduccion_dano(),pedir_vida(),pedir_nombre_soldado());
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
/*---------------------- FUNCION MOSTRAR SOLADADO(SOLO) -------------------*/
void mostrarListaJugador(jugador *lista){
   // Mostrar lista de jugadores solamente
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
     cout<<"No existen soldados"<<endl;
}
/*---------------------- FUNCION MOSTRAR SOLADADO_ARMAS_ACCESORIOS -------------------*/
void mostrarListaJugador_armas_accesorios(jugador *lista)
{
    jugador *mover;arma*mover2;accesorio*mover3;

   if (!lista_vacia_jugador(lista)){
      mover = lista;
      cout<<"Lista de Soldados: "<<endl;
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
                    cout<<"dano: "<<mover2->dano<<endl;
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
                    cout<<"Modificador: "<<mover3->modificador<<endl;
                     cout<<"Usos: "<<mover3->usos<<endl;
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
/*---------------------- FUNCION MOSTRAR SOLDADO_ARMAS-------------------*/
void mostrar_lista_arma_jugador(jugador*soldado)
{
    jugador*mover=(soldado);arma*arma_actual=NULL;
    while(mover!=NULL)
    {
        cout<<"nombre soldado: "<<mover->nombre<<endl;        
        arma_actual=mover->arma_jugador;
        if(mover->arma_jugador==NULL)
        {
            cout<<"arma no disponible"<<endl;
        }
        else{
             while(arma_actual!=NULL)
                {
                    cout<<endl<<"arma y propiedades"<<endl;
                    cout<<"arma: "<<arma_actual->nombre_arma<<endl;
                    cout<<"tipo de arma: "<<arma_actual->tipo_arma<<endl;
                    cout<<"dano: "<<arma_actual->dano<<endl;
                    cout <<"-------------------------------------------->"<<endl;
                    arma_actual=arma_actual->sgte;
                }
        }
        mover=mover->prox;
    }

}
/*---------------------- FUNCION BUSCAR SOLDADO-------------------*/
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
/*---------------------- FUNCION AGREGAR ARMA A SOLDADO-------------------*/
void agregar_arma_soldado(jugador**lista_soldados)
{
    //arma*arma_nueva=NULL; esto por si hay que hacer la lsita unica
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
        int cantidad_armas=0;
        cout<<"cuantas armas desea equipar  ?: ";
        cin>>cantidad_armas;
        for(int i=0;i<cantidad_armas;i++)
        {
            insertar_ultimo_armas(&(soldado_actual)->arma_jugador);
            // insertar_ultimo_armas(arma_nueva)//para reescribir la lista osea que la lista sea unica, solo modifica y elimnar, no agregar
        }
        
        //(soldado_actual)->arma_jugador=arma_nueva; esto si quieren reescribir la lita por una nueva 
    }
}
void agregar_arma_soldado_con_nombre(jugador**lista_soldados,string nombre)
{
    //arma*arma_nueva=NULL; esto por si hay que hacer la lsita unica
    jugador*soldado_actual=NULL;    
    soldado_actual=buscar_jugador(*lista_soldados,nombre);
    if(soldado_actual==NULL)
    {
        cout<<"soldado no encontrado"<<endl;        
    }
    else{
        int cantidad_armas=0;
        cout<<"cuantas armas desea equipar  ?: ";
        cin>>cantidad_armas;
        for(int i=0;i<cantidad_armas;i++)
        {
            insertar_ultimo_armas(&(soldado_actual)->arma_jugador);
            // insertar_ultimo_armas(arma_nueva)//para reescribir la lista osea que la lista sea unica, solo modifica y elimnar, no agregar
        }
        
        //(soldado_actual)->arma_jugador=arma_nueva; esto si quieren reescribir la lita por una nueva 
    }
}
/*---------------------- FUNCION AGREGAR ACCESORIO A SOLDADO-------------------*/
void agregar_accesorio_soldado(jugador**lista_soldados)
{
    //accesorio*accesorio_nuevo=NULL;
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
        int cantidad;
        cout<<"ingrese cantidad de accesorios a crear: ";
        cin>>cantidad;
        for(int i=0;i<cantidad;i++)
        {
            insertar_ultimo_accesorio(&(soldado_actual)->accesorio_jugador);
        }
        
        
    }
}
void agregar_accesorio_soldado_con_nombre(jugador**lista_soldados,string nombre)
{
    //accesorio*accesorio_nuevo=NULL;
    jugador*soldado_actual=NULL;    
    soldado_actual=buscar_jugador(*lista_soldados,nombre);
    if(soldado_actual==NULL)
    {
        cout<<"soldado no encontrado"<<endl;        
    }
    else{
        int cantidad;
        cout<<"ingrese cantidad de accesorios a crear: ";
        cin>>cantidad;
        for(int i=0;i<cantidad;i++)
        {
            insertar_ultimo_accesorio(&(soldado_actual)->accesorio_jugador);
        }
        
        
    }
}
/*---------------------- FUNCION ELIMINAR SOLDADO(TODO)-------------------*/
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
/*---------------------- FUNCION MODIFICAR SOLDADO-------------------*/
void modificar_soldado(jugador**lista_soldados)
{
    string nombre_soldado;
    cout<<"ingrese el nombre del soldado a buscar: ";
    cin>>nombre_soldado;
    jugador*soldado_actual=buscar_jugador(*lista_soldados,nombre_soldado);
    if(soldado_actual==NULL)
    {
        cout<<"Soldado no encontrado"<<endl;
        return;
    }
    else{
        cout<<"¿Que desea modificar del soldado "<<soldado_actual->nombre;
        char opcion;
        while(opcion!='9')
        {
            system("cls");
            cout << "Seleccione el campo a modificar:" << endl;
            cout << "1. Modificar nombre" << endl;
            cout << "2. Modificar salud " << endl;
            cout << "3. Modificar reduccion al dano" << endl;
            cout << "4. Agregar armas" << endl;
            cout << "5. Modificar armas" << endl;
            cout << "6. Agregar accesorios" << endl;
            cout << "7. Modificar accesorios" << endl;
            cout << "8. Mostrar soldado" << endl;
            cout << "9. Salir" << endl;
            cout << "Ingrese su opcion: ";
            cin>>opcion;
            switch (opcion)
            {
            case '1':
                {
                    string nombre;
                    nombre=pedir_nombre_soldado();
                    soldado_actual->nombre=nombre;
                    break;
                }
            case '2':
                {
                    int salud;
                    salud=pedir_vida();
                    soldado_actual->salud=salud;
                    break;
                }
            case '3':
                {
                    int reduccion_dano;
                    reduccion_dano=pedir_reduccion_dano();
                    soldado_actual->reduccion_dano=reduccion_dano;
                    break;
                }
            case '4':
                {
                    agregar_arma_soldado_con_nombre(&(soldado_actual),soldado_actual->nombre);
                    break;
                }
            case '5':
                {
                    modificar_arma(&(soldado_actual)->arma_jugador);
                    break;
                }
            case '6':
                {
                    agregar_accesorio_soldado_con_nombre(&(soldado_actual),soldado_actual->nombre);
                    break;
                }
            case '7':
                {
                    modificar_accesorio(&(soldado_actual)->accesorio_jugador);
                    break;
                }
            case '8':
                {
                    mostrarListaJugador_armas_accesorios((soldado_actual));
                    system("pause");
                    break;
                }
            case '9':
                {
                    cout<<"Salir"<<endl;
                    break;
                }
            
            default:
                break;
            }
        }
    }
}
void vacia()
{
    
}



#endif 