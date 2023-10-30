#include <fstream>
#include <iostream>
#include <string>
#include "Bien.hpp"

using std::ifstream;
using std::string;

Bien::Bien(string nro, string tipo, string marca, string modelo) {
    this->nro = nro;
    this->tipo = tipo;
    this->marca = marca;
    this->modelo = modelo;
};