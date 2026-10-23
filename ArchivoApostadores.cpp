#include <fstream>
#include <sstream>
#include "ArchivoApostadores.hpp"

// Lee cada fila del CSV y agrega el apostador a la lista.
int cargarApostadores(string nombreArchivo, ListaApostadores& lista) {
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo.is_open()) {
        return -1;
    }

    string linea;
    getline(archivo, linea); // Encabezados del archivo.
    int cargados = 0;

    while (getline(archivo, linea)) {
        stringstream fila(linea);
        string textoId, nombre, textoApuestas, textoTotal, textoGanancia;

        if (!getline(fila, textoId, ',') ||
            !getline(fila, nombre, ',') ||
            !getline(fila, textoApuestas, ',') ||
            !getline(fila, textoTotal, ',') ||
            !getline(fila, textoGanancia, ',')) {
            continue;
        }

        int id, apuestas;
        double totalApostado, ganancia;
        stringstream datoId(textoId);
        stringstream datoApuestas(textoApuestas);
        stringstream datoTotal(textoTotal);
        stringstream datoGanancia(textoGanancia);

        if (!(datoId >> id) || !(datoApuestas >> apuestas) ||
            !(datoTotal >> totalApostado) || !(datoGanancia >> ganancia)) {
            continue;
        }

        char extra;
        if ((datoId >> extra) || (datoApuestas >> extra) ||
            (datoTotal >> extra) || (datoGanancia >> extra)) {
            continue;
        }

        if (id <= 0 || nombre == "" || apuestas < 0 || totalApostado < 0) {
            continue;
        }

        lista.agregar(Apostador(id, nombre, apuestas, totalApostado, ganancia));
        cargados++;
    }

    return cargados;
}
