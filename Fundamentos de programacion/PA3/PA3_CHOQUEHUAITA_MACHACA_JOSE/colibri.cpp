#include <iostream>
#include <iomanip>
#include <algorithm>
#include "ValidarDatos.h"

using namespace std;

/***** Variables Globales *****/
bool    validOption, validGender, validBooksNumber, endProgram; // variables de validacion y fin de programa
char    gender;                                                 // variable que almacena el genero
string  bookType;                                               // string que guarda el tipo de libro elegido
int     opt;                                                    // opcion elegida en el menu 
int     price, cant;                                            // precio y cantidad de libros
int     rawPrice;                                               // precio bruto
float   dsctAmmount, netPrice;                                  // descuento aplicado, precio neto
float   dsct;                                                   // % de descuento

/** Variables para reporte **/
/* Contadores */
int     quanticFisicsSales = 0;     // cantidad de ventas de libros de Fisica Cuantica
int     fictionBooksSales = 0;      // Cantidad de ventas de libros de Ficcion con descuento de 6%
int     salesToMen = 0;             // Cantidad de ventas a clientes varones con descuento entre 200 y 2500
int     menBuyCuentos = 0;          // Cantidad de clientes varones que compraron libros de Cuentos.

/* Acumuladores */
float   totalNetPrice = 0;          // Monto total de Importe Neto
float   totalNetPriceWomen = 0;     // Monto total de Importe Neto de los clientes mujeres que compraron libros de Novelas
float   totalNetPriceMen = 0;       // Monto total de Importe Neto de clientes varones que compraron libros de Cuentos.

float   avgNetPriceMen = 0;         // Monto total de Importe Neto de clientes varones que compraron libros de Cuentos.

// Declaracion de metodos
void ShowMenu();
void ShowBooksMenu();
void RegisterNewSale();
void ProcessSale();
void SalesReport();

