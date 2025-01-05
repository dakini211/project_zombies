#ifndef ACCESORIOS_H
#define ACCESORIOS_H
#include <iostream>
#include <string>
using namespace std;
/*-------------------- STRUCT,CREACION Y LISTA_VACIA------------------*/
struct accesorio {
   int codigo;
   string nombre;
   string tipo;  
   int modificador;
   int usos;   
   accesorio* prox;
};

bool listaVaciaAccesorios(accesorio*accesorios)
{
    return accesorios==NULL;
}

accesorio*crear_accesorio(int usos,int modificador,string nombre,string tipo,int codigo)
{

    accesorio*nuevo_accesorio=new accesorio;
    nuevo_accesorio->codigo=codigo;
    nuevo_accesorio->tipo=tipo;
    nuevo_accesorio->nombre=nombre;
    nuevo_accesorio->modificador=modificador;
    nuevo_accesorio->usos=usos;
    nuevo_accesorio->prox=NULL;
    return nuevo_accesorio;
}
/*---------------------- FUNCION MOSTRAR  -------------------*/
void mostrar_accesorio(accesorio*lista_accesorio)
{
    accesorio*mover=lista_accesorio;
    if(listaVaciaAccesorios(lista_accesorio))
    {
        cout<<"lista de accesorio vacia:"<<endl;
    }
    else{
        while(mover!=NULL)
        {
            cout << "-------------------------------------------------------" << endl;
            cout<<"Codigo: "<<mover->codigo<<endl;
            cout<<"Tipo: "<<mover->tipo<<endl;
            cout<<"nombre: "<<mover->nombre<<endl;
            cout<<"modificador: "<<mover->modificador<<endl;
            cout<<"usos: "<<mover->usos<<endl;
            cout << "-------------------------------------------------------" << endl;
            mover=mover->prox;
        }
        
    }
    
}
/*-------------------- FUNCIONES PEDIR  ------------------*/

string pedir_tipo_accesorio()
{
    string tipo;
    char opcion;
    
    cout<<"============================================"<<endl;
    cout << "\n\tSeleccione el tipo de accesorio a registrar:\n";
    cout << "1. Accesorio de ataque\n";
    cout << "2. Accesorio de defensa\n";
    cout << "3. Accesorio de supervivencia\n"; 
    cout<<"============================================"<<endl;   
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case '1':
        return "Ataque";        

    case  '2':
        return "Defensa";        

    case  '3':
        return "Supervivencia";       

    
    default:
        cout << "Opción inválida." << endl;
        return "Indefinido";
        break;
    }

}

string pedir_nombre_accesorio_vacio()
{
    string nombre;       
    return nombre;
}

string pedir_nombre_accesorio2()
{
    string nombre;
    cout<<"Escriba el nombre del accesorio: ";
    cin>>nombre;       
    return nombre;
}

int pedir_modificador_accesorio()
{
    int modificador;
    cout<<"Escriba modificador correspondiente: ";
    cin>>modificador;
    return modificador;
}

int pedir_usos_accesorio()
{
    int usos;
    cout<<"Escriba Usos o Municiones para el accesorio correspondiente: ";
    cin>>usos;
    return usos;
}

int pedir_codigo_accesorio()
{
    int codigo=0;
    return codigo;
}

