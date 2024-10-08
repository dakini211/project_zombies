//IMPORTACIÓN DE LIBRERIAS.
#include <iostream>
#include <fstream>
using namespace std;

struct jugador{
    string nombre;
    int salud=100; /*La salud en este caso es la vida y siempre inicializa con 100 según el PDF*/
    int afectacion=0; /*Afectacion viene siendo los daños que resive el jugador*/
    jugador *prox;
};

jugador *crear_jugador(string nom, int sald, int afect){
    jugador *nuevo_jugador =new jugador;
    nuevo_jugador->nombre=nom;
    nuevo_jugador->salud=sald;
    nuevo_jugador->afectacion=afect;
    nuevo_jugador->prox=NULL;
    return nuevo_jugador;
}

bool lista_vacia(jugador *soldado){
    return soldado==NULL;
}

void insertar_Ultimo_jugador(jugador *&inicio, string nom, int sald, int afect){
    jugador *nuevo = crear_jugador(nom, sald, afect);
 
   if (lista_vacia(inicio)) {
       inicio = nuevo;
    } 
    else {
       jugador *mover = inicio;
       while (mover->prox != NULL) {
           mover = mover->prox;
       }
        mover->prox = nuevo;
  } 
}

void lista_jugador(jugador *&inicio){ /*La función crea la lista en donde se guardará la información de la estructura jugador*/
    string escribir_nombre;
    int escribir_salud=100; 
    int escribir_afectacion=0;
    int cantidad;
    cout<<"ingrese el numero de jugadores: ";
    cin>>cantidad;
    for(int i=0; i<cantidad; i++){
        cout<<"Ingrese jugador: ";
        cin>>escribir_nombre;
        insertar_Ultimo_jugador(inicio, escribir_nombre, escribir_salud, escribir_afectacion);
    }
    
}

void mostrar_lista_jugador(jugador *inicio){ /*Esta función mostrará a cada jugador que se llenó en la lista*/
    cout<<"\n\n";
   jugador *mostrar_jugador;

    if (!lista_vacia(inicio)){
        mostrar_jugador = inicio;
        while (!lista_vacia(mostrar_jugador)){
            cout<<"[Nombre: "<<mostrar_jugador->nombre<<"; vida: "<<mostrar_jugador->salud<<", Afectacion: "<<mostrar_jugador->afectacion<<"]\n";
            mostrar_jugador = mostrar_jugador->prox;
        }
    }  
    else
        cout<<"Lista esta vacia"<<endl;
}

void buscarElemento(jugador *primero, string valor) {
    jugador *buscar = primero; 
    bool encontrado = false;
    if (lista_vacia(primero))
    cout<<"Lista vacia\n";
     else{   
        while (!lista_vacia(buscar) && encontrado == false) {
            if (buscar->nombre == valor){
                encontrado = true;
                string nuevo_nombre;
                cout<<"Ingrese el nuevo nombre del jugador: ";
                cin>>nuevo_nombre; 
                verificar_existe_jugador(primero, nuevo_nombre); //acomodar...
            }
            else 
                buscar = buscar->prox;
        }
        if (encontrado == false)
            cout<<"El jugador no fue encontrado en la lista."<<endl;
        }   
}

void verificar_existe_jugador(jugador *inicio, string buscar_nombre){
    jugador *buscar_2=inicio;
    bool encontrado_2=false;
    while(!lista_vacia(buscar_2) && encontrado_2==false){
        if(buscar_2->nombre==buscar_nombre){
            encontrado_2=true;
            cout<<"Este usuario ya existe\n";
        }
        else{
            if(buscar_2->nombre != buscar_nombre){
                buscar_2=buscar_2->prox;
            }
            if(lista_vacia(buscar_2)){
                buscar_2->nombre=buscar_nombre;
            }
        }      
    }
}

void modificar_jugador(jugador *&inicio){ /*Esta funcion busca y cambia al jugador a modificar,por haora modifica el nombre */
    string nombre_aux;                    /*pero mas adelante se mejorará si es necesario modificarle la salud y afectación*/
    cout<<"Ingresa jugador a modificar: ";
    cin>>nombre_aux;
    buscarElemento(inicio, nombre_aux);
}

