/********************************************************
 *  Docente		: Ing. EDSON RAUL LAZO ALVAREZ			*
 *  Alumno		: JOSE ALONSO CHOQUEHUAITA MACHACA		*
 * 	Asignatura	: Estructura de Datos					*
 ********************************************************/


#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct estudiante {				// Definimos la estructura 'estudiante' con 4 miembros para almacenar los datos de todos los estudiantes
  char	nombre[50];				// Miembro de tipo char para el nombre
  int	dni;					// Miembro de tipo int para el dni
  int	semestres;				// Miembro de tipo int para el numero de semestres cursados
  float	promedio;				// Miembro de tipo float para el promedio
};

struct estudiante2 {			// Definimos la estructura 'estudiante2' con 2 miembros para almacenar los datos solo de nombre y dni de algunos estudiantes 
  char	nombre[50];				// Miembro de tipo char para el nombre
  int	dni;					// Miembro de tipo int para el dni
};

int		cantEst;				// Para guardar la cantidad de estudiantes ingresados por el usuario

// Variables de control
bool	cantEstValida = false;							// Para evaluar la validez de la cantidad de estudiantes ingresados
bool	dniValido, semestresValidos, promValido;		// Para evaluar la validez del dni, semestres y promedio de estudiantes ingresados

/** Prototipos de funciones/procesos usados **/
void clearInputShowErrorMessage(string errorMessage);	//Proceso

