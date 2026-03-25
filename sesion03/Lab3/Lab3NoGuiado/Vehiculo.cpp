#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(std::string placa, std::string marca, int year, double kilometraje)
    : placa(placa), marca(marca), year(year), kilometraje(kilometraje), activo(true)
{
}

std::string Vehiculo::getPlaca() const
{
    return placa;
}

std::string Vehiculo::getMarca() const
{
    return marca;
}

int Vehiculo::getYear() const
{
    return year;
}

double Vehiculo::getKilometraje() const
{
    return kilometraje;
}

bool Vehiculo::isActivo() const
{
    return activo;
}

void Vehiculo::registrarKilometros(double km)
{
    if (km <= 0) {
        std::cout << "Error: la cantidad de kilómetros debe ser positiva." << std::endl;
        return;
    }
    if (!activo) {
        std::cout << "Error: vehículo fuera de servicio. No se puede registrar kilometraje." << std::endl;
        return;
    }
    kilometraje += km;
}

void Vehiculo::desactivar()
{
    if (!activo) {
        std::cout << "El vehículo ya está fuera de servicio." << std::endl;
        return;
    }
    activo = false;
}

void Vehiculo::reactivar()
{
    if (activo) {   
        std::cout << "El vehículo ya está activo." << std::endl;
        return;
    }
    activo = true;
}

void Vehiculo::mostrar() const
{
    std::cout << "Placa: " << placa << std::endl;
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Año: " << year << std::endl;
    std::cout << "Kilometraje: " << kilometraje << std::endl;
    std::cout << "Estado: " << (activo ? "ACTIVO" : "FUERA DE SERVICIO") << std::endl;
}

