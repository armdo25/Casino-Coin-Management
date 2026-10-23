/*
    Segundo avance TC1031.
    El objetivo es organizar una serie de apostadores usando MergeSort y mostrar
    una clasificacion sencilla a partir de su rendimiento histórico, pero ahora
    consultando una lista enlazada (en el primer avance se alamcenaban los datos
    en un vector, ahora en un .csv y se usa un vector temporal para su ordenamiento).
*/

#include <iostream>
#include <vector>
#include "Apostador.hpp"
#include "Ordenamiento.hpp"
#include "ListaApostadores.hpp"
#include "ArchivoApostadores.hpp"

using namespace std;

int main() {
    ListaApostadores apostadores;
    int cargados = cargarApostadores("apostadores.csv", apostadores);

    if (cargados == -1) {
    cout << "No se pudo abrir apostadores.csv" << endl;
    cout << "Vuelve a intentar." << endl;
    return 1;
}

    cout << "Se cargaron bien los datos." << endl;

    Ordenamiento ordenamiento;

    int opcion = 0;

    while (opcion != 6) {

        cout << endl;
        cout << "===== CASINO COIN =====" << endl;
        cout << "1. Mostrar apostadores" << endl;
        cout << "2. Ordenar por rendimiento" << endl;
        cout << "3. Mostrar apostadores comunes" << endl;
        cout << "4. Mostrar apostadores profesionales" << endl;
        cout << "5. Buscar apostador por ID" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
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
            cin >> id;
        
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "ID no valido." << endl;
            } else {
                Apostador* encontrado = apostadores.buscarPorId(id);
        
                if (encontrado != 0) {
                    cout << endl;
                    encontrado->mostrar();
                } else {
                    cout << "No se encontro ese apostador." << endl;
                }
            }
        
        } else if (opcion == 6) {
            cout << "Saliendo del programa..." << endl;
        
        } else {
            cout << "Opcion no valida." << endl;
        }
            }

    return 0;
}
