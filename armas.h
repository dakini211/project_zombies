#ifndef ARMAS_H
#define ARMAS_H
#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

/*-------------------- STRUCT,CREACION Y LISTA_VACIA------------------*/
struct arma{
    string tipo_arma;    
    string nombre_arma; // campo que almacena el nombre del arma
    int dano;
    arma*sgte;   
};    
arma *crear_arma(int dano, string nombre_arma,string tipo_arma)
{    
    arma *nueva_arma=new arma;
    nueva_arma->tipo_arma=tipo_arma;
    nueva_arma->nombre_arma=nombre_arma;
    nueva_arma->dano=dano;
    nueva_arma->sgte=NULL;
    return nueva_arma;
}
bool lista_vacia_arma(arma *lista)
{
    return lista==NULL;
}
void menu_registro_arma(){
    cout << "\n\t\t[    REGISTRO DE  ARMA    ]\n";
    cout << "\t\t----------------------------\n\n";
    cout << " 1. REGISTRAR ARMA                       " << endl;
    cout << " 2. ELIMINAR DATOS DEL ARMA               " << endl;
    cout << " 3. MOSTRAR LISTADO                       " << endl;
    cout << " 4. SALIR                                 " << endl;
    cout << "\n Ingrese opcion : ";
}
/*-------------------- FUNCION INSERTAR  ------------------*/
string pedir_tipo() {
    string tipo;
    char opcion;
    
    cout << "\t\t------------------>";
    cout << "\n\tSeleccione el tipo de arma a registrar:\n";
    cout << "1. Armas de fuego\n";
    cout << "2. Armas arrojadizas\n";
    cout << "3. Armas proyectiles\n";
    cout << "4. Armas blancas\n";
    cout << "5. Armas contundentes\n";
    cout << "6. Armas improvisadas\n";
    cin >> opcion;

    switch (opcion)
    {
    case '1': // Armas de fuego
    { 
        system("cls");       
        char subOpcion;
        cout << "Seleccione el arma de fuego:\n";
        cout << "1. Pistola\n";
        cout << "2. Escopeta\n";
        cout << "3. Fusiles de asalto\n";
        cout << "4. Rifles de francotirador\n";
        cout << "Ingrese su opción: ";
        cin >> subOpcion;

        switch (subOpcion)
        {
        case '1':
            return "Pistola";            
        case '2':
            return "Escopeta";            
        case '3':
            return "Fusil de asalto";            
        case '4':
            return "Rifle francotirador";            
        default:
            cout << "Arma de fuego no valida." << endl;
            return "No disponible";
        }
    }

    case '2': // Armas arrojadizas
    {
        system("cls");  
        char subOpcion;
        cout << "Seleccione el arma arrojadiza:\n";
        cout << "1. Granadas\n";
        cout << "2. Cocteles molotov\n";
        cin >> subOpcion;

        switch (subOpcion)
        {
        case '1':
            return "Granada";            
        case '2':
            return "Cocteles molotov";            
                
        default:
            cout << "Arma arrojadiza no valida." << endl;
            return "No disponible";
        }
    }
        

    case '3': // Armas proyectiles
    {
        system("cls");  
        char subOpcion;
        cout << "Seleccione el arma de proyectil:\n";
        cout << "1. Ballestas\n";
        cout << "2. Tira chinas\n";
        cin >> subOpcion;

        switch (subOpcion)
        {
        case '1':
            return "Ballesta";            
        case '2':
            return "Tira china";            
                
        default:
            cout << "Arma de projectil no valida." << endl;
            return "No disponible";
        }
    }
       

    case '4': // Armas blancas
    {
        system("cls");  
        char subOpcion;
        cout<<"Seleccione el arma blanca:\n";
        cout<<"1. Cuchillos\n";
        cout<<"2. Machete\n";
        cout<<"3. Espada\n";
        cin>>subOpcion;
        switch (subOpcion)
        {
        case '1': 
            return  "Cuchillo";            
        case '2':
            return "Machete";
        case '3':
            return "Espada";             
                
        default:
            cout << "Arma blanca no valida." << endl;
            return "No disponible";
        }
    }
       

    case '5': // Armas contundentes
    {
        system("cls");  
        char subOpcion;
        cout << "1. Bat de beisbol\n";
        cout << "2. Martillo\n";
        cout << "3. Tuberia\n";
        cin >> subOpcion;
        switch (subOpcion)
        {
        case '1': 
            return  "Bat de beisbol";            
        case '2':
            return "Martillo";
        case '3':
            return "Tuberia";             
                
        default:
            cout << "Arma Contudente no valida." << endl;
            return "No disponible";
        }
            
    }

    case '6': // Armas improvisadas
    {
        system("cls");  
        char subOpcion;
        cout << "Seleccione el  tipo de arma improvisada:\n";
        cout << "1. Objetos punzantes\n";
        cout << "2. Objetos contundentes\n";
        cout << "3. Objetos armas incendiarias\n";
        cout << "4. Tranpas\n";
        cin >> subOpcion;
        switch (subOpcion)
        {
        case '1':
        {
            system("cls");  
            char subOpcion2;
            cout << "Seleccione el  arma a  improvisar:\n";
            cout << "1. Clavo\n";
            cout << "2. Tijeras\n";
            cout << "3. Destornillandor\n";        
            cin >> subOpcion2;
            switch (subOpcion2)
            {
                case '1':               
                    return "Clavo";
                case '2':               
                    return "Tijeras";
                case '3':               
                    return "Destornillandor";            
                default:
                    break;
            }
            break;    
        }                     
        case '2':
        {
            system("cls");  
            char subOpcion2;
            cout << "Seleccione el  arma a  improvisar:\n";
            cout << "1. Ladrillos\n";
            cout << "2. Rocas\n";
            cout << "3. Palo\n";        
            cin >> subOpcion2;
            switch (subOpcion2)
            {
                case '1':               
                    return "Ladrillo";
                case '2':               
                    return "Roca";
                case '3':               
                    return "Palo";            
                default:
                    break;
            }
            break;    

        }
            
      case '3':
        {
            system("cls");  
            char subOpcion2;
            cout << "Seleccione el  arma a  improvisar:\n";
            cout << "1. Fosforo\n";
            cout << "2. Gasolina\n";                   
            cin >> subOpcion2;
            switch (subOpcion2)
            {
                case '1':               
                    return "Fosforo";
                case '2':               
                    return "Gasolina";                       
                default:
                    break;
            } 
            break;               
        } 
         case '4':
        {
            system("cls");  
            char subOpcion2;
            cout << "Seleccione el  arma a  improvisar:\n";
            cout << "1. Alambre electrificado\n";
            cout << "2. Trampa de caida\n";                   
            cin >> subOpcion2;
            switch (subOpcion2)
            {
                case '1':               
                    return " Alambre electrificado";
                case '2':               
                    return "Trampa de caida";                       
                default:
                    break;
            }
            break;            
        }                 
        default:
            cout << "Arma inprovisada no valida." << endl;
            return "No disponible";
        }
        break;
            
    }      

    default:
        cout << "Opción inválida." << endl;
        return "Indefinido";
    }
    return "No disponible";
}
int pedir_dano_arma()
{
     system("cls");  
    int dano=0;
    cout<<"escriba dano del arma: ";
    cin>>dano;
    return dano;  
}
string pedir_nombre_arma()
{
    string nombre_arma;
    cout<<"escriba nombre del arma: ";
    cin>>nombre_arma;
    return nombre_arma;
}
void insertar_ultimo_armas(arma **lista)
{
    arma*nueva_arma=crear_arma(pedir_dano_arma(),pedir_nombre_arma(),pedir_tipo());
    if(lista_vacia_arma(*lista))
    {
        (*lista)=nueva_arma;
    }
    else{
        arma*mover=(*lista);
        while(mover->sgte!=NULL)
        {
            mover=mover->sgte;
        }
        mover->sgte=nueva_arma;
    }
}


