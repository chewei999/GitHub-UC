#include <iostream>

using namespace std;

/*** PROCEDIMIENTO PARA MOSTRAR ERROR DE ENTRADA ***/
void ShowErrorInput() {
    string  optionError = "ERROR...Opcion incorrecta, vuelva a intentar. ";
    cout << optionError;
    system("pause");
}

/*** PROCEDIMIENTO PARA VALIDAR OPCION VALIDA DE MENU ***/
void ValidateMenuOption(int maxOpt, int &chosenOption, bool &valid) {
    if (!(cin >> chosenOption) or cin.get() != '\n') {      // Si la opcion no es un numero entero...
        cin.clear();                                        // Borramos el stream,
        cin.ignore(256, '\n');                              // descartamos la entrada previa,
        ShowErrorInput();
        valid = false;
    }
    else {
        if (chosenOption >= 1 and chosenOption <= maxOpt) {
            valid = true;
        }
        else {
            ShowErrorInput();                               // Si la opcion no es menor que el max nro de 
            valid = false;                                  // opciones, mostramos el mensaje de error
        }
    }
}

/*** PROCEDIMIENTO PARA VALIDAR GENERO ***/
void ValidateGender(char &chosenGender, bool &valid) {

    if (!(cin >> chosenGender) or cin.get() != '\n') {      // Si el genero no es tipo char
        cin.clear();                                        // Borramos el stream,
        cin.ignore(256, '\n');                              // descartamos la entrada previa,
        ShowErrorInput();
        valid = false;
    }
    else {
        if (toupper(chosenGender) == 'M' or toupper(chosenGender) == 'F') {
            valid = true;
        }
        else {
            ShowErrorInput();                               // Si el genero no es 'M' o 'F', mostramos
            valid = false;                                  // mensaje de error
        }
    }
}

/*** PROCEDIMIENTO PARA VALIDAR CANTIDAD DE LIBROS ***/
void ValidateBooksNumber(int &chosenBooksNumber, bool &valid) {

    if (!(cin >> chosenBooksNumber) or cin.get() != '\n') {      // Si el genero no es tipo char
        cin.clear();                                        // Borramos el stream,
        cin.ignore(256, '\n');                              // descartamos la entrada previa,
        ShowErrorInput();
        valid = false;
    }
    else {
        if (chosenBooksNumber > 0) {
            valid = true;
        }
        else {
            ShowErrorInput();                               // Si el genero no es 'M' o 'F', mostramos
            valid = false;                                  // mensaje de error
        }
    }
}