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

        void limpiarContenido();
        void mostrarMenu(vector<string> opciones);
        void mostrarPopup(string mensaje);

        Interfaz(string cabecera, string pie);
    private:
        string cabecera;
        string pie;

        void mostrarCabecera();
        void mostrarPie();
};