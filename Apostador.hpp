/*
    La clase Apostador representa el resumen de actividad de un usuario dentro de Casino Coin.
    Para este primer avance no se simulan apuestas una por una, sino que se usan datos históricos
    resumidos.
*/

#ifndef APOSTADOR_HPP
#define APOSTADOR_HPP

#include <iostream>
#include <string>

using namespace std;

class Apostador {
private:
    int id;
    string nombre;
    int apuestas;
    double totalApostado;
    double ganancia;

public:
    Apostador(int, string, int, double, double);

    int getId();
    string getNombre();
    int getApuestas();
    double getTotalApostado();
    double getGanancia();

    double calcularRendimiento();
    string obtenerCategoria();
    void mostrar();
};

#endif
