#ifndef MAPA_H//HOLA CHAMO
#define MAPA_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <climits> // Para usar INT_MAX
#include <cstdlib> // Para usar rand() y srand()
#include <ctime> 
#include <random>
#include "zombies.h"
#include "grupos.h"
using namespace std;

struct zombies_estaciones {
    string nombre_zombie;
    int cantidad_zombies;
    int vida;
    int dano_ataque;
    zombies_estaciones* prox;
};

struct lista_adyacencia {
    int distancia;
    string nombre_estacion;
    int numero_estacion;
    lista_adyacencia* prox;
};

struct nodo {
    string estacion;
    int numero_estacion;
    int distancia;       // Distancia mínima desde el origen
    bool visitado;       // Para marcar si ya fue procesado
    nodo* prox;
    nodo* anterior;         // Para lista doblemente enlazada
    nodo* camino;    // Para reconstruir el camino
    lista_adyacencia* adyacencia;
    zombies_estaciones* zombies_estacion;
};

void agregar_adyacencia(nodo* origen, int distancia, int numero_est, string nombre_est) {
    lista_adyacencia* nuevaAdyacencia = new lista_adyacencia;
    nuevaAdyacencia->distancia = distancia;
    nuevaAdyacencia->nombre_estacion = nombre_est;
    nuevaAdyacencia->numero_estacion = numero_est;
    nuevaAdyacencia->prox = origen->adyacencia;
    origen->adyacencia = nuevaAdyacencia;
}

zombies_estaciones* nuevo_zombies(string nom, int salud, int dano_ataque, int cantidad_zombies) {
    zombies_estaciones* zombie = new zombies_estaciones;
    zombie->nombre_zombie = nom;
    zombie->vida = salud; 
    zombie->cantidad_zombies = cantidad_zombies; // Asumimos que se crea un zombie a la vez
    zombie->dano_ataque = dano_ataque;
    zombie->prox = NULL;
    return zombie;
}
bool listaVaciaZombiesEstaciones(zombies_estaciones* zombies) {
    return zombies == NULL;
}

nodo* nuevo_estacion(string estacion, int numero_estacion) {
    nodo* nuevo = new nodo;
    nuevo->estacion = estacion;
    nuevo->numero_estacion = numero_estacion;
    nuevo->adyacencia = NULL;
    nuevo->prox = NULL;
    nuevo->anterior = NULL;
    nuevo->distancia = INT_MAX;
    nuevo->camino = NULL;
    nuevo->zombies_estacion = NULL;
    nuevo->visitado = false;
    return nuevo;
}

void mostrar_zombies_estaciones(zombies_estaciones* lista_zombies) {
    if (lista_zombies == NULL) {
        cout << "No hay zombies en esta estación." << endl;
        return;
    }

    zombies_estaciones* mover = lista_zombies;
    while (mover != NULL) {
        cout << "----------------------------------------" << endl;
        cout << "Nombre del zombie: " << mover->nombre_zombie << endl;
        cout << "Cantidad de zombies: " << mover->cantidad_zombies << endl;
        cout << "Vida del zombie: " << mover->vida << endl;
        cout << "Daño de ataque del zombie: " << mover->dano_ataque << endl;
        cout << "----------------------------------------" << endl;
        mover = mover->prox;
    }
}

void insertar_ultimo_zombie(zombies_estaciones*& lista, string nombre_zombie, int vida, int dano_ataque, int cantidad_zombies) {
    zombies_estaciones* nuevo = new zombies_estaciones;
    nuevo->nombre_zombie = nombre_zombie;
    nuevo->vida = vida;
    nuevo->dano_ataque = dano_ataque;
    nuevo->cantidad_zombies = cantidad_zombies;
    nuevo->prox = NULL;
    if (lista == NULL) {
        lista = nuevo;
    } else {
        zombies_estaciones* temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nuevo;
    }
}

void insertar_ultimo_adyacencia(lista_adyacencia*& adyacencia, int distancia, int numero_est, string nombre_est) {
    lista_adyacencia* nuevo = new lista_adyacencia;
    nuevo->distancia = distancia;
    nuevo->numero_estacion = numero_est;
    nuevo->nombre_estacion = nombre_est;
    nuevo->prox = NULL;
    if (adyacencia == NULL) {
        adyacencia = nuevo;
    } else {
        lista_adyacencia* temp = adyacencia;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nuevo;
    }
}

nodo* Buscar_estacion(nodo* lista, int estacion) {
    nodo* buscar = lista;
    while (buscar != NULL) {
        if (buscar->numero_estacion == estacion) {
            return buscar;
        }
        buscar = buscar->prox;
    }
    return NULL;
}

nodo* Buscar_estacion_nom(nodo* lista, string estacion) {
    nodo* buscar = lista;
    while (buscar != NULL) {
        if (buscar->estacion == estacion) {
            return buscar;
        }
        buscar = buscar->prox;
    }
    return NULL;
}

void insertar_ultimo_estacion(nodo*& lista, string estacion, int numero_estacion) {
    nodo* nuevo = nuevo_estacion(estacion, numero_estacion);
    if (lista == NULL) {
        lista = nuevo;
    } else {
        nodo* temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nuevo;
        nuevo->anterior = temp;
    }
}

void agregar_estacion(nodo*& lista) {
    string nombre_est;
    int numero_est;

    cout << "Ingrese el nombre de la estacion: ";
    getline(cin, nombre_est);
    cout << "Ingrese el numero de la estacion: ";
    cin >> numero_est;
    cin.ignore(); // Ignorar el salto de línea después del número

    insertar_ultimo_estacion(lista, nombre_est, numero_est);
}

void llenar_estaciones(nodo*& lista) {
    int cantidad_estaciones;
    cout << "Ingrese la cantidad de estaciones a agregar: ";
    cin >> cantidad_estaciones;
    cin.ignore(); // Ignorar el salto de línea después del número

    for (int i = 0; i < cantidad_estaciones; ++i) {
        cout << "\nAgregando estación " << (i + 1) << " de " << cantidad_estaciones << ":\n";
        agregar_estacion(lista);
    }
    cout << "Todas las estaciones han sido agregadas con éxito." << endl;
}

