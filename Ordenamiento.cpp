#include "Ordenamiento.hpp"

void Ordenamiento::ordenar(vector<Apostador>& apostadores) {
    if (apostadores.size() > 1) {
        mergeSort(apostadores, 0, apostadores.size() - 1);
    }
}

void Ordenamiento::mergeSort(vector<Apostador>& apostadores, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;

        mergeSort(apostadores, inicio, mitad);
        mergeSort(apostadores, mitad + 1, fin);

        merge(apostadores, inicio, mitad, fin);
    }
}

void Ordenamiento::merge(vector<Apostador>& apostadores, int inicio,
                          int mitad, int fin) {

    vector<Apostador> izquierda;
    vector<Apostador> derecha;

    for (int i = inicio; i <= mitad; i++) {
        izquierda.push_back(apostadores[i]);
    }

    for (int i = mitad + 1; i <= fin; i++) {
        derecha.push_back(apostadores[i]);
    }

    int i = 0;
    int j = 0;
    int k = inicio;
    int totalIzquierda = izquierda.size();
    int totalDerecha = derecha.size();

    while (i < totalIzquierda.size() && j < totalDerecha.size()) {

        if (izquierda[i].calcularRendimiento() >=
            derecha[j].calcularRendimiento()) {

            apostadores[k] = izquierda[i];
            i++;
        } else {
            apostadores[k] = derecha[j];
            j++;
        }

        k++;
    }

    while (i < totalIzquierda.size()) {
        apostadores[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < totalDerecha.size()) {
        apostadores[k] = derecha[j];
        j++;
        k++;
    }
}
