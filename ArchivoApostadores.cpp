#include <fstream>
#include <sstream>
#include "ArchivoApostadores.hpp"

int cargarApostadores(string nombreArchivo, ListaApostadores& lista) {
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo.is_open()) {
        return -1;
    }

    string linea;

    if (!getline(archivo, linea)) {
        return -2;
    }

    if (!linea.empty() && linea[linea.size() - 1] == '\r') {
        linea.erase(linea.size() - 1);
    }

    if (linea != "id,nombre,apuestas,totalApostado,ganancia") {
        return -2;
    }

    int cargados = 0;
    int numeroLinea = 1;

    while (getline(archivo, linea)) {
        numeroLinea++;

        int comas = 0;

        for (int i = 0; i < (int) linea.size(); i++) {
            if (linea[i] == ',') {
                comas++;
            }
        }

        stringstream fila(linea);
        string textoId, nombre, textoApuestas, textoTotal, textoGanancia;

        if (comas != 4 || !getline(fila, textoId, ',') ||
            !getline(fila, nombre, ',') ||
            !getline(fila, textoApuestas, ',') ||
            !getline(fila, textoTotal, ',') ||
            !getline(fila, textoGanancia)) {
            cout << "Linea " << numeroLinea
                 << ": formato incorrecto. Se omite." << endl;
            continue;
        }

        int id, apuestas;
        double totalApostado, ganancia;

        stringstream datoId(textoId);
        stringstream datoApuestas(textoApuestas);
        stringstream datoTotal(textoTotal);
        stringstream datoGanancia(textoGanancia);
        stringstream datoNombre(nombre);
        string palabra;

        // Comprueba los numeros y que el nombre no esté en blanco.
        if (!(datoId >> id) || !(datoApuestas >> apuestas) ||
            !(datoTotal >> totalApostado) || !(datoGanancia >> ganancia) ||
            !(datoNombre >> palabra)) {
            cout << "Linea " << numeroLinea
                 << ": datos invalidos. Se omite." << endl;
            continue;
        }

        // Rechaza números con caracteres sobrantes y valores no permitidos.
        char extra;

        if ((datoId >> extra) || (datoApuestas >> extra) ||
            (datoTotal >> extra) || (datoGanancia >> extra) ||
            id <= 0 || apuestas < 0 || totalApostado < 0) {
            cout << "Linea " << numeroLinea
                 << ": datos invalidos. Se omite." << endl;
            continue;
        }

        if (lista.buscarPorId(id) != 0) {
            cout << "Linea " << numeroLinea
                 << ": ID repetido. Se omite." << endl;
            continue;
        }

        lista.agregar(Apostador(id, nombre, apuestas,
                                totalApostado, ganancia));
        cargados++;
    }

    if (archivo.bad()) {
        return -3;
    }

    return cargados;
}
