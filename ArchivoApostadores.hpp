#ifndef ARCHIVO_APOSTADORES_HPP
#define ARCHIVO_APOSTADORES_HPP

#include <string>
#include "ListaApostadores.hpp"

// Lee los registros del CSV. Regresa -1 si no se puede abrir.
int cargarApostadores(string nombreArchivo, ListaApostadores& lista);

#endif
