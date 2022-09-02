#include <iostream>
#include <iomanip>
#include <algorithm>
#include "ValidarDatos.h"

using namespace std;

/***** Variables Globales *****/
bool    validOption, validGender, validPeopleNumber, endProgram;    // variables de validacion y fin de programa
bool    validateName, validAns;                                     // variables de validacion y fin de programa
char    gender;                                                     // variable que almacena el genero
char    ans;                                                        // variable que almacena la rpta de preguntas cuya rpta es S/N
string  raceTypeSTR;                                                // string que guarda el tipo de carrera elegida
string  carTypeSTR;                                                 // string que guarda el tipo de carro elegido
string  driverName;                                                 // string para el nombre del piloto
int     opt;                                                        // opcion elegida en los menu s
int     raceType;                                                   // tipo de carrera elegida
int     carType;                                                    // tipo de carro elegido
int     peopleNum;                                                  // cantidad de personas de apoyo
float   rawPrice;                                                   // precio bruto

float   dsctAmmount, netPrice;                                      // descuento aplicado, precio neto
float   dsct;                                                       // % de descuento

/** Variables para reporte **/
/* Contadores */
int     femaleDrivers = 0;          // Cantidad de pilotos de género femenino
int     supportPeople = 0;          // Cantidad de personas de apoyo entre 26 y 35
int     ferrariRaces = 0;           // Cantidad de carreras cuyo tipo de carro sea 1 - Ferrari
int     maleRaces = 0;              // Cantidad de carreras con pilotos de género masculino cuyo Importe Bruto sea >=800,000 y <=1´500,000
int     races2 = 0;                 // Cantidad de carreras de tipo 2.

/* Acumuladores */
float   totalNetPrice = 0;          // El acumulado del Importe Pago.
float   totalNetPriceRace3 = 0;     // El acumulado del Importe Pago, de carreras de tipo 3.
float   totalNetPriceRace2 = 0;     // El acumulado del Importe Pago, de carreras de tipo 2

float   avgNetPriceRace2 = 0;       // Monto total de Importe Neto de clientes varones que compraron libros de Cuentos.

// Declaracion de metodos
void ShowMainMenu();
void ShowRaceTypeMenu();
void RegisterNewInscription();
void ProcessInscription();
void RegistrationReport();

int main() {
    endProgram = false;
    do {
        do
        {
            ShowMainMenu();

            /* Pasamos los parametros "opt" y "validOption" por referencia para
            saber la opcion elegida y si es valida,
            y usar estas variables para evaluar la continuacion del codigo */
            validOption = ValidateMenuOption(3, opt);
        } while (!validOption);

        // Evaluamos la opcion elegida en el menu principal
        switch (opt) {
            case 1:
                RegisterNewInscription();
                ProcessInscription();
                break;
            case 2:
                RegistrationReport();
                break;
            case 3:
                endProgram = true;
                cout << "\nGracias, vuelva pronto...\n\n";
                system("pause");
                break;
        }
    } while(!endProgram);

    return 0;
}


/*** Definicion de Métodos ***/
// Menu Principal
void ShowMainMenu() {
    system("cls");
    cout<<"       ========= MENU DE OPCIONES =========\n\n"
        "1. Registrar.\n"
        "2. Reportar.\n"
        "3. Salir.\n\n"
        "Ingrese opcion (1-3): ";
}

// Menu de tipo de carrera
void ShowRaceTypeMenu() {
    system("cls");
    cout<<"   Tipo de Carrera\tPrecio (US$.)\n"
          "1. Formula 2\t\t1'500,000.00\n"
          "2. Karting\t\t   75,000.00\n"
          "3. Formula 3\t\t  800,000.00\n\n"
          "Ingrese opcion (1-3): ";
}

// Menu de tipo de carro
void ShowCarTypeMenu() {
    system("cls");
    cout<<"   Elija el tipo de Carro\n"
          "1. Ferrari.\n"
          "2. Audi.\n"
          "2. Porsche.\n"
          "4. MercedesBenz.\n\n"
          "Ingrese opcion (1-4): ";
}

// Registrar nuevo registro de carrera
void RegisterNewInscription() {

    // Ingreso de tipo de Carrera
    do {
        ShowRaceTypeMenu();
        
        /* Pasamos el parámetro "raceType" por referencia para
            saber la carrera elegida, y usar esta variables para
            calculos posteriores */
        validOption = ValidateMenuOption(3, raceType);
    } while (!validOption);

    //Ingreso de cantidad de personas de apoyo
    do {
        system("cls");
        cout << "Ingrese la cantidad de personas de apoyo: ";

        /* Pasamos el parametro "peopleNum" por referencia para
            saber la cantidad de personas de apoyo, y usar esta
            variable para calculos posteriores */
        validPeopleNumber = ValidatePeopleNumber(peopleNum);
    } while (!validPeopleNumber);
    
    //Ingreso de nombre de piloto
    do {
        system("cls");
        cout << "Ingrese el nombre del piloto: ";

        /* En el caso el nombre, podriamos validar que no contenga caracteres numéricos,
           pero supongamos que algun nombre si lo contenga, nuestro sistema estaría de cierto
           modo discriminando, por lo tanto, lo que hacemos es que el usuario valide el nombre
           una vez ingresado, y solo con su confirmacion continuamos con el programa */
        getline(cin, driverName);
        transform(driverName.begin(), driverName.end(), driverName.begin(), ::toupper);
        do {
            system("cls");
            cout << "El nombre del piloto se guardara en el sistema como: " << driverName << " esta de acuerdo? (S/N): ";
            validAns = ValidateYesNoAns(ans);
        } while (!validAns);
        
        if(ans == 'S') validateName = true; else validateName = false;
    } while (!validateName);

    // Ingreso de Genero
    do {
        system("cls");
        cout << "Ingrese genero del piloto (M/F): ";

        /* Pasamos el parametro "gender" por referencia para
            saber el genero ingresado, y usar esta variable
            para calculos posteriores.

            La funcion 'ValidateGender' convierte a mayuscula la
            variable 'gender', asi tenemos un código mas limpio
            al usar esta variable mas adelante*/
        validGender = ValidateGender(gender);
    } while (!validGender);

    // Ingreso de tipo de Carro
    do {
        ShowCarTypeMenu();
        
        /* Pasamos el parametro "carType"  por referencia para
            saber el tipo de carro elegido, y usar esta variable
            para calculos posteriores */
        validOption = ValidateMenuOption(4, carType);
    } while (!validOption);
}

