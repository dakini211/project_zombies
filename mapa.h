#ifndef mapa_h
#define mapa_h
#include "zombies.h"
#include <iostream>
using namespace std;

struct mapa{
    string nombre_estacion;
    mapa *proximo;
    zombies *zombies_estacion;
};

string pedir_dato_estacion(){
    string dato_estacion;
    cout << "Ingrese el nombre de la estacion: ";
    cin >> dato_estacion;
    return dato_estacion;
}

mapa *crear_jugador(string nom){
    mapa *nueva_estacion =new mapa;
    nueva_estacion->nombre_estacion=nom;
    nueva_estacion->proximo=NULL;
    nueva_estacion->zombies_estacion=NULL;
    return nueva_estacion;
}

bool lista_vacia_mapa(mapa *lista){
    return lista==NULL;
}

void insertar_Ultimo_mapa(mapa *&inicio, string nom){
    mapa *nuevo = crear_jugador(nom);
 
    if (lista_vacia_mapa(inicio)) {
        inicio = nuevo;
    } 
    else {
        mapa *mover = inicio;
        while (mover->proximo != NULL) {
            mover = mover->proximo;
        }
        mover->proximo = nuevo;
    } 
}

void eliminar_estacion(mapa **lista_map, string nom_estacion){
    mapa *mover,*anterior = NULL;
    zombies *borrar_zombies=NULL; 
   
    if (lista_vacia_mapa(*lista_map)){
        cout<<"No hay estaciones disponibles"<<endl;
    }

    else {   
        mover = *lista_map;
        while (mover != NULL && mover->nombre_estacion != nom_estacion){
            anterior = mover;
            mover = mover->proximo;
        }

        if (mover == NULL){
            cout<<endl<<"La estacion no esta disponibles en el mapa";
        }
            
        else{ 
        borrar_zombies = mover->zombies_estacion;
            if (mover == *lista_map){
                *lista_map=(*lista_map)->proximo;
            }

            else{
                anterior->proximo = mover->proximo;
            }
               
            if(borrar_zombies != NULL){  
                zombies *aux= borrar_zombies;
                while (aux != NULL){
                    borrar_zombies = aux->prox;
                    delete aux;
                    aux= borrar_zombies; 
                }

            }  
            delete mover;        
              
        }      
    }

}

mapa *devolver_estacion_mapa(mapa*lista_grupo,string nombre){
    mapa *mover=lista_grupo; 
    bool encontrado=false;
    if(lista_vacia_mapa(lista_grupo)){
        return NULL;   
    }
    else{
        while(mover!=NULL && encontrado==false){
            if(mover->nombre_estacion==nombre){
                encontrado=true;
            }
            else{
                mover=mover->proximo;
            } 
        }
        return mover;
    }
}

void existe_estacion(mapa *lista, string valor_1) {
    mapa *buscar_2 = lista;
    bool encontrado_2 = false;

    while (buscar_2 != NULL && !encontrado_2) {
        if (buscar_2->nombre_estacion == valor_1) {
            encontrado_2 = true;
            cout << "\e[47m \e[0m";
            cout << "\e[41mEsta estacion ya existe\e[0m";
            cout << "\e[47m \e[0m\n\n";
        }
        buscar_2 = buscar_2->proximo;
    }

    if (!encontrado_2) {
        cout << "\n";
        cout << "\e[47m \e[0m";
        cout << "\e[42mEl nombre de la estacion se modificó con éxito!!!\e[0m";
        cout << "\e[47m \e[0m\n\n";
    }
}

void buscar_estacion(mapa *list, string actual) {
    mapa *buscar = list;
    bool encontrado = false;

    if (lista_vacia_mapa(list)) {
        cout << "\e[47m \e[0m";
        cout << "\e[41mNo se han introducido datos de la estacion\e[0m";
        cout << "\e[47m \e[0m\n\n";
    } else {
        while (buscar != NULL && !encontrado) {
            if (buscar->nombre_estacion == actual) {
                encontrado = true;
                string nuevo_nombre;
                cout << "Ingrese el nuevo nombre de la estacion: ";
                cin >> nuevo_nombre;
                existe_estacion(list, nuevo_nombre);
                buscar->nombre_estacion = nuevo_nombre;
            } 
            else {
                buscar = buscar->proximo;
            }
        }
        if (!encontrado) {
            cout << "\e[47m \e[0m";
            cout << "\e[41mLa estacion no fue encontrada en la lista\e[0m";
            cout << "\e[47m \e[0m\n\n";
        }
    }
}

