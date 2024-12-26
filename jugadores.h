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
    int salud; /*La salud en este caso es la vida y siempre inicializa con 100 según el PDF*/ 
    accesorio*accesorio_jugador;    
    jugador *prox;
};

jugador *crear_soldado( int sald, string nom){
    jugador *nuevo_jugador =new jugador;
    nuevo_jugador->nombre=nom;
    nuevo_jugador->salud=sald;    
    nuevo_jugador->prox=NULL;    
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
    int cantidad;
    cout<<"Cantidad de soldados a ingresar  en el equipo: ";
    cin>>cantidad;
    for(int i=0;i<cantidad;i++)
    {
        jugador*nueva_soldado=crear_soldado(pedir_vida(),pedir_nombre_soldado());
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
    
}

void insertar_ultimo_soldado_existente(jugador**lista_accesorio,jugador**accesorio_nuevo)
{
    jugador*nuevo_accesorio=(*accesorio_nuevo);    
        if(lista_vacia_jugador(*lista_accesorio))
        {
            (*lista_accesorio)=nuevo_accesorio;
        }
        else{
            jugador*mover=(*lista_accesorio);
            while(mover->prox!=NULL)
            {
                mover=mover->prox;
            }
            mover->prox=nuevo_accesorio;        
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
           cout <<" salud: "<<mover->salud <<endl;           
           mover = mover->prox;
         }
   }  
  else
     cout<<"No existen soldados"<<endl;
}
/*---------------------- FUNCION MOSTRAR SOLADADO_ARMAS_ACCESORIOS -------------------*/
void mostrarListaJugador_armas_accesorios(jugador *lista)
{
    system("cls");
    jugador *mover;accesorio*mover3;

   if (!lista_vacia_jugador(lista)){
      mover = lista;
      cout<<"Lista de Soldados: "<<endl;
      while (mover != NULL)
        {
           cout <<" Nombre: "<<mover->nombre <<" "<<endl;
           cout <<" salud: "<<mover->salud <<" "<<endl;           
           cout <<"-------------------------------------------->"<<endl;          
           mover3=mover->accesorio_jugador;//a mover 3 le paso la lista de accesorio del jugador
           if(mover3!=NULL)
           {
             while(mover3!=NULL)
                {
                    cout<<endl<<"accesorios y propiedades"<<endl;
                    cout<<"Codigo: "<<mover3->codigo<<endl;
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


/*---------------------- FUNCION BUSCAR SOLDADO-------------------*/
jugador *buscar_jugador(jugador *lisita_jugador,string nombre)
{
    jugador *mover=lisita_jugador;bool encontrado=false;
    if(lista_vacia_jugador(lisita_jugador)){
        return NULL;
    }
    else{
        while(mover!=NULL && encontrado==false)
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

void insertar_arma_accesorio_jugador_final(jugador**soldado)
{
    int cantidad;
    cout<<"Cantidad de soldados a ingresar  en el equipo: ";
    cin>>cantidad;
    for(int i=0;i<cantidad;i++)
    {
        jugador*nueva_soldado=crear_soldado(pedir_vida(),pedir_nombre_soldado());
        if(lista_vacia_jugador(*soldado))
        {
            (*soldado)=nueva_soldado;            
            agregar_accesorio_soldado_con_nombre(&(*soldado),nueva_soldado->nombre);
            
        }
        else{
            jugador*mover=(*soldado);
            while(mover->prox!=NULL)
            {
                mover=mover->prox;
            }
            mover->prox=nueva_soldado;            
            agregar_accesorio_soldado_con_nombre(&(mover),nueva_soldado->nombre);
        }

    }
    
}

void insertar_arma_accesorio_jugador_final_sin_ciclo_for(jugador**soldado)
{
    
        jugador*nueva_soldado=crear_soldado(pedir_vida(),pedir_nombre_soldado());
        if(lista_vacia_jugador(*soldado))
        {
            (*soldado)=nueva_soldado;            
            agregar_accesorio_soldado_con_nombre(&(*soldado),nueva_soldado->nombre);
            
        }
        else{
            jugador*mover=(*soldado);
            while(mover->prox!=NULL)
            {
                mover=mover->prox;
            }
            mover->prox=nueva_soldado;            
            agregar_accesorio_soldado_con_nombre(&(mover),nueva_soldado->nombre);
        }

    
    
}

/*---------------------- FUNCION ELIMINAR SOLDADO(TODO)-------------------*/
void eliminar_jugador(jugador**lista_soldado,string nombre)
{
    jugador*anterior=NULL;jugador*actual=NULL;   
    accesorio*borrar_accesorio=NULL;
    if(lista_vacia_jugador(*lista_soldado))
    {
        cout<<"No hay soldados a eliminar"<<endl;
        return;
    }    
    else{
        actual=(*lista_soldado);
        while(actual!=NULL && actual->nombre!=nombre)
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
        while(opcion!='6')
        {
            system("cls");
            cout << "Seleccione el campo a modificar:" << endl;
            cout << "0. Modificar nombre" << endl;
            cout << "1. Modificar salud " << endl;            
            cout << "2. Agregar accesorios" << endl;
            cout << "3. Modificar accesorios" << endl;
            cout << "4. Mostrar soldado" << endl;
            cout << "5. Eliminar soldado" << endl;
            cout << "6. Salir" << endl;
            cout << "Ingrese su opcion: ";
            cin>>opcion;
            switch (opcion)
            {
            case '0':
                {
                    system("cls");
                    string nombre;
                    nombre=pedir_nombre_soldado();
                    soldado_actual->nombre=nombre;
                    break;
                }
            case '1':
                {
                    system("cls");
                    int salud;
                    salud=pedir_vida();
                    soldado_actual->salud=salud;
                    break;
                }        
                    
            case '2':
                {
                    system("cls");
                    agregar_accesorio_soldado_con_nombre(&(soldado_actual),soldado_actual->nombre);
                    break;
                }
            case '3':
                {
                    system("cls");
                    modificar_accesorio(&(soldado_actual)->accesorio_jugador);
                    break;
                }
            case '4':
                {
                    system("cls");
                    mostrarListaJugador_armas_accesorios((soldado_actual));
                    system("pause");
                    break;
                }
            case '5':
                {
                    system("cls");
                    eliminar_jugador(&(*lista_soldados),soldado_actual->nombre);
                    system("pause");
                    opcion = '6';
                    break;
                }

            case '6':
                {
                    system("cls");
                    cout<<"Salir"<<endl;
                    system("pause");
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
