#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib> // Para usar rand() y srand()
#include <ctime> // Para usar time()
#include "zombies.h"
using namespace std;

struct aristas {
    int numero_estacion;
    int distancia;
    aristas *prox;
};

struct vertice {
    string estacion;
    int numero_estacion;
    vertice *sig;
    aristas *ady_estacion;
    zombies *zombies_estacion;
};

vertice *nuevo_vertice(string est, int num){
    vertice *nuevo = new vertice;
    nuevo->estacion = est;
    nuevo->numero_estacion = num;
    nuevo->sig = NULL;
    nuevo->ady_estacion = NULL;
    nuevo->zombies_estacion = NULL;
    return nuevo;
}

aristas *nuevo_arista(int num, int dist){
    aristas *nuevo = new aristas;
    nuevo->numero_estacion = num;
    nuevo->distancia = dist;
    nuevo->prox = NULL;
    return nuevo;
}

vertice* Buscar_vertice(vertice* grafo, string ciudad) {
    vertice* buscar = grafo;
    while (buscar != NULL) {
        if (buscar->estacion == ciudad) {
            return buscar;
        }
        buscar = buscar->sig;
    }
    return NULL;
}

void insertar_ultimo_arista(aristas*& grafo, int num_est, int dist) {
    aristas* nueva_arista = nuevo_arista(num_est, dist);
    if (grafo == NULL) {
        grafo = nueva_arista;
    } else {
        aristas* recorrer = grafo;
        while (recorrer->prox != NULL) {
            recorrer = recorrer->prox;
        }
        recorrer->prox = nueva_arista;
    }
}

void insertar_ultimo_vertice(vertice*& grafo, string est, int num) {
    vertice* nuevo = nuevo_vertice(est, num);
    if (grafo == NULL) {
        grafo = nuevo;
    } else {
        vertice* recorrer = grafo;
        while (recorrer->sig != NULL) {
            recorrer = recorrer->sig;
        }
        recorrer->sig = nuevo;
    }
}

void cargar_mapa(vertice*& lista) {
    ifstream lectura("Mapa.zmb", ios::in);
    
    if (!lectura) {
        cout << "\e[0;31mError al abrir el archivo.\e[0m" << endl;
        return;
    }
    vertice *ubicacion_estacion = NULL;
    string linea;
    int numero_est;
    string nombre_est;
    getline(lectura, linea);
    string cantidad = linea;
    getline(lectura, linea);  
    for (int i = 0; i < stoi(cantidad); i++) {
        if(linea == "---"){
            getline(lectura, linea);
            numero_est = stoi(linea);
            getline(lectura, nombre_est);
            insertar_ultimo_vertice(lista, nombre_est, numero_est); 
        }
            
        ubicacion_estacion = Buscar_vertice(lista, nombre_est);
        getline(lectura, linea);
        if (linea == "-") {
            while (linea != "--") {
                getline(lectura, linea);
                size_t division = linea.find('|');
                if (division != string::npos) {
                    string cantidad_zomb = linea.substr(0, division);
                    int numero_zomb = stoi(cantidad_zomb);
                    string zombies_est = linea.substr(division + 1);
                    int vida_zombie = rand() % 30 + 1; // Generar número aleatorio entre 1 y 30 para la vida
                    int dano_zombie = rand() % 30 + 1; // Generar número aleatorio entre 1 y 30 para el daño
                    insertar_ultimo_zombie(ubicacion_estacion->zombies_estacion, zombies_est, vida_zombie, dano_zombie, numero_zomb);
                }
            }
        }

        while (getline(lectura, linea) && linea != "---") {
            stringstream ss(linea);
            string par;
            while (getline(ss, par, '|')) {
                size_t pos = par.find(':');
                if (pos != string::npos) {
                    string adyacente_est = par.substr(0, pos);
                    int adyacente = stoi(adyacente_est);
                    string distancia_est = par.substr(pos + 1);
                    int distancia = stoi(distancia_est);
                    insertar_ultimo_arista(ubicacion_estacion->ady_estacion, adyacente, distancia); 
                }
            }
        }
    }
    lectura.close();
}

void agregar_zombies(vertice* ubicacion_estacion) {
    int vida;
    int dano;
    int cantidad_zombies;
    string tipo_zombie;

    cout << "Ingrese la cantidad de tipos de zombies: ";
    cin >> cantidad_zombies;
    cin.ignore(); // Ignorar el salto de línea después del número

    for (int i = 0; i < cantidad_zombies; i++) {
        cout << "Ingrese el tipo de zombie: ";
        getline(cin, tipo_zombie);
        cout << "Ingrese la cantidad de "<<tipo_zombie<<" en la estacion: ";
        int cantidad;
        cout<<"Ingrese la vida del zombie: ";
        cin>> vida;
        cout<<"Ingrese el dano del zombie: ";
        cin>> dano; 
        cin >> cantidad;
        cin.ignore(); // Ignorar el salto de línea después del número
        insertar_ultimo_zombie(ubicacion_estacion->zombies_estacion, tipo_zombie, vida, dano, cantidad);
    }
}