string pedir_tipo_arma() {
    string tipo;
    char opcion;

    cout << "\n\t\tRECOMENDACIONES\n";
    cout << "\t\t----------------\n";
    cout << "1. Contra zombies rapidos y agiles, las armas mas efectivas son mas efectivas.\n";
    cout << "2. Contra zombies lentos las armas cuerpo a cuerpo son mas utiles.\n";
    cout << "3. En espacios cerrados, las armas cortas y cuerpo a cuerpo son mas practicas.\n";
    cout << "4. En espacios abiertos las aermas  de largo alcence son mas eficientes.\n";
    cout << "5. Asegurate de tener suficiente municion para el arma que elijas.\n";
    cout << "6. En espacios abiertos las aermas  de largo alcence son mas eficientes.\n";
    cout << "7. Si no conoces bien un arma, es mejor elegir la opcion mas  facil de usar.\n";
    cout << "8. Considera usar armas silenciosas porque alteran a los zombies.\n";
    
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



/*-------------------- FUNCION INSERTAR ------------------*/
void insertar_ultimo_accesorio(accesorio**lista_accesorio)
{
    accesorio*nuevo_accesorio=crear_accesorio(pedir_usos_accesorio(),pedir_modificador_accesorio(),pedir_nombre_accesorio_vacio(),pedir_tipo_accesorio(),pedir_codigo_accesorio());
    if(nuevo_accesorio->tipo=="Ataque")
    {
        nuevo_accesorio->nombre=pedir_tipo_arma();
    }
    else{
        nuevo_accesorio->nombre=pedir_nombre_accesorio2();
    }
    if(listaVaciaAccesorios(*lista_accesorio))
    {
        (*lista_accesorio)=nuevo_accesorio;
    }
    else{
        accesorio*mover=(*lista_accesorio);
        while(mover->prox!=NULL)
        {
            mover=mover->prox;
        }
        mover->prox=nuevo_accesorio;
        nuevo_accesorio->codigo=mover->codigo+1;
    }
}

void insertar_ultimo_accesorio_con_id(accesorio**lista_accesorio,accesorio**accesorio_nuevo)
{
    accesorio*nuevo_accesorio=(*accesorio_nuevo);    
    if(listaVaciaAccesorios(*lista_accesorio))
    {
        (*lista_accesorio)=nuevo_accesorio;
    }
    else{
        accesorio*mover=(*lista_accesorio);
        while(mover->prox!=NULL)
        {
            mover=mover->prox;
        }
        mover->prox=nuevo_accesorio;        
    }
}
/*------------------------ FUNCION ELIMINAR  ---------------------*/
void eliminar_accesorio_sin_nombre(accesorio**Lista_accesorio)
{
    string nombre_accesorio;
    cout<<"Nombre del accesorio a eliminar: ";
    cin>>nombre_accesorio;
    accesorio*actual=(*Lista_accesorio);
    if(listaVaciaAccesorios(*Lista_accesorio))
    {
        cout<<"no hay accesorio por eliminar: "<<endl;        
    }
    else{
        accesorio*anterior=NULL;
        while(actual!=NULL && actual->nombre!=nombre_accesorio)
        {
            anterior=actual;
            actual=actual->prox;
        }
        if(actual!=NULL)
        {
            cout<<"accesorio no encontrado"<<endl;
        }
        else{
            if(actual==(*Lista_accesorio))
            {
                (*Lista_accesorio)=(*Lista_accesorio)->prox;
            }
            else{
                anterior->prox=actual->prox;
            }
            delete actual;
        }

    }
}

void eliminar_accesorio_con_nombre(accesorio** Lista_accesorio, string nombre_accesorio)
{
    if(listaVaciaAccesorios(*Lista_accesorio))  
    {
        cout << "No hay accesorios por eliminar." << endl;
        return;
    }

    accesorio* actual = (*Lista_accesorio);
    accesorio* anterior = NULL;

    while(actual != NULL && actual->nombre != nombre_accesorio)
    {
        anterior = actual;
        actual = actual->prox;
    }

    if(actual == NULL)
    {
        cout << "Accesorio no encontrado." << endl;
    }
    else
    {
        if(actual == (*Lista_accesorio))  // Si es el primer elemento
        {
            (*Lista_accesorio) = (*Lista_accesorio)->prox;
        }
        else
        {
            anterior->prox = actual->prox;
        }
        delete actual;
    }
}
/*---------------------- FUNCION MODIFICAR-------------------*/
void modificar_accesorio(accesorio**lista_accesorio)
{
    string nombre_accesorio;
    cout<<"Nombre del accesorio a buscar: ";
    cin>>nombre_accesorio;
    if(listaVaciaAccesorios(*lista_accesorio))
    {
        cout<<"No hay accesorios "<<endl;
        return;
    }
    else{
        accesorio*actual=(*lista_accesorio);
        bool encontrado=false;
        while(actual!=NULL && encontrado==false)
        {
            if(actual->nombre==nombre_accesorio)
            {
                encontrado=true;
                cout<<"accesorio: "<<actual->nombre<<endl;
                char opcion;
                while(opcion!='6')
                {
                    cout <<      "Seleccione el campo a modificar:" << endl;
                    cout<<"============================================"<<endl;
                    cout << "1. Modificar nombre" << endl;
                    cout << "2. Modificar tipo" << endl;
                    cout << "3. Modificar modificador" << endl;
                    cout << "4. Modificar usos" << endl;
                    cout << "5. eliminar accesorio" << endl;                     
                    cout << "6. Salir" << endl;
                    cout<<"============================================"<<endl;
                    cout << "Ingrese su opcion (1 al 6): ";
                    cin >> opcion;
                    switch (opcion)
                    {
                    case '1':
                    {
                        string nuevo_nombre;
                        if(actual->tipo=="Ataque")
                        {
                            nuevo_nombre=pedir_tipo_arma();
                            actual->nombre=nuevo_nombre;
                        }
                        else{
                            nuevo_nombre=pedir_nombre_accesorio2();
                            actual->nombre=nuevo_nombre;
                        }                        
                        break;
                     }
                    case '2':
                    {
                        string nuevo_tipo = pedir_tipo_accesorio();
                        actual->tipo = nuevo_tipo;
                        break;
                    }
                    case '3':
                    {
                        int modificador;
                        modificador=pedir_modificador_accesorio();
                        actual->modificador=modificador;
                        break;
                    }
                    case '4':
                    {
                        int usos;
                        usos=pedir_usos_accesorio();
                        actual->usos=usos;
                        break;
                    }
                    case '5':
                    {
                        eliminar_accesorio_con_nombre(&(*lista_accesorio),actual->nombre);
                        cout<<"accesorio eliminado";
                        system("pause");
                        system("cls");
                        opcion='6';
                        break;                        
                    }
                    case '6':
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
                actual=actual->prox;
            }
        }
        if(encontrado==false)
        {
            cout<<"no se encontro accesorio"<<endl;
        }
    }

}
/*---------------------- FUNCION BUSCAR-------------------*/

accesorio*buscar_accesorio(accesorio*lista_accesorio,int codigo)
{
    accesorio*mover=lista_accesorio;
    bool encontrado=false;
    if(listaVaciaAccesorios(lista_accesorio))
    {
        return NULL;
    }
    else{
        while(mover!=NULL && encontrado==false)
        {
            if(mover->codigo==codigo)
            {
                encontrado=true;
            }
            else{
                mover=mover->prox;
            }
        
        }
    return mover;
    }   
}


#endif 
