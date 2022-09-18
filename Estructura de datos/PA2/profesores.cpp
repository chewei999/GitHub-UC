#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct profesor {				// Definimos la estructura 'profesor' con 3 miembros
  char	nombre[25];				// Miembro de tipo char para el nombre
  char	sexo;					// Miembro de tipo char para el sexo
  int	edad;					// Miembro de tipo int para la edad
};

int		cantProf;
bool	cantProfValida = false;
bool	sexoValido, edadValida;

/** Prototipos de funciones/procesos usados **/
void clearInputShowErrorMessage(string errorMessage);	//Proceso

int main() {
	/** Solicitud al usuario de la cantidad de profesores **/
	do {
		system("cls");	// Limpiamos la pantalla en pro de la UX
		cout << "Indique cantidad de docentes a ingresar: ";						// Mostramos el mensaje de peticion al usuario
		cin >> cantProf;															// Guardamos el dato ingresado por el usuario
		if (cin.good() and cantProf > 0) {											// Si todo va bien en la entrada de datos y el dato es mayor a 0
			cantProfValida = true;													// El booleano cantProfValida es verdadero, indicando que la entrada es valida y continuar con la ejecucion del programa
		} else { // SINO
			clearInputShowErrorMessage("Error...La cantidad debe ser mayor a cero."); 
		}
	} while (!cantProfValida); // Si la entrada no es valida, continuamos pidiendo la cantidad de profesores
	
	/** Solicitud al usuario de la cantidad de profesores **/
	profesor *plana_docente = new profesor[cantProf];		// Declaramos el vector de punteros de tipo 'profesor' de longitud definida por el usuario

	// Recorremos el arreglo para solicitar los datos al usuario
	cin.get();
	for(int i=0; i<cantProf; i++) {

		//** Nombre del profesor(a) **//
		cout << "[" << i << "] " << "Nombre de docente: ";		// Mostramos el mensaje al usuario indicando que ingrese el nombre del docente
		cin.getline(plana_docente[i].nombre,25);				// Guardamos el valor ingresado en la posicion correspondiente del vector,
																// y asignamos al miembro correspondiente de la estructura
		//** Nombre del profesor(a) **//

		//** Sexo del profesor(a) **//
		sexoValido = false;										// en cada lectura inicializamos la validez del Sexo en FALSO
		do {
			system("pause");									// Limpiamos la pantalla para mejor visualizacion
			cout << "[" << i << "] Ingrese el sexo de " << plana_docente[i].nombre << ": ";		// Mostramos el mensaje al usuario pidiendo el sexo del docente 
			cin >> plana_docente[i].sexo;
			if( cin.good() and (plana_docente[i].sexo == 'F' or plana_docente[i].sexo == 'f' or plana_docente[i].sexo == 'M' or plana_docente[i].sexo == 'm') ) {
				sexoValido = true;
			} else {
				clearInputShowErrorMessage("Error...El sexo ingresado no es correcto, vuelva a intentar.");
			}
		} while(!sexoValido);
		//** Sexo del profesor(a) **//

	}

	for(int i=0; i<cantProf; i++) {
		// ** Solicitud del nombre del profesor(a) **//
		cout << plana_docente[i].nombre << endl;		
		// ** Solicitud del nombre del profesor(a) **//
	}

	delete [] plana_docente;
	return 0;
}

//** Definicion de funciones/procesos usados **//

void clearInputShowErrorMessage(string errorMessage) {			// Proceso para limpiar el buffer de entrada y mostrar mensaje de error al usuario
	cin.clear();												// Reiniciamos el buffer de entrada a estado BUENO
	cin.ignore(numeric_limits<streamsize>::max(),'\n');			// Vaciamos el buffer de entrada
	cout << errorMessage << "\n\n";								// Mostramos un mensaje indicando el error al usuario
	system("pause");											// Pausa para que el usuario visualice el mensaje de error
}