void agregar_adyacencias(nodo* lista, nodo* ubicacion) {
    int cantidad_adyacencias;
    int nuevo_adyacente;
    int nueva_dist;
    cout << "Ingrese cantidad de estaciones adyacentes: ";
    cin >> cantidad_adyacencias;
    for (int i = 0; i < cantidad_adyacencias; i++) {
        cout << "Ingrese el numero de la estacion de adyacencia: ";
        cin >> nuevo_adyacente;
        cout << "Ingrese la nueva distancia: ";
        cin >> nueva_dist;
        nodo* adyacente = Buscar_estacion(lista, nuevo_adyacente);
        if (adyacente == NULL) {
            cout << "Estación adyacente no encontrada." << endl;
        } else {
            agregar_adyacencia(ubicacion, nueva_dist, nuevo_adyacente, adyacente->estacion);
        }
    }
}

void agregar_zombies(nodo* ubicacion) {
    int cantidad_zombies;
    cout << "Ingrese la cantidad de zombies: ";
    cin >> cantidad_zombies;
    cin.ignore(); // Ignorar el salto de línea después del número
    string nombre_zombie;
    int vida;
    int dano_ataque;
    cout << "Ingrese el tipo del zombie: ";
    getline(cin, nombre_zombie);
    cout << "Ingrese la vida del zombie: ";
    cin >> vida;
    cout << "Ingrese el daño de ataque del zombie: ";
    cin >> dano_ataque;
    insertar_ultimo_zombie(ubicacion->zombies_estacion, nombre_zombie, vida, dano_ataque, cantidad_zombies);
}

void asignar_nombres(nodo* lista, nodo*& nueva_lista) {
    nodo* actual = lista;
    while (actual != NULL) {
        // Asignar nombres a las aristas del nodo actual
        lista_adyacencia* adyacente = actual->adyacencia;
        while (adyacente != NULL) {
            nodo* estacion_aux = Buscar_estacion(lista, adyacente->numero_estacion);
            if (estacion_aux != NULL) {
                adyacente->nombre_estacion = estacion_aux->estacion;
            }
            adyacente = adyacente->prox;
        }

        // Insertar el nodo actual en la nueva lista
        insertar_ultimo_estacion(nueva_lista, actual->estacion, actual->numero_estacion);

        // Buscar el nodo recién insertado en la nueva lista
        nodo* nuevo_nodo = Buscar_estacion(nueva_lista, actual->numero_estacion);

        // Insertar los zombies del nodo actual en el nuevo nodo
        zombies_estaciones* mover_zombie = actual->zombies_estacion;
        while (mover_zombie != NULL) {
            insertar_ultimo_zombie(nuevo_nodo->zombies_estacion, mover_zombie->nombre_zombie, mover_zombie->vida, mover_zombie->dano_ataque, mover_zombie->cantidad_zombies);
            mover_zombie = mover_zombie->prox;
        }

        // Insertar las adyacencias del nodo actual en el nuevo nodo
        adyacente = actual->adyacencia;
        while (adyacente != NULL) {
            insertar_ultimo_adyacencia(nuevo_nodo->adyacencia, adyacente->distancia, adyacente->numero_estacion, adyacente->nombre_estacion);
            adyacente = adyacente->prox;
        }

        // Pasar al siguiente nodo
        actual = actual->prox;
    }
}

void cargar_mapa(nodo*& lista) {
    ifstream lectura("Mapa.zmb", ios::in);
    
    if (!lectura) {
        cout << "\e[0;31mError al abrir el archivo.\e[0m" << endl;
        return;
    }
    nodo *ubicacion_estacion = NULL;
    string linea;
    int numero_est;
    string nombre_est;
    getline(lectura, linea);
    string cantidad = linea;
    getline(lectura, linea);
    for (int i = 0; i < stoi(cantidad); i++) {
        if (linea == "---") {
            getline(lectura, linea);
            numero_est = stoi(linea);
            getline(lectura, nombre_est);
            insertar_ultimo_estacion(lista, nombre_est, numero_est); 
        }
            
        ubicacion_estacion = Buscar_estacion(lista, numero_est);
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
                    insertar_ultimo_adyacencia(ubicacion_estacion->adyacencia, distancia, adyacente, "vacio");
                }
            }
        }
    }
    lectura.close();
}

void mostrar_estaciones(nodo* lista) {
    if (lista == NULL) {
        cout << "No hay estaciones." << endl;
        return;
    }

    nodo* mover = lista;
    while (mover != NULL) {
        cout << "\nEstacion: " << mover->estacion << "\n";
        cout << "Número de estacion: " << mover->numero_estacion << "\n";
        cout << "=========================================\n";

        if (mover->zombies_estacion == NULL) {
            cout << "No hay zombies en esta estacion.\n";
        } else {
            cout << "Zombies en esta estacion:\n";
            zombies_estaciones* mover_zombie = mover->zombies_estacion;
            while (mover_zombie != NULL) {
                cout << " - " << mover_zombie->nombre_zombie << " [" << mover_zombie->cantidad_zombies << " zombies] con " << mover_zombie->vida << " de vida y " << mover_zombie->dano_ataque << " de dano de ataque\n"; 
                mover_zombie = mover_zombie->prox;
            }
        }

        if (mover->adyacencia == NULL) {
            cout << "No hay estaciones adyacentes.\n";
        } else {
            cout << "Estaciones adyacentes:\n";
            lista_adyacencia* mover_arista = mover->adyacencia;
            while (mover_arista != NULL) {
                cout << " - Estacion " << mover_arista->nombre_estacion << " a una distancia de " << mover_arista->distancia << "\n";
                mover_arista = mover_arista->prox;
            }
        }

        mover = mover->prox;
    }
}

