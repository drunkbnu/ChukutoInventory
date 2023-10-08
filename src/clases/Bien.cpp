#include <fstream>
#include <iostream>
#include "Bien.hpp"

using std::ifstream;
using std::string;

Bien::Bien(string nro_bien, string categoria, string marca, string modelo) {
    this->nro_bien = nro_bien;
    this->categoria = categoria;
    this->marca = marca;
    this->modelo = modelo;
}

Bien Bien::desde_archivo(string ruta) {
    ifstream archivo(ruta);
    string buffer;
    string contenido[4];
    int i = 0;

    while (getline(archivo, buffer)) {
        contenido[i] = buffer;
        i++;
    }

    archivo.close();

    return Bien(contenido[0], contenido[1], contenido[2], contenido[3]);
}