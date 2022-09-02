#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
      /**************************************/
     /****** Declaracion de variables ******/
    /**************************************/
    // Variables de control
    int     opt;
    bool    validGender, validSize, validGlasses, validCel, validAge, end = false;
    char    glassesOpt, celOpt;
    
    //Variables de entrada
    int     age;
    char    gender;
    bool    glasses, cel;
    string  size;

    // Constantes
    string  mainMenu =
        "       ========= MENU PRINCIPAL =========      \n\n"
        "1. Registrar nuevos datos.\n"
        "2. Generar reporte de registros.\n"
        "3. Salir.\n\n"
        "Ingrese opcion (1-3): ";
    string  inputGender     = "Ingrese genero de la persona (M/F): ";
    string  inputSize       = "Ingrese talla de polo (S/M/L/XL): ";
    string  inputGlasses    = "La persona usa lentes? (S/N): ";
    string  inputCel        = "La persona usa celular(S/N): ";
    string  inputAge        = "Ingrese la edad de la persona: ";

    string  errorMainMenu   = "ERROR...Opcion debe ser un numero entero entre 1 y 3. ";
    string  errorInput      = "ERROR...Opcion incorrecta, vuelva a intentar. ";
    string  errorAge        = "ERROR...La edad debe ser un numero entero positivo. ";

    // Contadores
    int     womenM = 0, menXL = 0, womenNoCel = 0, totalCelGlasses = 0, womenGlasses = 0, menCel = 0;

    // Acumuladores
    int     womenGlassesAge = 0, menCelAge = 0, womenGlassesAvg = 0, menCelAvg = 0;

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
                validGender     = false;
                validGlasses    = false;
                validSize       = false;
                validCel        = false;
                validAge        = false;
                // Ingreso de Genero
                do {
                    system("cls");
                    cout << inputGender;
                    while (!(cin >> gender) or cin.get() != '\n') {    // Mientras la opcion no sea un numero entero...
                        cin.clear();                                // Borramos el stream,
                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                        cout << errorInput;                  // explicamos el error,
                        system("pause");
                        system("cls");
                        cout << inputGender;                     // y volvemos a mostrar la pregunta.
                    }
                    if (toupper(gender) == 'M' or toupper(gender) == 'F') {
                        validGender = true;
                    }
                    else {
                        cout << errorInput;
                        system("pause");
                    }
                } while (!validGender);
                
                //Ingreso de talla de polo
                do {
                    system("cls");
                    cout << inputSize;
                    while (!(cin >> size) or cin.get() != '\n') {    // Mientras la talla no sea texto...
                        cin.clear();                                // Borramos el stream,
                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                        cout << errorInput;                  // explicamos el error,
                        system("pause");
                        system("cls");
                        cout << inputSize;                  // y volvemos a mostrar la pregunta.
                    }
                    transform(size.begin(), size.end(), size.begin(), ::toupper);   // Convertimos el string a MAYUSCULAS para validar más rapido
                    if (size == "S" or size == "M" or size == "L" or size == "XL") {
                        validSize = true;
                    }
                    else {
                        cout << errorInput;
                        system("pause");
                    }
                } while (!validSize);
                
                // Ingreso de uso de lentes
                do {
                    system("cls");
                    cout << inputGlasses;
                    while (!(cin >> glassesOpt) or cin.get() != '\n') {    // Mientras la opcion no sea un numero entero...
                        cin.clear();                                // Borramos el stream,
                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                        cout << errorInput;                  // explicamos el error,
                        system("pause");
                        system("cls");
                        cout << inputGlasses;               // y volvemos a mostrar la pregunta.
                    }
                    if (toupper(glassesOpt) == 'S' or toupper(glassesOpt) == 'N') {
                        if (toupper(glassesOpt) == 'S') {
                            glasses = true;
                        }
                        else {
                            glasses = false;
                        }
                        validGlasses = true;
                    }
                    else {
                        cout << errorInput;
                        system("pause");
                    }
                } while (!validGlasses);

                // Ingreso de uso de celular
                do {
                    system("cls");
                    cout << inputCel;
                    while (!(cin >> celOpt) or cin.get() != '\n') {    // Mientras la opcion no sea un numero entero...
                        cin.clear();                                // Borramos el stream,
                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                        cout << errorInput;                  // explicamos el error,
                        system("pause");
                        system("cls");
                        cout << inputCel;                    // y volvemos a mostrar la pregunta.
                    }
                    if (toupper(celOpt) == 'S' or toupper(celOpt) == 'N') {
                        if (toupper(celOpt) == 'S') {
                            cel = true;
                        }
                        else {
                            cel = false;
                        }                        
                        validCel = true;
                    }
                    else {
                        cout << errorInput;
                        system("pause");
                    }
                } while (!validCel);

                // Ingreso de edad
                do {
                    system("cls");
                    cout << inputAge;
                    while (!(cin >> age) or cin.get() != '\n') {    // Mientras la opcion no sea un numero entero...
                        cin.clear();                                // Borramos el stream,
                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                        cout << errorAge;                  // explicamos el error,
                        system("pause");
                        system("cls");
                        cout << inputAge;                 // y volvemos a mostrar el mensaje para ingreso de edad.
                    }
                    if (age > 0) {
                        validAge = true;
                    }
                    else {
                        cout << errorAge;
                        system("pause");
                    }
                } while (!validAge);

                cout << "\n\nDatos registrados. ";

                //Calculo de contadores
                //a. El número de mujeres con talla M y hombres con talla XL
                if (toupper(gender) == 'F' and size == "M") {
                    womenM++;
                }
                if (toupper(gender) == 'M' and size == "XL") {
                    menXL++;
                }
                
                //b. El número de mujeres que si usan lentes 
                if (toupper(gender) == 'F' and glasses) {
                    womenGlasses++;
                    womenGlassesAge += age;
                }                

                //c. El número de hombres con celulares.
                if (toupper(gender) == 'M' and cel) {
                    menCel++;
                    menCelAge += age;
                }                

                //d. El número de mujeres sin celulares.
                if (toupper(gender) == 'F' and !cel) {
                    womenNoCel++;
                }                

                //e. El número total de personas que utilizan celulares y lentes.
                if (cel and glasses) {
                    totalCelGlasses++;
                }
                
                system("pause");
                break;
            case 2: //Reporte de datos
                if (womenGlasses > 0) {
                    womenGlassesAvg = womenGlassesAge/womenGlasses;
                }
                if (menCel > 0) {
                    menCelAvg = menCelAge/menCel;
                }
                
                system("cls");
                cout << fixed << setprecision(2) <<
                "       ========= REPORTE DE REGISTROS =========        \n\n"
                "Numero de mujeres con talla M: " + to_string(womenM) + " y hombres con talla XL: " + to_string(menXL) + "\n"
                "Numero de mujeres que si usan lentes: " + to_string(womenGlasses) + "\n"
                "Numero de hombres con celulares: " + to_string(menCel) + "\n"
                "Numero de mujeres sin celulares: " + to_string(womenNoCel) + "\n"
                "Numero total de personas que utilizan celulares y lentes: " + to_string(totalCelGlasses) + "\n"
                "Edad promedio de las mujeres que usan lentes: " + to_string(womenGlassesAvg) + "\n"                
                "Edad promedio de los hombres con celulares: " + to_string(menCelAvg) + "\n\n";
                system("pause");
                break;

            case 3:
                end = true;
                cout << "\nGracias, vuelva pronto...\n\n";
                system("pause");
                break;
            
            default:                        // Si la opcion no estÃ¡ entre 1 y 3 ...
                cout << errorMainMenu;      // explicamos el error,
                system("pause");
                system("cls");
                break;
        }
        
    } while (!end);
    return 0;
}