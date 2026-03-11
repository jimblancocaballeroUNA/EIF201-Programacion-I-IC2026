#include "paquetes.h"
#include <iostream>

double* crearRegistro(int& cantidad)
{
	double* Paquetes = new double[cantidad];
	return Paquetes;
}

void ingresarPesos(double* pesos, int cantidad)
{
	for (int i = 0; i < cantidad; i++) {
		std::cout << "Ingrese el peso del paquete " << i + 1 << ": ";
		std::cin >> pesos[i];
	}

}
double calcularPesoTotal(double* pesos, int cantidad)
{
	double total = 0.0;
	for (int i = 0; i < cantidad; i++) {
		total = pesos[i] + total;
	}

	return total;
}


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

const double* buscarMasPesado(const double* pesos, int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > pesos[i + 1]) { 
			return &pesos[i];
		}
	}
}