void eliminar_jugador_lista(jugador *&inicio){ /* Su función lo dice, elimina al jugador */
    jugador *eliminar_jugador;
    jugador *auxiliar = NULL; 
    string nombre_aux;
    cout<<"Ingresa jugador a eliminar: ";
    cin>>nombre_aux;
    if (inicio==NULL)
       cout<<"Lista esta vacia"<<endl;
    else {   
        eliminar_jugador = inicio;
        while (eliminar_jugador != NULL && eliminar_jugador->nombre != nombre_aux){
            auxiliar = eliminar_jugador;
            eliminar_jugador = eliminar_jugador->prox;
        }
        if (eliminar_jugador == NULL)
             cout<<"El elemento no existe en la lista "<<endl;
        else{
            if (eliminar_jugador == inicio)
                inicio=inicio->prox;
            else
                auxiliar->prox = eliminar_jugador->prox;
            delete eliminar_jugador;
            cout<<"El jugador "<< eliminar_jugador->nombre<<" se elimino con exito!!!\n"; 
        }    
    }
}

int main(){
    jugador *lista_soldados=NULL;
    int opcion;
    while (opcion!=4){
        system("cls");
        cout<<"        Menu        "<<"\n";
        cout<<"Cristian Teran"<<"\n";
        cout<<"Maximiliano Urdaneta"<<"\n";
        cout<<"Javier Bonilla"<<"\n";
        cout<<"===================="<<"\n";
        cout<<"1. Jugar "<<"\n";
        cout<<"2. Opciones "<<"\n";
        cout<<"3. Reglas "<<"\n";
        cout<<"4. Salir "<<"\n";
        cout<<"===================="<<"\n";
        cout<<"Ingrese una opcion (1 al 4): ";
        cin>>opcion;
        switch (opcion){
            case 1:
                cout<<"falta programar"<<"\n";
                system("pause");
            break;
            case 2: 
                while(opcion!=5){
                    system("cls");
                    cout<<"        2. Opciones        "<<"\n";
                    cout<<"==========================="<<"\n";
                    cout<<"2.1. Gestionar zombies "<<"\n";
                    cout<<"2.2. Gestionar accesorios "<<"\n";
                    cout<<"2.3. Gestionar equipos "<<"\n";
                    cout<<"2.4. Gestionar mapas "<<"\n";
                    cout<<"2.5. Volver "<<"\n";
                    cout<<"==========================="<<"\n";
                    cout<<"Ingrese una opcion (1 al 5): ";
                    cin>>opcion;
                    switch (opcion){
                        case 1:
                            cout<<"falta programar";
                            system("pause");
                        break;
                        case 2:
                            cout<<"falta programar";
                            system("pause");
                        break;
                        case 3:
                            while(opcion!=4){
                                system("cls");
                                cout<<"        2.3. Gestionar equipos        "<<"\n";
                                cout<<"======================================"<<"\n";
                                cout<<"2.3.1. Agregar soldado "<<"\n";
                                cout<<"2.3.2. Modificar soldado "<<"\n";
                                cout<<"2.3.3. Eliminar soldado "<<"\n";
                                cout<<"2.3.4. Volver "<<"\n";
                                cout<<"======================================"<<"\n";
                                cout<<"Ingrese una opcion (1 al 4): ";
                                cin>>opcion;
                                switch (opcion){
                                    case 1:
                                        while(opcion!=3){                                        
                                            system("cls");
                                            cout<<"        2.3.1 Agregar soldado       "<<"\n";
                                            cout<<"======================================"<<"\n";
                                            cout<<"2.3.1.1. Crear soldado "<<"\n";
                                            cout<<"2.3.1.2. Consultar equipo "<<"\n";
                                            cout<<"2.3.1.3. Volver "<<"\n";
                                            cout<<"======================================"<<"\n";
                                            cout<<"Ingrese una opcion (1 al 3): ";
                                            cin>>opcion;
                                            switch (opcion){
                                                case 1:
                                                    lista_jugador(lista_soldados);
                                                    system("pause");
                                                break;
                                                case 2:                                                   
                                                    mostrar_lista_jugador(lista_soldados);
                                                    system("pause");
                                                break;
                                            }
                                        }
                                        system("pause");
                                    break;
                                    case 2:
                                        modificar_jugador(lista_soldados);
                                        system("pause");
                                    break;
                                    case 3:
                                        eliminar_jugador_lista(lista_soldados);
                                        system("pause");
                                    break;
                                }
                            }
                        break;
                        case 4:
                            cout<<"falta programar"<<"\n";
                            system("pause");
                        break;                   
                    }
                }
            case 3:
                cout<<"falta programar";
                system("pause");
            break;
        }
    } 
    return 0;
}
