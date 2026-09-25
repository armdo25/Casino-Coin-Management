#include "Apostador.hpp"

Apostador::Apostador(int id, string nombre, int apuestas,
                     double totalApostado, double ganancia) {
    this->id = id;
    this->nombre = nombre;
    this->apuestas = apuestas;
    this->totalApostado = totalApostado;
    this->ganancia = ganancia;
}

int Apostador::getId() {
    return id;
}

string Apostador::getNombre() {
    return nombre;
}

int Apostador::getApuestas() {
    return apuestas;
}

double Apostador::getTotalApostado() {
    return totalApostado;
}

double Apostador::getGanancia() {
    return ganancia;
}

double Apostador::calcularRendimiento() {
    if (totalApostado == 0) {
        return 0;
    }

    return (ganancia / totalApostado) * 100;
}

string Apostador::obtenerCategoria() {
    if (apuestas >= 10 && calcularRendimiento() > 0) {
        return "Profesional";
    }

    return "Comun";
}

void Apostador::mostrar() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apuestas: " << apuestas << endl;
    cout << "Total apostado: $" << totalApostado << endl;
    cout << "Ganancia: $" << ganancia << endl;
    cout << "Rendimiento: " << calcularRendimiento() << "%" << endl;
    cout << "Categoria: " << obtenerCategoria() << endl;
}
