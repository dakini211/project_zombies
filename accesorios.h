#ifndef ACCESORIOS_H
#define ACCESORIOS_H
#include <iostream>
#include <string>
using namespace std;
/*-------------------- STRUCT,CREACION Y LISTA_VACIA------------------*/
struct accesorio {
   string tipo;
   string nombre;
   int modificador;
   int usos;   
   accesorio* prox;
};

bool listaVaciaAccesorios(accesorio*accesorios)
{
    return accesorios==NULL;
}

accesorio*crear_accesorio(int usos,int modificador,string nombre,string tipo)
{
    accesorio*nuevo_accesorio=new accesorio;
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
    
    cout << "\t\t------------------>";
    cout << "\n\tSeleccione el tipo de accesorio a registrar:\n";
    cout << "1. Accesorio de ataque\n";
    cout << "2. Accesorio de defensa\n";
    cout << "3. Accesorio de supervivencia\n";    
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

string pedir_nombre_accesorio()
{
    string nombre;
    cout<<"Escriba nombre del accesorio: ";
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
    cout<<"Escriba usos para el accesorio correspondiente: ";
    cin>>usos;
    return usos;
}
/*-------------------- FUNCION INSERTAR ------------------*/
void insertar_ultimo_accesorio(accesorio**lista_accesorio)
{
    accesorio*nuevo_accesorio=crear_accesorio(pedir_usos_accesorio(),pedir_modificador_accesorio(),pedir_nombre_accesorio(),pedir_tipo_accesorio());
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
        while(actual!=NULL and actual->nombre!=nombre_accesorio)
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

void eliminar_accesorio_con_nombre(accesorio**Lista_accesorio,string nombre_accesorio)
{
    
    accesorio*actual=(*Lista_accesorio);
    if(listaVaciaAccesorios(*Lista_accesorio))
    {
        cout<<"no hay accesorio por eliminar: "<<endl;        
    }
    else{
        accesorio*anterior=NULL;
        while(actual!=NULL and actual->nombre!=nombre_accesorio)
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
/*---------------------- FUNCION MODIFICAR-------------------*/
void modificar_accesorio(accesorio**lista_accesorio)
{
    string nombre_accesorio;
    cout<<"Nombre del accesorio a eliminar: ";
    cin>>nombre_accesorio;
    if(listaVaciaAccesorios(*lista_accesorio))
    {
        cout<<"No hay accesorios "<<endl;
        return;
    }
    else{
        accesorio*actual=(*lista_accesorio);
        bool encontrado=false;
        while(actual!=NULL and encontrado==false)
        {
            if(actual->nombre==nombre_accesorio)
            {
                encontrado=true;
                cout<<"accesorio: "<<actual->nombre;
                char opcion;
                while(opcion!='6')
                {
                    cout << "Seleccione el campo a modificar:" << endl;
                    cout << "1. Modificar nombre" << endl;
                    cout << "2. Modificar tipo" << endl;
                    cout << "3. Modificar modificador" << endl;
                    cout << "4. Modificar usos" << endl;
                    cout << "5. Eliminar accesorio" << endl;
                    cout << "6. Salir" << endl;
                    cout << "Ingrese su opcion: ";
                    cin >> opcion;
                    switch (opcion)
                    {
                    case '1':
                    {
                        string nuevo_nombre;
                        nuevo_nombre=pedir_nombre_accesorio();
                        actual->nombre = nuevo_nombre;
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
                        eliminar_accesorio_con_nombre(&actual,actual->nombre);
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
void hola()
{
   
}


#endif 