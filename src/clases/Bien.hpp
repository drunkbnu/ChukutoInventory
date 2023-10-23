#include <iostream>
using std::string;

class Bien {
    public:
        string nro;
        string tipo;
        string marca;
        string modelo;

        Bien(string nro, string tipo, string marca, string modelo);
        static Bien desde_archivo(string ruta);
};