int main() {
    endProgram = false;
    do {
        do
        {
            ShowMenu();

            /* Pasamos los parametros "opt" y "validOption" por referencia para
            saber la opcion elegida y si es valida,
            y usar estas variables para evaluar la continuacion del codigo */
            ValidateMenuOption(3, opt, validOption);
        } while (!validOption);

        // Evaluamos la opcion elegida en el menu principal
        switch (opt) {
            case 1:
                RegisterNewSale();
                ProcessSale();
                break;
            case 2:
                SalesReport();
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
void ShowMenu() {
    system("cls");
    cout<<"************* LIBRERIA COLIBRI DORADO *************\n"
        "       ========= MENU PRINCIPAL =========\n\n"
        "1. Registrar venta.\n"
        "2. Reportar venta.\n"
        "3. Salir.\n\n"
        "Ingrese opcion (1-3): ";
}

// Menu de Libros
void ShowBooksMenu() {
    system("cls");
    cout<<"   Tipo de Libros\tPrecio (S/.)\n"
          "1. Ficcion\t\t90\n"
          "2. Novelas\t\t100\n"
          "3. Cuentos\t\t80\n"
          "4. Fisica Cuantica\t150\n\n"
          "Ingrese opcion (1-4): ";
}

// Registrar nueva venta
void RegisterNewSale() {

    // Ingreso de Genero
    do {
        system("cls");
        cout << "Ingrese genero de la persona (M/F): ";

        /* Pasamos los parametros "gender" y "validGender" por referencia para
            saber la opcion elegida y si es valida,
            y usar estas variables para evaluar la continuacion del codigo */
        ValidateGender(gender, validGender);
    } while (!validGender);

    // Ingreso de tipo de libro
    do {
        ShowBooksMenu();
        
        /* Pasamos los parametros "opt" y "validOption" por referencia para
            saber la opcion elegida y si es valida,
            y usar estas variables para evaluar la continuacion del codigo */
        ValidateMenuOption(4, opt, validOption);
    } while (!validOption);

    //Ingreso de cantidad de libros
    do {
        system("cls");
        cout << "Ingrese la cantidad de libros deseados: ";

        /* Pasamos los parametros "cant" y "validBooksNumber" por referencia para
            saber la opcion elegida y si es valida,
            y usar estas variables para evaluar la continuacion del codigo */
        ValidateBooksNumber(cant, validBooksNumber);
    } while (!validBooksNumber);
}

//Procesar Venta
void ProcessSale() {
    
    //Evaluamos el tipo de libro ingresado por el usuario
    switch (opt) {
        case 1:
            bookType = "Ficcion";
            price = 90;
            //Condicionales para asignar el descuento a aplicar, segun la cantidad de libros
            if (cant <= 2) {dsct = 0.05;}
            else if (cant <= 6) {dsct = 0.06;}
            else {dsct = 0.08;}
            break;
        case 2:
            bookType = "Novelas";
            price = 100;
            //Condicionales para asignar el descuento a aplicar, segun la cantidad de libros
            if (cant <= 2) {dsct = 0.08;}
            else if (cant >= 3 and cant <= 6) {dsct = 0.16;}
            else {dsct = 0.32;}
            break;
        case 3:
            bookType = "Cuentos";
            price = 80;
            //Condicionales para asignar el descuento a aplicar, segun la cantidad de libros
            if (cant <= 2) {dsct = 0.09;}
            else if (cant >= 3 and cant <= 6) {dsct = 0.18;}
            else {dsct = 0.36;}
            break;
        case 4:
            bookType = "Fisica Cuantica";
            price = 150;
            //Condicionales para asignar el descuento a aplicar, segun la cantidad de libros
            if (cant <= 2) {dsct = 0.02;}
            else if (cant >= 3 and cant <= 6) {dsct = 0.02;}
            else {dsct = 0.04;}
            break;
    }

    //Calculo de montos a pagar
    rawPrice = cant * price;
    dsctAmmount = rawPrice * dsct;
    netPrice = rawPrice - dsctAmmount;

    /****** Calculos de valores para reporte ******/
    if(bookType == "Fisica Cuantica") { quanticFisicsSales++; }             // Cantidad de venta registradas de  libros de Física Cuántica 
    if(bookType == "Ficcion" and cant >= 3 and cant <= 6) { fictionBooksSales++; }     // Cantidad de ventas registradas de libros de Ficción que tengan un descuento de 6%.
    
    //Cantidad de ventas registradas de clientes varones cuyo Descuento Neto sea >=200 y <=2500
    if(toupper(gender) == 'M' and dsctAmmount >= 200 and dsctAmmount <= 2500) { salesToMen++; }

    totalNetPrice += netPrice;                                              // Monto total de Importe Neto

    // Monto total de Importe Neto de los clientes mujeres que compraron libros de Novelas
    if(toupper(gender) == 'F' and bookType == "Novelas") { totalNetPriceWomen += netPrice; }

    //Promedio de Importe Neto de clientes varones que compraron libros de Cuentos.
    if (toupper(gender) == 'M' and bookType == "Cuentos") {
        totalNetPriceMen += netPrice;
        menBuyCuentos++;
    }
    /****** Calculos de valores para reporte ******/       

    //Mostramos los datos calculados para la venta actual
    //system("cls");
    cout << "Montos a pagar por " + to_string(cant) + " libros de tipo: " + bookType + ":\n\n";
    cout << "Importe Bruto: S/." + to_string(rawPrice) + "\n";
    cout << fixed << setprecision(2);   //para poder mostrar los float con dos decimales
    cout << "Monto de Descuento: S/." + to_string(dsctAmmount) + "\n";
    cout << "Importe Neto: S/." + to_string(netPrice) + "\n\n";
    system("pause");
}

void SalesReport() {
    system("cls");

    // Calculamos el promedio de Importe Neto de clientes varones que compraron libros de Cuentos, solo si la cantidad de
    // clientes varones que compraron libros de Cuentos es mayor a cero,
    // sino el promedioa mostrar será cero
    if(menBuyCuentos > 0) { avgNetPriceMen = totalNetPriceMen / menBuyCuentos; }
    
    cout << fixed << setprecision(2); //para poder mostrar los float con dos decimales
    cout<<"************* LIBRERIA COLIBRI DORADO *************\n"
    "    ============ REPORTE DE VENTAS ============\n\n"
    "Cantidad de venta registradas de  libros de Fisica Cuantica:\t\t\t\t\t" + to_string(quanticFisicsSales) + "\n"
    "Cantidad de ventas registradas de libros de Ficcion que tengan un descuento de 6%:\t\t" + to_string(fictionBooksSales) + "\n"
    "Cantidad de ventas registradas de clientes varones cuyo Descuento Neto sea >=200 y <=2500:\t" + to_string(salesToMen) + "\n"
    "Monto total de Importe Neto:\t\t\t\t\t\t\t\t\t" + to_string(totalNetPrice) + "\n"
    "Monto total de Importe Neto de los clientes mujeres que compraron libros de Novelas:\t\t" + to_string(totalNetPriceWomen) + "\n"
    "Promedio de Importe Neto de clientes varones que compraron libros de Cuentos:\t\t\t" + to_string(avgNetPriceMen) + "\n\n";

    system("pause");
}