#include <iostream>
#include "mapa.h"
#include "zombies.h"
using namespace std;

int main(){
    mapa *lista_mapa=NULL;
    zombies *lista_zombies=NULL;
    string estacion;
    char opcion;
    while(opcion!='3'){
            system("cls");
        cout << "            MENU   \n";
        cout<<"===================================="<<"\n";
        cout << " 1. gestinar zombies" << endl;
        cout << " 2. Gestionar mapa" << endl;
        cout << " 3. Volver" << endl;
        cout<<"===================================="<<"\n";
        cout<<"Ingrese una opcion (1 al 3): ";
        cin>>opcion;
        switch (opcion){
            case '1':
                while (opcion != '5') {
                    system("cls");
                    cout << "          2.1. Gestionar zombies      " << endl;
                    cout << "-----------------------------------------------" << endl;
                    cout << "1.- Agregar zombie" << endl;
                    cout << "2.- Mostrar zombies" << endl;
                    cout << "3.- Modificar zombie" << endl;
                    cout << "4.- Eliminar tipo de zombie" << endl;
                    cout << "5.- Volver" << endl;
                    cout << "-----------------------------------------------" << endl;
                    cout << "Ingrese la opcion deseada (1 al 5): ";
                    cin >> opcion;

                    switch (opcion) {
                        case '1': 
                            while (opcion != '6') {
                                system("cls");
                                cout << "*********** 2.1.1.- Agregar zombie **********" << endl;
                                cout << "-----------------------------------------------" << endl;
                                cout << "1.- Rapidos y agiles" << endl;
                                cout << "2.- Tanques" << endl;
                                cout << "3.- Inteligentes" << endl;
                                cout << "4.- Infectados por hongos" << endl;
                                cout << "5.- Bioluminicentes" << endl;
                                cout << "6.- Volver" << endl;
                                cout << "-----------------------------------------------" << endl;
                                cout << "Ingrese la opcion deseada (1 al 6): ";
                                cin >> opcion;

                                switch (opcion) {
                                    case '1':
                                        insertar_ultimo_zombie(&lista_zombies, "Rapidos y agiles", 4, 0, 20);
                                        break;
                                    case '2':
                                        insertar_ultimo_zombie(&lista_zombies, "Tanques", 5, 0, 25);
                                        break;
                                    case '3':
                                        insertar_ultimo_zombie(&lista_zombies, "Inteligentes", 3, 0, 15);
                                        break;
                                    case '4':
                                        insertar_ultimo_zombie(&lista_zombies, "Infectados por hongos", 2, 0, 10);
                                        break;
                                    case '5':
                                        insertar_ultimo_zombie(&lista_zombies, "Bioluminicentes", 1, 0, 5);
                                        break;
                                    case '6':
                                        break;
                                    default:
                                        cout << "Opcion invalida, vuelva a intentarlo" << endl;
                                }
                                system("pause");
                            }
                        break;
                        case '2':
                            if (listaVaciaZombies(lista_zombies))
                                cout << "Lista vacia, no es posible mostrar su contenido" << endl;
                            else
                                mostrarlistaZombies(lista_zombies);
                            system("pause");
                        break;
                    }
            break;
            case '2':
                while (opcion != '6') {
                    system("cls");
                    cout << "    2.3. Gestionar mapa    \n";
                    cout<<"===================================="<<"\n";
                    cout << " 2.3.1. Crear estacion" << endl;
                    cout << " 2.3.2. Añadir zombie a estacion" << endl;
                    cout << " 2.3.3. Mostrar mapa" << endl;
                    cout << " 2.3.4. modificar estacion" << endl;
                    cout << " 2.3.5. Eliminar estacion" << endl;
                    cout << " 2.3.6. Volver" << endl;
                    cout<<"===================================="<<"\n";
                    cout<<"Ingrese una opcion (1 al 5): ";
                    cin >> opcion;
                    switch (opcion) {
                        case '1':
                            system("cls");
                            cout << "    2.3.1. Crear estacion    \n";
                            cout<<"================================="<<"\n";
                            insertar_Ultimo_mapa(lista_mapa, pedir_dato_estacion());
                            cout<<"La estacion se creo con exito!!! si desea crear otra estacion ingrese a 'Crear estacion'\n";
                            system("pause");
                        break;
                        case '2'    :
                            system("cls");
                            cout << "          Añadir zombie a estacion     " << endl;
                            cout<<"==================================================="<<"\n";
                            agregar_zombies_mapa(lista_zombies, lista_mapa);
                            system("pause");
                        break;
                        case '3':
                        system("cls");
                            cout << "          Mostrar mapa     " << endl;
                            cout<<"==================================================="<<"\n";
                            mostrar_mapa(lista_mapa);
                            system("pause");
                        break;
                        case '4':
                            while(opcion!='3'){
                                system("cls");
                                cout << "           modificar estacion          " << endl;
                                cout<<"==================================================="<<"\n";
                                cout << " 1. Modificar nombre estacion" << endl;
                                cout << " 2. modificar tipo de zombies" << endl;
                                cout << " 3. volver" << endl;
                                cout<<"==================================================="<<"\n";
                                cout<<"Ingrese una opcion (1 al 3): ";
                                cin>>opcion;
                                switch (opcion){
                                case '1':
                                    modificar_estacion(lista_mapa);
                                    break;

                                case '2':
                                    modificar_tipo_zombi(lista_mapa, lista_zombies);
                                    system("pause");
                                break;
                                
                                default:
                                    cout<<"Opcion invalida.\n";
                                break;
                                }
                            }
                            system("pause");
                        break;
                        case '5':
                            system("cls");
                            cout << "           Eliminar estacion          " << endl;
                            cout<<"==================================================="<<"\n";
                            eliminar_estacion(&lista_mapa, pedir_dato_estacion());
                            system("pause");
                        break;
                        default:
                            cout<<"Opcion invalida.\n";
                            system("pause");
                        break;
                    }
                }
            break;
            default:
                cout<<"Opcion invalida.\n";
                system("pause");
            break;
        }
    }
}
}