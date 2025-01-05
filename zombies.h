#ifndef ZOMBIES_H
#define ZOMBIES_H
#include <iostream>
#include <fstream>
#include <string>
#include<limits>
using namespace std;

struct zombies {
    string nombre;
    int salud;
    int cantidad_zombies;
    int dano_ataque;
    zombies *prox;
};

bool validar_nombre(const string& nombre) {
    for (char c : nombre) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool validar_entero(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

zombies* crear_zombies(string nom, int salud, int dano_ataque, int cantidad_zombies) {
    if (!validar_nombre(nom)) {
        cout << "Nombre inválido. Por favor, intente nuevamente." << endl;
        return nullptr;
    }
    if (salud < 0 || dano_ataque < 0 || cantidad_zombies < 0) {
        cout << "Valores negativos no son permitidos. Por favor, intente nuevamente." << endl;
        return nullptr;
    }

    zombies* zombie = new zombies;
    zombie->nombre = nom;
    zombie->salud = salud;
    zombie->cantidad_zombies = cantidad_zombies; // Asumimos que se crea un zombie a la vez
    zombie->dano_ataque = dano_ataque;
    zombie->prox = NULL;
    return zombie;
}

void mostrar_zombies(zombies *list) {
    if (list == NULL) {
        cout << "La lista de zombies está vacía" << endl;
    } else {
        zombies *mover = list;
        cout << "\n          \e[47m*****LISTA DE ZOMBIES*****\e[0m      \n";
        while (mover != NULL) {
            cout << "\n[zombie " << mover->nombre << "]";
            cout << "\nSalud: " << mover->salud;
            cout << "\nCantidad: " << mover->cantidad_zombies;
            cout << "\nDano de ataque: " << mover->dano_ataque;
            cout << endl << "============================================" << endl;
            mover = mover->prox;
        }
    }
}

void insertar_ultimo_zombie(zombies *&lista_zombies, string nom, int salud, int dano_ataque, int cantidad_zombies) {
    zombies* nuevo_zombie = crear_zombies(nom, salud, dano_ataque, cantidad_zombies);
    if (nuevo_zombie == nullptr) {
        return;
    }

    if (lista_zombies == NULL) {
        lista_zombies = nuevo_zombie;
    } else {
        zombies *temp = lista_zombies;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nuevo_zombie;
    }
}

void cargar_zombies(zombies *&lista) {
    ifstream lectura("Zombie.zmb", ios::in);
    
    if (!lectura) {
        cout << "\e[0;31mError al abrir el archivo.\e[0m" << endl;
        return;
    }
    int cantidad;
    string linea;
    lectura >> cantidad;
    getline(lectura, linea);

    string nombre_zombi;
    string salud;
    string dano;

    for (int i=0; i < cantidad; i++) {
        getline(lectura, linea);
        getline(lectura, nombre_zombi);
        getline(lectura, salud);
        int salud_zombie=stoi(salud);
        getline(lectura, dano);
        int dano_zombie=stoi(dano);
        insertar_ultimo_zombie(lista, nombre_zombi, salud_zombie, dano_zombie, 1);
    }

    lectura.close();
}

bool buscar_zombie(zombies *lista, string valor) {
    zombies *buscar = lista;
    while (buscar != NULL) {
        if (buscar->nombre == valor) {
            return true;
        }
        buscar = buscar->prox;
    }
    return false;
}

void modificar_nombre_zomb(zombies *list, string nuevo_valor, string actual_valor) {
    if (!validar_nombre(nuevo_valor)) {
        cout << "Nombre inválido. Por favor, intente nuevamente." << endl;
        return;
    }

    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nombre == actual_valor) {
            mover->nombre = nuevo_valor;
        }
        mover = mover->prox;
    }
}

void modificar_vida(zombies *list, int nuevo_valor, string tipo_zomb) {
    if (nuevo_valor < 0) {
        cout << "Valor de salud inválido. Por favor, intente nuevamente." << endl;
        return;
    }

    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nombre == tipo_zomb) {
            mover->salud = nuevo_valor;
        }
        mover = mover->prox;
    }
}

void modificar_dano(zombies *list, int nuevo_valor, string tipo_zomb) {
    if (nuevo_valor < 0) {
        cout << "Valor de daño inválido. Por favor, intente nuevamente." << endl;
        return;
    }

    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nombre == tipo_zomb) {
            mover->dano_ataque = nuevo_valor;
        }
        mover = mover->prox;
    }
}

