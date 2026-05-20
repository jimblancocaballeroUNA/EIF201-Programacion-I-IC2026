#include <iostream>
#include <iomanip>
#include "Bitacora.h"
#include "AnalisisAves.h"

using namespace std;
using namespace EIF201;

void mostrarMenuPrincipal() {
    cout << "\n====== MENU PRINCIPAL - BIRD ANALYSIS ======\n";
    cout << "1. Add a new bird\n";
    cout << "2. View all birds\n";
    cout << "3. View valid birds only\n";
    cout << "4. Analyze birds\n";
    cout << "5. Exit\n";
    cout << "Select an option: ";
}

void mostrarMenuAnalisis() {
    cout << "\n====== ANALYSIS MENU ======\n";
    cout << "1. Count total birds\n";
    cout << "2. Sum weights of all birds\n";
    cout << "3. Count birds by species\n";
    cout << "4. Check species existence\n";
    cout << "5. Find heaviest bird\n";
    cout << "6. Print birds in chronological order\n";
    cout << "7. Print birds in reverse order\n";
    cout << "8. Back to main menu\n";
    cout << "Select an option: ";
}

int main()
{
    Bitacora bitacora("anillamientos.txt");
    AnalisisAves analyzer;
    NodoAve* allList = nullptr;
    int opcion = 0;

    cout << "====== WELCOME TO BIRD ANALYSIS SYSTEM ======\n";
    cout << "Data will be saved in: anillamientos.txt\n";

    while (true) {
        mostrarMenuPrincipal();
        if (!(cin >> opcion)) {
            cout << "Error: Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();

        if (opcion == 1) {
            string anillo, especie, fecha;
            double peso;
            char sexo;

            cout << "\n--- Add New Bird ---\n";
            cout << "Ring (ID): ";
            getline(cin, anillo);

            if (anillo.empty()) {
                cout << "Error: Ring cannot be empty.\n";
                continue;
            }

            cout << "Species: ";
            getline(cin, especie);

            if (especie.empty()) {
                cout << "Error: Species cannot be empty.\n";
                continue;
            }

            cout << "Weight (kg): ";
            if (!(cin >> peso)) {
                cout << "Error: Invalid weight. Please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            cin.ignore();

            if (peso <= 0) {
                cout << "Error: Weight must be greater than 0.\n";
                continue;
            }

            cout << "Sex (M/H/X): ";
            cin >> sexo;
            cin.ignore();

            if (sexo != 'M' && sexo != 'H' && sexo != 'X') {
                cout << "Error: Sex must be M, H, or X.\n";
                continue;
            }

            cout << "Date (YYYY-MM-DD): ";
            getline(cin, fecha);

            if (fecha.empty()) {
                cout << "Error: Date cannot be empty.\n";
                continue;
            }

            if (bitacora.registrarAve(anillo, especie, peso, sexo, fecha)) {
                cout << "Bird registered successfully!\n";
            }
            else {
                cout << "Error registering bird.\n";
            }
        }
        else if (opcion == 2) {
            cout << "\n--- Loading ALL birds from file ---\n";
            int totalLoaded = bitacora.cargarTodas(allList);
            cout << "Total birds loaded: " << totalLoaded << "\n\n";

            if (totalLoaded > 0) {
                cout << "Birds (in chronological order):\n";
                cout << "-------------------------------------------------------\n";
                analyzer.imprimirCronologico(allList);
                cout << "-------------------------------------------------------\n";
            }
        }
        else if (opcion == 3) {
            cout << "\n--- Loading VALID birds only ---\n";
            NodoAve* validList = nullptr;
            int valid = bitacora.cargarValidas(validList);
            int discarded = bitacora.getDesacartadas();
            cout << "Valid birds: " << valid << "\n";
            cout << "Discarded birds: " << discarded << "\n\n";

            if (valid > 0) {
                cout << "Valid birds (in chronological order):\n";
                cout << "-------------------------------------------------------\n";
                analyzer.imprimirCronologico(validList);
                cout << "-------------------------------------------------------\n";
            }
            Bitacora::liberarListas(validList);
        }
        else if (opcion == 4) {
            cout << "\n--- Loading birds for analysis ---\n";
            int totalLoaded = bitacora.cargarTodas(allList);
            if (totalLoaded == 0) {
                cout << "No birds to analyze.\n";
                continue;
            }

            int opcionAnalisis = 0;
            while (opcionAnalisis != 8) {
                mostrarMenuAnalisis();
                if (!(cin >> opcionAnalisis)) {
                    cout << "Error: Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                cin.ignore();

                if (opcionAnalisis == 1) {
                    int totalBirds = analyzer.contar(allList);
                    cout << "\nTotal birds: " << totalBirds << "\n";
                }
                else if (opcionAnalisis == 2) {
                    double totalWeight = analyzer.sumarPesos(allList);
                    int totalBirds = analyzer.contar(allList);
                    cout << "\nTotal weight: " << fixed << setprecision(2) << totalWeight << " kg\n";
                    cout << "Average weight: " << (totalBirds > 0 ? totalWeight / totalBirds : 0) << " kg\n";
                }
                else if (opcionAnalisis == 3) {
                    string especie;
                    cout << "\nEnter species name: ";
                    getline(cin, especie);
                    int count = analyzer.contarEspecie(allList, especie);
                    cout << "Number of " << especie << ": " << count << "\n";
                }
                else if (opcionAnalisis == 4) {
                    string especie;
                    cout << "\nEnter species name: ";
                    getline(cin, especie);
                    bool exists = analyzer.existeEspecie(allList, especie);
                    cout << "Does '" << especie << "' exist? " << (exists ? "YES" : "NO") << "\n";
                }
                else if (opcionAnalisis == 5) {
                    NodoAve* heaviest = analyzer.aveMasPesada(allList);
                    if (heaviest) {
                        cout << "\nHeaviest bird:\n";
                        cout << "Ring: " << heaviest->anillo << " | ";
                        cout << "Species: " << heaviest->especie << " | ";
                        cout << "Weight: " << fixed << setprecision(2) << heaviest->peso << " kg\n";
                    }
                }
                else if (opcionAnalisis == 6) {
                    cout << "\nBirds (chronological order):\n";
                    cout << "-------------------------------------------------------\n";
                    analyzer.imprimirCronologico(allList);
                    cout << "-------------------------------------------------------\n";
                }
                else if (opcionAnalisis == 7) {
                    cout << "\nBirds (reverse order):\n";
                    cout << "-------------------------------------------------------\n";
                    analyzer.imprimirInverso(allList);
                    cout << "-------------------------------------------------------\n";
                }
                else if (opcionAnalisis != 8) {
                    cout << "Invalid option. Try again.\n";
                }
            }
        }
        else if (opcion == 5) {
            cout << "\nFreeing memory...\n";
            Bitacora::liberarListas(allList);
            cout << "Thank you for using Bird Analysis System!\n";
            break;
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}