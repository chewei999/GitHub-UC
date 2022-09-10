#include <iostream>
#include <string.h>

using namespace std;

// Declare struct

struct profesor {
    char    nombre[40];
    char    sexo[1];
    int     edad;
};


int main () {
      /**************************************/
     /****** Declaracion de variables ******/
    /**************************************/
    // Variables de control
    int     opt;
    bool    endProgram = false;

    // Constantes
        string  mainMenu =
            "       ========= MENU PRINCIPAL =========      \n\n"
            "1. Registrar nuevos datos.\n"
            "2. Generar reporte de registros.\n"
            "3. Salir.\n\n"
            "Ingrese opcion (1-3): ";


        string  errorMainMenu   = "ERROR...Opcion debe ser un numero entero entre 1 y 3. ";


    do {
        system("cls");
        cout << mainMenu;

        while (!(cin >> opt) or cin.get() != '\n') {    // Mientras la opcion no sea un numero entero...
            cin.clear();                                // Borramos el stream,
            cin.ignore(256, '\n');                      // descartamos la entrada previa,
            cout << errorMainMenu;                      // explicamos el error,
            system("pause");
            system("cls");
            cout << mainMenu;                           // y volvemos a mostrar el menu.
        }
        switch (opt) {
            case 1:
                cout<<"Nuevo dato\n";
                system("pause");
                break;
            case 2:
                cout<<"Reporte\n";
                system("pause");
                break;
            case 3:
                endProgram = true;
                break;
            default:                        // Si la opcion no está entre 1 y 3 ...
                cout << errorMainMenu;      // explicamos el error,
                system("pause");
                break;
        }
    } while(!endProgram);

    return 0;
}