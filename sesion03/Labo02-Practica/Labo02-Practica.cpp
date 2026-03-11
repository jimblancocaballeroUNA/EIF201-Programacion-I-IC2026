#include <iostream>
#include "paquetes.h"
int main()
{

	int cantidad = 0;
	double pesos = 0;
	double limitePeso = 0;
	double* pesoPaquetes = nullptr;

	while (cantidad <= 0) {
		std::cout << "Ingrese la cantidad de paquetes: ";
		std::cin >> cantidad;
	}
	pesoPaquetes = crearRegistro(cantidad);

	ingresarPesos(pesoPaquetes, cantidad);
	
	std::cout << "Ingrese un limite de peso: ";
	std::cin >> limitePeso;

	std::cout<<contarSobreLimite(pesoPaquetes, cantidad, limitePeso)<<std::endl;

	std::cout<<*buscarMasPesado(pesoPaquetes, cantidad);

	delete[] pesoPaquetes;

	pesoPaquetes = nullptr;

}
	
