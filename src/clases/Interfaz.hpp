#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Interfaz {
    public:
        int obtenerAncho();
        int obtenerAlto();

        string obtenerCabecera();
        string obtenerPie();
        string leerLinea(int caracteres);

        void escribir(const char *texto);
        void escribir(string texto);
        void establecerCabecera(string cabecera);
        void establecerPie(string pie);
        void mover(int y, int x);
        void limpiarContenido();
        void mostrarMenu(vector<string> opciones);
        void mostrarFormulario(vector<string> campos);
        void mostrarPopup(string mensaje);
        void cerrar();

        Interfaz(string cabecera, string pie);
    private:
        int ancho;
        int alto;
        bool invertido;
        string cabecera;
        string pie;

        void alternarColores();
        void mostrarCabecera();
        void mostrarPie();
};