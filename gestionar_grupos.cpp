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
        jugador *nuevo_jugador =new jugador;
        nuevo_jugador->nombre=escribir_nombre;
        nuevo_jugador->salud=escribir_salud;
        nuevo_jugador->afectacion=escribir_afectacion;
        nuevo_jugador->prox=NULL;
        if (inicio==NULL) {
            inicio = nuevo_jugador;
        } 
        else {
            jugador *avanzar = inicio;
            while (avanzar->prox != NULL) {
                avanzar = avanzar->prox;
            }
            avanzar->prox = nuevo_jugador;
        }
    }
    
}

void mostrar_lista_jugador(jugador *inicio){ /*Esta función mostrará a cada jugador que se llenó en la lista*/
    cout<<"\n\n";
   jugador *mostrar_jugador;

    if (inicio!=NULL){
        mostrar_jugador = inicio;
        while (mostrar_jugador != NULL){
            cout<<"[Nombre: "<<mostrar_jugador->nombre<<"; vida: "<<mostrar_jugador->salud<<", Afectacion: "<<mostrar_jugador->afectacion<<"]\n";
            mostrar_jugador = mostrar_jugador->prox;
        }
    }  
    else
        cout<<"Lista esta vacia"<<endl;
}

void modificar_jugador(jugador *&inicio){ /*Esta funcion busca y cambia al jugador a modificar,por haora modifica el nombre */
    jugador *buscar=inicio;               /*pero mas adelante se mejorará si es necesario modificarle la salud y afectación*/
    string nombre_aux;
    bool encontrado_1=false;
    bool encontrado_2=false;
    cout<<"Ingresa jugador a modificar: ";
    cin>>nombre_aux;
    if (inicio==NULL)
        cout<<"Lista vacia\n";
    else{   
        while (buscar != NULL && encontrado_1 == false) {
            if (buscar->nombre == nombre_aux) {
                jugador *buscar_2=inicio;
                encontrado_1 = true;
                string nuevo_nombre;
                cout<<"Ingrese el nuevo nombre del jugador: ";
                cin>>nuevo_nombre;
                while(buscar_2 != NULL && encontrado_2==false){
                    if(buscar_2->nombre==nuevo_nombre){
                        encontrado_2=true;
                        cout<<"Este usuario ya existe\n";
                    }
                    else{
                        if(buscar_2->nombre != nuevo_nombre){
                            buscar_2=buscar_2->prox;
                        }
                        if(buscar_2==NULL){
                            buscar->nombre=nuevo_nombre;
                        }
                    }      
                }    
            }
            else 
                buscar = buscar->prox;
        }
        if (encontrado_1 == false)
            cout<<"El jugador no fue encontrado en la lista."<<endl;
    } 
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
