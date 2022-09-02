#include <iostream>

using namespace std;

int main() {
      /**************************************/
     /****** Declaracion de variables ******/
    /**************************************/
    // Variables de control
    bool    end = false, endSale = false, effectiveSale = true;
    bool    continueSale = false, validSale = false, validAmmount = false, partialSale = false, validNewStock = false;
    char    optContinue, optPartialSale;
    int     opt, ammount, newStock;
    float   rawPrice, dsctPrice, paidPrice;
    string  partialSaleTV, ammountTV, newStockTV, partialSaleCel, ammountCel, newStockCel, partialSaleEq, ammountEq, newStockEq, productsMenu;

    // Contadores
    int     countOrderTV = 0, countClient = 0, countCelDsct = 0;

    // Acumuladores
    int     totalUnitTV = 0, totalUnitCel = 0, totalUnitEq = 0;
    float   totalSoldTV = 0, totalSoldCel = 0, totalSoldEq = 0;

    // Constantes
    float   tvPrice   = 3500, tvDsct    = 0.10, tvStock     = 200;
    float   celPrice  = 2500, celDsct   = 0.20, celStock    = 1500;
    float   eqPrice   = 1600, eqDsct    = 0.15, eqStock     = 150;

    string  mainMenu =
        "************* SSONNY - SEDE CUSCO *************\n"
        "       ========= MENU PRINCIPAL =========      \n"
        "1. Registrar venta.\n"
        "2. Generar reporte.\n"
        "3. Salir.\n\n"
        "Ingrese opcion (1-3): ";
    string  mainMenuError = "ERROR...Opcion debe ser un numero entero entre 1 y 3. ";
    string  productsMenuError = "ERROR...Opcion debe ser un numero entero entre 1 y 4. ";
    string  numberProductsError = "ERROR...La cantidad de productos debe ser un numero entero positivo. ";
    string  noStock = "No se cuenta con el stock suficiente, Continuar con venta? (S/N): ";
    string  optionError = "ERROR...Opcion incorrecta, vuelva a intentar. ";
    string  newStockError = "ERROR...Nuevo stock debe ser un numero entero positivo. ";

    do {
        system("cls");
        cout << mainMenu;

        while (!(cin >> opt) or cin.get() != '\n') {    // Mientras la opcion no sea un numero entero...
            cin.clear();                                // Borramos el stream,
            cin.ignore(256, '\n');                      // descartamos la entrada previa,
            cout << mainMenuError;                      // explicamos el error,
            system("pause");
            system("cls");
            cout << mainMenu;                           // y volvemos a mostrar el menu.
        }
        
        switch (opt) {
            case 1:
                do {
                    productsMenu =
                        "************* SSONNY - SEDE CUSCO *************\n"
                        "     ========= MENU DE PRODUCTOS =========     \n"
                        "   PRODUCTO\tPRECIO\t\t\tSTOCK\n"
                        "   ---------------------------\n"
                        "1. TV\t\tS/. 3500.00\t\t" + to_string((int)tvStock) + "\n"
                        "2. CELULAR\tS/. 2500.00\t\t" + to_string((int)celStock) + "\n"
                        "3. EQUIPO\tS/. 1600.00\t\t" + to_string((int)eqStock) + "\n"
                        "4. Regresar al Menu Principal\n\n"
                        "Ingrese el producto a adquirir (1-3) o 4 para regresar al Menu Principal: ";
                    system("cls");
                    cout << productsMenu;
                    while (!(cin >> opt) or cin.get() != '\n') {    // Mientras la opcion no sea un numero entero...
                        cin.clear();                                // Borramos el stream,
                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                        cout << productsMenuError;                  // explicamos el error,
                        system("pause");
                        system("cls");
                        cout << productsMenu;                       // y volvemos a mostrar el menu de productos.
                    }
                    switch (opt) {
                    case 1: //Venta de TV
                        endSale = false;
                        ammountTV = "Ingrese la cantidad de TV, stock actual es de " + to_string((int)tvStock) + " unidades: ";
                        do {
                            system("cls");
                            cout<<ammountTV;
                            while (!(cin >> ammount) or cin.get() != '\n') {   // Mientras la cantidad no sea un numero entero...
                                cin.clear();                                // Borramos el stream,
                                cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                cout << numberProductsError;                  // explicamos el error.
                                system("pause");
                                system("cls");
                                cout << ammountTV;
                            }
                            if (ammount >= 0) {
                                do {
                                    partialSaleTV =  "Stock disponible: " + to_string((int)tvStock) + ", pedido: " + to_string((int)ammount) + ". Desea vender una parte? (S/N): "; 
                                    if (ammount > tvStock) {
                                        partialSale = false;
                                        continueSale = false;
                                        validSale = false;
                                        validAmmount = false;
                                        validNewStock = false;
                                        do {
                                            system("cls");
                                            cout << noStock;
                                            while (!(cin >> optContinue) or cin.get() != '\n') {   // Mientras la no sea un caracter...
                                                cin.clear();                                // Borramos el stream,
                                                cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                cout << optionError;                  // explicamos el error.
                                                system("pause");
                                                system("cls");
                                                cout << noStock;
                                            }
                                            switch (toupper(optContinue)) {
                                                case 'S':
                                                    do {
                                                        system("cls"); 
                                                        cout << partialSaleTV;
                                                        while (!(cin >> optPartialSale) or cin.get() != '\n') {   // Mientras la no sea un caracter...
                                                            cin.clear();                                // Borramos el stream,
                                                            cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                            cout << optionError;                  // explicamos el error.
                                                            system("pause");
                                                            system("cls");
                                                            cout << partialSaleTV;
                                                        }
                                                        switch (toupper(optPartialSale)) {
                                                            case 'S':
                                                                ammount = tvStock;
                                                                partialSale = true;
                                                                continueSale = true;
                                                                validSale = true;
                                                                validAmmount = true;
                                                                break;
                                                            case 'N':
                                                                newStockTV = "Stock disponible: " + to_string((int)tvStock) + ", pedido: " + to_string((int)ammount) + "\nIngrese nuevo stock: ";
                                                                do {
                                                                    system("cls");
                                                                    cout << newStockTV;
                                                                    while (!(cin >> newStock) or cin.get() != '\n') {   // Mientras la no sea un entero...
                                                                        cin.clear();                                // Borramos el stream,
                                                                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                                        cout << optionError;                  // explicamos el error.
                                                                        system("pause");
                                                                        system("cls");
                                                                        cout << newStockTV;
                                                                    }
                                                                    if (newStock > 0) {
                                                                        tvStock = newStock;
                                                                        validNewStock = true;
                                                                        partialSale = true;
                                                                        continueSale = true;
                                                                    }
                                                                } while (!validNewStock);
                                                                break;
                                                            default:
                                                                cout << optionError;                  // explicamos el error.
                                                                system("pause");
                                                                system("cls");
                                                                break;
                                                        }
                                                    } while (!partialSale);
                                                    break;
                                                case 'N':
                                                    cout << "Se cancela la venta.\n";
                                                    system("pause");
                                                    continueSale = true;
                                                    validSale = true;
                                                    break;
                                                default:
                                                    cout << optionError;                  // explicamos el error.
                                                    system("pause");
                                                    system("cls");
                                                    break;
                                            }
                                        } while (!continueSale);
                                    }
                                    else {
                                        validAmmount = true;
                                        validSale = true;
                                    }
                                } while (!validSale);
                                if (validAmmount) {
                                    countOrderTV ++;
                                    countClient ++;
                                    totalUnitTV += ammount;

                                    //Calculos
                                    rawPrice = ammount * tvPrice;
                                    dsctPrice = rawPrice * tvDsct;
                                    paidPrice = rawPrice - dsctPrice;
                                    totalSoldTV += paidPrice;

                                    tvStock -= ammount; //Actualizamos el stock

                                    cout << fixed;
                                    cout.precision(2);
                                    cout << "\nMonto total a pagar por " << ammount << " unidades de TV: S/. " << paidPrice << "\n";
                                    system("pause");
                                }
                                endSale = true;
                            }
                            else {
                                cout << numberProductsError;
                                system("pause");
                            }                
                        } while (!endSale);
                        break;
                    case 2:     //Venta de celulares
                        endSale = false;
                        ammountCel = "Ingrese la cantidad de Celulares, stock actual es de " + to_string((int)celStock) + " unidades: ";
                        do {
                            system("cls");
                            cout<<ammountCel;
                            while (!(cin >> ammount) or cin.get() != '\n') {   // Mientras la cantidad no sea un numero entero...
                                cin.clear();                                // Borramos el stream,
                                cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                cout << numberProductsError;                  // explicamos el error.
                                system("pause");
                                system("cls");
                                cout << ammountCel;
                            }
                            if (ammount >= 0) {
                                do {
                                    partialSaleCel =  "Stock disponible: " + to_string((int)celStock) + ", pedido: " + to_string((int)ammount) + ". Desea vender una parte? (S/N): "; 
                                    if (ammount > celStock) {
                                        partialSale = false;
                                        continueSale = false;
                                        validSale = false;
                                        validAmmount = false;
                                        validNewStock = false;
                                        do {
                                            system("cls");
                                            cout << noStock;
                                            while (!(cin >> optContinue) or cin.get() != '\n') {   // Mientras la no sea un caracter...
                                                cin.clear();                                // Borramos el stream,
                                                cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                cout << optionError;                  // explicamos el error.
                                                system("pause");
                                                system("cls");
                                                cout << noStock;
                                            }
                                            switch (toupper(optContinue)) {
                                                case 'S':
                                                    do {
                                                        system("cls"); 
                                                        cout << partialSaleCel;
                                                        while (!(cin >> optPartialSale) or cin.get() != '\n') {   // Mientras la no sea un caracter...
                                                            cin.clear();                                // Borramos el stream,
                                                            cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                            cout << optionError;                  // explicamos el error.
                                                            system("pause");
                                                            system("cls");
                                                            cout << partialSaleCel;
                                                        }
                                                        switch (toupper(optPartialSale)) {
                                                            case 'S':
                                                                ammount = celStock;
                                                                partialSale = true;
                                                                continueSale = true;
                                                                validSale = true;
                                                                validAmmount = true;
                                                                break;
                                                            case 'N':
                                                                newStockCel = "Stock disponible: " + to_string((int)celStock) + ", pedido: " + to_string((int)ammount) + "\nIngrese nuevo stock: ";
                                                                do {
                                                                    system("cls");
                                                                    cout << newStockCel;
                                                                    while (!(cin >> newStock) or cin.get() != '\n') {   // Mientras la no sea un entero...
                                                                        cin.clear();                                // Borramos el stream,
                                                                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                                        cout << optionError;                  // explicamos el error.
                                                                        system("pause");
                                                                        system("cls");
                                                                        cout << newStockCel;
                                                                    }
                                                                    if (newStock > 0) {
                                                                        celStock = newStock;
                                                                        validNewStock = true;
                                                                        partialSale = true;
                                                                        continueSale = true;
                                                                    }
                                                                } while (!validNewStock);
                                                                break;
                                                            default:
                                                                cout << optionError;                  // explicamos el error.
                                                                system("pause");
                                                                system("cls");
                                                                break;
                                                        }
                                                    } while (!partialSale);
                                                    break;
                                                case 'N':
                                                    cout << "Se cancela la venta.\n";
                                                    system("pause");
                                                    continueSale = true;
                                                    validSale = true;
                                                    break;
                                                default:
                                                    cout << optionError;                  // explicamos el error.
                                                    system("pause");
                                                    system("cls");
                                                    break;
                                            }
                                        } while (!continueSale);
                                    }
                                    else {
                                        validAmmount = true;
                                        validSale = true;
                                    }
                                } while (!validSale);
                                if (validAmmount) {
                                    countCelDsct ++;
                                    countClient ++;
                                    totalUnitCel += ammount;

                                    //Calculos
                                    rawPrice = ammount * celPrice;
                                    dsctPrice = rawPrice * celDsct;
                                    paidPrice = rawPrice - dsctPrice;
                                    totalSoldCel += paidPrice;

                                    celStock -= ammount; //Actualizamos el stock

                                    cout << fixed;
                                    cout.precision(2);
                                    cout << "\nMonto total a pagar por " << ammount << " unidades de Celulares: S/. " << paidPrice << "\n";
                                    system("pause");
                                }
                                endSale = true;
                            }
                            else {
                                cout << numberProductsError;
                                system("pause");
                            }                
                        } while (!endSale);
                        break;
                    case 3:     //Venta de equipos
                        endSale = false;
                        ammountEq = "Ingrese la cantidad de Equipos, stock actual es de " + to_string((int)eqStock) + " unidades: ";
                        do {
                            system("cls");
                            cout<<ammountEq;
                            while (!(cin >> ammount) or cin.get() != '\n') {   // Mientras la cantidad no sea un numero entero...
                                cin.clear();                                // Borramos el stream,
                                cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                cout << numberProductsError;                  // explicamos el error.
                                system("pause");
                                system("cls");
                                cout << ammountEq;
                            }
                             if (ammount >= 0) {
                                do {
                                    partialSaleEq =  "Stock disponible: " + to_string((int)eqStock) + ", pedido: " + to_string((int)ammount) + ". Desea vender una parte? (S/N): "; 
                                    if (ammount > eqStock) {
                                        partialSale = false;
                                        continueSale = false;
                                        validSale = false;
                                        validAmmount = false;
                                        validNewStock = false;
                                        do {
                                            system("cls");
                                            cout << noStock;
                                            while (!(cin >> optContinue) or cin.get() != '\n') {   // Mientras la no sea un caracter...
                                                cin.clear();                                // Borramos el stream,
                                                cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                cout << optionError;                  // explicamos el error.
                                                system("pause");
                                                system("cls");
                                                cout << noStock;
                                            }
                                            switch (toupper(optContinue)) {
                                                case 'S':
                                                    do {
                                                        system("cls"); 
                                                        cout << partialSaleEq;
                                                        while (!(cin >> optPartialSale) or cin.get() != '\n') {   // Mientras la no sea un caracter...
                                                            cin.clear();                                // Borramos el stream,
                                                            cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                            cout << optionError;                  // explicamos el error.
                                                            system("pause");
                                                            system("cls");
                                                            cout << partialSaleEq;
                                                        }
                                                        switch (toupper(optPartialSale)) {
                                                            case 'S':
                                                                ammount = eqStock;
                                                                partialSale = true;
                                                                continueSale = true;
                                                                validSale = true;
                                                                validAmmount = true;
                                                                break;
                                                            case 'N':
                                                                newStockEq = "Stock disponible: " + to_string((int)eqStock) + ", pedido: " + to_string((int)ammount) + "\nIngrese nuevo stock: ";
                                                                do {
                                                                    system("cls");
                                                                    cout << newStockEq;
                                                                    while (!(cin >> newStock) or cin.get() != '\n') {   // Mientras la no sea un entero...
                                                                        cin.clear();                                // Borramos el stream,
                                                                        cin.ignore(256, '\n');                      // descartamos la entrada previa,
                                                                        cout << newStockError;                  // explicamos el error.
                                                                        system("pause");
                                                                        system("cls");
                                                                        cout << newStockEq;
                                                                    }
                                                                    if (newStock > 0) {
                                                                        eqStock = newStock;
                                                                        validNewStock = true;
                                                                        partialSale = true;
                                                                        continueSale = true;
                                                                    }
                                                                    else {
                                                                        cout << newStockError;                  // explicamos el error.
                                                                        system("pause");
                                                                    }
                                                                } while (!validNewStock);
                                                                break;
                                                            default:
                                                                cout << optionError;                  // explicamos el error.
                                                                system("pause");
                                                                system("cls");
                                                                break;
                                                        }
                                                    } while (!partialSale);
                                                    break;
                                                case 'N':
                                                    cout << "Se cancela la venta.\n";
                                                    system("pause");
                                                    continueSale = true;
                                                    validSale = true;
                                                    break;
                                                default:
                                                    cout << optionError;                  // explicamos el error.
                                                    system("pause");
                                                    system("cls");
                                                    break;
                                            }
                                        } while (!continueSale);
                                    }
                                    else {
                                        validAmmount = true;
                                        validSale = true;
                                    }
                                } while (!validSale);
                                if (validAmmount) {
                                    countClient ++;
                                    totalUnitEq += ammount;

                                    //Calculos
                                    rawPrice = ammount * eqPrice;
                                    dsctPrice = rawPrice * eqDsct;
                                    paidPrice = rawPrice - dsctPrice;
                                    totalSoldEq += paidPrice;

                                    eqStock -= ammount; //Actualizamos el stock

                                    cout << fixed;
                                    cout.precision(2);
                                    cout << "\nMonto total a pagar por " << ammount << " unidades de Equipos: S/. " << paidPrice << "\n";
                                    system("pause");
                                }
                                endSale = true;
                            }
                            else {
                                cout << numberProductsError;
                                system("pause");
                            }                
                        } while (!endSale);
                        break;
                    case 4:
                        end = true;                 // Salimos del menu de productos
                        system("cls");
                        break;                    
                    default:                        // Si la opcion no estÃ¡ entre 1 y 4 ...
                        cout << productsMenuError;  // explicamos el error.
                        system("pause");
                        system("cls");
                        break;
                    }

                } while (!end);
                
                end = false;                        // end = false nuevamente porque no deseamos salir del menu principal
                break;
            case 2: //Reporte de Ventas
                system("cls");
                cout <<
                "************* SSONNY - SEDE CUSCO *************\n"
                "      ======== REPORTE DE VENTAS ========      \n"
                "a. Cantidad de pedidos del producto TV: " + to_string(int(countOrderTV)) + "\n"
                "b. Cantidad de clientes atendidos     : " + to_string(int(countClient)) + "\n"
                "c. Cantidad de descuentos a Celulares : " + to_string(int(countCelDsct)) + "\n"
                "d. Total de unidades vendidas por producto:\n"
                "\tTV       : " + to_string(int(totalUnitTV)) + "\n"
                "\tCelulares: " + to_string(int(totalUnitCel)) + "\n"
                "\tEquipos  : " + to_string(int(totalUnitEq)) + "\n"
                "e. Stock remanente por producto:\n"
                "\tTV       : " + to_string(int(tvStock)) + "\n"
                "\tCelulares: " + to_string(int(celStock)) + "\n"
                "\tEquipos  : " + to_string(int(eqStock)) + "\n"
                "f. Monto total vendido por producto:\n"
                "\tTV       : " + to_string(int(totalSoldTV)) + "\n"
                "\tCelulares: " + to_string(int(totalSoldCel)) + "\n"
                "\tEquipos  : " + to_string(int(totalSoldEq)) + "\n\n";

                system("pause");
                break;

            case 3:
                end = true;
                cout << "\nGracias, vuelva pronto...\n\n";
                system("pause");
                break;
            
            default:                        // Si la opcion no estÃ¡ entre 1 y 3 ...
                cout << mainMenuError;      // explicamos el error,
                system("pause");
                system("cls");
                break;
        }
        
    } while (!end);
    return 0;
}