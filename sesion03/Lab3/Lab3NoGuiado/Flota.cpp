#include "Flota.h"
#include <iostream>

Flota::Flota(int capacidad) :cantidad(0), capacidad(capacidad) {

	vehiculos = new Vehiculo* [capacidad];
	for (int i = 0; i < capacidad; i++) {

		vehiculos[i] = nullptr;

	}
}

Flota::~Flota()
{
	for (int i = 0; i < cantidad; i++) {
		delete vehiculos[i];
		vehiculos[i] = nullptr;
	}

	delete[] vehiculos;
	vehiculos = nullptr;
	std::cout << "inventario destruido";
}

void Flota::agregarVehiculo(const Vehiculo& vehiculo)
{
    if (cantidad >= capacidad) {
        redimensionar();
    }

    // crear una copia dinámica del vehículo recibido
    Vehiculo* nuevo = new Vehiculo(vehiculo.getPlaca(), vehiculo.getMarca(), vehiculo.getYear(), vehiculo.getKilometraje());
    vehiculos[cantidad] = nuevo;
    cantidad++;
}

Vehiculo* Flota::buscarVehiculo(const std::string& placa) const
{
    for (int i = 0; i < cantidad; i++) {
        if (vehiculos[i] != nullptr && vehiculos[i]->getPlaca() == placa) {
            return vehiculos[i];
        }
    }

    return nullptr;
}

Vehiculo* Flota::mostrarPorPlaca(const std::string& placa) const
{
    Vehiculo* v = buscarVehiculo(placa);
    if (v != nullptr) {
        v->mostrar();
    }
    return v;
}

bool Flota::eliminarVehiculo(const std::string& placa)
{
    for (int i = 0; i < cantidad; i++) {
        if (vehiculos[i] != nullptr && vehiculos[i]->getPlaca() == placa) {
            delete vehiculos[i];
            // shift left
            for (int j = i; j < cantidad - 1; j++) {
                vehiculos[j] = vehiculos[j + 1];
            }
            vehiculos[cantidad - 1] = nullptr;
            cantidad--;
            return true;
        }
    }
    return false;
}

int Flota::getCapacidad()
{
    return capacidad;   
}

int Flota::getCantidad()
{
    return cantidad;    
}


void Flota::redimensionar()
{
	int nuevaCapacidad = capacidad * 2;
	Vehiculo** nuevoArray = new Vehiculo * [nuevaCapacidad];

    // copy existing pointers
    for (int i = 0; i < cantidad; i++) {
        nuevoArray[i] = vehiculos[i];
    }

    // initialize remaining slots to nullptr
    for (int i = cantidad; i < nuevaCapacidad; i++) {
        nuevoArray[i] = nullptr;
    }

	delete[] vehiculos;

	vehiculos = nuevoArray;
	capacidad = nuevaCapacidad;
}