void modificar_estacion(mapa *inicio) { 
    string nombre_a_modificar;
    cout << "Ingrese el nombre de la estacion que desea modificar: ";
    cin >> nombre_a_modificar;
    buscar_estacion(inicio, nombre_a_modificar);
}

void agregar_zombies_mapa(zombies *list_zombie, mapa *&list_mapa){
    mapa *ubicacion=NULL;
    int numero_zombies_estacion;
    int numero_zombies;
    string estacion;
    cout<<"Ingrese el nombre de la estacion a insertar zombies: ";
    cin>>estacion;
    ubicacion=devolver_estacion_mapa(list_mapa, estacion);

    if(ubicacion==NULL){
        cout<<"No hay estaciones disponibles"<<endl;
        return;
    }

    zombies *lista_zombies_mapa=ubicacion->zombies_estacion;
    cout<<"Indica nivel de peligro del zombies: ";
    cin>>numero_zombies_estacion;
    zombies *buscar_nivel_zombie=buscar_zombie_para_mapa(list_zombie, numero_zombies_estacion);

    if(buscar_nivel_zombie==NULL){
        cout<<"No hay zombies con ese nivel de peligro"<<endl;
        return;
    }

           
    cout<<"Cantidad de zombies: ";
    cin>>numero_zombies_estacion;
    if (numero_zombies_estacion < 0) {
        cout << "No puedes pedir un numero negativo" << endl;
        return;
    }
    numero_zombies=contar_zombies(list_zombie, buscar_nivel_zombie->nivel);
    if (numero_zombies_estacion > numero_zombies) {
        cout << "No puedes pedir un numero mayor a la cantidad de zombies\n";
        return;
    }
    for (int i = 0; i < numero_zombies_estacion; i++) {
        insertar_ultimo_zombie_mapa(&lista_zombies_mapa, buscar_nivel_zombie);
    }
    ubicacion->zombies_estacion = lista_zombies_mapa;

    cout << "Zombies agregados a la estación " << estacion << " exitosamente." << endl;
}



void mostrar_mapa(mapa *list){
   mapa *mover_estacion;
   zombies *mover_zombies;

    if (!lista_vacia_mapa(list)){
        mover_estacion = list;
        while (mover_estacion != NULL){
            cout <<"\n\n\e[47m[Estacion "<<mover_estacion->nombre_estacion <<"]\e[0m\n";  
            cout<<"******************************************************************************\n"; 
            mover_zombies = mover_estacion->zombies_estacion;  
            if (mover_zombies != NULL){
                while(mover_zombies!=NULL){
                    cout << "[tipo zombie: "<<mover_zombies->nombre<<"; nivel de peligro: "<<mover_zombies->nivel<<"; salud: "<<mover_zombies->salud<<"; Dano de ataque: "<<mover_zombies->dano_ataque<<"]\n";
                    mover_zombies = mover_zombies->prox;
                }
            }
            else{
                cout<<endl<<"La estacion aun no tiene zombies"<<endl;
            }
           cout<<"******************************************************************************\n";   
           mover_estacion = mover_estacion->proximo;
        }   
    }
    else{
        cout<<"La lista de estaciones esta vacia"<<endl;
    }
}

void modificar_zomb(zombies *list, zombies *nueva_info) {
    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nivel == nueva_info->nivel) {
            mover->nombre = nueva_info->nombre;
            mover->nivel = nueva_info->nivel;
            mover->salud = nueva_info->salud;
            mover->dano_ataque = nueva_info->dano_ataque;
        }
        mover = mover->prox;
    }
}

void eliminar_zombie_mapa(mapa *&lista){
    
    while(lista->zombies_estacion!=NULL){
        zombies *aux=lista->zombies_estacion;
        lista->zombies_estacion=aux->prox;
        delete aux;
    }
}

void modificar_zombi(mapa *&lista) {
    mapa *ubicacion = NULL;
    string estacion;

    cout << "Ingrese el nombre de la estacion a eliminar zombies: ";
    cin >> estacion;
    ubicacion = devolver_estacion_mapa(lista, estacion);
    
    if (ubicacion == NULL) {
        cout << "No hay estaciones disponibles" << endl;
        return;
    }

    eliminar_zombie_mapa(ubicacion);
}


#endif 