void dijkstra(nodo* lista, nodo*& camino_corto, string origen, string destino) {
    if (lista == NULL) {
        cout << "El grafo está vacío." << endl;
        return;
    }

    // Inicializar todos los nodos
    nodo* mover = lista;
    while (mover != NULL) {
        mover->distancia = INT_MAX; // Establecer la distancia inicial a infinito
        mover->camino = NULL;       // No hay camino previo
        mover->visitado = false;    // Marcar como no visitado
        mover = mover->prox;
    }

    nodo* nodoOrigen = NULL;
    nodo* nodoDestino = NULL;

    // Encontrar los nodos de origen y destino
    mover = lista;
    while (mover != NULL) {
        if (mover->estacion == origen) nodoOrigen = mover;
        if (mover->estacion == destino) nodoDestino = mover;
        mover = mover->prox;
    }

    // Verificar si los nodos de origen y destino existen
    if (nodoOrigen == NULL || nodoDestino == NULL) {
        cout << "Uno o ambos nodos no existen." << endl;
        return;
    }

    nodoOrigen->distancia = 0; // La distancia al nodo de origen es 0
    nodo* actual = nodoOrigen;

    // Algoritmo de Dijkstra
    while (actual != NULL) {
        actual->visitado = true; // Marcar el nodo actual como visitado
        lista_adyacencia* adyacente = actual->adyacencia;

        // Actualizar las distancias a los nodos adyacentes
        while (adyacente != NULL) {
            nodo* vertice = Buscar_estacion(lista, adyacente->numero_estacion);
            if (!vertice->visitado) {
                int nuevaDistancia = actual->distancia + adyacente->distancia;
                if (nuevaDistancia < vertice->distancia) {
                    vertice->distancia = nuevaDistancia;
                    vertice->camino = actual;
                }
            }
            adyacente = adyacente->prox;
        }

        // Encontrar el siguiente nodo no visitado con la menor distancia
        nodo* menorNodo = NULL;
        int menorDistancia = INT_MAX;
        mover = lista;
        while (mover != NULL) {
            if (!mover->visitado && mover->distancia < menorDistancia) {
                menorDistancia = mover->distancia;
                menorNodo = mover;
            }
            mover = mover->prox;
        }
        actual = menorNodo;
    }

    // Construir la lista camino_corto y devolver la distancia más corta
    if (nodoDestino->distancia == INT_MAX) {
        cout << "No hay camino entre " << origen << " y " << destino << "." << endl;
    } else {
        nodo* mov = nodoDestino;
        while (mov != NULL) {
            nodo* nuevo_nodo = nuevo_estacion(mov->estacion, mov->numero_estacion);
            insertar_ultimo_estacion(camino_corto, nuevo_nodo->estacion, nuevo_nodo->numero_estacion);
            mov = mov->camino;
        }
        system("pause");
        system("cls");
        cout << "La distancia más corta desde " << origen << " hasta " << destino << " es: " << nodoDestino->distancia << endl;
        system("pause");
    }
    nodo* mover_camino = camino_corto;
    nodo* mover_lista = lista;
    while(mover_camino != NULL) {
        while(mover_lista != NULL) {
            if(mover_camino->estacion == mover_lista->estacion) {
                mover_camino->zombies_estacion = mover_lista->zombies_estacion;
            }
            mover_lista = mover_lista->prox;
        }
        mover_lista = lista;
        mover_camino = mover_camino->prox;
    }
}

int contar_zombies(zombies_estaciones* lista_zombies) {
    int total = 0;
    while (lista_zombies != NULL) {
        total += lista_zombies->cantidad_zombies;
        lista_zombies = lista_zombies->prox;
    }
    return total;
}

void camino_menor_zombies(nodo* lista, nodo*& camino_corto, string origen, string destino) {
    if (lista == NULL) {
        cout << "El grafo está vacío." << endl;
        return;
    }

    // Inicializar todos los nodos
    nodo* mover = lista;
    while (mover != NULL) {
        mover->distancia = INT_MAX; // Usaremos la distancia para almacenar la cantidad de zombies
        mover->camino = NULL;       // No hay camino previo
        mover->visitado = false;    // Marcar como no visitado
        mover = mover->prox;
    }

    nodo* nodoOrigen = NULL;
    nodo* nodoDestino = NULL;

    // Encontrar los nodos de origen y destino
    mover = lista;
    while (mover != NULL) {
        if (mover->estacion == origen) nodoOrigen = mover;
        if (mover->estacion == destino) nodoDestino = mover;
        mover = mover->prox;
    }

    // Verificar si los nodos de origen y destino existen
    if (nodoOrigen == NULL || nodoDestino == NULL) {
        cout << "Uno o ambos nodos no existen." << endl;
        return;
    }

    nodoOrigen->distancia = 0; // La cantidad de zombies en el nodo de origen es 0
    nodo* actual = nodoOrigen;

    // Algoritmo para encontrar el camino con menor cantidad de zombies
    while (actual != NULL) {
        actual->visitado = true; // Marcar el nodo actual como visitado
        lista_adyacencia* adyacente = actual->adyacencia;

        // Actualizar las cantidades de zombies a los nodos adyacentes
        while (adyacente != NULL) {
            nodo* vertice = Buscar_estacion(lista, adyacente->numero_estacion);
            if (!vertice->visitado) {
                int cantidadZombies = actual->distancia + contar_zombies(vertice->zombies_estacion);
                if (cantidadZombies < vertice->distancia) {
                    vertice->distancia = cantidadZombies;
                    vertice->camino = actual;
                }
            }
            adyacente = adyacente->prox;
        }

        // Encontrar el siguiente nodo no visitado con la menor cantidad de zombies
        nodo* menorNodo = NULL;
        int menorCantidadZombies = INT_MAX;
        mover = lista;
        while (mover != NULL) {
            if (!mover->visitado && mover->distancia < menorCantidadZombies) {
                menorCantidadZombies = mover->distancia;
                menorNodo = mover;
            }
            mover = mover->prox;
        }
        actual = menorNodo;
    }

    // Construir la lista camino_corto y devolver la cantidad total de zombies
    if (nodoDestino->distancia == INT_MAX) {
        cout << "No hay camino entre " << origen << " y " << destino << "." << endl;
    } else {
        nodo* mov = nodoDestino;
        int totalZombies = 0;
        while (mov != NULL) {
            nodo* nuevo_nodo = nuevo_estacion(mov->estacion, mov->numero_estacion);
            insertar_ultimo_estacion(camino_corto, nuevo_nodo->estacion, nuevo_nodo->numero_estacion);
            totalZombies += contar_zombies(mov->zombies_estacion);
            mov = mov->camino;
        }
        cout << "La cantidad total de zombies en el camino desde " << origen << " hasta " << destino << " es: " << totalZombies << endl;
    }
    nodo* mover_camino = camino_corto;
    nodo* mover_lista = lista;
    while(mover_camino != NULL) {
        while(mover_lista != NULL) {
            if(mover_camino->estacion == mover_lista->estacion) {
                mover_camino->zombies_estacion = mover_lista->zombies_estacion;
            }
            mover_lista = mover_lista->prox;
        }
        mover_lista = lista;
        mover_camino = mover_camino->prox;
    }
}

