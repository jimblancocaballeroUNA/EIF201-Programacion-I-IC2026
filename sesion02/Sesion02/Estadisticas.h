#pragma once
#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H
#include <array>
#include <iostream>

constexpr int ROWS = 3;
constexpr int COLS = 3;



//Ejercicio #1
void maxNumValue(std::array<int, 10> numMatrix);
void minNumValue(std::array<int, 10> numMatrix);
void promNumValue(std::array<int, 10> numMatrix);
void allSumMatrix(std::array<int, 10> numMatrix);

//Ejercicio #2
std::array<int, 20> reverseArray(std::array<int, 20> numMatrix);

//Ejercicio #3
std::array<std::array<int, ROWS>, COLS> createMatrix();
void sumColsMatrix(std::array<std::array<int, ROWS>, COLS> matrix);
void sumRowsMatrix(std::array<std::array<int, ROWS>, COLS> matrix);
void sumDiangonalMatrix(std::array<std::array<int, ROWS>, COLS> matrix);




#endif 

