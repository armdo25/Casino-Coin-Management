#include "Ordenamiento.hpp"

void Ordenamiento::ordenarPorRendimiento(vector<Apostador>& apostadores) {
    if (apostadores.size() > 1) {
        mergeSort(apostadores, 0, apostadores.size() - 1);
    }
}

void Ordenamiento::mergeSort(vector<Apostador>& apostadores, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        mergeSort(apostadores, inicio, medio);
        mergeSort(apostadores, medio + 1, fin);

        merge(apostadores, inicio, medio, fin);
    }
}

void Ordenamiento::merge(vector<Apostador>& apostadores, int inicio, int medio, int fin) {
    vector<Apostador> izquierda;
    vector<Apostador> derecha;

    for (int i = inicio; i <= medio; i++) {
        izquierda.push_back(apostadores[i]);
    }

    for (int i = medio + 1; i <= fin; i++) {
        derecha.push_back(apostadores[i]);
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < (int)izquierda.size() && j < (int)derecha.size()) {
        //El mayor rendimiento se coloca primero.
        //El >= conserva el orden original cuando existe un empate.
        if (izquierda[i].calcularRendimiento() >= derecha[j].calcularRendimiento()) {
            apostadores[k] = izquierda[i];
            i++;
        }
        else {
            apostadores[k] = derecha[j];
            j++;
        }

        k++;
    }

    while (i < (int)izquierda.size()) {
        apostadores[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < (int)derecha.size()) {
        apostadores[k] = derecha[j];
        j++;
        k++;
    }
}
