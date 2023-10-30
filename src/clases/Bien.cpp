#include <fstream>
#include <iostream>
#include <string>
#include "Bien.hpp"

using std::ifstream;
using std::string;

Bien::Bien(string nro, string departamento, string marca, string modelo) {
    this->nro = nro;
    this->departamento = departamento;
    this->marca = marca;
    this->modelo = modelo;
};