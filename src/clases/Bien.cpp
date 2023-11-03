#include <chrono>
#include <format>
#include <sstream>
#include <string>
#include <vector>
#include "Bien.hpp"

using std::string;
using std::stringstream;
using std::vector;

// Éste constructor se utiliza únicamente para nuevos registros
// Se pasan los campos introducidos manualmente, y se utiliza la fecha del sistema
// como la fecha de incorporación

Bien::Bien(string nro, string dpto, string marca, string modelo) :
    nro(nro), dpto(dpto), marca(marca), modelo(modelo) {
    // "chrono" es una librería estándar en C++20 para trabajar cómodamente con fecha y hora

    std::chrono::time_point tiempo = std::chrono::system_clock::now();

    // Se escribe la fecha y hora en formato ISO, formato estándar para escribir el tiempo
    // Ésto es para permitir la construcción de instancias de tiempo en un futuro

    fecha_incorp = std::format("{:%FT%TZ}", tiempo);
    fecha_modif = "-";
    fecha_desinc = "-";
};

// Éste constructor se utilizará para el listado de registros
// La idea es guardar todos los registros en una colección, y no volver a leer el archivo
// para cambiar de página en el listado

Bien::Bien(string texto) {
    string campoErroneo = "???";
    vector<string> campos(7);

    for (int i = 0; i < campos.size(); i++) {
        campos[i] = campoErroneo;
    }

    string campo;
    stringstream stream(texto);
    int i;

    while (std::getline(stream, campo, '|')) {
        campos[i] = campo;
        i++;
    }
}

// La función que genera el texto que posteriormente se guardará en el archivo
// Se utiliza el caracter | como separador, ya que si se separan los campos
// con espacios, será imposible crear un objeto si algún campo tiene un espacio

string Bien::generarTexto() {
    vector<string> campos = {
        nro, dpto, marca, modelo, fecha_incorp, fecha_modif, fecha_desinc
    };
    string texto = "";
    stringstream stream(texto);

    // Ésta es una iteración especialmente para vectores, que elimina la necesidad de
    // manipular contadores

    for (string &campo : campos) {
        stream.write(campo.c_str(), campo.size());
        stream << '|';
    }

    texto = stream.str();

    return texto;
}