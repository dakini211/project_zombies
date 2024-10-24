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

   if(!listaVaciaZombies(lista))
   {
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
            cout<<"el zombie: "<< buscar<<" existe";            
         }
         aux=aux->prox;
      }
      cout<<"el zombie: "<<buscar<<" no existe, puede hacer el cambio pero no sera efectivo"<<endl;
   }
}

int modificar_nivel(zombies *list, int nuevo_valor, int actual_valor){
   zombies *mover=list;
   while(mover!=NULL){
      if(mover->nivel==actual_valor){
         mover->nivel=nuevo_valor;
         return mover->nivel;
      }
      mover=mover->prox;
   }
}

void modificar_vida(zombies *list, int nuevo_valor, int actual_valor){
   zombies *mover=list;
   while(mover!=NULL){
      if(mover->nivel==actual_valor){
         mover->salud=nuevo_valor;
      }
      mover=mover->prox;
   }
}

void modificar_dano(zombies *list, int nuevo_valor, int actual_valor){
   zombies *mover=list;
   while(mover!=NULL){
      if(mover->nivel==actual_valor){
         mover->dano_ataque=nuevo_valor;
      }
      mover=mover->prox;
   }
}

int pedir_nivel(){
   int valor;
   cout<<"Ingrese el nivel del zombie a modificar: ";
   cin>>valor;
   return valor;
}

bool verificar_valor_nivel(int valor_dato, int x, int y) {
   while (true) {
      if ((valor_dato >= x) && (valor_dato <= y)) {
         return true;
      } 
      else{
         cout<<"Ingrese un valor entre "<<x<<" y "<<y<<endl;
         valor_dato = pedir_nivel();
      }
   }
}

void modificar_zombie(zombies*&lista){
   zombies *auxiliar= lista;
   int nueva_salud;
   char opcion;

   if(listaVaciaZombies(lista)){
      cout<<"La lista de zombies esta vacia"<<endl;
   }
   else{
      int valor_nivel=pedir_nivel();
      bool ok=verificar_valor_nivel(valor_nivel, 1, 5);
      buscar_zombie(auxiliar, valor_nivel);

      while (opcion != '4') {
         system("cls");
         cout << "***********     MENU DE MODIFICACION    **********" << endl;
         cout << "-----------------------------------------------" << endl;
         cout << "1.- Editar Nivel de peligro del zombie" << endl;
         cout << "2.- Editar vida del zombie" << endl;
         cout << "3.- Editar dano del zombie" << endl;              
         cout << "4.- Salir del programa" << endl;
         cout << "-----------------------------------------------" << endl;
         cout << "Ingrese la opcion deseada del Menu: ";
         cin >> opcion;
         switch (opcion){
            case '1':
               int nivel;
               cout<<"Redefina el nivel de peligro: ";
               cin>>nivel;
               if((nivel>=1) && (nivel<=5)){
                  valor_nivel=modificar_nivel(auxiliar, nivel, valor_nivel);
               }
               else{
                  cout<<"Ingrese un nivel entre 1 y 5"<<endl;
               }
               system("pause");
            break;
            case '2':
               cout<<"Redefina la salud actual: ";
               cin>>nueva_salud;
               modificar_vida(auxiliar, nueva_salud, valor_nivel);
               system("pause");
            break;
            case '3':
               int dano_ataque;
               cout<<"Redefina el atributo de dano: ";
               cin>>dano_ataque;
               modificar_dano(auxiliar, dano_ataque, valor_nivel);
               system("pause");
            break;
            default:
               cout<<"Opcion invalida"<<endl;
            break;
         }
      }      
   }
}


void eliminar(zombies*&lista_zombies, string valor){
   if(listaVaciaZombies(lista_zombies))
   {
      cout<<"lista vacia"<<endl;
      return;
   }
   else{
      zombies*mover,*anterior=NULL;
      mover=lista_zombies;
      while(mover->prox!=NULL && mover->nombre!=valor)
      {
         anterior=mover;
         mover=mover->prox;
      }
      if(mover==NULL)
      {
         cout<<"zombie no encontrado"<<endl;
         return;
      }
      else{
         if(mover==lista_zombies)
         {
            lista_zombies=lista_zombies->prox;
         }
         else{
            anterior->prox=mover->prox;
         }
         delete mover;
      }
   }  
}

void eliminar_apariciones(zombies *&inicio, string nombre_zombie){
   zombies *aux=inicio;
   int contador=0;
   while(aux!=NULL){
      if(aux->nombre==nombre_zombie){
         eliminar(aux, nombre_zombie);
         contador++;
      }
      aux=aux->prox;
   }
   cout<<"Total de elementos eliminados "<<contador<<endl;
}
#endif 