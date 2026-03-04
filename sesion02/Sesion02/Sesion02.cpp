#include <iostream>
#include "Estadisticas.h"
#include <string>






int main()
{
	std::cout << " PRUEBAS ARRAY 10 ELEMENTOS " << std::endl;
	std::array<int, 10> miArray10 = { 5, 12, 8, 20, 3, 15, 7, 2, 11, 9 };
	maxNumValue(miArray10);
	minNumValue(miArray10);
	promNumValue(miArray10);
	allSumMatrix(miArray10);

	std::cout << "\n PRUEBA REVERSE ARRAY 20 " << std::endl;
	std::array<int, 20> miArray20 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	std::array<int, 20> invertido = reverseArray(miArray20);
	std::cout << "Array invertido: ";
	for (int n : invertido) std::cout << n << " ";
	std::cout << std::endl;

	std::cout << "\n PRUEBA MATRIZ 3x3 " << std::endl;
	std::array<std::array<int, 3>, 3> miMatriz = createMatrix();

	sumRowsMatrix(miMatriz);
	sumColsMatrix(miMatriz);
	sumDiangonalMatrix(miMatriz);
	
	//ejercicio 4
	std::string name;
	std::string firstname = "";
	std::string lastname1 = "";
	int vowels = 0;
	bool firstspace = false;

	std::cout << "\n ingrese su nombre" << "\n";
	std::getline(std::cin, name);

	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') {
			break;
		}
		firstname = firstname + name[i];
	}

	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') {

			if (firstspace == false) {
				firstspace = true;
				continue;
			}
			else {
				break;
			}
		}

		if (firstspace) {
			lastname1 += name[i];
		}

	}

	for (int i = 0; i < name.length(); i++) {
		name[i] = toupper(name[i]);
	}

	for (int i = 0; i < name.length(); i++) {
		if (name[i] == 'A' || name[i] == 'a' || name[i] == 'E' || name[i] == 'e' || name[i] == 'I' || name[i] == 'i' || name[i] == 'O' || name[i] == 'o'
			|| name[i] == 'U' || name[i] == 'u') {
			vowels++;
		}

	}

	std::cout << "Primer nombre:" << firstname << std::endl;
	std::cout << "Su apellido es:" << lastname1 << std::endl;
	std::cout << "Su nombre tiene " << vowels << " vocales" << std::endl;
	std::cout << "Su nombre tiene " << name.length() << " letras de longitud" << std::endl;
	std::cout << "Su nombre en mayusculas:" << name << std::endl;


	std::cin.get();
	return 0;

}