void modificar_zombie(zombies *lista) {
    if (lista == NULL) {
        cout << "\e[0;31mLa lista de zombies está vacía\e[0m" << endl;
        return;
    }
    
    string name;
    cout << "Ingrese el nombre del zombie a modificar: ";
    cin >> name;
    while (!validar_nombre(name)) {
        cout << "Nombre inválido. Por favor, intente nuevamente: ";
        cin >> name;
    }
    
    zombies* buscar = lista;
    while (buscar != NULL) {
        if (buscar->nombre == name) {
            char opcion = '0';
            while (opcion != '4') {
                system("cls");
                cout << "              \e[47mModificar zombies\e[0m" << endl;
                cout << "1. Modificar nombre" << endl;
                cout << "2. Modificar vida" << endl;
                cout << "3. Modificar daño" << endl;
                cout << "4. Salir" << endl;
                cout << "Seleccione una opción: ";
                cin >> opcion;

              switch (opcion) {
                    case '1': {
                        string nuevo_nombre;
                        cout << "Ingrese el nuevo nombre: ";
                        cin >> nuevo_nombre;
                        modificar_nombre_zomb(lista, nuevo_nombre, name);
                        break;
                    }
                    case '2': {
                        int nueva_vida;
                        cout << "Ingrese la nueva vida: ";
                        while (!(cin >> nueva_vida) || nueva_vida < 0) {
                            cout << "Valor de vida inválido. Por favor, intente nuevamente: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        modificar_vida(lista, nueva_vida, name);
                        break;
                    }
                    case '3': {
                        int nuevo_dano;
                        cout << "Ingrese el nuevo daño: ";
                        while (!(cin >> nuevo_dano) || nuevo_dano < 0) {
                            cout << "Valor de daño inválido. Por favor, intente nuevamente: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        modificar_dano(lista, nuevo_dano, name);
                        break;
                    }
                    case '4': 
                    cout << "Saliendo..." << endl;
                        break;
                    default:
                        cout << "Opción inválida. Por favor, intente nuevamente." << endl;
                        break;
                }
            }
            return;
        }
        buscar = buscar->prox;
    }
    cout << "\e[0;31mZombie no encontrado\e[0m" << endl;
} 

void eliminar(zombies*& lista_zombies, string valor) {
   if (lista_zombies==NULL) {
      cout << "\e[0;31mLista vacia\e[0m" << endl;
      return;
   }

   zombies* mover = lista_zombies;
   zombies* anterior = NULL;

   while (mover != NULL && mover->nombre != valor) {
      anterior = mover;
      mover = mover->prox;
   }

   if (mover == NULL) {
      cout << "\e[0;31mZombie no encontrado\e[0m" << endl;
      return;
    } 
    else{
      if (mover == lista_zombies) {
         lista_zombies = lista_zombies->prox;
      } 
      else {
         anterior->prox = mover->prox;
      }
      delete mover;
   }
}

void eliminar_apariciones(zombies*& inicio, string nombre_zombie) {
   zombies* aux = inicio;
   zombies* anterior = NULL;
   int contador = 0;

   while (aux != NULL) {
      if (aux->nombre == nombre_zombie) {
         zombies* a_eliminar = aux; 
         if (anterior == NULL) {
               inicio = aux->prox;
               aux = inicio;
         } 
         else{

            anterior->prox = aux->prox;
            aux = anterior->prox; 
         }
         delete a_eliminar;
         contador++;
      } 
      else {
         anterior = aux; 
         aux = aux->prox; 
      }
   }

   cout << "\e[0;32mTotal de elementos eliminados: \e[0m" << contador << endl;
}

void llenar_zombie(zombies *&list) {
    int cantidad;
    cout << "Ingrese la cantidad de zombies que desea agregar: ";
    while (!(cin >> cantidad) || cantidad < 0) {
        cout << "Cantidad inválida. Por favor, intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string nombre;
    cout << "Ingrese el tipo de zombie: ";
    cin >> nombre;
    while (!validar_nombre(nombre)) {
        cout << "Nombre inválido. Por favor, intente nuevamente: ";
        cin >> nombre;
    }

    int vida;
    cout << "Ingrese la vida del zombie: ";
    while (!(cin >> vida) || vida < 0) {
        cout << "Valor de vida inválido. Por favor, intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
int ataque;
    cout << "Ingrese el ataque del zombie: ";
    while (!(cin >> ataque) || ataque < 0) {
        cout << "Valor de ataque inválido. Por favor, intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    insertar_ultimo_zombie(list, nombre, vida, ataque, cantidad);
}

#endif 

