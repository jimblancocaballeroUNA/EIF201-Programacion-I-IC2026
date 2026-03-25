#pragma once
#ifndef FLOTA_H
#define FLOTA_H
#include "Vehiculo.h"

class Flota
{
private:
	Vehiculo** vehiculos;
	int capacidad;
	int cantidad;

	void redimensionar();
public:

	Flota(int capacidad);

	~Flota();

	void agregarVehiculo(const Vehiculo& vehiculo);
	Vehiculo* buscarVehiculo(const std::string& placa) const;
	Vehiculo* mostrarPorPlaca(const std::string& placa) const;
	bool eliminarVehiculo(const std::string& placa);

	int getCapacidad();
	int getCantidad();
};

#endif FLOTA_H