/*------------------------ FUNCION ELIMINAR  ---------------------*/
void eliminar_arma(arma **lista) {
    int opcion, subOpcion;
    arma *q, *t = nullptr;
    q = (*lista);

    cout << "\n\n\n\tELIMINAR UN ARMA";
    cout << "\n\n\tSeleccione el tipo de arma a eliminar:\n";
    cout << "1. Armas de fuego\n";
    cout << "2. Armas arrojadizas\n";
    cout << "3. Armas proyectiles\n";
    cout << "4. Armas blancas\n";
    cout << "5. Armas contundentes\n";
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    const char* nombreArma = nullptr;
    switch (opcion) {
        case 1:
            cout << "Seleccione el arma de fuego:\n";
            cout << "1. Pistola\n";
            cout << "2. Escopeta\n";
            cout << "3. Fusiles de asalto\n";
            cout << "4. Rifles de francotirador\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: nombreArma = "Pistola"; break;
                case 2: nombreArma = "Escopeta"; break;
                case 3: nombreArma = "Fusiles de asalto"; break;
                case 4: nombreArma = "Rifles de francotirador"; break;
                default: cout << "\nOpcion invalida."; return;
            }
            break;
        case 2:
            cout << "Seleccione el arma arrojadiza:\n";
            cout << "1. Granadas\n";
            cout << "2. Cocteles molotov\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: nombreArma = "Granadas"; break;
                case 2: nombreArma = "Cocteles molotov"; break;
                default: cout << "\nOpcion invalida."; return;
            }
            break;
        case 3:
            cout << "Seleccione el arma de proyectil:\n";
            cout << "1. Ballestas\n";
            cout << "2. Tira chinas\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: nombreArma = "Ballestas"; break;
                case 2: nombreArma = "Tira chinas"; break;
                default: cout << "\nOpcion invalida."; return;
            }
            break;
        case 4:
            cout << "Seleccione el arma blanca:\n";
            cout << "1. Cuchillos\n";
            cout << "2. Machete\n";
            cout << "3. Espada\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: nombreArma = "Cuchillos"; break;
                case 2: nombreArma = "Machete"; break;
                case 3: nombreArma = "Espada"; break;
                default: cout << "\nOpcion invalida."; return;
            }
            break;
        case 5:
            cout << "Seleccione el arma contundente:\n";
            cout << "1. Bat de beisbol\n";
            cout << "2. Martillo\n";
            cout << "3. Tuberia\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: nombreArma = "Bat de beisbol"; break;
                case 2: nombreArma = "Martillo"; break;
                case 3: nombreArma = "Tuberia"; break;
                default: cout << "\nOpcion invalida."; return;
            }
            break;
        default:
            cout << "\nOpcion invalida. No se eliminara el arma.\n";
            return;
    }

     while (q != NULL) {
        if (q->nombre_arma == nombreArma) {  //eliminar normal
            if (q == *lista) {
                *lista = q->sgte;  
            } else {
                t->sgte = q->sgte;  
            }

            delete q;  
            cout << "\n\n\tREGISTRO ELIMINADO...!!!!!\n";
            return;
        } else {
            t = q;
            q = q->sgte;
        }
    }
    cout << "\n\tARMA NO ENCONTRADA...!!\n";
}

