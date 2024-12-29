#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "zombies.h"
#include "mapa.h"
#include "grupos.h"

using namespace std;

int main(){

    jugador *lista_soldados = NULL;    
    grupo *lista_grupo = NULL;
    zombies *lista_zombies = NULL;
    accesorio*lista_accesorios=NULL;
    vertice *lista_mapa=NULL;
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
            case '1':{
                //cout << "Esta opción no está disponible aún." << "\n";
                cout<<"\e[0;33mDesea cargar partida o crear una desde cero?\e[0m"<<endl;
                char opcion_opciones = '0';
                while(opcion_opciones!='3'){
                    cout << "1. Cargar partida " << "\n";
                    cout << "2. Crear partida " << "\n";
                    cout << "3. Salir " << "\n";
                    cout << "Ingrese una opcion (1 al 3): ";
                    cin >> opcion_opciones;
                    switch (opcion_opciones){
                    case '1':{
                            if((archivoExiste("Accesorio")))
                            {
                                cout<<"\e[0;31mpartida no se puede cargar\e[0m"<<endl;
                                opcion_opciones='3';
                            }
                            else{
                                carga_de_accesorio(&lista_accesorios);
                                cargar_jugadores(&lista_soldados);
                                cout<<"\e[0;32mLos archivos se han cargado con exito!!\e[0m\n";
                                cout<<"\e[0;33mPara editar debes ir a >> Menu >> Opciones\e[0m"<<endl;
                                mostrarListaJugador(lista_soldados);
                                crear_grupos_usuario(lista_grupo,lista_soldados);
                            }
                            system("pause"); 
                            break;  
                        }
                    case '2':{
                           cout<<"en desarrollo";
                           break;
                        }
                    case '3':{
                           cout<<"saliendo";
                           break;
                        }
                    default:
                        break;
                    }
                }
                system("pause");
                break;   
            }
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
                        case '1':
                            while (opcion != '6') {
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
                                cin >> opcion;
                                switch (opcion) {
                                    case '1':
                                        if(lista_zombies != NULL){
                                            cout << "Ya se han cargado zombies\n";
                                        }
                                        else{
                                            cargar_zombies(lista_zombies);
                                            system("pause");
                                        }
                                    break;
                                    case '2':
                                        llenar_zombie(lista_zombies);
                                        cout << "\e[0;32mZombies agregados con exito\e[0m\n";
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
                                        cout << "\e[0;33mDesea eliminar un solo zombie (1) o todas las apariciones de un zombie (2)?: \e[0m";
                                        cin >> eleccion;

                                        if (eleccion == '1') {
                                            string nombre_zombie;
                                            cout << "Ingrese el nombre del zombie a eliminar: ";
                                            cin >> nombre_zombie;
                                            eliminar(lista_zombies, nombre_zombie);
                                            cout << "\e[0;32mZombie eliminado con exito\e[0m\n";
                                        } 
                                        else if (eleccion == '2'){
                                            string nombre_zombie;
                                            cout << "Ingrese el nombre del zombie a eliminar todas sus apariciones: ";
                                            cin >> nombre_zombie;
                                            eliminar_apariciones(lista_zombies, nombre_zombie);
                                        } 
                                        else{
                                            cout << "\e[0;31mOpcion invalida\e[0m\n";
                                        }
                                        system("pause");
                                    break;
                                    default:
                                        cout << "\e[0;31mOpcion invalida\e[0m\n";
                                    break;
                                }
                            }
                        break;
                        case '2': 
                            while (opcion != '5') {
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
                                cin >> opcion;

                                switch (opcion) {
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
                                        cout << "\e[0;31mOpcion invalida, vuelva a intentarlo\e[0m" << endl;
                                        system("pause");
                                }
                            }
                            break;
                        case '3':
                            while (opcion != '6'){
                                system("cls");
                                cout << "    \e[47mGestionar mapa\e[0m    \n";
                                cout<<"===================================="<<"\n";
                                cout << "1. Cargar mapa\n";
                                cout << "2. Agregar estacion\n";
                                cout << "3. Mostrar estaciones\n";
                                cout << "4. Modificar estacion\n";
                                cout << "5. Eliminar estacion\n";
                                cout << "6. Salir\n";
                                cout<<"===================================="<<"\n";
                                cout<<"Ingrese una opcion (1 al 5): ";
                                cin >> opcion;
                                switch (opcion) {
                                    case '1':
                                        if(lista_mapa != NULL){
                                        cout << "Ya se ha cargado un mapa\n";
                                        }
                                        else{
                                            cargar_mapa(lista_mapa);
                                            cout<<"\e[0;32mMapa cargado con exito\e[0m"<<endl;
                                        }
                                        system("pause");
                                    break;
                                    case '2'    :
                                        agregar_estacion(lista_mapa);
                                        system("pause");
                                    break;
                                    case '3':
                                        system("cls");
                                        cout << "                \e[47mMostrar mapa\e[0m     " << endl;
                                        cout<<"==================================================="<<"\n";
                                        mostrar_estaciones(lista_mapa);
                                        system("pause");
                                    break;
                                    case '4':
                                        modificar_estacion(lista_mapa);
                                        system("pause");
                                    break;
                                    case '5':
                                        eliminar_vertice(lista_mapa);
                                        system("pause");
                                    break;
                                    default:
                                        cout << "\e[0;31mOpcion no valida\e[0m\n";
                                        system("pause");
                                    break;
                                }
                            }
                        break;
                        default:
                            cout << "Opcion invalida. Intente nuevamente." << endl;
                            system("pause");
                        break;
                    }
                }
                break;
            }

            case '3':
                cout << "Reglas del juego no disponibles aun." << "\n";
                system("pause");
                break;

            case '4':
                cout << "Gracias por jugar." << "\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                system("pause");
        }
    }

    // Liberación de memoria
    delete lista_soldados;
    delete lista_zombies;    
    delete lista_grupo;
    delete lista_mapa;
    //if((archivoExiste("Soldado") or archivoVacio("Soldado"))and(archivoExiste("Accesorio") or archivoVacio("Accesorio")))
    return 0;
}



