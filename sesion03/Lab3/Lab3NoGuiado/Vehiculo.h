#pragma once
#include <string>
#ifndef VEHICULO_H
#define VEHICULO_H
class Vehiculo
{
private:
	std::string placa;
	std::string marca;
	int year;
	double kilometraje;
	bool activo;

public:

    Vehiculo(std::string placa, std::string marca, int year, double kilometraje);

    std::string getPlaca() const;
    std::string getMarca() const;
    int getYear() const;
    double getKilometraje() const;
    bool isActivo() const;
        
    void registrarKilometros(double km);
    void desactivar();
    void reactivar();
    void mostrar() const;

};
#endif VEHICULO_H
