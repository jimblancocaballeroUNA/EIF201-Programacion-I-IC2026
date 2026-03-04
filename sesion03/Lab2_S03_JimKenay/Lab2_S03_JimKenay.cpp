#include <iostream>
#include "Temperatura.h"

int main()
{
	int cantidadDias = 0;

	double* regitroTemp = crearRegistro(cantidadDias);

	ingresarTemperaturas(regitroTemp, cantidadDias);

	mostrarResultados(regitroTemp, cantidadDias);

	delete[] regitroTemp;
	regitroTemp = nullptr;
	
	return 0;


}

