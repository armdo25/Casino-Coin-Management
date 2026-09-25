#include "Apostador.hpp"
#include <iomanip>

Apostador::Apostador(int idApostador, string nombre, int numeroApuestas,
                     double totalApostado, double gananciaNeta) {
    this->idApostador = idApostador;
    this->nombre = nombre;
    this->numeroApuestas = numeroApuestas;
    this->totalApostado = totalApostado;
    this->gananciaNeta = gananciaNeta;
}

int Apostador::getIdApostador() {
    return idApostador;
}

string Apostador::getNombre() {
    return nombre;
}

int Apostador::getNumeroApuestas() {
    return numeroApuestas;
}

double Apostador::getTotalApostado() {
    return totalApostado;
}

double Apostador::getGananciaNeta() {
    return gananciaNeta;
}

double Apostador::calcularRendimiento() {
    if (totalApostado == 0) {
        return 0;
    }

    return (gananciaNeta / totalApostado) * 100;
}

string Apostador::obtenerCategoria() {
    //Para efectos de esta simulacion se pide un minimo de 10 apuestas
    //y rendimiento positivo para mostrar al jugador como profesional.
    if (numeroApuestas >= 10 && calcularRendimiento() > 0) {
        return "Profesional";
    }

    return "Comun";
}

void Apostador::mostrarApostador() {
    cout << fixed << setprecision(2);
    cout << "ID: " << idApostador << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Numero de apuestas: " << numeroApuestas << endl;
    cout << "Total apostado: $" << totalApostado << endl;
    cout << "Ganancia neta: $" << gananciaNeta << endl;
    cout << "Rendimiento: " << calcularRendimiento() << "%" << endl;
    cout << "Categoria: " << obtenerCategoria() << endl;
}
