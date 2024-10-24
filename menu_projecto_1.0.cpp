#include "zombies.h"
#include "grupos.h" 
#include <fstream>

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
                            while (opcion != '7') {
                            cout << "***********     MENU DE OPCIONES     **********" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "1.- Modificar zombie" << endl;
                            cout << "2.- Agregar un nodo al final de la Lista" << endl;
                            cout << "3.- Agregar varios nodos al final de la Lista" << endl;
                            cout << "4.- Mostrar contenido de la Lista" << endl;
                            cout << "5.- Eliminar un nodo de la Lista" << endl;
                            cout << "6.- Buscar un elemento en la Lista" << endl;
                            cout << "7.- Salir del programa" << endl;
                            cout << "-----------------------------------------------" << endl;

                            cout << "Ingrese la opcion deseada del Menu: ";
                            cin >> opcion;

                            switch (opcion) {
                                case '1':
                                    modificar_zombie(&lista_zombies,pedir_nombre());
                                    break;
                                case '2':
                                    {
                                        string nombre; 
                                        int salud = 0, dano_zombie = 0, nivel = 0;
                                        cout << "ingrese el nombre del zombie: ";
                                        cin >> nombre;
                                        cout << "ingrese el nivel del zombie: ";
                                        cin >> nivel;
                                        cout << "ingrese el salud del zombie: ";
                                        cin >> salud;
                                        cout << "ingrese el dano del zombie: ";
                                        cin >> dano_zombie;
                                        insertar_ultimo_zombie(&lista_zombies, nombre, nivel, salud, dano_zombie); 
                                    }
                                    break;
                                case '3': 
                                    {
                                        int cantidad, i = 1;
                                        cout << "Indica cantidad de nodos a ser colocados: ";
                                        cin >> cantidad;
                                        if (cantidad <= 0) {
                                            cout << "Cantidad no válida." << endl;
                                            break;
                                        }
                                        while (i <= cantidad) {
                                            string nombre; int salud, dano_zombie, nivel = 0;
                                            cout << "ingrese el nombre del zombie: ";
                                            cin >> nombre;
                                            cout << "ingrese el nivel del zombie: ";
                                            cin >> nivel;
                                            cout << "ingrese el salud del zombie: ";
                                            cin >> salud;
                                            cout << "ingrese el dano del zombie: ";
                                            cin >> dano_zombie;
                                            insertar_ultimo_zombie(&lista_zombies, nombre, nivel, salud, dano_zombie); 
                                            i++;
                                        }
                                    }
                                    break;
                                case '4': 
                                    if (listaVaciaZombies(lista_zombies))
                                        cout << "Lista vacia, no es posible mostrar su contenido" << endl;
                                    else
                                        mostrarlistaZombies(lista_zombies);
                                    break;     
                                case '5': 
                                    if (listaVaciaZombies(lista_zombies))
                                        cout << "Lista vacia, no es posible eliminar" << endl;
                                    else
                                        eliminar(&lista_zombies, pedir_nombre());
                                    break;  
                                case '6': 
                                    if (listaVaciaZombies(lista_zombies))
                                        cout << "Lista vacia, no es posible hacer una busqueda" << endl;
                                    else
                                        buscar_zombie(lista_zombies, pedir_nombre());
                                    break;  
                                case '7':
                                    cout << "Adios" << endl;
                                    break;
                                default: 
                                    cout << "Opción inválida. Intente nuevamente." << endl;
                            }
                            }


                                cout<<"falta programar";
                                system("pause");
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
                                                    mostrarListaJugador_armas_accesorios(lista_soldados);
                                                    system("pause");
                                                break;
                                                case '3':
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
                                        system("pause");
                                    break;
                                    case '2':
                                        agregar_arma_soldado(&lista_soldados);
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
    delete lista_zombies;
    delete arma; 
    delete lista_soldados;
    return 0;
}