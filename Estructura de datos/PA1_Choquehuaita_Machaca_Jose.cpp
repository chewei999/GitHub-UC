#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

  /***************************/
 /** Constants declaration **/
/***************************/
// Messages for user
string initMsg = "Ingrese un numero entero entre 1 y 20: ";
string initError = "ERROR...El numero debe ser entero y entre 0 y 20, vuelva a intentar.\n\n";

// Variables declaration
float results[4];       // Array to store results
int num;                // Number entered by user
bool endInput = false;  // Boolean to validate data input

// Functions definitions
int power(int num) {
    return num*num;
}

int units(int num) {

    if (num%2 == 0) {
        return abs(20 - num);
    }
    else {
        return abs(10 - num);
    }
}

int sum(int num) {
    int acum = 0;
    for (int i=1 ; i<=num; i++) {
        acum +=i;
    }
    return acum;
}

double average(double num) {
    return (power(num) + units(num) + sum(num))/3.0;
}

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

    results[0] = power(num);
    results[1] = units(num);
    results[2] = sum(num);
    results[3] = average(num);

    //TODO:validate 2 decimal places for average function

    for(const int &n : results) {
        cout << setprecision(3) << n << '\n';
    }

    system("pause");
    return 0;
}