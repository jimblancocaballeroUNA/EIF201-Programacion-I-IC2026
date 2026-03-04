#include "Estadisticas.h"

void maxNumValue(std::array<int, 10> numMatrix)
{
	int maxValue = numMatrix[0];
	for (int i = 1; i < numMatrix.size(); i++)
	{
		if (numMatrix[i] > maxValue)
		{
			maxValue = numMatrix[i];
		}
	}
}
void minNumValue(std::array<int, 10> numMatrix)
{
	int minValue = numMatrix[0];
	for (int i = 1; i < numMatrix.size(); i++)
	{
		if (numMatrix[i] < minValue)
		{
			minValue = numMatrix[i];
		}
	}
}

void promNumValue(std::array<int, 10> numMatrix)
{
	int sum = 0;
	for (int i = 0; i < numMatrix.size(); i++)
	{
		sum += numMatrix[i];
	}
	double promValue = static_cast<double>(sum) / numMatrix.size();
}

void allSumMatrix(std::array<int, 10> numMatrix)
{
	int sum = 0;
	for (int i = 0; i < numMatrix.size(); i++)
	{
		sum += numMatrix[i];
	}
}

std::array<int, 20>  reverseArray(std::array<int, 20> numMatrix)
{
	std::array<int, 20> reversedMatrix;
	int counter = 0;
	for(int i = 19; i >= 0 ; i--)
	{
		reversedMatrix[counter] = numMatrix[i];
		counter++;
	}

	return reversedMatrix;
}

std::array<std::array<int, 3>, 3> createMatrix()
{
	std::array<std::array<int, 3>, 3> matrix;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << "Ingrese el valor para la posicion [" << i << "][" << j << "]: ";
			std::cin >> matrix[i][j];
		}
	}

	return matrix;
}

void sumColsMatrix(std::array<std::array<int, 3>, 3> matrix) {
	for (int j = 0; j < 3; j++) { 
		int sum = 0;
		for (int i = 0; i < 3; i++) { 
			sum += matrix[i][j];
		}
		std::cout << "Suma de columna " << j << ": " << sum << std::endl;
	}
}
void sumRowsMatrix(std::array<std::array<int, 3>, 3> matrix) {
	for (int i = 0; i < 3; i++) { 
		int sum = 0;
		for (int j = 0; j < 3; j++) { 
			sum += matrix[i][j];
		}
		std::cout << "Suma de fila " << i << ": " << sum << std::endl;
	}
}

void sumDiangonalMatrix(std::array<std::array<int, ROWS>, COLS> matrix)
{
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += matrix[i][i];
	}
	std::cout << "Suma de la diagonal principal: " << sum << std::endl;

}
