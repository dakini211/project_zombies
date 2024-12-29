#ifndef ZOMBIES_H
#define ZOMBIES_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct zombies {
    string nombre;
    int salud;
    int cantidad_zombies;
    int dano_ataque;
    zombies *prox;
};

zombies* crear_zombies(string nom, int salud, int dano_ataque, int cantidad_zombies) {
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
    if (lista_zombies == NULL) {
        lista_zombies = nuevo_zombie;
    } else {
        zombies* aux = lista_zombies;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nuevo_zombie;
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
    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nombre == actual_valor) {
            mover->nombre = nuevo_valor;
        }
        mover = mover->prox;
    }
}

void modificar_vida(zombies *list, int nuevo_valor, string tipo_zomb) {
    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nombre == tipo_zomb) {
            mover->salud = nuevo_valor;
        }
        mover = mover->prox;
    }
}

void modificar_dano(zombies *list, int nuevo_valor, string tipo_zomb) {
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
        cout << "\e[0;31mLa lista de zombies esta vacia\e[0m" << endl;
        return;
    }
    
    string name;
    cout << "Ingrese el nombre del zombie a modificar: ";
    cin >> name;
    
    zombies* buscar = lista;
    while (buscar != NULL) {
        if (buscar->nombre == name) {
            char opcion;
            while (opcion!='4') {
                system("cls");
                cout << "              \e[47Modificar zombies\e[0m" << endl;
                cout << "======================================================\n";
                cout << "1.- Editar nombre del zombie\n";
                cout << "2.- Editar vida del zombie\n";
                cout << "3.- Editar dano del zombie\n";
                cout << "4.- Salir del menu de modificacion\n";
                cout << "======================================================\n";
                cout << "Ingrese la opcion deseada del menu: ";
                cin >> opcion;

                switch (opcion) {
                    case '1': {
                        string nuevo_nombre;
                        cout << "Ingrese el nuevo nombre: ";
                        cin >> nuevo_nombre;
                        modificar_nombre_zomb(lista, nuevo_nombre, buscar->nombre);
                        break;
                    }
                    case '2': {
                        int nueva_salud;
                        cout << "Ingrese la nueva salud: ";
                        cin >> nueva_salud;
                        modificar_vida(lista, nueva_salud, buscar->nombre);
                        break;
                    }
                    case '3': {
                        int nuevo_dano;
                        cout << "Ingrese el nuevo dano: ";
                        cin >> nuevo_dano;
                        modificar_dano(lista, nuevo_dano, buscar->nombre);
                        break;
                    }
                    case '4':
                        return; // Salir de la función
                    default:
                        cout << "\e[0;31mOpcion invalida\e[0m" << endl;
                        break;
                }
                system("pause");
            }
        }
        buscar = buscar->prox;
    }
    cout << "\e[0;31mZombie no encontrado.\e[0m" << endl;
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

void llenar_zombie(zombies *&list){
    int cantidad;
    cout << "Ingrese la cantidad de zombies que desea agregar: ";
    cin >> cantidad;
        string nombre;
        cout<<"Ingrese el tipo de zombie: ";
        cin>>nombre;
        int vida;
        cout<<"Ingrese la vida del zombie: ";
        cin>>vida;
        int ataque;
        cout<<"Ingrese el ataque del zombie: ";
        cin>>ataque;
        insertar_ultimo_zombie(list, nombre, vida, ataque, cantidad);
}

#endif 
