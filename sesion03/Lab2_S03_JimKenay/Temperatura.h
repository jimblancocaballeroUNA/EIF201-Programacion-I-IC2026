#pragma once
#ifndef TEMPERATURA_H
#define TEMPERATURA_H
// Se solicita la cantidad de dias y reserva memoria dinamica.
// Retorna puntero al arreglo creado con new.
double* crearRegistro(int& cantidadDias);
// Llena el arreglo con temperaturas ingresadas por el usuario.
void ingresarTemperaturas(double* registro, int cantidad);
// Calcula y retorna el promedio del arreglo.
double calcularPromedio(const double* registro, int cantidad);
// Retorna la temperatura maxima.
double calcularMaximo(const double* registro, int cantidad);
// Retorna la temperatura minima.
double calcularMinimo(const double* registro, int cantidad);
// Muestra resumen de resultados en pantalla.
void mostrarResultados(const double* registro, int cantidad);
#endif // TEMPERATURA_H