void eliminar_arma_sin_nombre(arma**lista_arma)
{
    string nombre_arma;
    cout<<"Nombre del arma a eliminar: ";
    cin>>nombre_arma;
    arma*actual=(*lista_arma);
    if(lista_vacia_arma(*lista_arma))
    {
        cout<<"no hay arma por eliminar: "<<endl;        
    }
    else{
        arma*anterior=NULL;
        while(actual!=NULL && actual->nombre_arma!=nombre_arma)
        {
            anterior=actual;
            actual=actual->sgte;
        }
        if(actual==NULL)
        {
            cout<<"accesorio no encontrado"<<endl;
        }
        else{
            if(actual==(*lista_arma))
            {
                (*lista_arma)=(*lista_arma)->sgte;
            }
            else{
                anterior->sgte=actual->sgte;
            }
            delete actual;
        }

    }
}

void eliminar_arma_con_nombre(arma** lista_arma, string nombre_arma)
{   
    if(lista_vacia_arma(*lista_arma))  // Verificación de lista vacía antes
    {
        cout << "No hay armas por eliminar." << endl;        
        return;
    }

    arma* actual = (*lista_arma);
    arma* anterior = NULL;

    while(actual != NULL && actual->nombre_arma != nombre_arma)
    {
        anterior = actual;
        actual = actual->sgte;
    }

    if(actual == NULL)
    {
        cout << "Arma no encontrada." << endl;  // Cambié "accesorio" por "arma"
    }
    else
    {
        if(actual == (*lista_arma))  // Si es el primer elemento
        {
            (*lista_arma) = (*lista_arma)->sgte;
        }
        else
        {
            anterior->sgte = actual->sgte;
        }
        delete actual;
    }
}

