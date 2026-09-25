/*
    La clase Ordenamiento contiene el algoritmo MergeSort utilizado en el primer avance.
    El vector de apostadores se ordena de mayor a menor de acuerdo con su rendimiento.
*/

#ifndef ORDENAMIENTO_HPP
#define ORDENAMIENTO_HPP

#include <vector>
#include "Apostador.hpp"

using namespace std;

class Ordenamiento {
private:
    void merge(vector<Apostador>& apostadores, int inicio, int medio, int fin);
    void mergeSort(vector<Apostador>& apostadores, int inicio, int fin);

public:
    void ordenarPorRendimiento(vector<Apostador>& apostadores);
};

#endif
