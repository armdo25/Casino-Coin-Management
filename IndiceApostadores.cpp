#include "IndiceApostadores.hpp"
#include "Ordenamiento.hpp"

void IndiceApostadores::construir(vector<Apostador> apostadores) {
    datos = apostadores;

    Ordenamiento ordenamiento;
    ordenamiento.ordenarPorId(datos);
}

Apostador* IndiceApostadores::buscarPorId(int id) {
    int inicio = 0;
    int fin = (int) datos.size() - 1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;

        if (datos[mitad].getId() == id) {
            return &datos[mitad];
        } else if (id < datos[mitad].getId()) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }

    return 0;
}
