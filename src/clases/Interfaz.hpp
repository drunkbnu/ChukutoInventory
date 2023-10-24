#include <string>
#include <vector>

using std::string;
using std::vector;

class Interfaz {
    public:
        void establecerCabecera(string cabecera);
        void establecerPie(string pie);
        string obtenerCabecera();
        string obtenerPie();

        string leerLinea();
        void limpiarContenido();
        void mostrarMenu(vector<string> opciones);
        void mostrarPopup(string mensaje);
        void cerrar();

        Interfaz(string cabecera, string pie);
    private:
        int ancho;
        int alto;
        bool invertido;
        string cabecera;
        string pie;

        void mover(int y, int x);
        void escribir(const char *texto);
        void escribir(string texto);
        void alternarColores();
        void mostrarCabecera();
        void mostrarPie();
};