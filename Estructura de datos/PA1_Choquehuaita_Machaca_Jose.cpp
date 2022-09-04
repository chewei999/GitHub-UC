#include <iostream>

using namespace std;

/** CONSTATNS DECLARATION **/
// Messages for user
string initMsg = "Ingrese un numero entero entre 1 y 20: ";
string initError = "ERROR...El numero debe ser entero y entre 1 y 20, vuelva a intentar.\n\n";

/** FUNCTIONS DECLARATION **/
//Function to validate input is an integer between 0 and 20
bool askValidateInput(int *val);

//Function to return the input squared
int f1_power(int num);

//Function to return the number of units that input is from 20 or 10 depending on whether it is even or odd
int f2_units(int num);

//Function to return the sum of integers between 1 and the input
int f3_sum(int num);

//Funtion to return de average of previous 3 functions
float f4_average(int num);

/** MAIN FUNCTION **/
int main() {
    
    // Variables declaration
    float results[3];       // Array to store results
    int *num = new int;     // Number entered by user
    bool validInput;        // Boolean to validate data input
    bool even;              // Boolean if number is even

    do { 
        system("cls");
        cout << initMsg;
        validInput = askValidateInput(num);
    } while(!validInput);

    (*num%2 == 0)? even = true : even = false;
    results[0] = f1_power(*num);
    results[1] = f2_units(*num);
    results[2] = f3_sum(*num);
    results[3] = f4_average(*num);

    for(int i=0; i<=3; i++) {
        printf("%.2f\n", results[i]);
    }

    cout << "\nEl numero ingresado es: " << *num;
    cout << "\nEl numero ingresado al cuadrado: " << results[0];
    cout << "\nEl numero ingresado esta a " << results[1] << " unidades de ";
    even? cout << "20" : cout << "10";
    cout << "\nLa suma desde 1 hasta el numero ingresado es: " << results[2];
    printf("\nEl promedio de los 3 valores anteriores es: %.2f\n\n", results[3]);

    system("pause");

    delete num;
    return 0;
}


/** FUNCTIONS DEFINITION **/
bool askValidateInput(int *val) {

    if(!(cin >> *val) or cin.get() != '\n') {   // If input value is not the right type: Integer
        cin.clear();                            // we clear the stream
        cin.ignore(256, '\n');                  // discard previous input
        cout << initError;                      // show error message to user
        system("pause");                        // pause to user be able to see the message
        return false;                           // return FALSE because of the wrong input
    }
    else {                                      // If input is a integer
        if (*val >= 1 and *val <= 20) {         // we evaluate if input is bewteen 1 and 20
            return true;                        // return TRUE as the input is between correct range
        }
        else {                                  // If input is not between the correct range
            cout << initError;                  // show error message to user
            system("pause");                    // pause to user be able to see the message
            return false;                       // return FALSE as the input is not between correct range
        }
    }
}

int f1_power(int num) {
    return num*num;
}

int f2_units(int num) {
    int units;
    (num%2 == 0)? units = abs(20 - num) : units = abs(10 - num);
    return units;
}

int f3_sum(int num) {
    int acum = 0;
    for (int i=1 ; i<=num; i++) {
        acum +=i;
    }
    return acum;
}

float f4_average(int num) {
    return (f1_power(num) + f2_units(num) + f3_sum(num))/3.0;
}