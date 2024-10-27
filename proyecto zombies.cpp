//IMPORTACIÓN DE LIBRERIAS.
#include <iostream>
#include <fstream>
using namespace std;


struct armas{
    string nombre;
    armas *prox;
};

struct jugador{
    string nombre;
    int salud=100; /*La salud en este caso es la vida y siempre inicializa con 100 según el PDF*/
    int afectacion=0; /*Afectacion viene siendo los daños que resive el jugador*/
    jugador *prox;
};

struct grupos{//nuevo
    string nombre_grupo;
    grupos *sig;
    jugador *grupo_jugador;
};

jugador *crear_jugador(string nom, int sald, int afect){
    jugador *nuevo_jugador =new jugador;
    nuevo_jugador->nombre=nom;
    nuevo_jugador->salud=sald;
    nuevo_jugador->afectacion=afect;
    nuevo_jugador->prox=NULL;
    return nuevo_jugador;
}

grupos *crear_grupo(string  nom_grupo){//nuevo
    grupos *nuevo_grupo =new grupos;
    nuevo_grupo->nombre_grupo=nom_grupo;
    nuevo_grupo->sig=NULL;
    nuevo_grupo->grupo_jugador=NULL;
    return nuevo_grupo;
}

armas *crear_arma(string nom){
    armas *nueva_arma =new armas;
    nueva_arma->nombre=nom;
    nueva_arma->prox=NULL;
    return nueva_arma;
}

bool lista_vacia_jugador(jugador *soldado){
    return soldado==NULL;
}

bool lista_vacia_grupos(grupos *lista){
    return lista==NULL;
}

bool lista_vacia_arma(armas *lista){
    return lista==NULL;
}