//Procesar Venta
void ProcessInscription() {
    
    //Evaluamos el tipo de carrera ingresada por el usuario
    switch (raceType) {
        case 1:
            raceTypeSTR = "Formula 2";
            rawPrice = 1500000;
            break;
        case 2:
            raceTypeSTR = "Karting";
            rawPrice = 75000;
            break;
        case 3:
            raceTypeSTR = "Formula 3";
            rawPrice = 800000;
            break;
    }

    //Evaluamos el tipo de carro ingresado por el usuario
    switch (carType) {
        case 1:
            carTypeSTR = "Ferrari";
            break;
        case 2:
            carTypeSTR = "Audi";
            break;
        case 3:
            carTypeSTR = "Porsche";
            break;
        case 4:
            carTypeSTR = "MercedesBenz";
            break;
    }

    // Calculos dependiendo de la cantidad de personas de apoyo
    if (peopleNum < 26) {dsct = 0;}
    else if (peopleNum >= 26 and peopleNum < 36) {dsct = 0.05; supportPeople += peopleNum;}
    else if (peopleNum >= 36 and peopleNum < 45) {dsct = 0.1;}
    else {dsct = 0.14;}
    
    

    //Calculo de montos a pagar
    dsctAmmount = rawPrice * dsct;
    netPrice = rawPrice - dsctAmmount;

    /****** Calculos de valores para reporte ******/
    // Cantidad de pilotos de género femenino.
    if(gender == 'F') { femaleDrivers++; }

    // Cantidad de carreras cuyo tipo de carro sea 1 - Ferrari
    if(carTypeSTR == "Ferrari") { ferrariRaces++; }

    // Cantidad de carreras con pilotos de género masculino cuyo Importe Bruto sea >=800,000 y <=1´500,000
            /**** Aqui solo consideramos la primera condicion, ya que el precio bruto siempre estará entre 800,000 y 1´500,000
                  ya que es el rango total de precios para las carreras   ****/
    if(gender == 'M') { maleRaces++; }
    
    // El acumulado del Importe Pago
    totalNetPrice += netPrice;

    // El acumulado del Importe Pago, de carreras de tipo 3.
    if(raceType == 3) { totalNetPriceRace3 += netPrice; }

    // Promedio de Importe Pago, de carreras de tipo 2.
    if (raceType == 2) {
        totalNetPriceRace2 += netPrice;
        races2++;
    }
    /****** Calculos de valores para reporte ******/       

    //Mostramos los datos calculados para la venta actual
    system("cls");
    cout << "Montos a pagar por carrera tipo " + raceTypeSTR + " con carro: " + carTypeSTR + ":\n\n";
    cout << "Importe Bruto: US$." + to_string(rawPrice) + "\n";
    cout << fixed << setprecision(0) << "Monto de Descuento: US$." + to_string(dsctAmmount) + "\n";
    cout << "Importe Pago : US$." + to_string(netPrice) + "\n\n";
    system("pause");
}

void RegistrationReport() {
    system("cls");

    // Calculamos el promedio de Promedio de Importe Pago de carreras de tipo 2, solo si la cantidad de
    // carreras es mayor a cero, sino el promedio a mostrar será cero
    if(races2 > 0) { avgNetPriceRace2 = totalNetPriceRace2 / races2; }
    
    cout << fixed << setprecision(2); //para poder mostrar los float con dos decimales
    cout<<"    ============ REPORTE ============\n\n"
    "Cantidad de pilotos de genero femenino:\t\t\t\t\t\t\t\t\t" + to_string(femaleDrivers) + "\n"
    "Cantidad de personas de apoyo entre 26 y 35:\t\t\t\t\t\t\t\t" + to_string(supportPeople) + "\n"
    "Cantidad de carreras cuyo tipo de carro sea 1 - Ferrari:\t\t\t\t\t\t" + to_string(ferrariRaces) + "\n"
    "Cantidad de carreras con pilotos de genero masculino cuyo Importe Bruto sea >=800,000 y <=1 500,000:\t" + to_string(maleRaces) + "\n"
    "El acumulado del Importe Pago:\t\t\t\t\t\t\t\t\t\t" + to_string(totalNetPrice) + "\n"
    "El acumulado del Importe Pago, de carreras de tipo 3:\t\t\t\t\t\t\t" + to_string(totalNetPriceRace3) + "\n"
    "Promedio de Importe Pago, de carreras de tipo 2:\t\t\t\t\t\t\t" + to_string(avgNetPriceRace2) + "\n\n";

    system("pause");
}