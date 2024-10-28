#ifndef ZOMBIES_H
#define ZOMBIES_H
#include <iostream>
using namespace std;

struct zombies{
   string nombre;
   int nivel;
   int salud;
   int dano_ataque;
   zombies *prox;
 };

zombies *crear_zombies(string nom,int nivel,int salud,int dano_ataque) //Crear listas de zombies
{
   zombies* zombie=new zombies;
   zombie->nombre=nom;
   zombie->nivel=nivel;
   zombie->salud=salud;
   zombie->dano_ataque=dano_ataque;
   zombie->prox=NULL;
   return zombie;
}

bool listaVaciaZombies(zombies *lista)//verifica si una lista de zombies esta vacia
   {
   return lista==NULL;
   }

void mostrar_zombies(zombies *list, int valor){
   cout<<"\n[zombies "<<list->nombre<<"]";
   cout<<endl<<"============================================"<<endl;
   cout<<"Numero de zombies ["<<valor<<"]"<<endl;
   cout<<"Nivel de peligro: "<<list->nivel<<endl;
   cout<<"Salud: "<<list->salud<<endl;
   cout<<"Dano de ataque: "<<list->dano_ataque<<endl;
   cout<<endl<<"============================================\n";
}

int contar_zombies(zombies *lista, int valor){
   zombies *mover=lista;
   int cont=0;
   while(mover!=NULL){
      if(mover->nivel==valor){
         cont++;
      }
      mover=mover->prox;
   }
   return cont;
}

int contar_zombies_rapidos(zombies *list){
   zombies *buscar=list;
   int contador=0;
   while(!listaVaciaZombies(buscar)){
      if(buscar->nombre=="Rapidos y agiles"){
         contador++;
      }
      buscar=buscar->prox;
   }
   return contador;
}

int contar_zombies_Tanques(zombies *list){
   zombies *buscar=list;
   int contador=0;
   while(!listaVaciaZombies(buscar)){
      if(buscar->nombre=="Tanques"){
         contador++;
      }
      buscar=buscar->prox;
   }
   return contador;
}

int contar_zombies_Inteligentes(zombies *list){
   zombies *buscar=list;
   int contador=0;
   while(!listaVaciaZombies(buscar)){
      if(buscar->nombre=="Inteligentes"){
         contador++;
      }
      buscar=buscar->prox;
   }
   return contador;
}

int contar_zombies_Infectados_hongos(zombies *list){
   zombies *buscar=list;
   int contador=0;
   while(!listaVaciaZombies(buscar)){
      if(buscar->nombre=="Infectados por hongos"){
         contador++;
      }
      buscar=buscar->prox;
   }
   return contador;
}

int contar_zombies_Bioluminicentes(zombies *list){
   zombies *buscar=list;
   int contador=0;
   while(!listaVaciaZombies(buscar)){
      if(buscar->nombre=="Bioluminicentes"){
         contador++;
      }
      buscar=buscar->prox;
   }
   return contador;
}

void mostrarlistaZombies(zombies *lista)//muestra la lsita de zombies agregados
{
   zombies*mover=lista;
   bool auxiliar1=false;
   bool auxiliar2=false;
   bool auxiliar3=false;
   bool auxiliar4=false;
   bool auxiliar5=false;
   int numero_rapidos=contar_zombies_rapidos(lista);
   int numero_Tanques=contar_zombies_Tanques(lista);
   int numero_Inteligentes=contar_zombies_Inteligentes(lista);
   int numero_hongos=contar_zombies_Infectados_hongos(lista);
   int numero_Bioluminicentes=contar_zombies_Bioluminicentes(lista);

   if(!listaVaciaZombies(lista)){
   mover=lista;
   while(mover!=NULL){

      if(mover->nombre=="Rapidos y agiles" && auxiliar1==false){
         mostrar_zombies(mover, numero_rapidos);
         auxiliar1=true;
      }
      if(mover->nombre=="Tanques" && auxiliar2==false){
         mostrar_zombies(mover,numero_Tanques);
         auxiliar2=true;
      }
      if(mover->nombre=="Inteligentes" && auxiliar3==false){
         mostrar_zombies(mover, numero_Inteligentes);
         auxiliar3=true;
      }
      if(mover->nombre=="Infectados por hongos" && auxiliar4==false){
         mostrar_zombies(mover, numero_hongos);
         auxiliar4=true;
      }
      if(mover->nombre=="Bioluminicentes" && auxiliar5==false){
         mostrar_zombies(mover,numero_Bioluminicentes);
         auxiliar5=true;
      }
      mover=mover->prox;
   }

   }
   else{
   cout<<"no hay zombies escritos"<<endl;
   }
}

void insertar_ultimo_zombie(zombies **lista_zombies,string nom, int nivel, int salud, int dano_ataque)
{
   zombies*nuevo_zombie=crear_zombies(nom,nivel,salud,dano_ataque);
   if(listaVaciaZombies(*lista_zombies))
   {
      *lista_zombies=nuevo_zombie;
   }
   else
   {
      zombies*aux=*lista_zombies;
      while(aux->prox!=NULL)
      {
         aux=aux->prox;
      }
      aux->prox=nuevo_zombie;
   }
}

void insertar_ultimo_zombie_mapa(zombies **lista_zombies_nueva, zombies *lista_zombie){
   zombies*nuevo_zombie=crear_zombies(lista_zombie->nombre, lista_zombie->nivel, lista_zombie->salud, lista_zombie->dano_ataque);
   if(listaVaciaZombies(*lista_zombies_nueva))
   {
      *lista_zombies_nueva=nuevo_zombie;
   }
   else
   {
      zombies*aux=*lista_zombies_nueva;
      while(aux->prox!=NULL)
      {
         aux=aux->prox;
      }
      aux->prox=nuevo_zombie;
   }
}

