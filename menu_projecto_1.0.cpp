#include "zombies.h"
#include "grupos.h" 
using namespace std;

int main()
{
    jugador *lista_soldados = NULL;
    arma *arma = NULL;
    grupo *lista_grupo = NULL;
    zombies *lista_zombies = NULL;
    char opcion = '0'; // Inicializamos la opción

    while (opcion != '4') {
        system("cls");
        cout << "        Menu        " << "\n";
        cout << "Cristian Teran" << "\n";
        cout << "Maximiliano Urdaneta" << "\n";
        cout << "Javier Bonilla" << "\n";
        cout << "====================" << "\n";
        cout << "1. Jugar " << "\n";
        cout << "2. Opciones " << "\n";
        cout << "3. Reglas " << "\n";
        cout << "4. Salir " << "\n";
        cout << "====================" << "\n";
        cout << "Ingrese una opcion (1 al 4): ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                cout << "Esta opción no está disponible aún." << "\n";
                system("pause");
                break;

            case '2': {
                char opcion_opciones = '0'; // Variable para las opciones del submenú

                while (opcion_opciones != '4') {
                    system("cls");
                    cout << "        2. Opciones        " << "\n";
                    cout << "===========================" << "\n";
                    cout << "1. Gestionar zombies " << "\n";
                    cout << "2. Gestionar grupos " << "\n";
                    cout << "3. Gestionar mapas " << "\n";
                    cout << "4. Volver " << "\n";
                    cout << "===========================" << "\n";
                    cout << "Ingrese una opcion (1 al 4): ";
                    cin >> opcion_opciones;

                    switch (opcion_opciones) {
                        case '1': {
                            char opcion_zombies = '0';
                            while (opcion_zombies != '5') {
                                system("cls");
                                cout << "          2.1. Gestionar zombies      " << endl;
                                cout << "-----------------------------------------------" << endl;
                                cout << "1.- Agregar zombie" << endl;
                                cout << "2.- Modificar zombie" << endl;
                                cout << "3.- Mostrar zombies" << endl;
                                cout << "4.- Eliminar tipo de zombie" << endl;
                                cout << "5.- Volver" << endl;
                                cout << "-----------------------------------------------" << endl;
                                cout << "Ingrese la opcion deseada (1 al 5): ";
                                cin >> opcion_zombies;

                                switch (opcion_zombies) {
                                    case '1': {
                                        char tipo_zombie = '0';
                                        while (tipo_zombie != '6') {
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
                                            cin >> tipo_zombie;

                                            switch (tipo_zombie) {
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
                                    }
                                    case '2':
                                        modificar_zombie(lista_zombies);
                                        system("pause");
                                        break;
                                    case '3':
                                        if (listaVaciaZombies(lista_zombies))
                                            cout << "Lista vacia, no es posible mostrar su contenido" << endl;
                                        else
                                            mostrarlistaZombies(lista_zombies);
                                        system("pause");
                                        break;
                                    case '4': {
                                        char tipo_eliminar = '0';
                                        while (tipo_eliminar != '6') {
                                            system("cls");
                                            cout << "*********** 2.1.4.- Eliminar tipo de zombie **********" << endl;
                                            cout << "-----------------------------------------------" << endl;
                                            cout << "1.- Rapidos y agiles" << endl;
                                            cout << "2.- Tanques" << endl;
                                            cout << "3.- Inteligentes" << endl;
                                            cout << "4.- Infectados por hongos" << endl;
                                            cout << "5.- Bioluminicentes" << endl;
                                            cout << "6.- Volver" << endl;
                                            cout << "-----------------------------------------------" << endl;
                                            cout << "Ingrese la opcion deseada (1 al 6): ";
                                            cin >> tipo_eliminar;

                                            switch (tipo_eliminar) {
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
                                                    break;
                                                default:
                                                    cout << "Opcion invalida, vuelva a intentarlo" << endl;
                                            }
                                            system("pause");
                                        }
                                        break;
                                    }
                                    case '5':
                                        break;
                                    default:
                                        cout << "Opcion invalida, vuelva a intentarlo" << endl;
                                }
                            }
                            break;
                        }
                        case '2': {
                            char opcion_grupos = '0';
                            while (opcion_grupos != '5') {
                                system("cls");
                                cout << "        2.3. Gestionar Grupos        " << "\n";
                                cout << "======================================" << "\n";
                                cout << "1. Agregar Grupo " << "\n";
                                cout << "2. Modificar Grupo " << "\n";
                                cout << "3. Eliminar Grupos " << "\n";
                                cout << "4. Mostrar Grupo " << "\n";
                                cout << "5. Volver " << "\n";
                                cout << "======================================" << "\n";
                                cout << "Ingrese una opcion (1 al 5): ";
                                cin >> opcion_grupos;

                                switch (opcion_grupos) {
                                    case '1':
                                        insertar_ultimo_grupos(&lista_grupo);
                                        system("pause");
                                        break;
                                    case '2':
                                        modificar_grupo(&lista_grupo);
                                        system("pause");
                                        break;
                                    case '3':
                                        eliminar_grupo(&lista_grupo, pedir_nombre_grupo());
                                        mostrar_grupos(lista_grupo);
                                        system("pause");
                                        break;
                                    case '4':
                                        mostrar_grupos(lista_grupo);
                                        system("pause");
                                        break;
                                    case '5':
                                        break;
                                    default:
                                        cout << "Opcion invalida, vuelva a intentarlo" << endl;
                                        system("pause");
                                }
                            }
                            break;
                        }
                        case '3':
                            cout << "Esta opción no está disponible aún." << "\n";
                            system("pause");
                            break;

                        case '4':
                            break;

                        default:
                            cout << "Opción inválida. Intente nuevamente." << endl;
                            system("pause");
                            break;
                    }
                }
                break;
            }

            case '3':
                cout << "Reglas del juego no disponibles aún." << "\n";
                system("pause");
                break;

            case '4':
                cout << "Gracias por jugar." << "\n";
                break;

            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                system("pause");
        }
    }

    // Liberación de memoria
    delete lista_soldados;
    delete lista_zombies;
    delete arma;
    delete lista_grupo;

    return 0;
}