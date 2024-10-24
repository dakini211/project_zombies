#include "zombies.h"
#include "grupos.h" 
using namespace std;

int main(){
    jugador *lista_soldados=NULL;
    arma*arma=NULL;
    char opcion;
    zombies *lista_zombies = NULL;
    while (opcion!='4'){
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
            case '1':
                cout<<"falta programar"<<"\n";
                system("pause");
            break;
            case '2': 
                while(opcion!='5'){
                    system("cls");
                    cout<<"        2. Opciones        "<<"\n";
                    cout<<"==========================="<<"\n";
                    cout<<"2.1. Gestionar zombies "<<"\n";
                    cout<<"2.2. Gestionar mochila "<<"\n";
                    cout<<"2.3. Gestionar equipos "<<"\n";
                    cout<<"2.4. Gestionar mapas "<<"\n";
                    cout<<"2.5. Volver "<<"\n";
                    cout<<"==========================="<<"\n";
                    cout<<"Ingrese una opcion (1 al 5): ";
                    cin>>opcion;
                    switch (opcion){
                        case '1':
                            while (opcion != '6') {
                            system("cls");
                            cout << "          2.1. Gestionar zombies      " << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "2.1.1.- Agregar zombie" << endl;
                            cout << "2.1.2.- Modificar zombie" << endl;
                            cout << "2.1.3.- Mostrar zombies" << endl;
                            cout << "2.1.4.- Eliminar tipo de zombie" << endl;
                            cout << "2.1.5.- Salir del programa" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Ingrese la opcion deseada del Menu del (1 al 5): ";
                            cin >> opcion;

                            switch (opcion) {
                                case '1':
                                    while(opcion!='6'){
                                        system("cls");
                                        cout << "*********** 2.1.1.- Agregar zombie **********" << endl;
                                        cout << "-----------------------------------------------" << endl;
                                        cout << "2.1.1.1.- Rapidos y agiles" << endl;
                                        cout << "2.1.1.2.- Tanques" << endl;
                                        cout << "2.1.1.3.- Inteligentes" << endl;
                                        cout << "2.1.1.4.- Infectados por hongos" << endl;
                                        cout << "2.1.1.5.- Bioluminicentes" << endl;
                                        cout << "2.1.1.6.- volver" << endl;
                                        cout << "-----------------------------------------------" << endl;
                                        cout << "Ingrese la opcion deseada del Menu del (1 al 6): ";
                                        cin >> opcion;
                                        switch (opcion){
                                            case '1':
                                                insertar_ultimo_zombie(&lista_zombies,"Rapidos y agiles", 4, 0, 20);
                                                system("pause");
                                            break;
                                            case '2':
                                                insertar_ultimo_zombie(&lista_zombies,"Tanques", 5, 0, 25);
                                                system("pause");
                                            break;
                                            case '3':
                                                insertar_ultimo_zombie(&lista_zombies,"Inteligentes", 3, 0, 15);
                                                system("pause");
                                            break;
                                            case '4':
                                                insertar_ultimo_zombie(&lista_zombies,"Infectados por hongos", 2, 0, 10);
                                                system("pause");
                                            break;
                                            case '5':
                                                insertar_ultimo_zombie(&lista_zombies,"Bioluminicentes", 1, 0, 5);
                                                system("pause");
                                            break;
                                            case '6':
                                            cout<<"adios.";
                                            break;
                                            default:
                                                cout << "Opcion invalida, vuelva a intentarlo" << endl;
                                            break;
                                        }
                                    }
                                    break;
                                case '2':
                                    modificar_zombie(lista_zombies);    
                                    break;
                                case '3': 
                                    if (listaVaciaZombies(lista_zombies))
                                        cout << "Lista vacia, no es posible mostrar su contenido" << endl;
                                    else{
                                        mostrarlistaZombies(lista_zombies);
                                    }
                                    system("pause");
                                    break;     
                                case '4': 
                                    while(opcion!='6'){
                                        system("cls");
                                        cout << "*********** 2.1.4.- Eliminar tipo de zombie **********" << endl;
                                        cout << "-----------------------------------------------" << endl;
                                        cout << "1.1.- Rapidos y agiles" << endl;
                                        cout << "1.2.- Tanques" << endl;
                                        cout << "1.3.- Inteligentes" << endl;
                                        cout << "1.4.- Infectados por hongos" << endl;
                                        cout << "1.5.- Bioluminicentes" << endl;
                                        cout << "1.6.- volver" << endl;
                                        cout << "-----------------------------------------------" << endl;
                                        cout << "Ingrese la opcion deseada del Menu del (1 al 6): ";
                                        cin >> opcion;
                                        switch(opcion){
                                            case '1':
                                                eliminar_apariciones(lista_zombies, "Rapidos y agiles");
                                            break;
                                            case '2':
                                                eliminar_apariciones(lista_zombies, "Tanques");
                                            break;
                                            case '3':
                                                eliminar_apariciones(lista_zombies, "Inteligentes");
                                            break;
                                            case '4':
                                                eliminar_apariciones(lista_zombies, "Infectados por hongos");
                                            break;
                                            case '5':
                                                eliminar_apariciones(lista_zombies, "Bioluminicentes");
                                            break;
                                            case '6':
                                                cout<<"adios";
                                            break;
                                            default:
                                                cout << "Opcion invalida, vuelva a intentarlo" << endl;
                                            break;
                                        }
                                    }  
                                case '5':
                                    cout<<"adios.\n"; 
                                break;  
                                default: 
                                    cout << "Opción inválida. Intente nuevamente.\n" << endl;
                            }
                            }
                        break;
                        case '2':
                            insertar_ultimo_armas(&arma);
                            mostrar_arma(arma);
                            system("pause");
                        break;
                        case '3':
                            while(opcion!='4'){
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
                                    case '1':
                                        while(opcion!='3'){                                        
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
                                                case '1':
                                                    insertar_ultimo_jugador(&lista_soldados);
                                                    system("pause");
                                                break;
                                                case '2':                                                   
                                                    mostrarListaJugador(lista_soldados);
                                                    system("pause");
                                                break;
                                                case '3':                                                    
                                                break;
                                                default:
                                                    cout<<"\e[47m \e[0m";
                                                    cout<<"\e[41mERROR, no esta en las opciones vuelva a intentar\e[0m";
                                                    cout<<"\e[47m \e[0m\n\n";
                                                    system("pause");
                                                break; 
                                            }
                                        }
                                        system("pause");
                                    break;
                                    case '2':
                                        //agregar_arma_soldado(&lista_soldados);
                                        //agregar_accesorio_soldado(&lista_soldados);
                                        modificar_soldado(&lista_soldados);
                                        system("pause");
                                        system("cls");                                   
                                        mostrarListaJugador_armas_accesorios(lista_soldados);
                                        system("pause");
                                    break;
                                    case '3':
                                        eliminar_jugador(&lista_soldados,pedir_nombre());
                                        mostrarListaJugador_armas_accesorios(lista_soldados);
                                        system("pause");
                                    break;
                                    case '4':
                                        system("pause");
                                    break;
                                    default:
                                        cout<<"\e[47m \e[0m";
                                        cout<<"\e[41mERROR, no esta en las opciones vuelva a intentar\e[0m";
                                        cout<<"\e[47m \e[0m\n\n";
                                        system("pause");
                                    break;
                                }
                            }
                        break;
                        case '4':
                            cout<<"falta programar"<<"\n";
                            system("pause");
                        break; 
                        case '5':
                            system("pause");
                        break;
                        default:
                            cout<<"\e[47m \e[0m";
                            cout<<"\e[41mERROR, no esta en las opciones vuelva a intentar\e[0m";
                            cout<<"\e[47m \e[0m\n\n";
                            system("pause");
                        break;                  
                    }
                }
            case '3':
                cout<<"falta programar";
                system("pause");
            break;
            case '4':
                delete lista_zombies;
                delete arma;
                system("pause");
            break;
            default:
                cout<<"\e[47m \e[0m";
                cout<<"\e[41mERROR, no esta en las opciones vuelva a intentar\e[0m";
                cout<<"\e[47m \e[0m\n\n";
                system("pause");
            break;
        }
    }
    delete lista_soldados;
    delete lista_zombies;
    delete arma;
    return 0;
}
