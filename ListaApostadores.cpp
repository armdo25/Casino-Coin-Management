#include "ListaApostadores.hpp"

ListaApostadores::ListaApostadores() {
    primero = 0;
    ultimo = 0;
    total = 0;
}

ListaApostadores::~ListaApostadores() {
    Nodo* actual = primero;

    while (actual != 0) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Agrega cada apostador al final de la lista.
void ListaApostadores::agregar(Apostador nuevo) {
    Nodo* nodo = new Nodo(nuevo);

    if (primero == 0) {
        primero = nodo;
        ultimo = nodo;
    } else {
        ultimo->siguiente = nodo;
        ultimo = nodo;
    }

    total++;
}

// Recorre la lista para mostrar todos los registros.
void ListaApostadores::mostrarTodos() {
    Nodo* actual = primero;

    while (actual != 0) {
        actual->apostador.mostrar();
        cout << endl;
        actual = actual->siguiente;
    }
}

// Muestra solamente los apostadores de la categoria indicada.
void ListaApostadores::mostrarPorCategoria(string categoria) {
    Nodo* actual = primero;

    while (actual != 0) {
        if (actual->apostador.obtenerCategoria() == categoria) {
            actual->apostador.mostrar();
            cout << endl;
        }

        actual = actual->siguiente;
    }
}

// Busca un apostador por ID y regresa 0 si no existe.
Apostador* ListaApostadores::buscarPorId(int id) {
    Nodo* actual = primero;

    while (actual != 0) {
        if (actual->apostador.getId() == id) {
            return &actual->apostador;
        }

        actual = actual->siguiente;
    }

    return 0;
}

// Pasa los datos a un vector para usar el MergeSort del avance 1.
vector<Apostador> ListaApostadores::pasarAVector() {
    vector<Apostador> datos;
    Nodo* actual = primero;

    while (actual != 0) {
        datos.push_back(actual->apostador);
        actual = actual->siguiente;
    }

    return datos;
}

// Guarda el orden del vector nuevamente en los nodos de la lista.
void ListaApostadores::acomodar(vector<Apostador>& ordenados) {
    Nodo* actual = primero;
    int cantidadOrdenados = ordenados.size();

    for (int i = 0; i < cantidadOrdenados && actual != 0; i++) {
        actual->apostador = ordenados[i];
        actual = actual->siguiente;
    }
}

int ListaApostadores::cantidad() {
    return total;
}