void camino_posible_sobreviviente(nodo* lista, nodo*& camino_corto, string origen, string destino, int fuerza_grupo) {
    if (lista == NULL) {
        cout << "El grafo está vacío." << endl;
        return;
    }

    // Inicializar todos los nodos
    nodo* mover = lista;
    while (mover != NULL) {
        mover->distancia = INT_MAX; // Usaremos la distancia para almacenar la cantidad de zombies
        mover->camino = NULL;       // No hay camino previo
        mover->visitado = false;    // Marcar como no visitado
        mover = mover->prox;
    }

    nodo* nodoOrigen = NULL;
    nodo* nodoDestino = NULL;

    // Encontrar los nodos de origen y destino
    mover = lista;
    while (mover != NULL) {
        if (mover->estacion == origen) nodoOrigen = mover;
        if (mover->estacion == destino) nodoDestino = mover;
        mover = mover->prox;
    }

    // Verificar si los nodos de origen y destino existen
    if (nodoOrigen == NULL || nodoDestino == NULL) {
        cout << "Uno o ambos nodos no existen." << endl;
        return;
    }

    nodoOrigen->distancia = 0; // La cantidad de zombies en el nodo de origen es 0
    nodo* actual = nodoOrigen;

    // Algoritmo para encontrar el camino con menor cantidad de zombies
    while (actual != NULL) {
        actual->visitado = true; // Marcar el nodo actual como visitado
        lista_adyacencia* adyacente = actual->adyacencia;

        // Actualizar las cantidades de zombies a los nodos adyacentes
        while (adyacente != NULL) {
            nodo* vertice = Buscar_estacion(lista, adyacente->numero_estacion);
            if (!vertice->visitado) {
                int cantidadZombies = actual->distancia + contar_zombies(vertice->zombies_estacion);
                if (cantidadZombies < vertice->distancia) {
                    vertice->distancia = cantidadZombies;
                    vertice->camino = actual;
                }
            }
            adyacente = adyacente->prox;
        }

        // Encontrar el siguiente nodo no visitado con la menor cantidad de zombies
        nodo* menorNodo = NULL;
        int menorCantidadZombies = INT_MAX;
        mover = lista;
        while (mover != NULL) {
            if (!mover->visitado && mover->distancia < menorCantidadZombies) {
                menorCantidadZombies = mover->distancia;
                menorNodo = mover;
            }
            mover = mover->prox;
        }
        actual = menorNodo;
    }

    // Construir la lista camino_corto y devolver la cantidad total de zombies
    if (nodoDestino->distancia == INT_MAX) {
        cout << "No hay camino entre " << origen << " y " << destino << "." << endl;
    } else {
        nodo* mov = nodoDestino;
        int totalZombies = 0;
        bool sobreviviente = true;
        while (mov != NULL) {
            nodo* nuevo_nodo = nuevo_estacion(mov->estacion, mov->numero_estacion);
            insertar_ultimo_estacion(camino_corto, nuevo_nodo->estacion, nuevo_nodo->numero_estacion);
            int zombies_estacion = contar_zombies(mov->zombies_estacion);
            totalZombies += zombies_estacion;
            if (zombies_estacion > fuerza_grupo) {
                sobreviviente = false;
            }
            mov = mov->camino;
        }
        cout << "La cantidad total de zombies en el camino desde " << origen << " hasta " << destino << " es: " << totalZombies << endl;
        if (sobreviviente) {
            cout << "Existe la posibilidad de un sobreviviente del grupo." << endl;
        } else {
            cout << "No existe la posibilidad de un sobreviviente del grupo." << endl;
        }
    }
    nodo* mover_camino = camino_corto;
    nodo* mover_lista = lista;
    while(mover_camino != NULL) {
        while(mover_lista != NULL) {
            if(mover_camino->estacion == mover_lista->estacion) {
                mover_camino->zombies_estacion = mover_lista->zombies_estacion;
            }
            mover_lista = mover_lista->prox;
        }
        mover_lista = lista;
        mover_camino = mover_camino->prox;
    }
}

void modificar_nombre_est(string& nombre_actual, string nuevo_nombre, int nuevo_numero) {
    nombre_actual = nuevo_nombre;
    // Aquí se debería modificar el número de la estación si es necesario
    // Sin embargo, en el código actual no se está utilizando el número de la estación
}

bool verificar_estacion_adyacente(nodo* lista, int nuevo_ady) {
    nodo* temp = lista;
    while (temp != NULL) {
        if (temp->numero_estacion == nuevo_ady) {
            return true;
        }
        temp = temp->prox;
    }
    return false;
}

bool modificar_adyacencia_existente(lista_adyacencia*& ady_estacion, int nuevo_ady, int nueva_dist) {
    lista_adyacencia* buscar = ady_estacion;
    while (buscar != NULL) {
        if (buscar->numero_estacion == nuevo_ady) {
            buscar->distancia = nueva_dist;
            return true;
        }
        buscar = buscar->prox;
    }
    return false;
}

void modificar_adyacencias(lista_adyacencia*& ady_estacion, nodo* lista, int nuevo_ady, int nueva_dist) {
    if (!verificar_estacion_adyacente(lista, nuevo_ady)) {
        cout << "\e[0;31mError, la estación adyacente no existe.\e[0m" << endl;
        return;
    }

    if (!modificar_adyacencia_existente(ady_estacion, nuevo_ady, nueva_dist)) {
        nodo* vertice_adyacente = Buscar_estacion_nom(lista, to_string(nuevo_ady));
        if (vertice_adyacente != NULL) {
            insertar_ultimo_adyacencia(ady_estacion, nueva_dist, nuevo_ady, vertice_adyacente->estacion);
        } else {
            cout << "\e[0;31mError, la estación adyacente no se encontró.\e[0m" << endl;
        }
    }
}

void modificar_zombie_estacion(zombies_estaciones *lista) {
    if (lista == NULL) {
        cout << "\e[0;31mLa lista de zombies está vacía\e[0m" << endl;
        return;
    }
    
    string name;
    cout << "Ingrese el nombre del zombie a modificar: ";
    getline(cin, name);
    
    zombies_estaciones* buscar = lista;
    while (buscar != NULL) {
        if (buscar->nombre_zombie == name) {
            char opcion = '0';
            while (opcion != '4') {
                system("cls");
                cout << "              \e[47mModificar zombies\e[0m" << endl;
                cout << "======================================================\n";
                cout << "1.- Editar nombre del zombie\n";
                cout << "2.- Editar vida del zombie\n";
                cout << "3.- Editar daño del zombie\n";
                cout << "4.- Salir del menú de modificación\n";
                cout << "======================================================\n";
                cout << "Ingrese la opción deseada del menú: ";
                cin >> opcion;

                switch (opcion) {
                    case '1': {
                        string nuevo_nombre;
                        cout << "Ingrese el nuevo nombre: ";
                        getline(cin, nuevo_nombre);
                        buscar->nombre_zombie = nuevo_nombre;
                        break;
                    }
                    case '2': {
                        int nueva_salud;
                        cout << "Ingrese la nueva salud: ";
                        cin >> nueva_salud;
                        buscar->vida = nueva_salud;
                        break;
                    }
                    case '3': {
                        int nuevo_dano;
                        cout << "Ingrese el nuevo daño: ";
                        cin >> nuevo_dano;
                        buscar->dano_ataque = nuevo_dano;
                        break;
                    }
                    case '4':
                        return; // Salir de la función
                    default:
                        cout << "\e[0;31mOpción inválida\e[0m" << endl;
                        break;
                }
                system("pause");
            }
            return; // Salir de la función después de modificar el zombie
        }
        buscar = buscar->prox;
    }
    cout << "\e[0;31mZombie no encontrado.\e[0m" << endl;
}

