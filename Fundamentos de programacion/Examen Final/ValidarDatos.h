#include <iostream>

using namespace std;

/*** PROCEDIMIENTO PARA MOSTRAR ERROR DE ENTRADA ***/
void ShowErrorInput() {
    string  optionError = "ERROR...Opcion incorrecta, vuelva a intentar. ";
    cout << optionError;
    system("pause");
}

/*** FUNCION PARA VALIDAR OPCION VALIDA DE MENU ***/
bool ValidateMenuOption(int maxOpt, int &chosenOption) {
    if (!(cin >> chosenOption) or cin.get() != '\n') {      // Si la opcion no es un numero entero...
        cin.clear();                                        // Borramos el stream,
        cin.ignore(256, '\n');                              // descartamos la entrada previa,
        ShowErrorInput();
        return false;
    }
    else {
        if (chosenOption >= 1 and chosenOption <= maxOpt) {
            return true;
        }
        else {
            ShowErrorInput();                               // Si la opcion no es menor que el max nro de 
            return false;                                  // opciones, mostramos el mensaje de error
        }
    }
}

/*** FUNCION PARA VALIDAR GENERO ***/
bool ValidateGender(char &chosenGender) {

    if (!(cin >> chosenGender) or cin.get() != '\n') {      // Si el genero no es tipo char
        cin.clear();                                        // Borramos el stream,
        cin.ignore(256, '\n');                              // descartamos la entrada previa,
        ShowErrorInput();
        return false;
    }
    else {
        if (toupper(chosenGender) == 'M' or toupper(chosenGender) == 'F') {
            chosenGender = toupper(chosenGender);            // convertinos a mayusculas la variable pasada por referencia para que el codigo principal sea mas limpio
            return true;
        }
        else {
            ShowErrorInput();                               // Si el genero no es 'M' o 'F', mostramos
            return false;                                  // mensaje de error
        }
    }
}

/*** FUNCION PARA VALIDAR RESPUESTAS TIPO SI/NO ***/
bool ValidateYesNoAns(char &ans) {

    if (!(cin >> ans) or cin.get() != '\n') {      // Si la rpta no es tipo char
        cin.clear();                               // Borramos el stream,
        cin.ignore(256, '\n');                     // descartamos la entrada previa,
        ShowErrorInput();
        //valid = false;
        return false;
    }
    else {
        if (toupper(ans) == 'S' or toupper(ans) == 'N') {
            //valid = true;
            ans = toupper(ans);
            return true;
        }
        else {
            ShowErrorInput();                               // Si la rpta no es 'S' o 'N', mostramos
            //valid = false;
            return false;                                  // mensaje de error
        }
    }
}

/*** FUNCION PARA VALIDAR CANTIDAD DE PERSONAS ***/
bool ValidatePeopleNumber(int &chosenPeopleNumber) {

    if (!(cin >> chosenPeopleNumber) or cin.get() != '\n') { // Si el genero no es tipo int
        cin.clear();                                        // Borramos el stream,
        cin.ignore(256, '\n');                              // descartamos la entrada previa,
        ShowErrorInput();
        return false;
    }
    else {
        if (chosenPeopleNumber > 0) {
            return true;
        }
        else {
            ShowErrorInput();                               // Si el genero no es 'M' o 'F', mostramos
            return false;                                  // mensaje de error
        }
    }
}