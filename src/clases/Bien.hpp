#include <string>

using std::string;

class Bien {
    public:
        string nro;
        string dpto;
        string marca;
        string modelo;
        string obtenerFechaIncorp();
        string obtenerFechaModif();
        string obtenerFechaDesinc();
        string generarTexto();

        Bien(string nro, string dpto, string marca, string modelo);
        Bien(string texto);
    private:
        string fecha_incorp;
        string fecha_modif;
        string fecha_desinc;
};