/*---------------------- FUNCION MOSTRAR  -------------------*/
void mostrar_arma(arma*q) {
    int i = 1;
    arma*p=q;

    while ((p) != NULL) {
        cout << "\n\tDATOS DEL ARMA[" << i << "] ";
        cout << "\n\t------------------------";
        cout << "\n\n\tNOMBRE DEL ARMA  : " << p->nombre_arma << endl;

        p = p->sgte;
        i++;
    }
}
/*---------------------- FUNCION MODIFICAR-------------------*/
void modificar_arma(arma**lista_arma)
{
    string nombre_arma;
    cout<<"Nombre del arma a modificar: ";
    cin>>nombre_arma;
    if(lista_vacia_arma(*lista_arma))
    {
        cout<<"No hay armas "<<endl;
        return;
    }
    else{
        arma*actual=(*lista_arma);
        bool encontrado=false;
        while(actual!=NULL && encontrado==false)
        {
            if(actual->nombre_arma==nombre_arma)
            {
                encontrado=true;
                cout<<"arma: "<<actual->nombre_arma<<endl;
                char opcion;
                while(opcion!='5')
                {
                    cout << "Seleccione el campo a modificar:" << endl;
                    cout << "1. Modificar tipo" << endl;
                    cout << "2. Modificar nombre" << endl;
                    cout << "3. Modificar dano" << endl; 
                    cout << "4. Eliminar arma" << endl;                  
                    cout << "5. Salir" << endl;
                    cout << "Ingrese su opcion: ";
                    cin >> opcion;
                    switch (opcion)
                    {
                    case '1':
                    {
                        string nuevo_tipo;
                        nuevo_tipo=pedir_tipo();
                        actual->tipo_arma = nuevo_tipo;
                        break;
                     }
                    case '2':
                    {
                        string nuevo_nombre;
                        nuevo_nombre = pedir_nombre_arma();
                        actual->nombre_arma = nuevo_nombre;
                        break;
                    }
                    case '3':
                    {
                        int dano;
                        dano=pedir_dano_arma();
                        actual->dano=dano;
                        break;
                    }
                    case '4':
                    {
                        eliminar_arma_con_nombre(&(*lista_arma),actual->nombre_arma);
                        break;                        
                    }
                    case '5':
                    {
                        cout << "Saliendo de la modificación." << endl;
                        break;                        
                    }                    
                    
                    default:
                        break;
                    }
                }
            }
            else{
                actual=actual->sgte;
            }
        }
        if(encontrado==false)
        {
            cout<<"no se encontro arma"<<endl;
        }
    }

}
void adios(){
    
}


#endif 
