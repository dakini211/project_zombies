#include<iostream>
#include<string.h>

using namespace std;

struct nodo {
    char nombrearm[20]; // quite lo que decia codigo, pero lo deje con char porque no lo pude cambiar, o sea si pero no compilo xd
    struct nodo *sgte;
};

typedef struct nodo *PLista;

void menu(void) {
    cout << "\n\t\t[    REGISTRO DE  ARMA    ]\n";
    cout << "\t\t----------------------------\n\n";
    cout << " 1. REGISTRAR ARMA                       " << endl;
    cout << " 2. ELIMINAR DATOS DEL ARMA               " << endl;
    cout << " 3. MOSTRAR LISTADO                       " << endl;
    cout << " 4. SALIR                                 " << endl;

    cout << "\n Ingrese opcion : ";
}
/*-------------------- FUNCION REGISTRAR ARMA ------------------*/
void registrar_arma(PLista &lista) {
    PLista t, q = new(struct nodo);
    int opcion;

    cout << "\n\n\t\t[  REGISTRO  ]\n";
    cout << "\t\t------------";
    cout << "\n\tSeleccione el tipo de arma a registrar:\n";
    cout << "1. Armas de fuego\n";
    cout << "2. Armas arrojadizas\n";
    cout << "3. Armas proyectiles\n";
    cout << "4. Armas blancas\n";
    cout << "5. Armas contundentes\n";
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    int subOpcion;
    switch (opcion) {
        case 1:
            cout << "Seleccione el arma de fuego:\n";
            cout << "1. Pistola\n";
            cout << "2. Escopeta\n";
            cout << "3. Fusiles de asalto\n";
            cout << "4. Rifles de francotirador\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: strcpy(q->nombrearm, "Pistola"); break;
                case 2: strcpy(q->nombrearm, "Escopeta"); break;
                case 3: strcpy(q->nombrearm, "Fusiles de asalto"); break;
                case 4: strcpy(q->nombrearm, "Rifles de francotirador"); break;
                default: cout << "\nOpcion invalida."; delete q; return;
            }
            break;
        case 2:
            cout << "Seleccione el arma arrojadiza:\n";
            cout << "1. Granadas\n";
            cout << "2. Cocteles molotov\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: strcpy(q->nombrearm, "Granadas"); break;
                case 2: strcpy(q->nombrearm, "Cocteles molotov"); break;
                default: cout << "\nOpcion invalida."; delete q; return;
            }
            break;
        case 3:
            cout << "Seleccione el arma de proyectil:\n";
            cout << "1. Ballestas\n";
            cout << "2. Tira chinas\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: strcpy(q->nombrearm, "Ballestas"); break;
                case 2: strcpy(q->nombrearm, "Tira chinas"); break;
                default: cout << "\nOpcion invalida."; delete q; return;
            }
            break;
        case 4:
            cout << "Seleccione el arma blanca:\n";
            cout << "1. Cuchillos\n";
            cout << "2. Machete\n";
            cout << "3. Espada\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: strcpy(q->nombrearm, "Cuchillos"); break;
                case 2: strcpy(q->nombrearm, "Machete"); break;
                case 3: strcpy(q->nombrearm, "Espada"); break;
                default: cout << "\nOpcion invalida."; delete q; return;
            }
            break;
        case 5:
            cout << "Seleccione el arma contundente:\n";
            cout << "1. Bat de beisbol\n";
            cout << "2. Martillo\n";
            cout << "3. Tuberia\n";
            cin >> subOpcion;
            switch (subOpcion) {
                case 1: strcpy(q->nombrearm, "Bat de beisbol"); break;
                case 2: strcpy(q->nombrearm, "Martillo"); break;
                case 3: strcpy(q->nombrearm, "Tuberia"); break;
                default: cout << "\nOpcion invalida."; delete q; return;
            }
            break;
        default:
            cout << "\nOpcion invalida. No se registrara el arma.\n";
            delete q;
            return;
    }

    q->sgte = NULL;

    if (lista == NULL) {
        lista = q;
    } else {
        t = lista;
        while (t->sgte != NULL) {
            t = t->sgte;
        }
        t->sgte = q;
    }

    cout << "\nArma registrada: " << q->nombrearm << endl;
}
/*------------------------ FUNCION ELIMINAR ARMA ---------------------*/
void eliminar_arma(PLista &lista) {
    int opcion, subOpcion;
    PLista q, t = nullptr;
    q = lista;

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
        if (strcmp(q->nombrearm, nombreArma) == 0) {
            if (q == lista) {
                lista = lista->sgte;
            } else {
                t->sgte = q->sgte;
            }

            delete(q);
            cout << "\n\n\tREGISTRO ELIMINADO...!!!!!\n";
            return;
        } else {
            t = q;
            q = q->sgte;
        }
    }
    cout << "\n\tARMA NO ENCONTRADA...!!\n";
}
/*---------------------- FUNCION MOSTRAR ARMA -------------------*/
void mostrar_arma(PLista q) {
    int i = 1;

    while (q != NULL) {
        cout << "\n\tDATOS DEL ARMA[" << i << "] ";
        cout << "\n\t------------------------";
        cout << "\n\n\tNOMBRE DEL ARMA  : " << q->nombrearm << endl;

        q = q->sgte;
        i++;
    }
}
/*------------------------- FUNCION PRINCIPAL -------------------*/
int main(void) {
    PLista lista = NULL;
    int opcion;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1: registrar_arma(lista);
                    break;

            case 2: if (lista == NULL) {
                        cout << "\n\tNo Hay armas Registradas.....!!!!\n";
                    } else {
                        eliminar_arma(lista);
                    }
                    break;

            case 3: if (lista == NULL) {
                        cout << "\n\tNo Hay armas Registradas.....!!!!\n";
                    } else {
                        mostrar_arma(lista);
                    }
                    break;

            case 4: return 0;

            default: cout << "\nINGRESE UNA OPCION VALIDA...\n"; break;
        }

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        system("cls");

    } while (opcion != 4);

    return 0;
}
