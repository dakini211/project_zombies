#include<iostream>
#include<cstdlib>
#include<string.h>
#define maxchar 50

using namespace std;

struct nodo{
    int codigo;     // campo codigo del arma
    char nombrearm[maxchar]; // campo que almacena el nombre del arma
    struct nodo *sgte;

};

typedef struct nodo *PLista;


/*--------------------- FUNCION MENU PRINCIPAL --------------------*/
void menu(void){

    cout<<"\n\t\t[    REGISTRO DE  ARMA    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR ARMA                       "<<endl;
    cout<<" 2. ELIMINAR DATOS DEL DEL ARMA                "<<endl;
    cout<<" 3. MOSTRAR LISTADO                             "<<endl;
    cout<<" 4. SALIR                                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}

/*-------------------- FUNCION REGISTRAR ARMA ------------------*/
void registrar_arma(PLista &lista){

    PLista t,q = new(struct nodo);

    cout<<"\n\n\t\t[  REGISTRO  ]\n";
    cout<<"\t\t------------";
    cout<<"\n\tDATOS  "; 
    cin.ignore();cout<<"\n\n\tCODIGO:"; cin>>q->codigo;
    cin.ignore();cout<<"\n\tNOMBRE DEl ARMA:"; cin.getline(q->nombrearm,maxchar);

    system("cls");

    q->sgte = NULL;

    if(lista==NULL){

        lista = q;

    } else {

        t = lista;

        while(t->sgte!=NULL){

                t = t->sgte;
        }

        t->sgte = q;

    }
}
/*------------------------ FUNCION ELIMINAR ARMA ---------------------*/
void eliminar_arma(PLista &lista){

    int cod;
    PLista q,t;
    q=lista;

    cout<<"\n\n\n\tELIMINAR UN ARMA";
    cout<<"\n\n\tINGRESE CODIGO:"; cin>>cod;

    while(q!=NULL){

            if(q->codigo==cod){

                if(q==lista)
                    lista=lista->sgte;

                else
                    t->sgte=q->sgte;

                delete(q);

                cout<<"\n\n\tREGISTRO ELIMINADO...!!!!!\n";

                return;

            }else {

                t=q;
                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tCODIGO INCORRECTO...!!\n";

}
/*---------------------- FUNCION MOSTRAR ARMA -------------------*/
void mostrar_arma(PLista q){

    int i=1;

    while(q!=NULL){

        cout<<"\n\tDATOS DEL arma["<<i<<"] ";
        cout<<"\n\t------------------------";
        cout<<"\n\n\tCODIGO   : "<<q->codigo<<endl;
        cout<<"\n\tNOMBRE DEL ARMA  : "<<q->nombrearm<<endl;

        q=q->sgte;

        i++;
    }

}
/*------------------------- FUNCION PRINCIPAL -------------------*/
int main(void){

    system("color 0a");

    PLista lista=NULL;

    int opcion;

    do{
            menu();
            cin>>opcion;

            switch(opcion){

                case 1: registrar_arma(lista);
                        break;

                case 2: if(lista==NULL){

                            cout<<"\n\tNo Hay armas Registrados.....!!!!\n";

                        }else{

                            eliminar_arma(lista);

                        }
                        

                case 3: if(lista==NULL){

                            cout<<"\n\tNo Hay arma Registrados.....!!!!\n";

                        }else {

                            mostrar_arma(lista);

                        }
                    

                case 4: return 0;


                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

            }

            system("pause");  system("cls");

        }while(opcion!=4);

    system("pause");

    return 0;
    }
