#include "zombies.h"
//#include "mapa.h"
#include "grupos.h" 
#include <fstream>
using namespace std;

int main(){

    jugador *lista_soldados = NULL;
    arma *arma = NULL;
    grupo *lista_grupo = NULL;
    zombies *lista_zombies = NULL;
    //mapa *lista_mapa=NULL;
    ifstream leer_zombies;
    char opcion = '0'; // Inicializamos la opción

    while (opcion != '4') {
        system("cls");
        cout << "        \e[47mMenu\e[0m        " << "\n";
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
                    cout << "        \e[47mOpciones\e[0m        " << "\n";
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
                            while (opcion_zombies != '6') {
                                system("cls");
                                cout << "          \e[47mGestionar zombies\e[0m      \n";
                                cout << "======================================================\n";
                                cout << "1. Cargar Zombies\n";
                                cout << "2. Anadir Zombies\n";
                                cout << "3. Mostrar Zombies\n";
                                cout << "4. Modificar Zombies\n";
                                cout << "5. Eliminar tipo de Zombies\n";
                                cout << "6. Salir\n";
                                cout << "======================================================\n";
                                cout << "Ingrese una opcion: ";
                                cin >> opcion_zombies;
                                switch (opcion_zombies) {
                                    case '1':
                                        cargar_zombies(lista_zombies);
                                        system("pause");
                                    break;
                                    case '2':
                                        llenar_zombie(lista_zombies);
                                        system("pause");    
                                    break;
                                    case '3':
                                        mostrar_zombies(lista_zombies);
                                        system("pause");
                                    break;
                                    case '4':
                                        modificar_zombie(lista_zombies);
                                        system("pause");
                                    break;
                                    case '5':
                                        char eleccion;
                                        cout << "Desea eliminar un solo zombie (1) o todas las apariciones de un zombie (2)?: ";
                                        cin >> eleccion;

                                        if (eleccion == '1') {
                                            string nombre_zombie;
                                            cout << "Ingrese el nombre del zombie a eliminar: ";
                                            cin >> nombre_zombie;
                                            eliminar(lista_zombies, nombre_zombie);
                                        } 
                                        else if (eleccion == '2'){
                                            string nombre_zombie;
                                            cout << "Ingrese el nombre del zombie a eliminar todas sus apariciones: ";
                                            cin >> nombre_zombie;
                                            eliminar_apariciones(lista_zombies, nombre_zombie);
                                        } 
                                        else{
                                            cout << "Opcion invalida\n";
                                        }
                                        system("pause");
                                    break;
                                    default:
                                        cout << "Opcion invalida\n";
                                    break;
                                }
                            }
                            break;
                        }
                        case '2': {
                            char opcion_grupos = '0';
                            while (opcion_grupos != '5') {
                                system("cls");
                                cout << "        \e[47mGestionar Grupos\e[0m        " << "\n";
                                cout << "======================================" << "\n";
                                cout << "1. Agregar Grupo " << "\n";
                                cout << "2. Modificar Grupo y anadir jugadores" << "\n";
                                cout << "3. Eliminar Grupo" << "\n";
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
                        /*case '3':
                            while (opcion != '5'){
                                system("cls");
                                cout << "    \e[47mGestionar mapa\e[0m    \n";
                                cout<<"===================================="<<"\n";
                                cout << " 1. Crear estacion" << endl;
                                cout << " 2. modificar estacion" << endl;
                                cout << " 3. Mostrar mapa" << endl;
                                cout << " 4. Eliminar estacion" << endl;
                                cout << " 5. Volver" << endl;
                                cout<<"===================================="<<"\n";
                                cout<<"Ingrese una opcion (1 al 5): ";
                                cin >> opcion;
                                switch (opcion) {
                                    case '1':
                                        system("cls");
                                        cout << "        \e[47mCrear estacion\e[0m    \n";
                                        cout<<"=========================================="<<"\n";
                                        insertar_Ultimo_mapa(lista_mapa, pedir_dato_estacion());
                                        cout<<"La estacion se creo con exito!!! si desea crear otra estacion ingrese a 'Crear estacion'\n";
                                        system("pause");
                                    break;
                                    case '2'    :
                                        while(opcion!='4'){
                                            system("cls");
                                            cout << "           \e[47mmodificar estacion\e[0m         " << endl;
                                            cout<<"==================================================="<<"\n";
                                            cout << " 1. Modificar nombre estacion" << endl;
                                            cout << " 2. Añadir zombie a estacion" << endl;
                                            cout << " 3. Eliminar zombies de estacion" << endl;
                                            cout << " 4. volver" << endl;
                                            cout<<"==================================================="<<"\n";
                                            cout<<"Ingrese una opcion (1 al 4): ";
                                            cin>>opcion;
                                            switch (opcion){
                                                case '1':
                                                    modificar_estacion(lista_mapa);
                                                break;

                                                case '2':
                                                    system("cls");
                                                    cout << "          \e[47mAñadir zombie a estacion\e[0m     " << endl;
                                                    cout<<"==================================================="<<"\n";
                                                    agregar_zombies_mapa(lista_zombies, lista_mapa);
                                                    system("pause");
                                                break;
                                
                                                case '3':
                                                    system("cls");
                                                    cout << "          \e[47mEliminar zombies de estacion\e[0m    " << endl;
                                                    cout<<"========================================================="<<"\n";
                                                    modificar_zombi(lista_mapa);
                                                    system("pause");
                                                break;

                                                default:
                                                    cout<<"Opcion invalida.\n";
                                                break;
                                            }
                                        }
                                        system("pause");
                                    break;
                                    case '3':
                                        system("cls");
                                        cout << "                \e[47mMostrar mapa\e[0m     " << endl;
                                        cout<<"==================================================="<<"\n";
                                        mostrar_mapa(lista_mapa);
                                        system("pause");
                                    break;
                                    case '4':
                                        system("cls");
                                        cout << "           \e[47mEliminar estacion\e[0m          " << endl;
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
                        break;*/
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
    //delete lista_mapa;

    return 0;
}
