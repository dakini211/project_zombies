#include <iostream>
#include <fstream>
#include <string>
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


int main() {
    int opcion = 0;
    zombies *lista_zombies = NULL;

    while (opcion != 7) {
        cout << "***********     MENU DE OPCIONES     **********" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "1.- Modificar zombie" << endl;
        cout << "2.- Agregar un nodo al final de la Lista" << endl;
        cout << "3.- Agregar varios nodos al final de la Lista" << endl;
        cout << "4.- Mostrar contenido de la Lista" << endl;
        cout << "5.- Eliminar un nodo de la Lista" << endl;
        cout << "6.- Buscar un elemento en la Lista" << endl;
        cout << "7.- Salir del programa" << endl;
        cout << "-----------------------------------------------" << endl;

        cout << "Ingrese la opcion deseada del Menu: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                modificar_zombie(&lista_zombies,pedir_nombre());
                break;
            case 2:
                {
                    string nombre; 
                    int salud = 0, dano_zombie = 0, nivel = 0;
                    cout << "ingrese el nombre del zombie: ";
                    cin >> nombre;
                    cout << "ingrese el nivel del zombie: ";
                    cin >> nivel;
                    cout << "ingrese el salud del zombie: ";
                    cin >> salud;
                    cout << "ingrese el dano del zombie: ";
                    cin >> dano_zombie;
                    insertar_ultimo_zombie(&lista_zombies, nombre, nivel, salud, dano_zombie); 
                }
                break;
            case 3: 
                {
                    int cantidad, i = 1;
                    cout << "Indica cantidad de nodos a ser colocados: ";
                    cin >> cantidad;
                    if (cantidad <= 0) {
                        cout << "Cantidad no válida." << endl;
                        break;
                    }
                    while (i <= cantidad) {
                        string nombre; int salud, dano_zombie, nivel = 0;
                        cout << "ingrese el nombre del zombie: ";
                        cin >> nombre;
                        cout << "ingrese el nivel del zombie: ";
                        cin >> nivel;
                        cout << "ingrese el salud del zombie: ";
                        cin >> salud;
                        cout << "ingrese el dano del zombie: ";
                        cin >> dano_zombie;
                        insertar_ultimo_zombie(&lista_zombies, nombre, nivel, salud, dano_zombie); 
                        i++;
                    }
                }
                break;
            case 4: 
                if (listaVaciaZombies(lista_zombies))
                    cout << "Lista vacia, no es posible mostrar su contenido" << endl;
                else
                    mostrarlistaZombies(lista_zombies);
                break;     
            case 5: 
                if (listaVaciaZombies(lista_zombies))
                    cout << "Lista vacia, no es posible eliminar" << endl;
                else
                    eliminar(&lista_zombies, pedir_nombre());
                break;  
            case 6: 
                if (listaVaciaZombies(lista_zombies))
                    cout << "Lista vacia, no es posible hacer una busqueda" << endl;
                else
                    buscar_zombie(lista_zombies, pedir_nombre());
                break;  
            case 7:
                cout << "Hasta la vista baby" << endl;
                break;
            default: 
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }
    return 0;
}
