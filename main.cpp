/*
    Tercer avance TC1031.
    El programa carga los apostadores desde un archivo CSV y los
    almacena en una lista enlazada. Permite ordenarlos por rendimiento
    con MergeSort, consultar sus categorías, buscar por ID mediante
    búsqueda binaria y guardar los datos en el archivo.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include "Apostador.hpp"
#include "Ordenamiento.hpp"
#include "ListaApostadores.hpp"
#include "ArchivoApostadores.hpp"
#include "IndiceApostadores.hpp"

using namespace std;

bool leerEntero(int& numero) {
    string linea;

    if (!getline(cin, linea)) {
        return false;
    }

    stringstream entrada(linea);
    char extra;

    if (!(entrada >> numero) || (entrada >> extra)) {
        return false;
    }

    return true;
}

int main() {
    ListaApostadores apostadores;
    int cargados = cargarApostadores("apostadores.csv", apostadores);

    if (cargados < 0) {
        if (cargados == -1) {
            cout << "No se pudo abrir apostadores.csv" << endl;
        } else if (cargados == -2) {
            cout << "El archivo esta vacio o el encabezado es incorrecto."
                 << endl;
        } else {
            cout << "Ocurrio un error durante la lectura del archivo."
                 << endl;
        }

        return 1;
    }

    cout << "Apostadores cargados: " << cargados << endl;

    if (cargados == 0) {
        cout << "No hay apostadores validos para consultar." << endl;
    }

    IndiceApostadores indice;
    indice.construir(apostadores.pasarAVector());

    Ordenamiento ordenamiento;
    int opcion = 0;

    while (opcion != 7) {
        cout << endl;
        cout << "===== CASINO COIN =====" << endl;
        cout << "1. Mostrar apostadores" << endl;
        cout << "2. Ordenar por rendimiento" << endl;
        cout << "3. Mostrar apostadores comunes" << endl;
        cout << "4. Mostrar apostadores profesionales" << endl;
        cout << "5. Buscar apostador por ID" << endl;
        cout << "6. Guardar datos en apostadores.csv" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";

        if (!leerEntero(opcion)) {
            if (cin.fail()) {
                cout << "Fin de la entrada. Saliendo del programa..."
                     << endl;
                break;
            }

            opcion = 0;
            cout << "Ingresa un numero entero del 1 al 7." << endl;
            continue;
        }

        if (opcion < 1 || opcion > 7) {
            cout << "Opcion no valida. Elige del 1 al 7." << endl;
            continue;
        }

        if (opcion != 7 && apostadores.cantidad() == 0) {
            cout << "No hay apostadores cargados para realizar esta opcion."
                 << endl;
            continue;
        }

        cout << endl;

        if (opcion == 1) {
            apostadores.mostrarTodos();

        } else if (opcion == 2) {
            vector<Apostador> datosOrdenados = apostadores.pasarAVector();
            ordenamiento.ordenar(datosOrdenados);
            apostadores.acomodar(datosOrdenados);

            cout << "Apostadores ordenados por rendimiento:" << endl;
            cout << endl;
            apostadores.mostrarTodos();

        } else if (opcion == 3) {
            cout << "Apostadores comunes:" << endl;
            cout << endl;
            apostadores.mostrarPorCategoria("Comun");

        } else if (opcion == 4) {
            cout << "Apostadores profesionales:" << endl;
            cout << endl;
            apostadores.mostrarPorCategoria("Profesional");

        } else if (opcion == 5) {
            int id;
            cout << "ID del apostador: ";

            if (!leerEntero(id)) {
                if (cin.fail()) {
                    cout << "Fin de la entrada. Saliendo del programa..."
                         << endl;
                    break;
                }

                cout << "ID no valido. Ingresa un entero positivo." << endl;
                continue;
            }

            if (id <= 0) {
                cout << "ID no valido. Ingresa un entero positivo." << endl;
                continue;
            }

            Apostador* encontrado = indice.buscarPorId(id);

            if (encontrado != 0) {
                encontrado->mostrar();
            } else {
                cout << "No se encontro ese apostador." << endl;
            }

        } else if (opcion == 6) {
            if (guardarApostadores("apostadores.csv", apostadores)) {
                cout << "Datos guardados en apostadores.csv" << endl;
            } else {
                cout << "No se pudieron guardar todos los datos." << endl;
            }

        } else if (opcion == 7) {
            cout << "Saliendo del programa..." << endl;
        }
    }

    return 0;
}