void modificar_estacion(nodo *lista) {
    if (lista == NULL) {
        cout << "La lista de estaciones está vacía." << endl;
        return;
    }
    
    string name;
    cout << "Ingrese el nombre de la estación a modificar: ";
    getline(cin, name);
    
    nodo* ubicacion = Buscar_estacion_nom(lista, name);
    if (ubicacion == NULL) {
        cout << "\e[0;31mEstación no encontrada.\e[0m" << endl;
        return;
    }

    char opcion = '0';
    while (opcion != '4') {
        system("cls");
        cout << "              \e[47mModificar estación\e[0m" << endl;
        cout << "======================================================\n";
        cout << "1.- Editar nombre de la estación\n";
        cout << "2.- Editar zombies de la estación\n";
        cout << "3.- Editar estaciones adyacentes\n";
        cout << "4.- Salir del menú de modificación\n";
        cout << "======================================================\n";
        cout << "Ingrese la opción deseada del menú: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                string nuevo_nombre;
                int nuevo_numero;
                cout << "Ingrese el nuevo nombre: ";
                getline(cin, nuevo_nombre);
                cout << "Ingrese el nuevo número de la estación: ";
                cin >> nuevo_numero;
                modificar_nombre_est(ubicacion->estacion, nuevo_nombre, nuevo_numero);
                break;
            }
            case '2': {
                modificar_zombie_estacion(ubicacion->zombies_estacion);
                break;
            }
            case '3': {
                int nuevo_adyacente;
                int nueva_dist;
                int cantidad_adyacencias;
                cout << "Ingrese la nueva cantidad de estaciones adyacentes: ";
                cin >> cantidad_adyacencias;
                for (int i = 0; i < cantidad_adyacencias; i++) {
                    cout << "Ingrese el número de la nueva adyacencia: ";
                    cin >> nuevo_adyacente;
                    cout << "Ingrese la nueva distancia: ";
                    cin >> nueva_dist;
                    modificar_adyacencias(ubicacion->adyacencia, lista, nuevo_adyacente, nueva_dist);
                }
                break;
            }
            case '4':
                return; 
            default:
                cout << "\e[0;31mOpción inválida\e[0m" << endl;
                break;
        }
        system("pause");
    }
}

void eliminar_aristas_adyacentes(nodo* lista, int numero_est) {
    nodo* temp = lista;
    while (temp != NULL) {
        lista_adyacencia* actual = temp->adyacencia;
        lista_adyacencia* anterior = NULL;
        while (actual != NULL) {
            if (actual->numero_estacion == numero_est) {
                if (anterior == NULL) {
                    temp->adyacencia = actual->prox;
                } else {
                    anterior->prox = actual->prox;
                }
                delete actual;
                break;
            }
            anterior = actual;
            actual = actual->prox;
        }
        temp = temp->prox;
    }
}

void eliminar_arista_estacion(nodo* lista, string nombre_est) {
    nodo* temp = lista;
    while (temp != NULL) {
        lista_adyacencia* actual = temp->adyacencia;
        lista_adyacencia* anterior = NULL;
        while (actual != NULL) {
            if (actual->nombre_estacion == nombre_est) {
                if (anterior == NULL) {
                    temp->adyacencia = actual->prox;
                } else {
                    anterior->prox = actual->prox;
                }
                lista_adyacencia* arista_a_eliminar = actual;
                actual = actual->prox;
                delete arista_a_eliminar;
            } else {
                anterior = actual;
                actual = actual->prox;
            }
        }
        temp = temp->prox;
    }
}

void eliminar_vertice(nodo*& lista) {
    nodo* temp = lista;
    nodo* anterior = NULL;
    string nom_est;
    cout << "Ingrese el nombre de la estacion a eliminar: ";
    getline(cin, nom_est);

    // Buscar el vértice a eliminar
    while (temp != NULL && temp->estacion != nom_est) {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) {
        cout << "\e[0;31mEstación no encontrada.\e[0m" << endl;
        return;
    }

    // Eliminar las aristas que apuntan a este vértice
    eliminar_aristas_adyacentes(lista, temp->numero_estacion);

    // Eliminar el vértice de la lista
    if (anterior == NULL) {
        lista = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }

    // Eliminar las aristas y zombies del vértice
    while (temp->adyacencia != NULL) {
        lista_adyacencia* arista_a_eliminar = temp->adyacencia;
        temp->adyacencia = temp->adyacencia->prox;
        delete arista_a_eliminar;
    }

    while (temp->zombies_estacion != NULL) {
        zombies_estaciones* zombie_a_eliminar = temp->zombies_estacion;
        temp->zombies_estacion = temp->zombies_estacion->prox;
        delete zombie_a_eliminar;
    }

    eliminar_arista_estacion(lista, nom_est);

    cout << "\e[0;32mLa estación " << temp->estacion << " fue eliminada con éxito.\e[0m" << endl;
    delete temp;
}

void mostrar_menu() {
    cout << "              \e[47mMenu principal\e[0m" << endl;
    cout << "======================================================\n";
    cout << "1.- Cargar mapa\n";
    cout << "2.- Agregar estacion\n";
    cout << "3.- Agregar adyacencias\n";
    cout << "4.- Agregar zombies\n";
    cout << "5.- Mostrar estaciones\n";
    cout << "6.- Modificar estacion\n";
    cout << "7.- Eliminar estacion\n";
    cout << "8.- Salir\n";
    cout << "======================================================\n";
    cout << "Ingrese la opcion deseada del menu: ";
}

int generar_dado(int limiteinf, int limitesup) {    
    //system("pause");
    static default_random_engine generador(time(nullptr));
    uniform_int_distribution<int> distribucion(limiteinf, limitesup);
    return distribucion(generador);
}

