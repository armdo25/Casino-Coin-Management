/*
    Este archivo declara la función que carga los apostadores
    desde un archivo CSV a la lista enlazada.
    Durante la lectura se validan los datos y los IDs repetidos.
*/

#ifndef ARCHIVO_APOSTADORES_HPP
#define ARCHIVO_APOSTADORES_HPP

#include <string>
#include "ListaApostadores.hpp"

// Regresa la cantidad de registros cargados.
// -1: no se pudo abrir el archivo.
// -2: archivo vacio o encabezado incorrecto.
// -3: error durante la lectura.

int cargarApostadores(string nombreArchivo, ListaApostadores& lista);

#endif
