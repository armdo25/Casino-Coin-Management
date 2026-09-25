/*
    La clase Apostador representa el resumen de actividad de un usuario dentro de Casino Coin.
    Para este primer avance no se simulan apuestas una por una, sino que se usan datos historicos
    resumidos para poder enfocarnos en el tema principal de la materia: ordenar una serie de datos.
*/

#ifndef APOSTADOR_HPP
#define APOSTADOR_HPP

#include <iostream>
#include <string>

using namespace std;

class Apostador {
private:
    int idApostador;
    string nombre;
    int numeroApuestas;
    double totalApostado;
    double gananciaNeta;

public:
    Apostador(int idApostador, string nombre, int numeroApuestas,
              double totalApostado, double gananciaNeta);

    int getIdApostador();
    string getNombre();
    int getNumeroApuestas();
    double getTotalApostado();
    double getGananciaNeta();

    //Calcula el rendimiento del jugador con respecto al dinero total apostado.
    double calcularRendimiento();

    //Clasificacion interna del proyecto, no intenta representar una regla real de un casino.
    string obtenerCategoria();

    void mostrarApostador();
};

#endif
