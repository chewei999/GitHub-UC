#include <iostream>

using namespace std;

  /***************************/
 /** Constants declaration **/
/***************************/
// Messages for user
string initMsg = "Ingrese un numero entero entre 1 y 20: ";
string initError = "ERROR...El numero debe ser entero y entre 0 y 20, vuelva a intentar.\n\n";

// Declaracion de variables
float results[4];       // Vector para almacenar resultados
int num;                // Numero que ingresa usuario
bool endInput = false;  // Booleano para validar entrada de datos



int main() {

    while(!endInput) { 
        system("cls");
        cout << initMsg;
        while(!(cin >> num) or cin.get() != '\n') {
            cin.clear();
            cin.ignore(256, '\n');
            cout <<initError;
            system("pause");
            system("cls");
            cout << initMsg;
        }
        if (num >= 0 and num <= 20) {
            endInput = true;
        }
        else {
            cout <<initError;
            system("pause");
        }
    }

    cout << num << '\n';

    //TODO:add functiuons


    system("pause");
    return 0;
}