#include <iostream>
#include <string>
#include <limits>
#include "Vehiculo.h"
#include "Flota.h"

void mostrarMenu()
{
    std::cout << "\n--- MENU FLOTA ---\n";
    std::cout << "1. Agregar vehiculo\n";
    std::cout << "2. Mostrar vehiculo por placa\n";
    std::cout << "3. Registrar kilometros\n";
    std::cout << "4. Desactivar vehiculo\n";
    std::cout << "5. Reactivar vehiculo\n";
    std::cout << "6. Eliminar vehiculo\n";
    std::cout << "7. Mostrar cantidad y capacidad\n";
    std::cout << "8. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main()
{
    Flota flota(4);
    int opcion = 0;

    while (true) {
        mostrarMenu();
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Intente de nuevo." << std::endl;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcion == 1) {
            std::string placa, marca;
            int year;
            double km;
            std::cout << "Ingrese la placa: ";
            std::getline(std::cin, placa);
            if (flota.buscarVehiculo(placa) != nullptr) {
                std::cout << "Ya existe un vehiculo con esa placa." << std::endl;
                continue;
            }
            std::cout << "Ingrese la marca: ";
            std::getline(std::cin, marca);
            std::cout << "Ingrese el anio: ";
            std::cin >> year;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese el kilometraje inicial: ";
            std::cin >> km;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Vehiculo v(placa, marca, year, km);
            flota.agregarVehiculo(v);
            std::cout << "Vehiculo agregado." << std::endl;

        } else if (opcion == 2) {
            std::string placa;
            std::cout << "Ingrese la placa a mostrar: ";
            std::getline(std::cin, placa);
            if (flota.mostrarPorPlaca(placa) == nullptr) {
                std::cout << "Vehiculo no encontrado." << std::endl;
            }

        } else if (opcion == 3) {
            std::string placa;
            double km;
            std::cout << "Ingrese la placa: ";
            std::getline(std::cin, placa);
            Vehiculo* v = flota.buscarVehiculo(placa);
            if (v == nullptr) {
                std::cout << "Vehiculo no encontrado." << std::endl;
                continue;
            }
            std::cout << "Ingrese kilometros a registrar: ";
            std::cin >> km;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            v->registrarKilometros(km);

        } else if (opcion == 4) {
            std::string placa;
            std::cout << "Ingrese la placa a desactivar: ";
            std::getline(std::cin, placa);
            Vehiculo* v = flota.buscarVehiculo(placa);
            if (v == nullptr) {
                std::cout << "Vehiculo no encontrado." << std::endl;
                continue;
            }
            v->desactivar();

        } else if (opcion == 5) {
            std::string placa;
            std::cout << "Ingrese la placa a reactivar: ";
            std::getline(std::cin, placa);
            Vehiculo* v = flota.buscarVehiculo(placa);
            if (v == nullptr) {
                std::cout << "Vehiculo no encontrado." << std::endl;
                continue;
            }
            v->reactivar();

        } else if (opcion == 6) {
            std::string placa;
            std::cout << "Ingrese la placa a eliminar: ";
            std::getline(std::cin, placa);
            if (flota.eliminarVehiculo(placa)) {
                std::cout << "Vehiculo eliminado." << std::endl;
            } else {
                std::cout << "Vehiculo no encontrado." << std::endl;
            }

        } else if (opcion == 7) {
            std::cout << "Cantidad de vehiculos: " << flota.getCantidad() << std::endl;
            std::cout << "Capacidad: " << flota.getCapacidad() << std::endl;

        } else if (opcion == 8) {
            std::cout << "Saliendo..." << std::endl;
            break;

        } else {
            std::cout << "Opcion no valida." << std::endl;
        }
    }

    return 0;
}


