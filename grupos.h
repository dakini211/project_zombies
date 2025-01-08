#ifndef GRUPOS_H
#define GRUPOS_H
#include "jugadores.h"
#include "accesorios.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>
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

grupo *buscar_grupo2(grupo**lista_grupo)
{
  
    
    
        if(listaVaciaGrupo(*lista_grupo))
        {
            cout<<"No hay grupos disponibles"<<endl;
            
            return NULL;        
        }
        else{
            mostrar_grupos(*lista_grupo);
            string nombre;
            cout << "Ingrese el nombre del grupo a insertar en estacion: ";
            cin >> nombre;
            grupo*mover=*lista_grupo; bool encontrado=false;
            while(mover!=NULL && encontrado==false)
            {
                if(mover->nombre_grupo==nombre)
                {
                    cout<<"Grupo "<<mover->nombre_grupo<< " encontrado"<<endl;
                    encontrado=true;                    
                    system("pause");
                    system("cls");
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

void insertar_soldado_grupo_sin_arma(grupo**lista_grupo,jugador**nuevo_soldado)
{
    if(listaVaciaGrupo(*lista_grupo))
    {
        cout<<"No hay grupos para insertar soldados"<<endl;
        return;
    }
    else{
                  
        jugador*nuevo=(*nuevo_soldado);
        if(lista_vacia_jugador((*lista_grupo)->grupo_jugador))
        {
            (*lista_grupo)->grupo_jugador=nuevo;
            (*lista_grupo)->numero_miembros++;
        }
        else{
            jugador*mover=(*lista_grupo)->grupo_jugador;
            while(mover->prox!=NULL)
            {
                mover=mover->prox;
            }
            mover->prox=nuevo;
            (*lista_grupo)->numero_miembros++;
        }        
        
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

void insertar_soldado_txt_grupo(jugador** lista_de_jugadores, jugador* nuevo_soldado) {
    jugador* nuevo_soldado_copia = crear_soldado(nuevo_soldado->salud, nuevo_soldado->nombre);
    insertar_ultimo_soldado_existente(&(*lista_de_jugadores), &nuevo_soldado_copia);
}
void insertar_soldado_grupo3(grupo** grupo_actual, jugador** jugador_actual) {
    if (grupo_actual == NULL || *grupo_actual == NULL || jugador_actual == NULL || *jugador_actual == NULL) {
        cout << "Error: Puntero nulo pasado a la función." << endl;
        return;
    }

    jugador* nuevo_soldado = crear_soldado_con_accesorio((*jugador_actual)->salud, (*jugador_actual)->nombre,(*jugador_actual)->accesorio_jugador);    

    if ((*grupo_actual)->grupo_jugador == NULL) {
        (*grupo_actual)->grupo_jugador= nuevo_soldado;
    } else {
        jugador* mover = (*grupo_actual)->grupo_jugador;
        while (mover->prox != NULL) {
            mover = mover->prox;
        }
        mover->prox = nuevo_soldado;
    }
    (*grupo_actual)->numero_miembros++;
}

void crear_grupos_usuario(grupo** grupo_actual, jugador* lista_de_jugadores) {
    grupo* ubicacion = NULL;
    jugador* jugador_actual = lista_de_jugadores;
    string nombre_grupo;
    insertar_ultimo_grupos(&(*grupo_actual));
    
    while (jugador_actual != NULL) {
        system("cls");
        mostrar_grupos(*grupo_actual);
        cout << "Seleccione un grupo para el jugador: " << jugador_actual->nombre << endl;
        cin >> nombre_grupo;

        ubicacion = buscar_grupo(*grupo_actual, nombre_grupo);
        if (ubicacion) {
            insertar_soldado_txt_grupo(&(ubicacion->grupo_jugador), jugador_actual);
            //agregar_accesorio_soldado_TXT(ubicacion->grupo_jugador);
            //pedir_tipo_accesorio();
            //pedir_modificador_accesorio();
            //pedir_usos_accesorio();
            //pedir_tipo_arma();
            ubicacion->numero_miembros++;
            jugador_actual = jugador_actual->prox;
        } else {
            cout << "Grupo no encontrado. Intente nuevamente." << endl;
        }       
        
    }    
    system("cls");
    mostrar_grupos(*grupo_actual);       
}

/*-------------------- Cargar zmb-----------------*/

bool archivoExiste(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);  
    return archivo.good();           
}

bool archivoVacio(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);  
    if (!archivo) {
        return true;  
    }
    archivo.seekg(0, ios::end);  
    return archivo.tellg() == 0; 
}

void carga_de_accesorio(accesorio**lista_de_accesorio){
    ifstream archivo("Accesorio.zmb",ios::in);
    int cantidad_de_accesorios;
    archivo>>cantidad_de_accesorios;
    archivo.ignore();
    int id;
    string nombre;
    string tipo;
    int modificador;
    int usos;
    string linea;
    int contador=0;
    while(getline(archivo,linea)&& contador<cantidad_de_accesorios)
    {
        if(linea=="---" && archivo.good())
        {
            archivo>>id;
            archivo.ignore();
            getline(archivo,nombre);
            getline(archivo,tipo);
            archivo>>modificador>>usos;
            archivo.ignore();
            contador++; 
        }
        
        accesorio*nuevo=crear_accesorio(usos,modificador,nombre,tipo,id);
        /*cout<<cantidad_de_accesorios<<endl;
        cout<<id<<endl;
        cout<<nombre<<endl;
        cout<<tipo<<endl;
        cout<<modificador<<endl;
        cout<<usos<<endl;*/
        //mostrar_accesorio(nuevo);     
        insertar_ultimo_accesorio_con_id(&(*lista_de_accesorio),&nuevo);
    }
    archivo.close();      
}


void cargar_jugadores(jugador** lista_de_jugadores) {
    ifstream archivo("Soldado.zmb");
    if (!archivo.is_open()) {
        cout << "Error, No se pudo abrir el archivo de jugadores." << endl;
        return;
    }

    int cantidad_de_jugadores;
    archivo >> cantidad_de_jugadores;
    archivo.ignore();

    string nombre, linea;
    int salud;

    for (int i = 0; i < cantidad_de_jugadores; i++) {
        getline(archivo, linea); 
        if (linea == "---") {
            getline(archivo, nombre);
            archivo >> salud;
            archivo.ignore();

            jugador* nuevo = crear_soldado(salud,nombre);
            insertar_ultimo_soldado_existente(&(*lista_de_jugadores), &nuevo);
        }
    }
    archivo.close();
}



void crear_grupos_usuario_accesorios(grupo** lista_de_grupos, jugador** lista_de_jugadores, accesorio** lista_de_accesorios) {            
    //insertar_ultimo_grupos(lista_de_grupos);
    int cantidad;
    cout<<"Inserte la cantidad de Grupos: ";
    cin>>cantidad;
    for(int i=0;i<cantidad;i++)
    {
        grupo*nuevo_grupo=crear_grupo(pedir_nombre_grupo());        
       if(listaVaciaGrupo(*lista_de_grupos))
       {
        (*lista_de_grupos)=nuevo_grupo;
        
       }
       else{
        grupo*mover=(*lista_de_grupos);
        while(mover->prox!=NULL)
        {
            mover=mover->prox;
        }
        mover->prox=nuevo_grupo;
       }
    }
    if(cantidad>0)
    {
        jugador* jugador_actual = *lista_de_jugadores;
        while (jugador_actual != NULL) { 
            char opcion = '0'; 
            while (opcion != '1' && opcion != '2' && opcion != '3') {
                system("pause");
                system("cls");
                cout << "1) Seleccionar 1 accesorio" << endl;
                cout << "2) Seleccionar 2 accesorios" << endl;
                cout << "3) Seleccionar 3 accesorios" << endl;            
                cout << "======================================================\n";
                cout << "Ingrese la opcion deseada del menu: ";
                cin >> opcion;

                if (opcion != '1' && opcion != '2' && opcion != '3') {
                    cout << "Opción inválida. Intente nuevamente." << endl;
                    continue;
                }

                int num_accesorios = opcion - '0'; // Convertir char a int
                for (int i = 0; i < num_accesorios; ++i) {
                    mostrar_accesorio(*lista_de_accesorios);
                    int codigo;
                    while (true) {
                        cout << "Coloque el codigo del accesorio a seleccionar: ";
                        cin >> codigo;

                        // Validar que la entrada es un número entero
                        if (cin.fail() || codigo < 1) {
                            cin.clear(); // Limpiar el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
                            cout << "Entrada inválida. Por favor, ingrese un número entero válido." << endl;
                        } else {
                            break; // Salir del bucle si la entrada es válida
                        }
                    }

                    accesorio* accesorio_seleccionado = buscar_accesorio(*lista_de_accesorios, codigo);
                    if (accesorio_seleccionado!=NULL) {                  
                        insertar_ultimo_accesorio_jugador(&jugador_actual, &accesorio_seleccionado);
                    } else {
                        cout << "Accesorio no encontrado. Intente nuevamente." << endl;
                        --i; // se puede repetir la seleccion del accesorio
                    }
                }
            }
            mostrarListaJugador_armas_accesorios(jugador_actual);
            system("pause");
            system("cls");

            mostrar_grupos(*lista_de_grupos);
            cout << "Seleccione un grupo para el jugador: " << jugador_actual->nombre << endl;
            string nombre_grupo;
            cin >> nombre_grupo;

            grupo* grupo_actual = buscar_grupo(*lista_de_grupos, nombre_grupo);
            if (grupo_actual!=NULL) {           
                insertar_soldado_grupo3(&grupo_actual, &jugador_actual);            
            } else {
                cout << "Grupo no encontrado. Intente nuevamente." << endl;
                continue; // Volver al inicio para seleccionar un grupo válido
            }

            jugador_actual = jugador_actual->prox; 
        }
    }
    else{
        cout<<"No hay grupos para insertar soldados"<<endl;
    }  
    
}






#endif 