zombies_estaciones*zombie_menor_vida(zombies_estaciones*lista_zombies)
{
    if(lista_zombies==NULL)
    {
        return NULL;
    }
    zombies_estaciones*mover=lista_zombies;
    zombies_estaciones*menor=nuevo_zombies(mover->nombre_zombie,mover->vida,mover->dano_ataque,mover->cantidad_zombies);
    
    while(mover!=NULL)
    {
        if(mover->vida<menor->vida)
        {
            menor->cantidad_zombies=mover->cantidad_zombies;
            menor->dano_ataque=mover->dano_ataque;
            menor->nombre_zombie=mover->nombre_zombie;
            menor->vida=mover->vida;
        }  
        mover=mover->prox;
    }
    return menor;
}
int accesorio_menor_dano(accesorio*lista_accesorios)
{
    if(listaVaciaAccesorios(lista_accesorios))
    {
        return 0;
    }
    accesorio*mover=lista_accesorios;
    bool primero_accesorio=false;
    int dano_accesorio=0;
    while(mover!=NULL)
    {
        if(mover->tipo=="Ataque" && primero_accesorio==false)
        {
            dano_accesorio=mover->modificador;
            primero_accesorio=true;
        }
        if(mover->tipo=="Ataque" && mover->modificador<dano_accesorio)
        {
            dano_accesorio=mover->modificador;
        }
        mover=mover->prox;
    }
    //mover->usos=mover->usos-1;
    return dano_accesorio;   
}

void accesorio_menor_dano_durabilidad(accesorio** lista_accesorios) {
    if (listaVaciaAccesorios(*lista_accesorios)) {
        return;
    }

    accesorio* mover = *lista_accesorios;
    accesorio* menor_accesorio = NULL;

    while (mover != NULL) {
        if (mover->tipo == "Ataque") {
            if (menor_accesorio == NULL || mover->modificador < menor_accesorio->modificador) {
                menor_accesorio = mover;
            }
        }
        mover = mover->prox;
    }

    if (menor_accesorio != NULL) {
        menor_accesorio->usos =menor_accesorio->usos-1;
    }
}

void eliminar_zombie_por_cantidad(zombies_estaciones** Lista_zombies, int cantidad)
{
    if(listaVaciaZombiesEstaciones(*Lista_zombies))  
    {
        return;
    }

    zombies_estaciones* actual = (*Lista_zombies);
    zombies_estaciones* anterior = NULL;

    while(actual != NULL && actual->cantidad_zombies != cantidad)
    {
        anterior = actual;
        actual = actual->prox;
    }

    if(actual == NULL)
    {
       return; 
    }
    else
    {
        if(actual == (*Lista_zombies))  // Si es el primer elemento
        {
            (*Lista_zombies) = (*Lista_zombies)->prox;
        }
        else
        {
            anterior->prox = actual->prox;
        }
        delete actual;
    }
}

void eliminar_zombie_por_cantidad2(zombies_estaciones** lista_zombies, int cantidad) {
    if ((*lista_zombies) == NULL) {
        return;
    }

    zombies_estaciones* actual = *lista_zombies;
    zombies_estaciones* anterior = NULL;

    while (actual != NULL) {
        if (actual->cantidad_zombies == cantidad) {
            if (anterior == NULL) {
                
                *lista_zombies = actual->prox;
                delete actual;
                actual = *lista_zombies;
            } else {                
                anterior->prox = actual->prox;
                delete actual;
                actual = anterior->prox;
            }
        } else {
            anterior = actual;
            actual = actual->prox;
        }
    }
}


void actualizar_zombie(zombies_estaciones** lista_zombies, zombies_estaciones* zombie_actualizado) {
    if (lista_zombies == NULL || *lista_zombies == NULL || zombie_actualizado == NULL) {
        return;
    }

    zombies_estaciones* mover = *lista_zombies;
    while (mover != NULL) {
        if (mover->nombre_zombie == zombie_actualizado->nombre_zombie) {
            mover->vida = zombie_actualizado->vida;
            mover->dano_ataque = zombie_actualizado->dano_ataque;
            mover->cantidad_zombies = zombie_actualizado->cantidad_zombies;
            return;
        }
        mover = mover->prox;
    }
}

jugador* buscar_jugador_por_id(jugador* lista_jugadores, int id) {
    if (lista_vacia_jugador(lista_jugadores)) {
        cout << "No hay jugadores en el grupo." << endl;
        return NULL;
    }

    jugador* mover = lista_jugadores;
    int cont=1;
    while(mover != NULL) {
        if (cont== id) {
            
            return mover;
        }
        mover = mover->prox;
        cont++;
    }
    return mover;
}

int accesorio_defensa_juagdor(accesorio*lista_accesorios)
{
    if(listaVaciaAccesorios(lista_accesorios))
    {
        return 0;
    }
    accesorio*mover=lista_accesorios;
    bool primero_accesorio=false;
    int defensa_accesorio=0;
    while(mover!=NULL)
    {
        if(mover->tipo=="Defensa" && primero_accesorio==false)
        {
            defensa_accesorio=mover->modificador;
            primero_accesorio=true;
        }
        if(mover->tipo=="Defensa" && mover->modificador>defensa_accesorio)
        {
            defensa_accesorio=mover->modificador;
        }
        mover=mover->prox;
    }
    if(mover==NULL and primero_accesorio==false)
    {
        defensa_accesorio=0;
        return defensa_accesorio;
    }
    return defensa_accesorio;   
}



int retribucion_de_dano(int dano_zombie, int defensa_jugador)
{
    int dano_retribuido=defensa_jugador-dano_zombie;
    if(dano_retribuido>0)
    {
        dano_retribuido=0;
    }
    return dano_retribuido;
}

void accesorio_menor_defensa_durabilidad(accesorio** lista_accesorios) {
    if (listaVaciaAccesorios(*lista_accesorios)) {
        return;
    }

    accesorio* mover = *lista_accesorios;
    accesorio* menor_accesorio = NULL;

    while (mover != NULL) {
        if (mover->tipo == "Defensa") {
            if (menor_accesorio == NULL || mover->modificador > menor_accesorio->modificador) {
                menor_accesorio = mover;
            }
        }
        mover = mover->prox;
    }

    if (menor_accesorio != NULL) {
        menor_accesorio->usos =menor_accesorio->usos-1;
    }
}


accesorio*buscar_accesorio_de_supervivencia_menor(accesorio*lista_accesorios)
{
    if(listaVaciaAccesorios(lista_accesorios))
    {
        return NULL;
    }
    accesorio*mover=lista_accesorios;    
    while(mover!=NULL)
    {
        if(mover->tipo=="Supervivencia")
        {
           return mover;
        }
        mover=mover->prox;
    }
    return mover;
}

