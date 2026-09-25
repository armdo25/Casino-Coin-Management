/*
    Primer avance de Casino Coin para TC1031.
    El objetivo es organizar una serie de apostadores usando MergeSort y mostrar
    una clasificacion sencilla a partir de su rendimiento historico.
*/

#include <iostream>
#include <vector>
#include "Apostador.hpp"
#include "Ordenamiento.hpp"

using namespace std;

void mostrarLista(vector<Apostador>& apostadores) {
    for (int i = 0; i < (int)apostadores.size(); i++) {
        apostadores[i].mostrarApostador();
        cout << "------------------------------" << endl;
    }
}

void mostrarPorCategoria(vector<Apostador>& apostadores, string categoria) {
    bool encontrado = false;

    for (int i = 0; i < (int)apostadores.size(); i++) {
        if (apostadores[i].obtenerCategoria() == categoria) {
            apostadores[i].mostrarApostador();
            cout << "------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No hay apostadores en esta categoria." << endl;
    }
}

int main() {
    //Datos de prueba que representan un historial resumido de varios apostadores.
    vector<Apostador> apostadores;

    apostadores.push_back(Apostador(1, "Luis", 18, 12500, 1650));
    apostadores.push_back(Apostador(2, "Alejandro", 15, 9800, -1200));
    apostadores.push_back(Apostador(3, "Erick", 24, 17600, 950));
    apostadores.push_back(Apostador(4, "Armando", 8, 5400, 1100));
    apostadores.push_back(Apostador(5, "David", 20, 14300, -450));
    apostadores.push_back(Apostador(6, "Carlos", 12, 8000, 400));

    Ordenamiento ordenamiento;
    int opcion = 0;
    bool ordenados = false;

    while (opcion != 5) {
        cout << endl;
        cout << "===== CASINO COIN - ANALISIS DE APOSTADORES =====" << endl;
        cout << "1. Ver datos almacenados" << endl;
        cout << "2. Ordenar apostadores por rendimiento" << endl;
        cout << "3. Mostrar apostadores comunes" << endl;
        cout << "4. Mostrar apostadores profesionales" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarLista(apostadores);
        }
        else if (opcion == 2) {
            ordenamiento.ordenarPorRendimiento(apostadores);
            ordenados = true;

            cout << endl;
            cout << "Apostadores ordenados de mayor a menor rendimiento:" << endl;
            mostrarLista(apostadores);
        }
        else if (opcion == 3) {
            if (!ordenados) {
                ordenamiento.ordenarPorRendimiento(apostadores);
                ordenados = true;
            }

            cout << endl;
            cout << "Apostadores comunes:" << endl;
            mostrarPorCategoria(apostadores, "Comun");
        }
        else if (opcion == 4) {
            if (!ordenados) {
                ordenamiento.ordenarPorRendimiento(apostadores);
                ordenados = true;
            }

            cout << endl;
            cout << "Apostadores profesionales:" << endl;
            mostrarPorCategoria(apostadores, "Profesional");
        }
        else if (opcion == 5) {
            cout << "Saliendo de Casino Coin..." << endl;
        }
        else {
            cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}