int main() {
	// Variables para procesamiento de datos
	int		mejorProm = -1;																	// Para obtener los datos del estudiante con mejor promedio  (inicializamos en un valor muy bajo para las comparaciones)
	int		cantEstAprobados = 0;															// Para contabilizar la cantidad de estudiantes con promedio mayor o igual a 10.5
	int		cantEstMenosMediaCarrera = 0;													// Para contabilizar la cantidad de estudiantes que hayan cursado menos de 5 semestres
	char	estMejorPromNombre[50];															// El nombre del estudiante que tiene mejor promedio
	int		estMejorPromDNI;																// El DNI del estudiante que tiene mejor promedio
	int 	pos;																			// Variable para recorrer los vectores con data de estudiantes aprobados y con menos de 5 semestres cursados

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
			cout << "[" << i+1 << "] " << "Nombre de estudiante: ";	// Mostramos el mensaje al usuario indicando que ingrese el nombre del docente
			if(i>0) cin.get();										// cin.get para evitar que se trunque el primer caracter del nombre
			cin.getline(salon[i].nombre, 50);						// Guardamos el valor ingresado en la posicion correspondiente del vector,
																	// y asignamos al miembro correspondiente de la estructura
			//** Nombre del estudiante **//

			//** DNI del estudiante **//
			dniValido = false;																					// En cada lectura inicializamos la validez del DNI en FALSO
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

			//** Semestres cursados **//
			semestresValidos = false;																					// En cada lectura inicializamos la validez de la cantidad de semestres en FALSO
			do {
				system("cls");																							// Limpiamos la pantalla para mejor visualizacion
				cout << "[" << i+1 << "] Ingrese la cantidad de semetres cursados por " << salon[i].nombre << ": ";		// Mostramos el mensaje al usuario pidiendo la cantidad de semestres cursados por el estudiante
				cin >> salon[i].semestres;																				// Guardamos el valor ingresado en la posicion correspondiente del vector,
																														// y asignamos al miembro correspondiente de la estructura
				//Si todo va bien en la entrada de datos y el dato es un entero entre 1 y 10 (El estudiante no podria haber cursado 10 o mas semestres, en tal caso debería de haber aprobado todas las asignaturas)
				if( cin.good() and salon[i].semestres > 0 and salon[i].semestres < 10 ) {
					semestresValidos = true;																			// El booleano semestresValidos es verdadero, indicando que la entrada es valida y que se continue con la ejecucion del programa
				} else {																								// SINO
					clearInputShowErrorMessage("Error...La cantidad de semestres debe estar entre 1 y 9."); 			// Si hay algun error, limpiamos el buffer de entrada y mostramos el respectivo mensaje al usuario
				}
			} while(!semestresValidos);																					// Si la entrada no es valida, continuamos pidiendo la cantidad de semestres
			//** Semestres cursados **//

			//** Promedio del estudiante **//
			promValido = false;																							// En cada lectura inicializamos la validez del promedio en FALSO
			do {
				system("cls");																							// Limpiamos la pantalla para mejor visualizacion
				cout << "[" << i+1 << "] Ingrese el promedio para " << salon[i].nombre << ": ";							// Mostramos el mensaje al usuario pidiendo el promedio del estudiante
				cin >> salon[i].promedio;																				// Guardamos el valor ingresado en la posicion correspondiente del vector,
																														// y asignamos al miembro correspondiente de la estructura
				//Si todo va bien en la entrada de datos y el dato es un entero entre 0 y 20 (promedio en base bigesimal)
				if( cin.good() and salon[i].promedio >= 0 and salon[i].promedio <= 20 ) {
					promValido = true;																					// El booleano semestresValidos es verdadero, indicando que la entrada es valida y que se continue con la ejecucion del programa
				} else {																								// SINO
					clearInputShowErrorMessage("Error...El promedio debe estar entre 0 y 20."); 						// Si hay algun error, limpiamos el buffer de entrada y mostramos el respectivo mensaje al usuario
				}
			} while(!promValido);																						// Si la entrada no es valida, continuamos pidiendo el promedio del estudiante
			//** Promedio del estudiante **//
		}
		/** Recorremos el arreglo para solicitar los datos al usuario **/
	///*************** INGRESO DE DATOS ***************///



	///*************** PROCESAMIENTO DE DATOS ***************///
		/** Calculo de estudiante con mejor promedio **/
		for(int i=0; i<cantEst; i++) {																		// Recorremos el arreglo
			if(salon[i].promedio > mejorProm) {																// Si el promedio del estudiante es mayor al mejor promedio (valor inicial es -1)
				mejorProm = salon[i].promedio;																// ahora el mejor promedio es el promedio del estudiante
				memcpy(estMejorPromNombre, salon[i].nombre, sizeof(estMejorPromNombre));					// Y tambien guardamos el nombre del estudiante con la funcion memcpy copiamos el arreglo de chars, 
																											// que es el nombre, ya que no se puede hacer una asignacion directa con el operador "="
				estMejorPromDNI = salon[i].dni;																// Tambien guardamos el DNI del estudiante 																											
			}
		}
		/** Calculo de estudiante con mejor promedio **/

		/** Calculo de estudiantes con promedio mayores o iguales a 10.5 **/
		// Primero debemos saber la cantidad de estudiantes que cumplen esta condicion:
		for(int i=0; i<cantEst; i++) {																		// Recorremos el arreglo
			if(salon[i].promedio >= 10.5) {																	// Si el promedio del estudiante es mayor o igual a 10.5
				cantEstAprobados++;																			// Incrementamos el contador correspondiente
			}
		}

		// Declaramos un vector de punteros de tipo 'estudiante2' de longitud definida por la cantidad de estudiantes con promedio mayor o igual a 10.5, calculada anteriormente
		estudiante2 *estAprobados = new estudiante2[cantEstAprobados];

		pos = 0;																							// Inicializamos pos en 0, para recorrer el vector que almacena los datos de estudiantes aprobados
		for(int i=0; i<cantEst; i++) {																		// Recorremos el arreglo
			if(salon[i].promedio >= 10.5) {																	// Si el promedio del estudiante es mayor o igual a 10.5
				memcpy(estAprobados[pos].nombre, salon[i].nombre, sizeof(estAprobados[pos].nombre));		// Copiamos el nombre del estudiante al arreglo correspondiente y al miembro correspondiente de la estructura
				estAprobados[pos].dni = salon[i].dni;														// Copiamos el DNI del estudiante al arreglo correspondiente y al miembro correspondiente de la estructura
				pos++;																						// Incrementamos pos, para seguir almacenando datos en la siguiente posicion
			}
		}
		/** Calculo de estudiantes con promedio mayores o iguales a 10.5 **/

		/** Calculo de estudiantes con menos de 5 semstres cursados **/
		// Primero debemos saber la cantidad de estudiantes que cumplen esta condicion:
		for(int i=0; i<cantEst; i++) {																		// Recorremos el arreglo
			if(salon[i].semestres < 5) {																	// Si la cantidad de semestres cursados es menor a 5
				cantEstMenosMediaCarrera++;																	// Incrementamos el contador correspondiente
			}
		}

		// Declaramos un vector de punteros de tipo 'estudiante2' de longitud definida por la cantidad de estudiantes con menos de 5 semstres cursados, calculada anteriormente
		estudiante2 *estMenosMediaCarrera = new estudiante2[cantEstMenosMediaCarrera];

		pos = 0;																											// Inicializamos pos en 0, para recorrer el vector que almacena los datos de estudiantes con menos de 5 semstres cursados
		for(int i=0; i<cantEst; i++) {																							// Recorremos el arreglo
			if(salon[i].semestres < 5) {																					// Si la cantidad de semestres cursados es menor a 5
				memcpy(estMenosMediaCarrera[pos].nombre, salon[i].nombre, sizeof(estMenosMediaCarrera[pos].nombre));		// Copiamos el nombre del estudiante al arreglo correspondiente y al miembro correspondiente de la estructura
				estMenosMediaCarrera[pos].dni = salon[i].dni;																// Copiamos el DNI del estudiante al arreglo correspondiente y al miembro correspondiente de la estructura
				pos++;																										// Incrementamos pos, para seguir almacenando datos en la siguiente posicion
			}
		}
		/** Calculo de estudiantes con menos de 5 semstres cursados **/
	///*************** PROCESAMIENTO DE DATOS ***************///



	///*************** VISUALIZACION DE DATOS ***************///
		system("cls");													// Limpiamos la pantalla previo a mostrar los resultados
		
		for(int i=0;i<80;i++) cout<<"=";								// Mostramos
		cout << "\n\t\t\t\tDATOS INGRESADOS\n";							// un encabezado
		for(int i=0;i<80;i++) cout<<"=";								// para la seccion de datos
		cout <<"\nN - NOMBRE - DNI - SEMESTRES - PROMEDIO\n";			// ingresados

		/** Datos Ingresados **/
		for(int i=0; i<cantEst; i++) {									// Recorremos el arreglo
			cout << i+1 << " - " << salon[i].nombre << " - ";			// Mostramos el nombre
			cout << salon[i].dni << " - ";								// Mostramos el DNI
			cout << salon[i].semestres << " - ";						// Mostramos los semestres
			cout << salon[i].promedio << "\n";							// Mostramos el promedio
		}
		for(int i=0;i<80;i++) cout<<"=";
		/** Datos Ingresados **/

		/** Resultados **/
		cout << "\n\n\n";
		for(int i=0;i<80;i++) cout<<"=";																				// Mostramos							
		cout << "\n\t\t\t\tRESULTADOS\n";																				// un encabezado
		for(int i=0;i<80;i++) cout<<"=";																				// para la seccion de resultados
		cout << "\na) nombre y DNI del estudiante que tiene mejor promedio:\t\t\t" << estMejorPromNombre << " - " << estMejorPromDNI;			// Mostramos el nombre y DNI de los estudiantes con mejor promedio
		cout << "\nb) Listado de nombre y DNI de estudiantes con promedios mayores o iguales a 10.5\n";											// Mostramos el listado de nombre y DNI de estudiantes con promedios mayores o iguales a 10.5
		for (int i = 0; i < cantEstAprobados; i++) {																							// Recorremos el arreglo que almacena la data de estudiantes aprobados
			cout << estAprobados[i].nombre << " - " << estAprobados[i].dni << "\n";																// Mostramos el miembro correspondiente de la estructura
		}
		
		cout << "\nc) Listado de nombre y DNI de estudiantes que han cursado menos de 5 semestres hasta el momento:\n";							// Mostramos el nombre y DNI de los estudiantes con menos de 5 semestres cursados
		for (int i = 0; i < cantEstMenosMediaCarrera; i++) {																					// Recorremos el arreglo que almacena la data de estudiantes con menos de 5 semestres cursados
			cout << estMenosMediaCarrera[i].nombre << " - " << estMenosMediaCarrera[i].dni << "\n";												// Mostramos el miembro correspondiente de la estructura
		}
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