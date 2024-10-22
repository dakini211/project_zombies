#ifndef ZOMBIES_H
#define ZOMBIES_H
#include <iostream>
#include <fstream>
using namespace std;

struct zombies{
   string nombre;
   int nivel;
   int salud=0;
   int dano_ataque=0;
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

void mostrarlistaZombies(zombies *lista)//muestra la lsita de zombies agregados
   {
   zombies*mover=lista;

   if(!listaVaciaZombies(lista))
   {
   mover=lista;
   while(mover!=NULL)
   {
      cout<<endl<<"-------------------------------------------------------"<<endl;
      cout<<"Nombre del zombie: "<<mover->nombre<<endl;
      cout<<"nivel de peligrosidad del zombie: "<<mover->nivel<<endl;
      cout<<"salud del zombie: "<<mover->salud<<endl;
      cout<<"Dano del zombie: "<<mover->dano_ataque<<endl;
      cout<<endl<<"-------------------------------------------------------"<<endl;
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

bool buscar_zombie(zombies*lista_zombies,string nom)//para buscar algun zombie especefico 
{
   if(listaVaciaZombies(lista_zombies))
   {
      cout<<"No hay zombies disponibles"<<endl;
      return 0;
   }
   else{
      zombies*aux=lista_zombies; bool encontrado=false;
      while(aux!=NULL&&encontrado==false)
      {
         if(aux->nombre==nom)
         {
            cout<<"el zombie: "<< nom<<" existe";            
            return 1;
         }
         aux=aux->prox;
      }
      cout<<"el zombie: "<<nom<<" no existe"<<endl;
      return 0;
   }
   
}

void modificar_zombie(zombies**lista_zombies,string nom)
{
   if(listaVaciaZombies(*lista_zombies))
   {
      cout<<"lista vacia"<<endl;
      return;
   }
   else{
      zombies*aux=(*lista_zombies);
      bool encontrado=false;

      while(aux!=NULL && encontrado==false)
      {
         if(aux->nombre==nom)
         {
            system("cls");
            int opcion = 0;
            while (opcion != 5) {
               cout << "***********     MENU DE MODIFICACION    **********" << endl;
               cout << "-----------------------------------------------" << endl;
               cout << "1.- Editar Nombre del zombie" << endl;
               cout << "2.- Editar Nivel de peligro del zombie" << endl;
               cout << "3.- Editar vida del zombie" << endl;
               cout << "4.- Editar dano del zombie" << endl;              
               cout << "5.- Salir del programa" << endl;
               cout << "-----------------------------------------------" << endl;

               cout << "Ingrese la opcion deseada del Menu: ";
               cin >> opcion;
               switch (opcion)
               {
               case 1:{
                  string nombre;
                  cout<<"escriba un nuevo nombre: ";
                  cin>>nombre;
                  aux->nombre=nombre;
                  break;
               }

               case 2:{
                  int nivel;
                  cout<<"Redefina el nivel de peligro: ";
                  cin>>nivel;
                  aux->nivel=nivel;
                  break;
               }
               case 3:{
                  int salud;
                  cout<<"Redefina la salud actual: ";
                  cin>>salud;
                  aux->salud=salud;
               }
               case 4:{
                  int dano_ataque;
                  cout<<"Redefina el atributo de dano: ";
                  cin>>dano_ataque;
                  aux->dano_ataque=dano_ataque;
               }
               case 5:{
                  break;
               }
                 
               
               default:
                  break;
               }
            
            }
            encontrado=true;
            
         }
         aux=aux->prox;
      }
      if(encontrado==false)
      {
         cout<<"nombre no encontrado"<<endl;
      }
   }
}


void eliminar(zombies**lista_zombies,string nom)
{
   if(listaVaciaZombies(*lista_zombies))
   {
      cout<<"lista vacia"<<endl;
      return;
   }
   else{
      zombies*mover,*anterior=NULL;
      mover=*lista_zombies;
      while(mover->prox!=NULL && mover->nombre!=nom)
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
         if(mover==*lista_zombies)
         {
            (*lista_zombies)=(*lista_zombies)->prox;
         }
         else{
            anterior->prox=mover->prox;
         }
         delete mover;
      }
   }  
}
#endif 