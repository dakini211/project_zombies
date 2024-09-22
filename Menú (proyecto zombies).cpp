#include <iostream>
#include <fstream>
using namespace std;

struct jugador{
    string nombre;
    string rango; /*Rango sirve para definir quien es el lider del grupo, ya sean lider o soldado*/
    int salud=100; /*La salud en este caso es la vida y siempre inicializa con 100 según el PDF*/
    int afectacion=0; /*Afectacion viene siendo los daños que resive el jugador*/
    jugador *prox;
};

void escribir_archivo_jugador(ofstream &escribir){ /*La función crea el archivo en donde se guardará la información de la estructura jugador*/
    string nombre_jugador;
    string rango_jugador;
    int salud_jugador=100; 
    int afectacion_jugador=0;
    cout<<"Ingrese jugador: ";
    cin>>nombre_jugador;
    cout<<"Ingrese el rango (lider / soldado): ";
    cin>>rango_jugador;
    if(rango_jugador!="lider" && rango_jugador!="soldado"){
        cout<<"Error, el dato no se encuentre entre las opciones\n"; /*prueba de modificacion para github*/
    }
    else{
        escribir.open("archivo jugador.txt", ios::out | ios::app);
        escribir<<nombre_jugador<<" "<<rango_jugador<<" "<<salud_jugador<<" "<<afectacion_jugador<<"\n";
        escribir.close();
    }   
}

void leer_archivo_jugador(ifstream &leer){

}

int main(){
    ofstream escritura_jugador;
    ifstream lectura_jugador;
    int opcion;
    while (opcion!=4){
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
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        switch (opcion){
            case 1:
                cout<<"falta programar"<<"\n";
                system("pause");
            break;
            case 2: 
                while(opcion!=5){
                    system("cls");
                    cout<<"        2. Opciones        "<<"\n";
                    cout<<"==========================="<<"\n";
                    cout<<"2.1. Gestionar zombies "<<"\n";
                    cout<<"2.2. Gestionar accesorios "<<"\n";
                    cout<<"2.3. Gestionar equipos "<<"\n";
                    cout<<"2.4. Gestionar mapas "<<"\n";
                    cout<<"2.5. Volver "<<"\n";
                    cout<<"==========================="<<"\n";
                    cout<<"Ingrese una opcion: ";
                    cin>>opcion;
                    switch (opcion){
                        case 1:
                            cout<<"falta programar";
                            system("pause");
                        break;
                        case 2:
                            cout<<"falta programar";
                            system("pause");
                        break;
                        case 3:
                            while(opcion!=4){
                                system("cls");
                                cout<<"        2.3. Gestionar equipos        "<<"\n";
                                cout<<"======================================"<<"\n";
                                cout<<"2.3.1. Agregar soldado "<<"\n";
                                cout<<"2.3.2. Modificar soldado "<<"\n";
                                cout<<"2.3.3. Eliminar soldado "<<"\n";
                                cout<<"2.3.4. Consultar equipo "<<"\n";
                                cout<<"2.3.5. Volver "<<"\n";
                                cout<<"======================================"<<"\n";
                                cout<<"Ingrese una opcion: ";
                                cin>>opcion;
                                switch (opcion){
                                    case 1:
                                        system("pause");
                                        cout<<"        2.3.1 Gestionar equipos        "<<"\n";
                                        cout<<"======================================"<<"\n";
                                        escribir_archivo_jugador(escritura_jugador);
                                        system("pause");
                                        break;
                                    case 2:
                                        cout<<"falta programar";
                                        system("pause");
                                        break;
                                    case 3:
                                        cout<<"falta programar";
                                        system("pause");
                                        break;
                                    case 4:
                                        leer_archivo_jugador(lectura_jugador);
                                        system("pause");
                                        break;
                                }
                            }
                        break;
                        case 4:
                            cout<<"falta programar"<<"\n";
                            system("pause");
                        break;                   
                    }
                }
            case 3:
                cout<<"falta programar";
                system("pause");
            break;
        }
    }
    
    return 0;
}