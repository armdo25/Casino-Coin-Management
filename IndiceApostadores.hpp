/*
    La clase IndiceApostadores guarda una copia de los apostadores
    en un vector ordenado por ID y permite consultar sus datos
    utilizando busqueda binaria.
*/

#ifndef INDICE_APOSTADORES_HPP
#define INDICE_APOSTADORES_HPP

#include <vector>
#include "Apostador.hpp"

class IndiceApostadores {
private:
    vector<Apostador> datos;

public:
    void construir(vector<Apostador> apostadores);
    Apostador* buscarPorId(int id);
};

#endif
