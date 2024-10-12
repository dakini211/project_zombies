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

void lista_jugador(jugador *&inicio){ 
    string escribir_nombre;           /*La función crea la lista en donde se guardará la información de la estructura jugador*/
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

void mostrar_lista_jugador(jugador *inicio){ 
    cout<<"\n\n";                            /*Esta función mostrará a cada jugador que se llenó en la lista*/
    jugador *mostrar_jugador;

    if (!lista_vacia(inicio)){
        mostrar_jugador = inicio;
        while (!lista_vacia(mostrar_jugador)){
            cout<<"[Nombre: "<<mostrar_jugador->nombre<<"; vida: "<<mostrar_jugador->salud<<", Afectacion: "<<mostrar_jugador->afectacion<<"]\n";
            mostrar_jugador = mostrar_jugador->prox;
        }
    }  
    else{
        cout<<"\e[47m \e[0m";
        cout<<"\e[41mNo se han introducido datos del jugador\e[0m"<<endl;
        cout<<"\e[47m \e[0m\n\n"; 
    }
}

void existe_jugador(jugador *lista, jugador *auxiliar, string valor_1){
    jugador *buscar_2=lista;
    bool encontrado_2=false;
    while(!lista_vacia(buscar_2) && encontrado_2==false){
        if(buscar_2->nombre==valor_1){
            encontrado_2=true;
            cout<<"\e[47m \e[0m";
            cout<<"\e[41mEste usuario ya existe\e[0m";
            cout<<"\e[47m \e[0m\n\n"; 
        }
        else{
            buscar_2=buscar_2->prox;
        }
        if(lista_vacia(buscar_2)){
            auxiliar->nombre= valor_1;
            cout<<"\n";
            cout<<"\e[47m \e[0m";
            cout<<"\e[42mEl jugador se modifico con exito!!!\e[0m";   
            cout<<"\e[47m \e[0m\n\n";      
        }
    }
}

void buscar_jugador_gestionar_soldado(jugador *list, string actual){
    jugador *buscar = list;                      
    bool encontrado = false; 
    if (lista_vacia(list)){
        cout<<"\e[47m \e[0m";
        cout<<"\e[41mNo se han introducido datos del jugador\e[0m";
        cout<<"\e[47m \e[0m\n\n";
    }  
    else{   
        while (!lista_vacia(buscar) && encontrado == false) {
            if (buscar->nombre == actual){
                encontrado = true;
                string nuevo_nombre;
                cout<<"Ingrese el nuevo nombre del jugador: ";
                cin>>nuevo_nombre; 
                existe_jugador(list, buscar, nuevo_nombre);
            }
            else{
                buscar = buscar->prox;
            }
        }
        if (!encontrado){
            cout<<"\e[47m \e[0m";
        cout<<"\e[41mEl jugador no fue encontrado en la lista\e[0m";
            cout<<"\e[47m \e[0m\n\n";
        }
    }
}

void modificar_jugador(jugador *inicio){ 
    string nombre_aux;                     /*Esta funcion busca y cambia al jugador a modificar,por haora modifica el nombre */        
    cout<<"Ingresa jugador a modificar: ";/*pero mas adelante se mejorará si es necesario modificarle la salud y afectación*/
    cin>>nombre_aux;
    buscar_jugador_gestionar_soldado(inicio, nombre_aux);
}

void eliminar_jugador_lista(jugador *&inicio){ 
    jugador *eliminar_jugador;                /* Su función lo dice, elimina al jugador */
    jugador *auxiliar = NULL; 
    string nombre_aux;
    cout<<"Ingresa jugador a eliminar: ";
    cin>>nombre_aux;
    if (inicio==NULL){
        cout<<"\e[47m \e[0m";
        cout<<"\e[41mEl jugador no fue encontrado en la lista\e[0m";
        cout<<"\e[47m \e[0m\n\n";
    }
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

void menu_inicio(){
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
}

void menu_opciones(){
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
}

void menu_gestionar_accesorios(){
    system("cls");
    cout << "    2.2. Gestinar accesorios    \n";
    cout<<"===================================="<<"\n";
    cout << " 2.2.1. Registrar arma" << endl;
    cout << " 2.2.2. Eliminar datos del arma" << endl;
    cout << " 2.2.3. Mostrar listado" << endl;
    cout << " 2.2.4. Volver" << endl;
    cout<<"===================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_registrar_arma(){
    system("cls");
    cout << "    2.2.1. Registrar arma    \n";
    cout<<"================================="<<"\n";
    cout << " 2.2.1.1. Armas a distancia" << endl;
    cout << " 2.2.1.2. Armas cuerpo a cuerpo" << endl;
    cout << " 2.2.1.3. Armas improvisadas" << endl;
    cout << " 2.2.1.4. Volver" << endl;
    cout<<"================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_armas_distancia(){
    system("cls");
    cout << "    2.2.1.1. Armas a distancia    \n";
    cout<<"======================================"<<"\n";
    cout << " 2.2.1.1.1. Armas de fuego" << endl;
    cout << " 2.2.1.1.2. Armas arrojadizas" << endl;
    cout << " 2.2.1.1.3. Armas de proyectiles" << endl;
    cout << " 2.2.1.1.4. Volver" << endl;
    cout<<"======================================"<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_armas_de_fuego(){
    system("cls");
    cout << "    2.2.1.1.1. Armas de fuego    \n";
    cout<<"====================================="<<"\n";
    cout << " 2.2.1.1.1.1. Pistola " << endl;
    cout << " 2.2.1.1.1.2. Escopeta" << endl;
    cout << " 2.2.1.1.1.3. fusil de asalto" << endl;
    cout << " 2.2.1.1.1.4. Rifle de francotirador" << endl;
    cout << " 2.2.1.1.1.5. Volver " << endl;
    cout<<"====================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 5): ";
}

void menu_armas_arrojadizas(){
    system("cls");
    cout << "    2.2.1.1.2. Armas arrojadizas    \n";
    cout<<"========================================"<<"\n";
    cout << " 2.2.1.1.2.1. Granada " << endl;
    cout << " 2.2.1.1.2.2. Cócteles Molotov" << endl;
    cout << " 2.2.1.1.2.3. Volver " << endl;
    cout<<"========================================"<<"\n";
    cout<<"Ingrese una opcion (1 al 3): ";
}

void menu_armas_proyectiles(){
    system("cls");
    cout << "    2.2.1.1.3. Armas de proyectiles    \n";
    cout<<"==========================================="<<"\n";
    cout << " 2.2.1.1.3.1. Ballesta " << endl;
    cout << " 2.2.1.1.3.2. Tirachinas" << endl;
    cout << " 2.2.1.1.3.3. Volver " << endl;
    cout<<"==========================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 3): ";
}

void buscar_jugador_gestionar_accesorio(jugador *list, string actual){//Cristian
    jugador *buscar = list;                      
    bool encontrado = false; 
    if (lista_vacia(list)){
        cout<<"\e[47m \e[0m";
        cout<<"\e[41mNo se han introducido datos del jugador\e[0m";
        cout<<"\e[47m \e[0m\n\n";
        system("pause");
    }  
    else{   
        while (!lista_vacia(buscar) && encontrado == false) {
            if (buscar->nombre == actual){
                encontrado = true;
                menu_gestionar_accesorios();
            }
            else{
                buscar = buscar->prox;
            }
        }
        if (!encontrado){
            cout<<"\e[47m \e[0m";
        cout<<"\e[41mEl jugador no fue encontrado en la lista\e[0m";
            cout<<"\e[47m \e[0m\n\n";
        }
    }
}

void menu_armas_cuerpo(){
    system("cls");
    cout << "    2.2.1.2. Armas cuerpo a cuerpo  \n";
    cout<<"=========================================="<<"\n";
    cout << " 2.2.1.2.1. Armas blancas " << endl;
    cout << " 2.2.1.2.2. Armas contundentes" << endl;
    cout << " 2.2.1.2.3. Volver " << endl;
    cout<<"=========================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 3): ";
}

void menu_armas_blancas(){
    system("cls");
    cout << "    2.2.1.2.1. Armas blancas  \n";
    cout<<"===================================="<<"\n";
    cout << " 2.2.1.2.1.1. Cuchillo " << endl;
    cout << " 2.2.1.2.1.2. Machete" << endl;
    cout << " 2.2.1.2.1.3. Espada " << endl;
    cout << " 2.2.1.2.1.4. Volver " << endl;
    cout<<"===================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_armas_contundentes(){
    system("cls");
    cout << "    2.2.1.2.2. Armas contundentes  \n";
    cout<<"========================================="<<"\n";
    cout << " 2.2.1.2.1.1. Bate de beisbol " << endl;
    cout << " 2.2.1.2.1.2. martillo" << endl;
    cout << " 2.2.1.2.1.3. tuberia" << endl;
    cout << " 2.2.1.2.1.4. Volver " << endl;
    cout<<"========================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_gestionar_equipos(){
    system("cls");
    cout<<"        2.3. Gestionar equipos        "<<"\n";
    cout<<"======================================"<<"\n";
    cout<<"2.3.1. Agregar soldado "<<"\n";
    cout<<"2.3.2. Modificar soldado "<<"\n";
    cout<<"2.3.3. Eliminar soldado "<<"\n";
    cout<<"2.3.4. Volver "<<"\n";
    cout<<"======================================"<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_agregar_soldado(){
    system("cls");
    cout<<"        2.3.1 Agregar soldado       "<<"\n";
    cout<<"======================================"<<"\n";
    cout<<"2.3.1.1. Crear soldado "<<"\n";
    cout<<"2.3.1.2. Consultar equipo "<<"\n";
    cout<<"2.3.1.3. Volver "<<"\n";
    cout<<"======================================"<<"\n";
    cout<<"Ingrese una opcion (1 al 3): ";
}

int main(){//Cristian
    jugador *lista_soldados=NULL;
    char opcion;
    while (opcion!='4'){
        menu_inicio();
        cin>>opcion;
        switch (opcion){
            case '1':
                cout<<"falta programar"<<"\n";
                system("pause");
            break;
            case '2': 
                while(opcion!='5'){
                    menu_opciones();
                    cin>>opcion;
                    switch (opcion){
                        case '1':
                            cout<<"falta programar";
                            system("pause");
                        break;
                        case '2':
                            while(opcion!='4'){
                                string nombre_soldado;
                                cout<<"Ingrese el nombre del soldado a registrar el arma: ";
                                cin>>nombre_soldado;
                                buscar_jugador_gestionar_accesorio(lista_soldados, nombre_soldado);
                                cin>>opcion;
                                switch (opcion){
                                    case '1':
                                        while(opcion!='4'){
                                            menu_registrar_arma();
                                            cin>>opcion;
                                            switch (opcion){
                                                case '1':
                                                    while(opcion!='4'){
                                                        menu_armas_distancia();
                                                        cin>>opcion;
                                                        switch (opcion){
                                                            case '1':
                                                                while(opcion!='5'){
                                                                    menu_armas_de_fuego();
                                                                    cin>>opcion;
                                                                    /*
                                                                        Javier, has que funcione esta parte para elegir el arma y pasarlo a su lista
                                                                     */
                                                                }
                                                            break;
                                                            case '2':
                                                                while(opcion!='3'){
                                                                    menu_armas_arrojadizas();
                                                                    cin>>opcion;
                                                                    /*
                                                                        Javier, has que funcione esta parte para elegir el arma y pasarlo a su lista
                                                                     */
                                                                }
                                                            break;
                                                            case '3':
                                                                while(opcion!='3'){
                                                                    menu_armas_proyectiles();
                                                                    cin>>opcion;
                                                                    /*
                                                                        Javier, has que funcione esta parte para elegir el arma y pasarlo a su lista
                                                                     */
                                                                }
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
                                                case '2':
                                                    while(opcion!='3'){
                                                        menu_armas_cuerpo();
                                                        cin>>opcion;
                                                        switch (opcion){
                                                            case '1':
                                                                while(opcion!='4'){
                                                                    menu_armas_blancas();
                                                                    cin>>opcion;
                                                                    /*
                                                                        Javier, has que funcione esta parte para elegir el arma y pasarlo a su lista
                                                                     */
                                                                }
                                                            break;
                                                            case '2':
                                                                while(opcion!='4'){
                                                                    menu_armas_contundentes();
                                                                    cin>>opcion;
                                                                    /*
                                                                        Javier, has que funcione esta parte para elegir el arma y pasarlo a su lista
                                                                     */
                                                                }
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
                                                case '3':
                                                break;
                                            }
                                    }
                                        
                                    break;
                                    case '2':
                                    break;
                                    case '3':
                                    break;
                                } 
                            }      
                        break;
                        case '3':
                            while(opcion!='4'){
                                menu_gestionar_equipos();
                                cin>>opcion;
                                switch (opcion){
                                    case '1':
                                        while(opcion!='3'){                                        
                                            menu_agregar_soldado();
                                            cin>>opcion;
                                            switch (opcion){
                                                case '1':
                                                    lista_jugador(lista_soldados);
                                                    system("pause");
                                                break;
                                                case '2':                                                   
                                                    mostrar_lista_jugador(lista_soldados);
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
                                        modificar_jugador(lista_soldados);
                                        system("pause");
                                    break;
                                    case '3':
                                        eliminar_jugador_lista(lista_soldados);
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
    return 0;
}
