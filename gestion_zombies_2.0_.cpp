#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo *prox;
};

Nodo* crearNodo(int valor) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = valor;
  nuevo->prox = NULL;
  return nuevo;
}

bool listaVacia(Nodo *inicio){
    return inicio==NULL;
}

void mostrarLista(Nodo *inicio){
   Nodo *mover;

   if (!listaVacia(inicio)){
       mover = inicio;
      while (mover != NULL)
        {
           cout << mover->dato <<"->";
           mover = mover->prox;
         }
         cout<<"NULL"<<endl;
   }  
  else
     cout<<"Lista esta vacia"<<endl;
}

void insertarUltimo(Nodo **inicio, int valor){
    Nodo *nuevo = crearNodo(valor);
 
   if (listaVacia(*inicio)) {
       *inicio = nuevo;
    } 
    else {
       Nodo *auxiliar = *inicio;
       while (auxiliar->prox != NULL) {
           auxiliar = auxiliar->prox;
       }
        auxiliar->prox = nuevo;
  }
   
}

void eliminar(Nodo **inicio, int valor){
    Nodo *mover,*anterior = NULL; 
   
    if (listaVacia(*inicio))
       cout<<"Lista esta vacia"<<endl;
    else {   
        mover = *inicio;
        while (mover != NULL && mover->dato != valor){
             anterior = mover;
             mover = mover->prox;
         }
        if (mover == NULL)
             cout<<"El elemento no existe en la lista "<<endl;
        else
           { if (mover == *inicio)
                *inicio=(*inicio)->prox;
             else
                anterior->prox = mover->prox;
             delete mover;  
           }      
   }

}

void insertarPrincipio(Nodo **inicio, int valor) {
  Nodo *nuevo = crearNodo(valor);
  nuevo->prox = *inicio;
  *inicio = nuevo;
}

void buscarElemento(Nodo *inicio, int valor) {
  Nodo *aux = inicio; bool encontrado = false;
  if (listaVacia(inicio))
     cout<<"Lista vacia"<<endl;
  else
    {   
      while (aux != NULL && encontrado == false) {
         if (aux->dato == valor) {
            cout<<"El dato "<<valor<< " fue encontrado con exito"<<endl;
            encontrado = true;
         }
      else 
          aux = aux->prox;
     }
     if (encontrado == false)
        cout<<"Valor no encontrado en la lista "<<endl;
    }   
}

int pedir_valor(){
   int valor;
   cout<<"Indica valor: ";
   cin>>valor;
   return valor;
}

main(){
  int opcion=0;
  Nodo *primero = NULL;
  
  while (opcion!=7) {
     
    cout<<"***********     MENU DE OPCIONES     **********"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"1.- Agregar un nodo al inicio de la Lista"<<endl;
    cout<<"2.- Agregar un nodo al final de la Lista"<<endl;
    cout<<"3.- Agregar varios nodos al final de la Lista"<<endl;
    cout<<"4.- Mostrar contenido de la Lista"<<endl;
    cout<<"5.- Eliminar un nodo de la Lista"<<endl;
    cout<<"6.- Buscar un elemento en la Lista"<<endl;
    cout<<"7.- Salir del programa"<<endl;
    cout<<"-----------------------------------------------"<<endl;

    cout << "Ingrese la opcion deseada del Menu: ";
    cin >> opcion;


     switch (opcion) {
       case 1:
         // Agregar un nodo al inicio de la Lista
         insertarPrincipio(&primero, pedir_valor());
         break;
       case 2:
         // Agregar un Nodo al final de la Lista
         insertarUltimo(&primero,pedir_valor()); 
         break;
       case 3: {
         // Agregar varios Nodos al final de la Lista
         int cantidad,i=1;
         cout<<"Indica cantidad de nodos a ser colocados: ";
         cin>>cantidad;
         while (i <= cantidad) {
             insertarUltimo(&primero,pedir_valor());
             i++;
          }
         }
         break;
         
       case 4: 
         // Mostrar contenido de la lista
         if (listaVacia(primero))
             cout<<"Lista vacia, no es posible mostrar su contenido"<<endl;
         else
              mostrarLista(primero);
          break;     
      
       case 5: 
         // Eliminar un elemento lista
         if (listaVacia(primero))
            cout<<"Lista vacia, no es posible eliminar"<<endl;
         else
             eliminar(&primero, pedir_valor());
         break;  

      case 6: 
         // Buscar un elemento en la lista
         if (listaVacia(primero))
            cout<<"Lista vacia, no es posible hacer una busqueda"<<endl;
         else
             buscarElemento(primero, pedir_valor());
         break;  

       case 7:
           cout<<"Hasta la vista baby";
           break;
       default: if (opcion < 1 || opcion > 7) 
           cout << "Opción inválida. Intente nuevamente." << endl;

     }

   }

}  