void agregar_adyacencias(vertice* ubicacion_estacion) {
    int cantidad_adyacencias;
    int adyacente;
    int distancia;

    cout << "Ingrese la cantidad de adyacencias: ";
    cin >> cantidad_adyacencias;
    cin.ignore(); // Ignorar el salto de línea después del número

    for (int i = 0; i < cantidad_adyacencias; i++) {
        cout << "Ingrese el numero de la estacion adyacente: ";
        cin >> adyacente;
        while(Buscar_vertice(ubicacion_estacion, to_string(adyacente)) == NULL){
            cout << "\e[0;31mError, el numero de la estacion " << adyacente << " no existe.\e[0m" << endl;
            cout << "Ingrese el numero de la estacion adyacente: ";
            cin >> adyacente;
        }
        cout << "Ingrese la distancia a la estacion adyacente: ";
        cin >> distancia;
        cin.ignore(); // Ignorar el salto de línea después del número
        insertar_ultimo_arista(ubicacion_estacion->ady_estacion, adyacente, distancia);
    }
}

void agregar_estacion(vertice*& lista) {
    string nombre_est;
    int numero_est;

    cout << "Ingrese el numero de la estacion: ";
    cin >> numero_est;
    vertice* temp = lista;
    while (temp != NULL) {
        while (temp->numero_estacion == numero_est) {
            cout << "\e[0;31mError, El numero de estacion ya existe.\e[0m" << endl;
            cout << "Ingrese el numero de la estacion: ";
            cin >> numero_est;
        }
        temp = temp->sig;
    }

    cout << "Ingrese el nombre de la estacion: ";
    getline(cin, nombre_est);

    // Verificar que el nombre de estación no exista
    temp = lista;
    while (temp != NULL) {
            while(temp->estacion == nombre_est){
                cout << "\e[0;31mError, El nombre de estacion ya existe.\e[0m" << endl;
                cout << "Ingrese el nombre de la estacion: ";
                getline(cin, nombre_est);
            }
        temp = temp->sig;
    }

    insertar_ultimo_vertice(lista, nombre_est, numero_est);
    vertice* ubicacion_estacion = Buscar_vertice(lista, nombre_est);

    agregar_zombies(ubicacion_estacion);
    agregar_adyacencias(ubicacion_estacion);

    cout << "\e[0;32mEstacion agregada con exito.\e[0m" << endl;
}

void modificar_nombre_est(string& nombre_actual, string nuevo_nombre, int nurvo_numero) {
    nombre_actual = nuevo_nombre;
    nurvo_numero = nurvo_numero;
}

