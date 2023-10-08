#include <iostream>
using std::string;

class Bien {
    public:
        string nro_bien;
        string categoria;
        string marca;
        string modelo;

        Bien(string nro_bien, string categoria, string marca, string modelo);
        static Bien desde_archivo(string ruta);
};