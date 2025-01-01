#include "zombies.h"
#include "ultimo_mapa.h"
#include "grupos.h" 
#include <fstream>
#include <string>
using namespace std;

int main(){
    jugador *lista_soldados = NULL;    
    grupo *lista_grupo = NULL;
    zombies *lista_zombies = NULL;
    accesorio*lista_accesorios=NULL;
    nodo  *lista_mapa=NULL;
    nodo *lista_mapa2=NULL;
    nodo *camino_corto_peso = NULL;//nuevo
    nodo *camino_corto_zombies = NULL;//nuevo
    nodo *camino_corto_sobreviviente = NULL;//nuevo
    ifstream leer_zombies;
    string nombre_grupo, estacion_partida, estacion_llegada;//nuevo
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
                //cout << "Esta opción no está disponible aún." << "\n";
                cout<<"Desa cargar partida o crear una desde cero?"<<endl;
                while(opcion!='3'){
                    cout << "1. Cargar partida " << "\n";
                    cout << "2. Crear partida " << "\n";
                    cout << "3. Salir " << "\n";
                    cout << "Ingrese una opcion (1 al 3): ";
                    cin >> opcion;
                    switch (opcion)
                    {
                    case '1':{
                            if((archivoExiste("Accesorio")))
                            {
                                cout<<"partida no se puede cargar"<<endl;
                                opcion='3';
                            }
                            else{
                                carga_de_accesorio(&lista_accesorios);
                                cargar_jugadores(&lista_soldados);
                                while(opcion!='5'){
                                    system("cls");
                                    cout << "        \e[47mMenu de Misiones\e[0m        " << "\n";
                                    cout << "1. Definir puntos de partida y llegada de cada equipo" << "\n";
                                    cout << "2. Encontrar el camino más corto entre dos puntos" << "\n";
                                    cout << "3. Encontrar el camino con menor cantidad de zombies o menor fuerza de zombies" << "\n";
                                    cout << "4. Encontrar el camino más corto donde pueda existir la posibilidad de un sobreviviente que llegue con la cura" << "\n";
                                    cout << "5. Volver " << "\n";                    
                                    cout << "=============================================" << "\n";
                                    cout << "Ingrese una opcion (1 al 5): ";
                                    cin >> opcion;
                                    switch (opcion){
                                    case '1':{
                                        cout << "Ingrese el nombre del grupo a insertar en estacion: ";
                                        cin >> nombre_grupo;

                                        grupo* grupo_actual = buscar_grupo(lista_grupo, nombre_grupo);
                                        if (grupo_actual == NULL) {
                                            cout << "Grupo no encontrado." << endl;
                                            system("pause");
                                        }
                                        else{
                                            cout<<"Grupo asignado para insertar en las estaciones!!"<<endl;
                                            system("pause");
                                        }
                                        break;
                                    }
                                    case '2':{
                                        if (lista_mapa == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        } 
                                        else {
                                            cout << "Ingrese la estación de partida: ";
                                            getline(cin, estacion_partida);
                                            cout << "Ingrese la estación de llegada: ";
                                            getline(cin, estacion_llegada);
                                            camino_corto_peso = NULL; // Reiniciar la lista camino_corto_peso
                                            dijkstra(lista_mapa, camino_corto_peso, estacion_partida, estacion_llegada);
                                            mostrar_estaciones(camino_corto_peso); // Mostrar la lista camino_corto_peso
                                        }
                                        system("pause");
                                        break;
                                    }
                                    case '3':{
                                        if (lista_mapa == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        } 
                                        else {
                                            cout << "Ingrese la estación de partida: ";
                                            getline(cin, estacion_partida);
                                            cout << "Ingrese la estación de llegada: ";
                                            getline(cin, estacion_llegada);
                                            camino_corto_peso = NULL; // Reiniciar la lista camino_corto_peso
                                            camino_menor_zombies(lista_mapa, camino_corto_zombies, estacion_partida, estacion_llegada);
                                            mostrar_estaciones(camino_corto_zombies); // Mostrar la lista camino_corto_peso
                                        }
                                        system("pause");
                                        break;
                                    }
                                    case '4':{
                                        if (lista_mapa == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        } 
                                        else {
                                            cout << "Ingrese la estación de partida: ";
                                            getline(cin, estacion_partida);
                                            cout << "Ingrese la estación de llegada: ";
                                            getline(cin, estacion_llegada);
                                            camino_corto_peso = NULL; // Reiniciar la lista camino_corto_peso
                                            camino_posible_sobreviviente(lista_mapa, camino_corto_sobreviviente, estacion_partida, estacion_llegada, 10);
                                            mostrar_estaciones(camino_corto_sobreviviente); // Mostrar la lista camino_corto_peso
                                        }
                                        system("pause");
                                        break;
                                    }
                                    case '5':{
                                        cout << "Volviendo al menú principal..." << endl;
                                        break;
                                    }
                                    default:
                                        break;
                                    }
                                }
                            }
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
            case '2': 
                while (opcion != '4') {
                    system("cls");
                    cout << "        \e[47mOpciones\e[0m        " << "\n";
                    cout << "===========================" << "\n";
                    cout << "1. Gestionar zombies " << "\n";
                    cout << "2. Gestionar grupos " << "\n";
                    cout << "3. Gestionar mapas " << "\n";
                    cout << "4. Volver " << "\n";                     
                    cout << "===========================" << "\n";
                    cout << "Ingrese una opcion (1 al 4): ";
                    cin >> opcion;

                    switch (opcion) {
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
                                        cout << "Opcion invalida, vuelva a intentarlo" << endl;
                                        system("pause");
                                }
                            }
                        break;
                        case '3':
                            while (opcion != '8'){
                                system("cls");
                                cout << "    \e[47mGestionar mapa\e[0m    \n";
                                cout << "======================================================\n";
                                cout << "1.- Cargar mapa\n";
                                cout << "2.- Agregar estacion\n";
                                cout << "3.- Agregar adyacencias\n";
                                cout << "4.- Agregar zombies\n";
                                cout << "5.- Mostrar estaciones\n";
                                cout << "6.- Modificar estacion\n";
                                cout << "7.- Eliminar estacion\n";
                                cout << "8.- Salir\n";
                                cout << "======================================================\n";
                                cout << "Ingrese la opcion deseada del menu: ";
                                cin >> opcion;
                                switch (opcion) {
                                    case '1':
                                        cargar_mapa(lista_mapa);
                                        asignar_nombres(lista_mapa, lista_mapa2);
                                        system("pause");
                                    break;
                                    case '2':
                                        llenar_estaciones(lista_mapa2);
                                        system("pause");
                                    break;
                                    case '3':
                                        if (lista_mapa2 == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        }   
                                        else {
                                            string nombre_est;
                                            cout << "Ingrese  la estación a la que desea agregar adyacencias: ";
                                            cin >> nombre_est;
                                            nodo* ubicacion = Buscar_estacion_nom(lista_mapa2, nombre_est);
                                            if (ubicacion == NULL) {
                                                cout << "Estación no encontrada." << endl;
                                            } 
                                            else {
                                                agregar_adyacencias(lista_mapa2, ubicacion);
                                            }
                                        }
                                        system("pause");
                                    break;
                                    case '4':
                                        if (lista_mapa2 == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        }   
                                        else {
                                            string nombre_est;
                                            cout << "Ingrese la estación a la que desea agregar zombies: ";
                                            cin >> nombre_est;
                                            nodo* ubicacion = Buscar_estacion_nom(lista_mapa2, nombre_est);
                                            if (ubicacion == NULL) {
                                                cout << "Estación no encontrada." << endl;
                                            } 
                                            else {
                                                agregar_zombies(ubicacion);
                                            }
                                        }
                                        system("pause");
                                    break;
                                    case '5':
                                        if (lista_mapa2 == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        }   
                                        else {
                                            mostrar_estaciones(lista_mapa2);
                                        }
                                        system("pause");
                                    break;
                                    case '6'    :
                                        if (lista_mapa2 == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        }   
                                        else {
                                            modificar_estacion(lista_mapa2);
                                        }
                                        system("pause");
                                    break;
                                    case '7':
                                        if (lista_mapa2 == NULL) {
                                            cout << "El grafo está vacío." << endl;
                                        }   
                                        else {
                                            eliminar_vertice(lista_mapa2);
                                        }
                                        system("pause");
                                    break;
                                    default:
                                        cout << "Opción inválida. Intente nuevamente." << endl;
                                        system("pause");
                                    break;
                                }
                            }
                        break;
                        default:
                            cout << "Opcion invalida, vuelva a intentarlo" << endl;
                            system("pause");
                        }
                        break;
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
    delete lista_grupo;
    delete lista_mapa2;
    delete lista_mapa;
    //if((archivoExiste("Soldado") or archivoVacio("Soldado"))and(archivoExiste("Accesorio") or archivoVacio("Accesorio")))
    return 0;
}
}