bool verificar_estacion_adyacente(vertice* lista, int nuevo_ady) {
    vertice* temp = lista;
    while (temp != NULL) {
        if (temp->numero_estacion == nuevo_ady) {
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

bool modificar_adyacencia_existente(aristas*& ady_estacion, int nuevo_ady, int nueva_dist) {
    aristas* buscar = ady_estacion;
    while (buscar != NULL) {
        if (buscar->numero_estacion == nuevo_ady) {
            buscar->distancia = nueva_dist;
            return true;
        }
        buscar = buscar->prox;
    }
    return false;
}

void modificar_adyacencias(aristas*& ady_estacion, vertice* lista, int nuevo_ady, int nueva_dist) {
    if (!verificar_estacion_adyacente(lista, nuevo_ady)) {
        cout << "\e[0;31mError, la estación adyacente no existe.\e[0m" << endl;
        return;
    }

    if (!modificar_adyacencia_existente(ady_estacion, nuevo_ady, nueva_dist)) {
        insertar_ultimo_arista(ady_estacion, nuevo_ady, nueva_dist);
    }
}

void modificar_estacion(vertice *lista) {
    if (lista == NULL) {
        cout << "La lista de zombies esta vacia" << endl;
        return;
    }
    
    string name;
    cout << "Ingrese el nombre de la estacion a modificar: ";
    cin >> name;
    
    vertice* ubicacion = Buscar_vertice(lista, name);
    while (ubicacion != NULL) {
        if (ubicacion->estacion == name) {
            char opcion;
            while (opcion!='4') {
                system("cls");
                cout << "              \e[47Modificar estacion\e[0m" << endl;
                cout << "======================================================\n";
                cout << "1.- Editar nombre de la estacion\n";
                cout << "2.- Editar zombies de la estacion\n";
                cout << "3.- Editar estaciones adyacente\n";
                cout << "4.- Salir del menu de modificacion\n";
                cout << "======================================================\n";
                cout << "Ingrese la opcion deseada del menu: ";
                cin >> opcion;

                switch (opcion) {
                    case '1': {
                        string nuevo_nombre;
                        int nuevo_numero;
                        cout << "Ingrese el nuevo nombre: ";
                        cin >> nuevo_nombre;
                        cout << "Ingrese el nuevo numero de la estacion: ";
                        cin >> nuevo_numero;
                        modificar_nombre_est(ubicacion->estacion, nuevo_nombre, nuevo_numero);
                        break;
                    }
                    case '2': {

                        modificar_zombie(ubicacion->zombies_estacion);
                        break;
                    }
                    case '3': {
                        int nuevo_adyacente;
                        int nueva_dist;
                        int cantidad_adyacencias;
                        cout << "Ingrese la nueva cantidad de estaciones adyacentes: ";
                        cin >> cantidad_adyacencias;
                        for(int i = 0; i < cantidad_adyacencias; i++){
                            cout << "Ingrese el número de la nueva adyacencia: ";
                            cin >> nuevo_adyacente;
                            cout << "Ingrese la nueva distancia: ";
                            cin >> nueva_dist;
                            modificar_adyacencias(ubicacion->ady_estacion, lista, nuevo_adyacente, nueva_dist);
                        }
                        break;
                    }
                    case '4':
                        return; 
                    default:
                        cout << "\e[0;31mOpcion invalida\e[0m" << endl;
                        break;
                }
                system("pause");
            }
        }
        ubicacion = ubicacion->sig;
    }
    cout << "\e[0;31mEstacion no encontrada.\e[0m" << endl;
}

void eliminar_aristas_adyacentes(vertice* lista, int numero_est) {
    vertice* temp = lista;
    while (temp != NULL) {
        aristas* actual = temp->ady_estacion;
        aristas* anterior = NULL;
        while (actual != NULL) {
            if (actual->numero_estacion == numero_est) {
                if (anterior == NULL) {
                    temp->ady_estacion = actual->prox;
                } else {
                    anterior->prox = actual->prox;
                }
                delete actual;
                break;
            }
            anterior = actual;
            actual = actual->prox;
        }
        temp = temp->sig;
    }
}

void eliminar_vertice(vertice*& lista) {
    vertice* temp = lista;
    vertice* anterior = NULL;
    int num_est;
    cout << "Ingrese el numero de la estacion a eliminar: ";
    cin >> num_est;

    // Buscar el vértice a eliminar
    while (temp != NULL && temp->numero_estacion != num_est) {
        anterior = temp;
        temp = temp->sig;
    }

    if (temp == NULL) {
        cout << "\e[0;31mEstación no encontrada.\e[0m" << endl;
        return;
    }

    // Eliminar las aristas que apuntan a este vértice
    eliminar_aristas_adyacentes(lista, temp->numero_estacion);

    // Eliminar el vértice de la lista
    if (anterior == NULL) {
        lista = temp->sig;
    } else {
        anterior->sig = temp->sig;
    }

    // Eliminar las aristas y zombies del vértice
    while (temp->ady_estacion != NULL) {
        aristas* arista_a_eliminar = temp->ady_estacion;
        temp->ady_estacion = temp->ady_estacion->prox;
        delete arista_a_eliminar;
    }

    while (temp->zombies_estacion != NULL) {
        zombies* zombie_a_eliminar = temp->zombies_estacion;
        temp->zombies_estacion = temp->zombies_estacion->prox;
        delete zombie_a_eliminar;
    }

    cout << "\e[0;32mLa estación " << temp->estacion << " fue eliminada con éxito.\e[0m" << endl;
    delete temp;
}

void mostrar_estaciones(vertice* lista) {
    if (lista == NULL) {
        cout << "\e[0;31mNo hay estaciones\e[0m\n";
    } else {
        vertice* mover = lista;
        while (mover != NULL) {
            cout << "\n\nEstacion: " << mover->estacion << "\n";
            cout << "Número de estacion: " << mover->numero_estacion << "\n";
            cout << "=========================================\n";

            if (mover->zombies_estacion == NULL) {
                cout << "No hay zombies en esta estacion.\n";
            } else {
                cout << "Zombies en esta estacion:\n";
                zombies* mover_zombie = mover->zombies_estacion;
                while (mover_zombie != NULL) {
                    cout << " - " << mover_zombie->nombre << " [" << mover_zombie->cantidad_zombies << " zombies] con " << mover_zombie->salud << " de vida y " << mover_zombie->dano_ataque << " de dano de ataque\n"; 
                    mover_zombie = mover_zombie->prox;
                }
            }

            if (mover->ady_estacion == NULL) {
                cout << "No hay estaciones adyacentes.\n";
            } else {
                cout << "Estaciones adyacentes:\n";
                aristas* mover_arista = mover->ady_estacion;
                while (mover_arista != NULL) {
                    cout << " - Estacion " << mover_arista->numero_estacion << " a una distancia de " << mover_arista->distancia << "\n";
                    mover_arista = mover_arista->prox;
                }
            }

            mover = mover->sig;
        }
    }
}

#endif 
