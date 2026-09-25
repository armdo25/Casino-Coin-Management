/*
    Primer avance TC1031.
    El objetivo es organizar una serie de apostadores usando MergeSort y mostrar
    una clasificacion sencilla a partir de su rendimiento histórico.
*/

#include <iostream>
#include <vector>
#include "Apostador.hpp"
#include "Ordenamiento.hpp"

using namespace std;

int main() {

    vector<Apostador> apostadores;

    apostadores.push_back(Apostador(1, "Luis", 18, 12500, 1650));
    apostadores.push_back(Apostador(2, "Carlos", 15, 8000, -500));
    apostadores.push_back(Apostador(3, "Erick", 22, 15000, 2100));
    apostadores.push_back(Apostador(4, "Pedro", 7, 4500, 300));
    apostadores.push_back(Apostador(5, "Eli", 14, 10000, -1200));
    apostadores.push_back(Apostador(6, "Jorge", 11, 9000, 750));

    Ordenamiento ordenamiento;

    int opcion = 0;

    while (opcion != 5) {

        cout << endl;
        cout << "===== CASINO COIN =====" << endl;
        cout << "1. Mostrar apostadores" << endl;
        cout << "2. Ordenar por rendimiento" << endl;
        cout << "3. Mostrar apostadores comunes" << endl;
        cout << "4. Mostrar apostadores profesionales" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        cout << endl;

        if (opcion == 1) {

            for (int i = 0; i < apostadores.size(); i++) {
                apostadores[i].mostrar();
                cout << endl;
            }

        } else if (opcion == 2) {

            ordenamiento.ordenar(apostadores);

            cout << "Apostadores ordenados por rendimiento:" << endl;
            cout << endl;

            for (int i = 0; i < apostadores.size(); i++) {
                apostadores[i].mostrar();
                cout << endl;
            }

        } else if (opcion == 3) {

            cout << "Apostadores comunes:" << endl;
            cout << endl;

            for (int i = 0; i < apostadores.size(); i++) {

                if (apostadores[i].obtenerCategoria() == "Comun") {
                    apostadores[i].mostrar();
                    cout << endl;
                }
            }

        } else if (opcion == 4) {

            cout << "Apostadores profesionales:" << endl;
            cout << endl;

            for (int i = 0; i < apostadores.size(); i++) {

                if (apostadores[i].obtenerCategoria() == "Profesional") {
                    apostadores[i].mostrar();
                    cout << endl;
                }
            }

        } else if (opcion == 5) {

            cout << "Saliendo del programa..." << endl;

        } else {

            cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}
