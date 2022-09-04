#include <iostream>

using namespace std;

  /***************************/
 /** Constants declaration **/
/***************************/
// Messages for user
string initMsg = "Ingrese un numero entero entre 1 y 20: ";
string initError = "ERROR...El numero debe ser entero y entre 0 y 20, vuelva a intentar.\n\n";

// Variables declaration
float results[3];       // Array to store results
int num;                // Number entered by user
bool validInput;        // Boolean to validate data input

// Functions definitions

bool validateInput(int &num) {
    if(!(cin >> num) or cin.get() != '\n') {    // If input is not a integer
        cin.clear();                            // we clear the stream
        cin.ignore(256, '\n');                  // discard previous input
        cout << initError;                      // show error message to user
        system("pause");                        // pause to user be able to see the message
        return false;                           // return FALSE because of the wrong input
    }
    else {                                      // If input is a integer
        if (num >= 0 and num <= 20) {           // we evaluate if input is bewteen 0 and 20
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

    if (num%2 == 0) {
        return abs(20 - num);
    }
    else {
        return abs(10 - num);
    }
}

int f3_sum(int num) {
    int acum = 0;
    for (int i=1 ; i<=num; i++) {
        acum +=i;
    }
    return acum;
}

float f4_average(float num) {
    return (f1_power(num) + f2_units(num) + f3_sum(num))/3.0;
}

int main() {

    do { 
        system("cls");
        cout << initMsg;
        validInput = validateInput(num);
    } while(!validInput);

    results[0] = f1_power(num);
    results[1] = f2_units(num);
    results[2] = f3_sum(num);
    results[3] = f4_average(num);

    //TODO:validate 2 decimal places for f4_average function

/*
    for(const int &n : results) {
        printf("%.2f\n", n);
        //cout<<n<<'\n';
    }
*/

    for(int i=0; i<=3;i++) {
        printf("%.2f\n", results[i]);
    }

    system("pause");
    return 0;
}