accesorio*buscar_accesorio_de_defensa(accesorio*lista_accesorios)
{
    if(listaVaciaAccesorios(lista_accesorios))
    {
        return NULL;
    }
    accesorio*mover=lista_accesorios;
    bool primero_accesorio=false;
    accesorio*defensa_accesorio=NULL;
    while(mover!=NULL)
    {
        if(mover->tipo=="Defensa" and primero_accesorio==false)
        {
            defensa_accesorio=crear_accesorio(mover->usos,mover->modificador,mover->nombre,mover->tipo,mover->codigo);
            primero_accesorio=true;
        }
        if(mover->tipo=="Defensa" and mover->modificador>defensa_accesorio->modificador)
        {
            defensa_accesorio->codigo=mover->codigo;
            defensa_accesorio->modificador=mover->modificador;
            defensa_accesorio->nombre=mover->nombre;
            defensa_accesorio->tipo=mover->tipo;
            defensa_accesorio->usos=mover->usos;
        }
        mover=mover->prox;
    }
    return defensa_accesorio; 
}
void accesorio_menor_supervivencia_durabilidad(accesorio** lista_accesorios) {
    if (listaVaciaAccesorios(*lista_accesorios)) {
        return;
    }

    accesorio* mover = *lista_accesorios;
    accesorio* menor_accesorio = NULL;

    while (mover != NULL) {
        if (mover->tipo == "Supervivencia") {
            if (menor_accesorio == NULL || mover->modificador < menor_accesorio->modificador) {
                menor_accesorio = mover;
            }
        }
        mover = mover->prox;
    }

    if (menor_accesorio != NULL) {
        menor_accesorio->usos =menor_accesorio->usos-1;
    }
}

void actualizar_vida_soldado(jugador** lista_jugadores,jugador*jugador_atacado)
{
    jugador*mover=*lista_jugadores;
    while(mover!=NULL)
    {
        if(mover->nombre==jugador_atacado->nombre)
        {
            mover->salud=jugador_atacado->salud;
        }
        mover=mover->prox;
    }
}

jugador* jugador_menor_vida(jugador* lista_jugadores) {
    if (lista_jugadores == NULL) {
        return NULL;
    }

    jugador* menor = lista_jugadores;
    jugador* mover = lista_jugadores->prox;

    while (mover != NULL) {
        if (mover->salud < menor->salud) {
            menor = mover;
        }
        mover = mover->prox;
    }

    return menor;
}
void eliminar_jugadores_por_vida(jugador** lista_soldado, int vida_limite) {
    if (lista_vacia_jugador(*lista_soldado)) {
        cout << "No hay soldados a eliminar" << endl;
        return;
    }

    jugador* actual = *lista_soldado;
    jugador* anterior = NULL;

    while (actual != NULL) {
        if (actual->salud <= vida_limite) {
            if (anterior == NULL) {
                *lista_soldado = actual->prox;
            } else {
                anterior->prox = actual->prox;
            }

            accesorio* borrar_accesorio = actual->accesorio_jugador;
            while (borrar_accesorio != NULL) {
                accesorio* aux = borrar_accesorio;
                borrar_accesorio = borrar_accesorio->prox;
                delete aux;
            }

            jugador* aux = actual;
            actual = actual->prox;
            delete aux;
        } else {
            anterior = actual;
            actual = actual->prox;
        }
    }
}

