#ifndef ACCESORIOS_H
#define ACCESORIOS_H
#include <iostream>
#include <string>
using namespace std;

struct accesorio {
   string nombre;
   string tipo;
   int modificador_dano = 0;
   int modificador_vida = 0;
   int modificador_reduccion_dao = 0;
   accesorio* prox;
};

// Función para crear un nuevo accesorio
accesorio* crear_accesorio(string nom,string tipo, int mod_dano, int mod_vida, int mod_reduccion_dao) {
   accesorio* nuevo = new accesorio;
   nuevo->nombre = nom;
   nuevo->tipo=tipo;
   nuevo->modificador_dano = mod_dano;
   nuevo->modificador_vida = mod_vida;
   nuevo->modificador_reduccion_dao = mod_reduccion_dao;
   nuevo->prox = NULL;
   return nuevo;
}

// Verifica si la lista de accesorios está vacía
bool listaVaciaAccesorios(accesorio* lista) {
   return lista == NULL;
}

// Muestra la lista de accesorios
void mostrarListaAccesorios(accesorio* lista) {
   accesorio* mover = lista;
   if (!listaVaciaAccesorios(lista)) {
      while (mover != NULL) {
         cout << endl << "-------------------------------------------------------" << endl;
         cout << "Nombre del accesorio: " << mover->nombre << endl;
         cout << "Tipo de accesorio: " << mover->tipo << endl;
         cout << "Modificador de dano: " << mover->modificador_dano << endl;
         cout << "Modificador de vida: " << mover->modificador_vida << endl;
         cout << "Modificador de reducción de daño: " << mover->modificador_reduccion_dao << endl;
         cout << "-------------------------------------------------------" << endl;
         mover = mover->prox;
      }
   } else {
      cout << "No hay accesorios escritos" << endl;
   }
}

// Inserta un accesorio al final de la lista
void insertar_ultimo_accesorio(accesorio** lista_accesorios, string nom,string tipo, int mod_dano, int mod_vida, int mod_reduccion_dao) {
   accesorio* nuevo_accesorio = crear_accesorio(nom,tipo, mod_dano, mod_vida, mod_reduccion_dao);
   if (listaVaciaAccesorios(*lista_accesorios)) {
      *lista_accesorios = nuevo_accesorio;
   } else {
      accesorio* aux = *lista_accesorios;
      while (aux->prox != NULL) {
         aux = aux->prox;
      }
      aux->prox = nuevo_accesorio;
   }
}

// Busca un accesorio en la lista por nombre
bool buscar_accesorio(accesorio* lista_accesorios, string nom) {
   if (listaVaciaAccesorios(lista_accesorios)) {
      cout << "No hay accesorios disponibles" << endl;
      return false;
   } else {
      accesorio* aux = lista_accesorios;
      while (aux != NULL) {
         if (aux->nombre == nom) {
            cout << "El accesorio: " << nom << " existe" << endl;
            return true;
         }
         aux = aux->prox;
      }
      cout << "El accesorio: " << nom << " no existe" << endl;
      return false;
   }
}

// Modifica los atributos de un accesorio
void modificar_accesorio(accesorio** lista_accesorios, string nom) {
   if (listaVaciaAccesorios(*lista_accesorios)) {
      cout << "Lista vacía" << endl;
      return;
   } else {
      accesorio* aux = *lista_accesorios;
      bool encontrado = false;

      while (aux != NULL && !encontrado) {
         if (aux->nombre == nom) {
            int opcion = 0;
            while (opcion != 6) {
               cout << "***********     MENU DE MODIFICACION    **********" << endl;
               cout << "1.- Editar Nombre del accesorio" << endl;
               cout << "1.- Cambiar tipo de accesorio" << endl;
               cout << "3.- Editar modificador de dano del accesorio" << endl;
               cout << "4.- Editar modificador de vida del accesorio" << endl;
               cout << "5.- Editar modificador de reduccion de dano del accesorio" << endl;
               cout << "6.- Salir del programa" << endl;

               cout << "Ingrese la opción deseada del menú: ";
               cin >> opcion;

               switch (opcion) {
                  case 1: {
                     string nombre;
                     cout << "Escriba un nuevo nombre: ";
                     cin >> nombre;
                     aux->nombre = nombre;
                     break;
                  }
                  case 2: {
                     string tipo;
                     cout << "Escriba el nuevo tipo ";
                     cin >> tipo;
                     aux->tipo = tipo;
                     break;
                  }
                  case 3: {
                     int mod_dano;
                     cout << "Redefina el modificador de daño: ";
                     cin >> mod_dano;
                     aux->modificador_dano = mod_dano;
                     break;
                  }
                  case 4: {
                     int mod_vida;
                     cout << "Redefina el modificador de vida: ";
                     cin >> mod_vida;
                     aux->modificador_vida = mod_vida;
                     break;
                  }
                  case 5: {
                     int mod_reduccion_dao;
                     cout << "Redefina el modificador de reducción de daño: ";
                     cin >> mod_reduccion_dao;
                     aux->modificador_reduccion_dao = mod_reduccion_dao;
                     break;
                  }
                  case 6: {
                     break;
                  }
                  default:
                     break;
               }
            }
            encontrado = true;
         }
         aux = aux->prox;
      }

      if (!encontrado) {
         cout << "Nombre no encontrado" << endl;
      }
   }
}

// Elimina un accesorio de la lista
void eliminar_accesorio(accesorio** lista_accesorios, string nom) {
   if (listaVaciaAccesorios(*lista_accesorios)) {
      cout << "Lista vacía" << endl;
      return;
   } else {
      accesorio* mover = *lista_accesorios;
      accesorio* anterior = NULL;

      while (mover != NULL && mover->nombre != nom) {
         anterior = mover;
         mover = mover->prox;
      }

      if (mover == NULL) {
         cout << "Accesorio no encontrado" << endl;
         return;
      } else {
         if (mover == *lista_accesorios) {
            *lista_accesorios = (*lista_accesorios)->prox;
         } else {
            anterior->prox = mover->prox;
         }
         delete mover;
      }
   }
}



#endif 