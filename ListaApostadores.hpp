/*
    Lista simplemente enlazada para guardar los apostadores.
    Cada nodo contiene los datos de un apostador.
*/

#ifndef LISTA_APOSTADORES_HPP
#define LISTA_APOSTADORES_HPP

#include <vector>
#include "Apostador.hpp"

class ListaApostadores {
private:
    struct Nodo {
        Apostador apostador;
        Nodo* siguiente;

        Nodo(Apostador nuevo) : apostador(nuevo), siguiente(0) {}
    };

    Nodo* primero;
    Nodo* ultimo;
    int total;

public:
    ListaApostadores();
    ~ListaApostadores();

    void agregar(Apostador nuevo);
    void mostrarTodos();
    void mostrarPorCategoria(string categoria);
    Apostador* buscarPorId(int id);
    vector<Apostador> pasarAVector();
    void acomodar(vector<Apostador>& ordenados);
    int cantidad();
};

#endif
