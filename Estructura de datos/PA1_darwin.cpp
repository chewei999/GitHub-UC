#include<iostream>
//libreria para tildacion
#include<locale.h> 

 
using namespace std;

int *piNumero();
int *analiza1(int *numero);
int *analiza2(int *numero);
void analiza3(int *numero);
float *analiza4(int *numero);

int main(){
	// es usada para cambiar o preguntar la localidad actual total del programa
	setlocale(LC_CTYPE, "Spanish");
	
	int *numero;
    int *resultados[3];

//	int resp1, resp2, resp3;
	double *promedio= new double;
	
	    numero = piNumero();
		
		resultados[0] = analiza1(numero);
		resultados[1] = analiza2(numero);
		 //analiza2(numero);
		 //analiza3(numero);
	//	*promedio =(resp1 + resp2 + resp3)/3;
		cout<<"El promedio de los resultados anteriores (F1, F2 Y F3) : "<<*resultados[0]<<endl;
	  return 0;
}

int *piNumero(){
	
	int *numero = new int;
	do{
		cout<<"ingresar el numero (0-20): ";
		cin>>*numero;
		
		if(*numero<0 || *numero>20)
		cout<<"error..." <<endl;
		
	}while (*numero<0 || *numero>20);
	
	return numero;
	
	  }	
//
int *analiza1 (int *numero){	
    int *res1 = new int;	
    // ---------------------------- 1. F1
    *res1 = *numero * *numero;
    //cout<<"el numero al cuadrado es: "<<*res1<<endl;		
    return res1;
}

int *analiza2(int *numero){

    int *res2 = new int;
    // ---------------------------- 2. F2
    if(*numero % 2==0){
        *res2 = 20 - *numero;
        cout<<"es par a cuantas unidades de 20 se encuentra: "<<*res2<<endl;
    }else{
        *res2 = abs(10 - *numero);
        cout<<"es impar a cuantas unidades de 10 se encuentra: "<<*res2<<endl;
    }	
    return res2;
}

void analiza3(int *numero){

int *res3 = new int;
for(int i=1; i <= *numero; i++){
    *res3 +=i;
    
}
cout<<"La suma de los números desde 1 hasta el número ingresado: "<<*res3<<endl;	
return;
} 

float *analiza4(int *numero) {
    float *res4 = new float;

    *res4 = *analiza1(numero) + *analiza1(numero);

    return res4;
}