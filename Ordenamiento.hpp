/*
    La clase Ordenamiento contiene el algoritmo MergeSort y permite
    ordenar el vector de apostadores de mayor a menor por rendimiento
    o de menor a mayor por ID.
*/

#ifndef ORDENAMIENTO_HPP
#define ORDENAMIENTO_HPP

#include <vector>
#include "Apostador.hpp"

using namespace std;

class Ordenamiento {
private:
    void merge(vector<Apostador>&, int, int, int, bool);
    void mergeSort(vector<Apostador>&, int, int, bool);

public:
    void ordenar(vector<Apostador>&);
    void ordenarPorId(vector<Apostador>&);
};

#endif