void insertar_Ultimo_jugador(jugador *&inicio, string nom, int sald, int afect){
    jugador *nuevo = crear_jugador(nom, sald, afect);
 
    if (lista_vacia_jugador(inicio)) {
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

void insertar_Ultimo_grupos(grupos *&inicio, int valor){//nuevo
    for(int i=0; i<valor; i++){
        string valor_grupo;
        cout<<"Ingrese el nombre del grupo "<<i+1<<": ";
        cin>>valor_grupo;
        grupos *nuevo = crear_grupo(valor_grupo);
        if (lista_vacia_grupos(inicio)){
        inicio = nuevo;
        } 
        else {
            grupos *mover = inicio;
            while (mover->sig != NULL) {
                mover = mover->sig;
            }
            mover->sig = nuevo;
        }
    }
}

void insertar_Ultimo_armas(armas *&inicio, string nom){
    armas *nuevo = crear_arma(nom);
 
    if (lista_vacia_arma(inicio)) {
        inicio = nuevo;
    } 
    else {
        armas *mover = inicio;
        while (mover->prox != NULL) {
            mover = mover->prox;
        }
        mover->prox = nuevo;
    }
}

grupos *buscar_grupos(grupos *list, string actual){//nuevo
    grupos *buscar = list;                      
    bool encontrado = false; 
    while (!lista_vacia_grupos(buscar) && encontrado == false){
        if (buscar->nombre_grupo == actual){
            encontrado = true;
        }
        else{
            buscar = buscar->sig;
        }
    }
    return buscar;
}

void agregar_soldado_grupo(grupos *&lista){//nuevo
    jugador *list_sold=NULL;
    grupos *ubicacion=NULL;
    string buscar_introducir_grupo;
    int cantidad_jugador;
    cout<<"Ingresa Grupo a insertar jugador: ";
    cin>>buscar_introducir_grupo;
    ubicacion= buscar_grupos(lista, buscar_introducir_grupo);
    if (lista_vacia_grupos(ubicacion)){
        cout<<"\e[47m \e[0m";
        cout<<"\e[41mEl grupo no fue encontrado en la lista\e[0m";
        cout<<"\e[47m \e[0m\n\n";
    }  
    else{
        cout<<"Indica cantidad de jugadores en el grupo '"<< ubicacion->nombre_grupo<<"': \n";
        cin>>cantidad_jugador;
        for (int i=0; i<cantidad_jugador; i++) {
            string nom_soldado;
            cout << "Indica Nombre del jugador: ";
            cin>>nom_soldado;
            insertar_Ultimo_jugador(list_sold, nom_soldado, 100, 0);
        }
        ubicacion->grupo_jugador=list_sold;
    }
}

void mostrar_lista_grupos_soldados(grupos *lista){//nuevo
   grupos *mover_grupo;
   jugador *mover_soldado;

    if (!lista_vacia_grupos(lista)){
        mover_grupo = lista;        //para moverte en grupos
        while (!lista_vacia_grupos(mover_grupo)){
            cout<<"\n\n["<<mover_grupo->nombre_grupo <<"]"<<"\n";  
            cout<<"================================================"<<endl; 
            mover_soldado = mover_grupo->grupo_jugador;  
            if (!lista_vacia_jugador(mover_soldado)){    
                while (!lista_vacia_jugador(mover_soldado)) {
                    cout<<"[Nombre: "<<mover_soldado->nombre<<"; vida: "<<mover_soldado->salud<<", Afectacion: "<<mover_soldado->afectacion<<"]\n";
                    mover_soldado = mover_soldado->prox;
                } 
            }
            else{
                cout<<endl<<"No hay soldados registrados"<<endl;
            }    
            cout<<"================================================"<<endl;    
            mover_grupo = mover_grupo->sig;
        }  
    }  
    else{
        cout<<"No existen este grupo"<<endl;
    }    
}

void mostrar_lista_armas(jugador *inicio){ 
    cout<<"\n\n";                            /*Esta función mostrará a cada jugador que se llenó en la lista*/
    jugador *mover_1;
    armas *mover_2;
    if(lista_vacia_arma(mover_2)){
        cout<<"[Nombre: "<<mover_1->nombre<<"]\n";
        cout<<"====================================\n";
        cout<<"Armas registradas\n";
        cout<<"====================================\n";

        while(lista_vacia_arma(mover_2)){
            cout<<mover_2->nombre<<"\n";
            mover_2->prox;
        } 
    }
    else{
        cout<<"No tiene armas registradas\n";
    }
}

void existe_jugador(jugador *lista, jugador *auxiliar, string valor_1){
    jugador *buscar_2=lista;
    bool encontrado_2=false;
    while(!lista_vacia_jugador(buscar_2) && encontrado_2==false){
        if(buscar_2->nombre==valor_1){
            encontrado_2=true;
            cout<<"\e[47m \e[0m";
            cout<<"\e[41mEste usuario ya existe\e[0m";
            cout<<"\e[47m \e[0m\n\n"; 
        }
        else{
            buscar_2=buscar_2->prox;
        }
        if(lista_vacia_jugador(buscar_2)){
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
    if (lista_vacia_jugador(list)){
        cout<<"\e[47m \e[0m";
        cout<<"\e[41mNo se han introducido datos del jugador\e[0m";
        cout<<"\e[47m \e[0m\n\n";
    }  
    else{   
        while (!lista_vacia_jugador(buscar) && encontrado == false) {
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

void destruir_lista_jugador(jugador *&list){
    while(!lista_vacia_jugador(list)){
        jugador *auxiliar = list;
        list=list->prox;
        delete auxiliar;
    }
}

void destruir_lista_armas(armas *&list){
    while(!lista_vacia_arma(list)){
        armas *auxiliar = list;
        list=list->prox;
        delete auxiliar;
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

jugador *buscar_jugador_gestionar_accesorio(jugador *list, string actual){
    jugador *buscar = list;                      
    bool encontrado = false; 
    while (!lista_vacia_jugador(buscar) && encontrado == false){
        if (buscar->nombre == actual){
            encontrado = true;
        }
        else{
            buscar = buscar->prox;
        }
    }
    return buscar;
}

jugador *agregar_armas_jugador(jugador *&lista){
   //no tiene validaciones, agrega materias a un estudiante dado por el usuario
   // para validar crea una lista con el pensum de la carrera
    armas *list_armas=NULL;
    string nombre_soldado;
    cout<<"Ingrese el nombre del soldado a registrar el arma: ";
    cin>>nombre_soldado;
    jugador *ubicacion= buscar_jugador_gestionar_accesorio(lista,nombre_soldado);
    if (lista_vacia_jugador(ubicacion)){
        cout<<"\e[47m \e[0m";
        cout<<"\e[41mEl jugador no fue encontrado en la lista\e[0m";
        cout<<"\e[47m \e[0m\n\n";
    }
    else{
        menu_gestionar_accesorios();
    }   
    return ubicacion;
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
    cout << " 2.2.1.2.1.2. Martillo" << endl;
    cout << " 2.2.1.2.1.3. Tuberia" << endl;
    cout << " 2.2.1.2.1.4. Volver " << endl;
    cout<<"========================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_armas_improvisadas(){
    system("cls");
    cout << "    2.2.1.3. Armas improvisadas  \n";
    cout<<"======================================="<<"\n";
    cout << " 2.2.1.3.1. Objetos punsantes " << endl;
    cout << " 2.2.1.3.2. Objetos contundentes" << endl;
    cout << " 2.2.1.3.3. Armas incendiarias" << endl;
    cout << " 2.2.1.3.4. Tramas " << endl;
    cout << " 2.2.1.3.5. Volver " << endl;
    cout<<"======================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 5): ";
}

void menu_armas_objetos_punsantes(){
    system("cls");
    cout << "    2.2.1.3.1. Objetos punsantes  \n";
    cout<<"========================================"<<"\n";
    cout << " 2.2.1.3.1.1. Clavos " << endl;
    cout << " 2.2.1.3.1.2. Tijeras" << endl;
    cout << " 2.2.1.3.1.3. Destornilladores" << endl;
    cout << " 2.2.1.3.1.4. Volver " << endl;
    cout<<"========================================"<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_armas_objetos_contundentes(){
    system("cls");
    cout << "    2.2.1.3.2. Objetos contundentes \n";
    cout<<"==========================================="<<"\n";
    cout << " 2.2.1.3.2.1. Ladrillos " << endl;
    cout << " 2.2.1.3.2.2. Rocas" << endl;
    cout << " 2.2.1.3.2.3. Palos" << endl;
    cout << " 2.2.1.3.2.4. Volver " << endl;
    cout<<"==========================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 4): ";
}

void menu_armas_incendiarias(){
    system("cls");
    cout << "    2.2.1.3.3. Armas incendiarias \n";
    cout<<"========================================="<<"\n";
    cout << " 2.2.1.3.3.1. Fosforos " << endl;
    cout << " 2.2.1.3.3.2. Liquidos inflamables" << endl;
    cout << " 2.2.1.3.3.3. Volver " << endl;
    cout<<"========================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 3): ";
}

void menu_armas_tramas(){
    system("cls");
    cout << "    2.2.1.3.4. Tramas \n";
    cout<<"========================================="<<"\n";
    cout << " 2.2.1.3.4.1. Alambres electrificados " << endl;
    cout << " 2.2.1.3.4.2. Trampas de caida" << endl;
    cout << " 2.2.1.3.4.3. Volver " << endl;
    cout<<"========================================="<<"\n";
    cout<<"Ingrese una opcion (1 al 3): ";
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
    cout<<"2.3.1.1. Crear grupos "<<"\n";
    cout<<"2.3.1.2. Consultar equipo "<<"\n";
    cout<<"2.3.1.3. Volver "<<"\n";
    cout<<"======================================"<<"\n";
    cout<<"Ingrese una opcion (1 al 3): ";
}

int main(){
    jugador *lista_soldados=NULL;
    armas *lista_armas=NULL;
    grupos *lista_grupos=NULL;
    char opcion;
    while (opcion!='4'){
        menu_inicio();
        cin>>opcion;
        switch (opcion){
            case '1':
                cout << "Esta opción aún no está disponible." << "\n";
                cout << "Presione 1 para volver: ";
                char volver;
                cin >> volver;
                while (volver != '1') {
                    cout << "Entrada no válida. Presione 1 para volver: ";
                    cin >> volver;
                }               
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
                                jugador *mochila_jugador=agregar_armas_jugador(lista_soldados);
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
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Pistola");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Escopeta");
                                                                            system("pause");
                                                                        break;
                                                                        case '3':
                                                                            insertar_Ultimo_armas(lista_armas, "fusil de asalto");
                                                                            system("pause");
                                                                        break;
                                                                        case '4':
                                                                            insertar_Ultimo_armas(lista_armas, "Rifle de francotirador");
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
                                                            case '2':
                                                                while(opcion!='3'){
                                                                    menu_armas_arrojadizas();
                                                                    cin>>opcion;
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Granada");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Cócteles Molotov");
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
                                                            case '3':
                                                                while(opcion!='3'){
                                                                    menu_armas_proyectiles();
                                                                    cin>>opcion;
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Ballesta");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Tirachinas");
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
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Cuchillo");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Machete");
                                                                            system("pause");
                                                                        break;
                                                                        case '3':
                                                                            insertar_Ultimo_armas(lista_armas, "Espada");
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
                                                            case '2':
                                                                while(opcion!='4'){
                                                                    menu_armas_contundentes();
                                                                    cin>>opcion;
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Bate de beisbol");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Martillo");
                                                                            system("pause");
                                                                        break;
                                                                        case '3':
                                                                            insertar_Ultimo_armas(lista_armas, "Tuberia");
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
                                                    while(opcion!='5'){
                                                        menu_armas_improvisadas();
                                                        cin>>opcion;
                                                        switch (opcion){
                                                            case '1':
                                                                while(opcion!='4'){
                                                                    menu_armas_objetos_punsantes();
                                                                    cin>>opcion;
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Clavos");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Tijeras");
                                                                            system("pause");
                                                                        break;
                                                                        case '3':
                                                                            insertar_Ultimo_armas(lista_armas, "Destornilladores");
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
                                                            case '2':
                                                                while(opcion!='4'){
                                                                    menu_armas_objetos_contundentes();
                                                                    cin>>opcion;
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Ladrillos");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Rocas");
                                                                            system("pause");
                                                                        break;
                                                                        case '3':
                                                                            insertar_Ultimo_armas(lista_armas, "Palos");
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
                                                            case '3':
                                                                while(opcion!='3'){
                                                                    menu_armas_incendiarias();
                                                                    cin>>opcion;
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Fosforos");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Liquidos inflamables");
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
                                                                while(opcion!='3'){
                                                                    menu_armas_tramas();
                                                                    cin>>opcion;
                                                                    switch (opcion){
                                                                        case '1':
                                                                            insertar_Ultimo_armas(lista_armas, "Alambres electrificados");
                                                                            system("pause");
                                                                        break;
                                                                        case '2':
                                                                            insertar_Ultimo_armas(lista_armas, "Trampas de caida");
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
                                                            default:
                                                                cout<<"\e[47m \e[0m";
                                                                cout<<"\e[41mERROR, no esta en las opciones vuelva a intentar\e[0m";
                                                                cout<<"\e[47m \e[0m\n\n";
                                                                system("pause");
                                                            break;
                                                        }
                                                    }
                                                break;
                                            }
                                    }
                                        
                                    break;
                                    case '2':
                                    break;
                                    case '3':
                                        mostrar_lista_armas(mochila_jugador);
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
                                                if(lista_vacia_grupos(lista_grupos)){
                                                    int numero_grupos;
                                                    cout<<"ingresa numero de grupos: ";
                                                    cin>>numero_grupos;
                                                    insertar_Ultimo_grupos(lista_grupos, numero_grupos);
                                                }
                                                    agregar_soldado_grupo(lista_grupos);
                                                    system("pause");
                                                break;
                                                case '2':                                                   
                                                    mostrar_lista_grupos_soldados(lista_grupos);
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
                destruir_lista_jugador(lista_soldados);
                destruir_lista_armas(lista_armas);
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