void juego2(grupo** lista_grupos, nodo** camino) {
    bool primer_golpe=false;    
    if (*camino == NULL) {
        cout << "No hay un camino seleccionado, seleccione algún camino en el menú." << endl;
        return;
    }

    if (listaVaciaGrupo(*lista_grupos)) {
        cout << "No hay grupos creados, cree un grupo para poder jugar." << endl;
        return;
    }

    grupo* actual = buscar_grupo2(&(*lista_grupos));
    if (actual == NULL) {
        cout << "No se encontró el grupo." << endl;
        return;
    }

    mostrar_grupos(actual);
    if (lista_vacia_jugador(actual->grupo_jugador)) {
        cout << "No hay jugadores en el grupo, agregue jugadores para poder jugar." << endl;
        return;
    }

    nodo* mover = (*camino);
    while (mover != NULL && actual != NULL) {
            while(!listaVaciaZombiesEstaciones(mover->zombies_estacion)) {
            cout << "Estación actual: " << mover->estacion << endl;
            cout << "Grupo actual: " << actual->nombre_grupo << endl;
            cout << "Cantidad de zombies en la estación: " << contar_zombies(mover->zombies_estacion) << endl;
            mostrar_zombies_estaciones(mover->zombies_estacion);
            system("pause");
            system("cls");

            jugador* mover_dano = actual->grupo_jugador;
            int dano_grupo = 0;
            int numero_max_jugadores = 0;
        
            while (mover_dano != NULL) {
                numero_max_jugadores++;
                dano_grupo += accesorio_menor_dano(mover_dano->accesorio_jugador);
                accesorio_menor_dano_durabilidad(&mover_dano->accesorio_jugador);
                eliminar_accesorio_por_durabilidad(&mover_dano->accesorio_jugador, 0);
                mover_dano = mover_dano->prox;
            }

            zombies_estaciones* zombie_con_menor_vida = zombie_menor_vida(mover->zombies_estacion);
            while (dano_grupo >= zombie_con_menor_vida->vida && zombie_con_menor_vida->cantidad_zombies != 0) {
                int vida = zombie_con_menor_vida->vida;
                dano_grupo -= vida;
                zombie_con_menor_vida->cantidad_zombies -= 1;                                
                cout<<"El grupo: "<<actual->nombre_grupo<<" a eliminado a zombie: "<<zombie_con_menor_vida->nombre_zombie<<endl;                               
                
            }
            cout<<"El grupo: "<<actual->nombre_grupo<<" a perdido un uso en su arma correspondiente y ataco con un poder combinado de: "<<dano_grupo<<endl;
            system("pause");
            system("cls");                        
            actualizar_zombie(&mover->zombies_estacion, zombie_con_menor_vida);
            if(dano_grupo<=zombie_con_menor_vida->vida)
            {
                cout<<"El grupo: "<<actual->nombre_grupo<<" No a logrado despejar el lugar "<<endl;
                //cout<<"Quedan:"<<endl;
                //mostrar_zombies_estaciones(mover->zombies_estacion);
                system("pause");
                system("cls");
            }

            if (zombie_con_menor_vida->cantidad_zombies == 0) {
                eliminar_zombie_por_cantidad(&mover->zombies_estacion, 0);                
                //mostrar_zombies_estaciones(mover->zombies_estacion);                
            }

            if (listaVaciaZombiesEstaciones(mover->zombies_estacion)) {
                cout << "Grupo " << actual->nombre_grupo << " ha sobrevivido un día más." << endl;
                mover = mover->prox;
                primer_golpe=false;
                system("pause");
                system("cls"); 
                break;
            }
            

            

            cout<<"Los zombies atacan a los jugadores"<<endl;
            zombies_estaciones* zombies_atacantes = mover->zombies_estacion;
            int dano_zombies = 0;
            
                        
            while(zombies_atacantes!=NULL)
            {
                dano_zombies=dano_zombies+(zombies_atacantes->cantidad_zombies*zombies_atacantes->dano_ataque);
                zombies_atacantes=zombies_atacantes->prox;
            }
            if(primer_golpe==false)
            {
                int id_persona_atacada=generar_dado(1,actual->numero_miembros);                
                jugador*jugador_atacado=buscar_jugador_por_id(actual->grupo_jugador,id_persona_atacada);                             
                int defensa_jugador=accesorio_defensa_juagdor(jugador_atacado->accesorio_jugador);                 
                accesorio_menor_defensa_durabilidad(&jugador_atacado->accesorio_jugador);                
                int danos_retribuido=retribucion_de_dano(dano_zombies,defensa_jugador);
               
                jugador_atacado->salud=jugador_atacado->salud+danos_retribuido;
                accesorio*accesorio_defensa=buscar_accesorio_de_defensa(jugador_atacado->accesorio_jugador);
                cout<<"El jugador: "<<jugador_atacado->nombre<<" a sido atacado por los zombies y recibio: "<< danos_retribuido<<endl;
                if(accesorio_defensa!=NULL)
                {
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" a sido salvado por el accesorio de defensa: "<< accesorio_defensa->nombre<<endl;
                    //eliminar_accesorio_por_durabilidad(&mover_dano->accesorio_jugador, 0);
                }
                else{
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" no tiene accesorios de defensa"<<endl;
                    //eliminar_accesorio_por_durabilidad(&mover_dano->accesorio_jugador, 0);
                }
                accesorio*accesorio_supervivencia=buscar_accesorio_de_supervivencia_menor(jugador_atacado->accesorio_jugador);
                
                if(accesorio_supervivencia!=NULL)
                {
                    accesorio_menor_supervivencia_durabilidad(&jugador_atacado->accesorio_jugador);
                    jugador_atacado->salud=jugador_atacado->salud+accesorio_supervivencia->modificador;
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" a sido salvado por el accesorio de supervivencia: "<< accesorio_supervivencia->nombre<< "y recupero: "<<accesorio_supervivencia->modificador<<endl;
                }
                else{
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" no tiene accesorios de supervivencia"<<endl;
                    system("pause");
                    system("cls");
                    cout<<"El grupo: "<<actual->nombre_grupo<<" No a logrado despejar el lugar "<<endl;
                }
                
                actualizar_vida_soldado(&actual->grupo_jugador,jugador_atacado);
                //eliminar_jugadores_por_vida(&actual->grupo_jugador, 0);
                if(lista_vacia_jugador(actual->grupo_jugador))
                {
                    cout<<"El grupo: "<<actual->nombre_grupo<<" a sido eliminado por los zombies"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
                primer_golpe=true;                
            }
            else{
                
                jugador*jugador_atacado=jugador_menor_vida(actual->grupo_jugador);
                int defensa_jugador=accesorio_defensa_juagdor(jugador_atacado->accesorio_jugador);
                accesorio_menor_defensa_durabilidad(&jugador_atacado->accesorio_jugador);
                int danos_retribuido=retribucion_de_dano(dano_zombies,defensa_jugador);
                jugador_atacado->salud=jugador_atacado->salud+danos_retribuido;
                accesorio*accesorio_defensa=buscar_accesorio_de_defensa(jugador_atacado->accesorio_jugador);
                cout<<"El jugador: "<<jugador_atacado->nombre<<" a sido atacado por los zombies y recibio: "<< danos_retribuido<<endl;
                if(accesorio_defensa!=NULL)
                {
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" a sido salvado por el accesorio de defensa: "<< accesorio_defensa->nombre<<endl;
                    //eliminar_accesorio_por_durabilidad(&mover_dano->accesorio_jugador, 0);
                }
                else{
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" no tiene accesorios de defensa"<<endl;
                }
                accesorio*accesorio_supervivencia=buscar_accesorio_de_supervivencia_menor(jugador_atacado->accesorio_jugador);
                
                if(accesorio_supervivencia!=NULL)
                {
                    accesorio_menor_supervivencia_durabilidad(&jugador_atacado->accesorio_jugador);
                    jugador_atacado->salud=jugador_atacado->salud+accesorio_supervivencia->modificador;
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" a sido salvado por el accesorio de supervivencia: "<< accesorio_supervivencia->nombre<< "y recupero: "<<accesorio_supervivencia->modificador<<endl;
                    //eliminar_accesorio_por_durabilidad(&mover_dano->accesorio_jugador, 0);
                }
                else{
                    cout<<"El jugador: "<<jugador_atacado->nombre<<" no tiene accesorios de supervivencia"<<endl;
                    system("pause");
                    system("cls");
                    cout<<"El grupo: "<<actual->nombre_grupo<<" No a logrado despejar el lugar "<<endl;
                }
                
                actualizar_vida_soldado(&actual->grupo_jugador,jugador_atacado);
                //eliminar_jugadores_por_vida(&actual->grupo_jugador, 0);
                if(lista_vacia_jugador(actual->grupo_jugador))
                {
                    cout<<"El grupo: "<<actual->nombre_grupo<<" a sido eliminado por los zombies"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }

            }
            system("pause");
            system("cls");
            
            

            

        }
        if (mover == NULL) {
            cout << "El grupo " << actual->nombre_grupo << " ha salvado al mundo." << endl;
            return;
        }
        if(lista_vacia_jugador(actual->grupo_jugador))
        {
            eliminar_grupo(&(*lista_grupos),actual->nombre_grupo);
            if(listaVaciaGrupo(*lista_grupos))
            {
                cout<<"La Humanidad a sido eliminada por los zombies"<<endl;
                return;
            }            
        }
       
        
    }
}



#endif