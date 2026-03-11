#include "paquetes.h"
#include <iostream>


//Esta funcion crea el puntero a base de la cantidad de paquetes que indique al usuario
double* crearRegistro(int& cantidad)
{
	double* Paquetes = new double[cantidad];
	return Paquetes;
}
//Esta funcion se encarga de pedir al usuario el peso de cada paquete y guardarlo en el arreglo creado anteriormente
void ingresarPesos(double* pesos, int cantidad)
{
	for (int i = 0; i < cantidad; i++) {
		std::cout << "Ingrese el peso del paquete " << i + 1 << ": ";
		std::cin >> pesos[i];
	}

}
//Esta funcion se encarga de sumar el peso de cada paquete para obtener el peso total
double calcularPesoTotal(double* pesos, int cantidad)
{
	double total = 0.0;
	for (int i = 0; i < cantidad; i++) {
		total = pesos[i] + total;
	}

	return total;
}

//Esta funcion se encarga de contar cuantos paquetes superan el limite de peso establecido por el usuario
int contarSobreLimite(const double* pesos, int cantidad, double limite)
{
	int contador = 0;
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > limite) {
			contador++;
		}
	}

	return contador;
}
//Esta funcion se encarga de buscar el paquete mas pesado y devolver su peso
const double* buscarMasPesado(const double* pesos, int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > pesos[i + 1]) { 
			return &pesos[i];
		}
	}
}