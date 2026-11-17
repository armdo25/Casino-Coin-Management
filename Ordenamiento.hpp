/*
    La clase Ordenamiento contiene el algoritmo MergeSort y 
    el vector de apostadores se ordena de mayor a menor de acuerdo con su rendimiento.
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
