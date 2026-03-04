#include "Temperatura.h";
#include <iostream>
#include <iomanip>

double* crearRegistro(int& cantidadDias) {
	std::cout << "--------------------------------------------+" << std::endl;
	std::cout << "| Sistema de registro de temperaturas |" << std::endl;
	std::cout << "--------------------------------------------+" << std::endl;
	std::cout << "Ingrese la cantidad de dias a registrar: ";
	std::cin >> cantidadDias;
	while (cantidadDias <= 0) {
		std::cout << "La cantidad de dias debe ser un numero positivo. Intente nuevamente: ";
		std::cin >> cantidadDias;
	}
	double* registro = new double[cantidadDias];
	return registro;
}

void ingresarTemperaturas(double* registro, int cantidad) {
	for (int i = 0; i < cantidad; ++i) {
		std::cout << "Ingrese la temperatura del dia " << (i + 1) << ": ";
		std::cin >> registro[i];
	}
}

double calcularPromedio(const double* registro, int cantidad) {
	double suma = 0.0;
	for (int i = 0; i < cantidad; ++i) {
		suma += registro[i];
	}
	return suma / cantidad;
}

double calcularMaximo(const double* registro, int cantidad) {
	double maximo = registro[0];
	for (int i = 1; i < cantidad; ++i) {
		if (registro[i] > maximo) {
			maximo = registro[i];
		}
	}
	return maximo;
}

double calcularMinimo(const double* registro, int cantidad) {
	double minimo = registro[0];
	for (int i = 1; i < cantidad; ++i) {
		if (registro[i] < minimo) {
			minimo = registro[i];
		}
	}
	return minimo;
}

void mostrarResultados(const double* registro, int cantidad) {
	double promedio = calcularPromedio(registro, cantidad);
	double maximo = calcularMaximo(registro, cantidad);
	double minimo = calcularMinimo(registro, cantidad);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "--------------------------------------------+" << std::endl;
	std::cout << "| Resumen de temperaturas registradas |" << std::endl;
	std::cout << "--------------------------------------------+" << std::endl;
	std::cout << "Promedio: " << promedio << " °C" << std::endl;
	std::cout << "Temperatura Maxima: " << maximo << " °C" << std::endl;
	std::cout << "Temperatura Minima: " << minimo << " °C" << std::endl;

}
