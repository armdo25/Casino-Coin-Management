#include "Ordenamiento.hpp"

void Ordenamiento::ordenar(vector<Apostador>& apostadores) {
    if (apostadores.size() > 1) {
        mergeSort(apostadores, 0, apostadores.size() - 1, false);
    }
}

void Ordenamiento::ordenarPorId(vector<Apostador>& apostadores) {
    if (apostadores.size() > 1) {
        mergeSort(apostadores, 0, apostadores.size() - 1, true);
    }
}

void Ordenamiento::mergeSort(vector<Apostador>& apostadores,
                            int inicio, int fin, bool porId) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;

        mergeSort(apostadores, inicio, mitad, porId);
        mergeSort(apostadores, mitad + 1, fin, porId);

        merge(apostadores, inicio, mitad, fin, porId);
    }
}

void Ordenamiento::merge(vector<Apostador>& apostadores,
                        int inicio, int mitad, int fin, bool porId) {
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

    while (i < totalIzquierda && j < totalDerecha) {
        bool tomarIzquierda;

        if (porId) {
            tomarIzquierda = izquierda[i].getId() <= derecha[j].getId();
        } else {
            tomarIzquierda = izquierda[i].calcularRendimiento() >=
                             derecha[j].calcularRendimiento();
        }

        if (tomarIzquierda) {
            apostadores[k] = izquierda[i];
            i++;
        } else {
            apostadores[k] = derecha[j];
            j++;
        }

        k++;
    }

    while (i < totalIzquierda) {
        apostadores[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < totalDerecha) {
        apostadores[k] = derecha[j];
        j++;
        k++;
    }
}
