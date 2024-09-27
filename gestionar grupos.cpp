#include <iostream>
#include <fstream>
using namespace std;

struct jugador{
    string nombre;
    int salud=100; /*La salud en este caso es la vida y siempre inicializa con 100 según el PDF*/
    int afectacion=0; /*Afectacion viene siendo los daños que resive el jugador*/
    jugador *prox;
};

void lista_jugador(jugador *&inicio){ /*La función crea el archivo en donde se guardará la información de la estructura jugador*/
    string escribir_nombre;
    int escribir_salud=100; 
    int escribir_afectacion=0;
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
            avanzar->prox = avanzar;
    }
}

void mostrar_lista_jugador(jugador *inicio){
   jugador *mostrar_jugador;

    if (inicio!=NULL){
        mostrar_jugador = inicio;
        while (mostrar_jugador != NULL){
            cout<<"[Nombre: "<<mostrar_jugador->nombre<<"; vida: "<<mostrar_jugador->salud<<", Afectacion: "<<mostrar_jugador->afectacion<<"]\n";
            mostrar_jugador = mostrar_jugador->prox;
        }
        cout<<"NULL"<<endl;
    }  
    else
        cout<<"Lista esta vacia"<<endl;
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
        cout<<"Ingrese una opcion: ";
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
                    cout<<"Ingrese una opcion: ";
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
                                cout<<"2.3.4. Consultar equipo "<<"\n";
                                cout<<"2.3.5. Volver "<<"\n";
                                cout<<"======================================"<<"\n";
                                cout<<"Ingrese una opcion: ";
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
                                            cout<<"Ingrese una opcion: ";
                                            cin>>opcion;
                                            switch (opcion){
                                                case 1:
                                                    lista_jugador(lista_soldados);
                                                    system("pause");
                                                break;
                                                case 2:
                                                    cout<<"\n\n";
                                                    mostrar_lista_jugador(lista_soldados);
                                                    system("pause");
                                                break;
                                            }
                                        }
                                        system("pause");
                                    break;
                                    case 2:
                                        cout<<"falta programar";
                                        system("pause");
                                    break;
                                    case 3:
                                        cout<<"falta programar";
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