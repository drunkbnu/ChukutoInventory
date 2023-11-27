#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Interfaz {
    public:
        int ancho();
        int alto();

        string cabecera();
        string pie();
        string leerLinea(int caracteres);
        char caracter();

        void escribir(const char *texto);
        void escribir(string texto);
        void cabecera(string cabecera);
        void pie(string pie);
        void mover(int y, int x);
        void limpiar();
        void menu(vector<string> opciones);
        void formulario(vector<string> campos);
        void popup(string mensaje);
        void cerrar();

        Interfaz(string cabecera, string pie);
    private:
        int _ancho;
        int _alto;
        bool invertido;
        string _cabecera;
        string _pie;

        void invertir();
        void mostrarCabecera();
        void mostrarPie();
};