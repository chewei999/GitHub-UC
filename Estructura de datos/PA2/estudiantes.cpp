/********************************************************
 *  Docente		: Ing. EDSON RAUL LAZO ALVAREZ			*
 *  Alumno		: JOSE ALONSO CHOQUEHUAITA MACHACA		*
 * 	Asignatura	: Estructura de Datos					*
 ********************************************************/


#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct estudiante {				// Definimos la estructura 'profesor' con 3 miembros
  char	nombre[25];				// Miembro de tipo char para el nombre
  int	dni;					// Miembro de tipo int para el dni
  int	semestres;				// Miembro de tipo int para el numero de semestres cursados
  float	promedio;				// Miembro de tipo float para el promedio
};

int		cantEst;					// Para guardar la cantidad de estudiantes ingresados por el usuario

// Variables de control
bool	cantEstValida = false;							// Para evaluar la validez de la cantidad de estudiantes ingresados
bool	dniValido, semestresValidos, promValido;		// Para evaluar la validez del dni, semestres y promedio de estudiantes ingresados

/** Prototipos de funciones/procesos usados **/
void clearInputShowErrorMessage(string errorMessage);	//Proceso

int main() {
	// Variables para procesamiento de datos
	float	edadPromedio = 0;															// Para calcular el promedio de las edades de todos los profesores
	int		edadMinima = 999;															// Para calcular la edad del profesor(a) mas joven (inicializamos en un valor muy alto para las comparaciones)
	char	nombreProfJoven[25];														// Nombre del profesor mas joven
	int		edadMaxima = -1;															// Para calcular la edad del profesor(a) de más edad  (inicializamos en un valor muy bajo para las comparaciones)
	char	nombreProfMayor[25];														// Nombre del profesor de mas edad
	int		cantProfesorasMayorProm = 0;												// Cantidad de profesoras mujeres con edad mayor al promedio
	int		cantProfesoresMenorProm = 0;												// Cantidad de profesores hombres con edad menor al promedio

	/** Solicitud al usuario de la cantidad de estudiantes **/
	do {
		system("cls");	// Limpiamos la pantalla en pro de la UX
		cout << "Indique cantidad de estudiantes a ingresar: ";							// Mostramos el mensaje de peticion al usuario
		cin >> cantEst;																	// Guardamos el dato ingresado por el usuario
		if (cin.good() and cantEst > 0) {												// Si todo va bien en la entrada de datos y el dato es mayor a 0
			cantEstValida = true;														// El booleano cantEstValida es verdadero, indicando que la entrada es valida y que se continue con la ejecucion del programa
		} else {																		// SINO
			clearInputShowErrorMessage("Error...La cantidad debe ser mayor a cero.");	// Si hay algun error, limpiamos el buffer de entrada y mostramos el respectivo mensaje al usuario
		}
	} while (!cantEstValida);															// Si la entrada no es valida, continuamos pidiendo la cantidad de profesores
	/** Solicitud al usuario de la cantidad de estudiantes **/


	estudiante *salon = new estudiante[cantEst];										// Declaramos el vector de punteros de tipo 'estudiante' de longitud definida por el usuario

	///*************** INGRESO DE DATOS ***************///
		/** Recorremos el arreglo para solicitar los datos al usuario **/
		cin.get();													// cin.get para evitar que se trunque el primer caracter del nombre
		for(int i=0; i<cantEst; i++) {

			//** Nombre del estudiante **//
			system("cls");											// Limpiamos la pantalla para mejor visualizacion
			cout << "[" << i+1 << "] " << "Nombre de docente: ";	// Mostramos el mensaje al usuario indicando que ingrese el nombre del docente
			if(i>0) cin.get();										// cin.get para evitar que se trunque el primer caracter del nombre
			cin.getline(salon[i].nombre,25);						// Guardamos el valor ingresado en la posicion correspondiente del vector,
																	// y asignamos al miembro correspondiente de la estructura
			//** Nombre del estudiante **//

			//** DNI del estudiante **//
			dniValido = false;																					// En cada lectura inicializamos la validez del Sexo en FALSO
			do {
				system("cls");																					// Limpiamos la pantalla para mejor visualizacion
				cout << "[" << i+1 << "] Ingrese el DNI de " << salon[i].nombre << ": ";						// Mostramos el mensaje al usuario pidiendo el DNI del estudiante
				cin >> salon[i].dni;																			// Guardamos el valor ingresado en la posicion correspondiente del vector,
																												// y asignamos al miembro correspondiente de la estructura
				if( cin.good() and salon[i].dni >= 11111111 and salon[i].dni <=99999999 ) {						// Si todo va bien en la entrada de datos y el dato es un DNI valido (de 8 digitos)
					dniValido = true;																			// El booleano dniValido es verdadero, indicando que la entrada es valida y que se continue con la ejecucion del programa
				} else {																						// SINO
					clearInputShowErrorMessage("Error...El DNI ingresado no es correcto, vuelva a intentar.");	// Si hay algun error, limpiamos el buffer de entrada y mostramos el respectivo mensaje al usuario
				}
			} while(!dniValido);																				// Si la entrada no es valida, continuamos pidiendo el DNI del estudiante
			//** DNI del estudiante **//

			//** Edad del profesor(a) **//
			semestresValidos = false;																					// En cada lectura inicializamos la validez de la edad en FALSO
			do {
				system("cls");																					// Limpiamos la pantalla para mejor visualizacion
				cout << "[" << i+1 << "] Ingrese la edad de " << salon[i].nombre << ": ";				// Mostramos el mensaje al usuario pidiendo la edad del docente
				cin >> salon[i].edad;																	// Guardamos el valor ingresado en la posicion correspondiente del vector,
																												// y asignamos al miembro correspondiente de la estructura
				//Si todo va bien en la entrada de datos y el dato es un entero mayor o igual a 18 (Ponemos la restriccion que para ser docente, la persona debe ser mayor de edad)
				if( cin.good() and salon[i].edad >= 18 ) {
					semestresValidos = true;																			// El booleano edadValida es verdadero, indicando que la entrada es valida y que se continue con la ejecucion del programa
				} else {																						// SINO
					clearInputShowErrorMessage("Error...El docente debe ser mayor de edad."); 					// Si hay algun error, limpiamos el buffer de entrada y mostramos el respectivo mensaje al usuario
				}
			} while(!semestresValidos);																				// Si la entrada no es valida, continuamos pidiendo la cantidad de profesores
			//** Edad del profesor(a) **//

		}
		/** Recorremos el arreglo para solicitar los datos al usuario **/
	///*************** INGRESO DE DATOS ***************///



	///*************** PROCESAMIENTO DE DATOS ***************///
		/** Calculo del promedio de edades **/
		for(int i=0; i<cantEst; i++) {																				// Recorremos el arreglo
			edadPromedio += salon[i].edad;																	// para obtener la suma de todas las edades
		}
		edadPromedio /= cantEst;																					// Dividimos la suma de todas las edades entre la cantidad de profesores
		/** Calculo del promedio de edades **/

		/** Calculo de profesor mas joven **/
		for(int i=0; i<cantEst; i++) {																				// Recorremos el arreglo
			if(salon[i].edad < edadMinima) {																// Si la edad del docente es menor a la edad minmima (valor inicial es 999)
				edadMinima = salon[i].edad;																	// ahora la edad minima es la edad del docente
				memcpy(nombreProfJoven, salon[i].nombre, sizeof(nombreProfJoven));							// Y tambien guardamos el nombre del docente con la funcion memcpy copiamos el arreglo de chars, 
																													// que es el nombre, ya que no se puede hacer una asignacion directa con el operador "="
			}
		}
		/** Calculo de profesor mas joven **/

		/** Calculo de profesor de mas edad **/
		for(int i=0; i<cantEst; i++) {																				// Recorremos el arreglo
			if(salon[i].edad > edadMaxima) {																// Si la edad del docente es mayor a la edad maxima (valor inicial es -1)
				edadMaxima = salon[i].edad;																	// ahora la edad maxima es la edad del docente
				memcpy(nombreProfMayor, salon[i].nombre, sizeof(nombreProfMayor));							// Y tambien guardamos el nombre del docente con la funcion memcpy copiamos el arreglo de chars, 
																													// que es el nombre, ya que no se puede hacer una asignacion directa con el operador "="
			}
		}
		/** Calculo de profesor de mas edad **/

		/** Calculo de profesoras mujeres con edad mayor al promedio **/
		for(int i=0; i<cantEst; i++) {																						// Recorremos el arreglo
			if( (salon[i].sexo == 'f' or salon[i].sexo == 'F') and salon[i].edad > edadPromedio) {	// Si es profesora mujer y con edad mayor al promedio
				cantProfesorasMayorProm++;																					// Incrementamos el contador correspondiente
			}
		}
		/** Calculo de profesoras mujeres con edad mayor al promedio **/

		/** Calculo de profesores hombres con edad menor al promedio **/
		for(int i=0; i<cantEst; i++) {																						// Recorremos el arreglo
			if( (salon[i].sexo == 'm' or salon[i].sexo == 'M') and salon[i].edad < edadPromedio) {	// Si es profesor hombre y con edad menor al promedio
				cantProfesoresMenorProm++;																					// Incrementamos el contador correspondiente
			}
		}
		/** Calculo de profesoras mujeres con edad mayor al promedio **/
	///*************** PROCESAMIENTO DE DATOS ***************///



	///*************** VISUALIZACION DE DATOS ***************///
		system("cls");													// Limpiamos la pantalla previo a mostrar los resultados
		
		for(int i=0;i<80;i++) cout<<"=";								// Mostramos
		cout << "\n\t\t\t\tDATOS INGRESADOS\n";							// un encabezado
		for(int i=0;i<80;i++) cout<<"=";								// para la seccion de datos
		cout <<"\nN - NOMBRE - SEXO - EDAD\n";							// ingresados

		/** Datos Ingresados **/
		for(int i=0; i<cantEst; i++) {																				// Recorremos el arreglo
			cout << i+1 << " - " << salon[i].nombre << " - ";												// Para cada elemento del arreglo mostramos cada uno de los miembros de la estructura
			(salon[i].sexo=='f' or salon[i].sexo=='F')? cout << "Femenino" : cout<<"Masculino";		// para el sexo, mostramos la palabra completo dependiendo del caracter almacenado
			cout << " - " << salon[i].edad << "\n";
		}
		for(int i=0;i<80;i++) cout<<"=";
		/** Datos Ingresados **/

		/** Resultados **/
		cout << "\n\n\n";
		for(int i=0;i<80;i++) cout<<"=";																				// Mostramos							
		cout << "\n\t\t\t\tRESULTADOS\n";																				// un encabezado
		for(int i=0;i<80;i++) cout<<"=";																				// para la seccion de resultados
		cout << "\na) Edad Promedio del grupo de profesores:\t\t\t" << edadPromedio;									// Mostramos la edad promedio de todos los profesores
		cout << "\nb) El profesor mas joven del grupo es:\t\t\t\t"<< nombreProfJoven;									// Mostramos el nombre del profesor mas joven
		cout << "\nc) El profesor de mas edad del grupo es:\t\t\t"<< nombreProfMayor;									// Mostramos el nombre del profesor de mas edad
		cout << "\nd) El numero de profesoras con edad mayor al promedio es:\t"<< cantProfesorasMayorProm;				// Mostramos la cantidad de profesoras con edad mayor al promedio
		cout << "\ne) El numero de profesores con edad menor al promedio es:\t"<< cantProfesoresMenorProm << endl;		// Mostramos la cantidad de profesores con edad menor al promedio
		for(int i=0;i<80;i++) cout<<"=";
		/** Resultados **/
	///*************** VISUALIZACION DE DATOS ***************///
					
	delete [] salon;																							// Liberamos es espacio de memoria que habiamos reservado inicialmente
	return 0;
}

//** Definicion de funciones/procesos usados **//

void clearInputShowErrorMessage(string errorMessage) {			// Proceso para limpiar el buffer de entrada y mostrar mensaje de error al usuario
	cin.clear();												// Reiniciamos el buffer de entrada a estado BUENO
	cin.ignore(numeric_limits<streamsize>::max(),'\n');			// Vaciamos el buffer de entrada
	cout << errorMessage << "\n\n";								// Mostramos un mensaje indicando el error al usuario
	system("pause");											// Pausa para que el usuario visualice el mensaje de error
}