string pedir_nombre(){
   string nombre;
   cout<<"Indica nombre: ";
   cin>>nombre;
   return nombre;
}

void buscar_zombie(zombies*list, int buscar)
{
   if(listaVaciaZombies(list))
   {
      cout<<"No hay zombies disponibles"<<endl;
   }
   else{
      zombies*aux=list; 
      bool encontrado=false;
      while(aux!=NULL && encontrado==false){
         if(aux->nivel==buscar){
            cout<<"el zombie "<< buscar<<" existe";            
         }
         aux=aux->prox;
      }
      cout<<"el zombie "<<buscar<<" no existe, puede hacer el cambio pero no sera efectivo"<<endl;
   }
}

zombies *buscar_zombie_para_mapa(zombies*list, int buscar){
   zombies*aux=list; 
   bool encontrado=false;

   if(!listaVaciaZombies(list)){
      
      while(aux!=NULL && encontrado==false){
         if(aux->nivel==buscar){
            cout<<"El zombie "<< buscar<<" existe\n"; 
            encontrado=true;
         }
         aux=aux->prox;
      }
      return aux;
   }
   else{
      cout<<"El zombie de nivel "<<buscar<<" no existe\n"<<endl;
      return NULL;
   }
}

int modificar_nivel(zombies *list, int nuevo_valor, int actual_valor) {
    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nivel == actual_valor) {
            mover->nivel = nuevo_valor;
        }
        mover = mover->prox;
    }
    return nuevo_valor;
}

void modificar_vida(zombies *list, int nuevo_valor, int actual_valor) {
    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nivel == actual_valor) {
            mover->salud = nuevo_valor;
        }
        mover = mover->prox;
    }
}

void modificar_dano(zombies *list, int nuevo_valor, int actual_valor) {
    zombies *mover = list;
    while (mover != NULL) {
        if (mover->nivel == actual_valor) {
            mover->dano_ataque = nuevo_valor;
        }
        mover = mover->prox;
    }
}

int pedir_nivel() {
    int valor;
    cout << "Ingrese el nivel del zombie a modificar: ";
    cin >> valor;
    return valor;
}

int verificar_valor_nivel(int valor_dato, int x, int y) {
    while (true) {
        if ((valor_dato >= x) && (valor_dato <= y)) {
            cout << "El nivel está en el rango.\n";
            return valor_dato; // Retorna el valor válido
        } else {
            cout << "Ingrese un valor entre " << x << " y " << y << endl;
            valor_dato = pedir_nivel();
        }
    }
}

void modificar_zombie(zombies *&lista) {
    if (listaVaciaZombies(lista)) {
        cout << "La lista de zombies está vacía" << endl;
        return;
    }

    int valor_nivel = pedir_nivel();
    valor_nivel = verificar_valor_nivel(valor_nivel, 1, 5); // Asegura que el nivel esté en rango

    char opcion = '0'; // Inicializa la opción
    while (opcion != '4') {
        system("cls");
        cout << "              \e[47MENU DE MODIFICACION\e[0m" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "1.- Editar Nivel de peligro del zombie" << endl;
        cout << "2.- Editar vida del zombie" << endl;
        cout << "3.- Editar daño del zombie" << endl;
        cout << "4.- Salir del programa" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Ingrese la opción deseada del menú: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                int nivel;
                cout << "Redefina el nivel de peligro: ";
                cin >> nivel;
                if ((nivel >= 1) && (nivel <= 5)) {
                    modificar_nivel(lista, nivel, valor_nivel);
                    valor_nivel = nivel; // Actualiza el valor_nivel para futuras modificaciones
                } else {
                    cout << "Ingrese un nivel entre 1 y 5" << endl;
                }
                system("pause");
                break;
            }
            case '2': {
                int nueva_salud;
                cout << "Redefina la salud actual: ";
                cin >> nueva_salud;
                modificar_vida(lista, nueva_salud, valor_nivel);
                system("pause");
                break;
            }
            case '3': {
                int dano_ataque;
                cout << "Redefina el atributo de daño: ";
                cin >> dano_ataque;
                modificar_dano(lista, dano_ataque, valor_nivel);
                system("pause");
                break;
            }
            case '4':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    }
}


void eliminar(zombies*& lista_zombies, string valor) {
   if (listaVaciaZombies(lista_zombies)) {
      cout << "Lista vacía" << endl;
      return;
   }

   zombies* mover = lista_zombies;
   zombies* anterior = NULL;

   while (mover != NULL && mover->nombre != valor) {
      anterior = mover;
      mover = mover->prox;
   }

   if (mover == NULL) {
      cout << "Zombie no encontrado" << endl;
      return;
    } 
    else{
      if (mover == lista_zombies) {
         lista_zombies = lista_zombies->prox;
      } 
      else {
         anterior->prox = mover->prox;
      }
      delete mover;
   }
}

void eliminar_apariciones(zombies*& inicio, string nombre_zombie) {
   zombies* aux = inicio;
   zombies* anterior = NULL;
   int contador = 0;

   while (aux != NULL) {
      if (aux->nombre == nombre_zombie) {
         zombies* a_eliminar = aux; 
         if (anterior == NULL) {
               inicio = aux->prox;
               aux = inicio;
         } 
         else{

            anterior->prox = aux->prox;
            aux = anterior->prox; 
         }
         delete a_eliminar;
         contador++;
      } 
      else {
         anterior = aux; 
         aux = aux->prox; 
      }
   }

   cout << "Total de elementos eliminados: " << contador << endl;
}

#endif 
