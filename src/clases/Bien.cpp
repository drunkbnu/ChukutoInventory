#include <chrono>
#include <format>
#include <sstream>
#include <string>
#include <vector>
#include "Bien.hpp"

using std::string;
using std::stringstream;
using std::vector;

// Crea un objeto, y establece la fecha de incorporación, en formato ISO 8601

Bien::Bien(string &nro, string &dpto, string &usuario, string &marca, string &modelo) :
    _nro(nro), _dpto(dpto), _usuario(usuario), _marca(marca), _modelo(modelo) {
    std::chrono::time_point tiempo = std::chrono::system_clock::now();
    fecha_incorp = std::format("{:%FT%TZ}", tiempo);
    fecha_modif = "-";
    fecha_desinc = "-";
};

// Crea un objeto a partir del texto que se guarda en el archivo

Bien::Bien(string &texto) {
    string campoErroneo = "???";
    vector<string> campos(8);

    for (int i = 0; i < campos.size(); i++) {
        campos[i] = campoErroneo;
    }

    string campo;
    stringstream stream(texto);
    int i = 0;

    while (std::getline(stream, campo, '|')) {
        campos[i] = campo;
        i++;
    }

    _nro = campos[0];
    _dpto = campos[1];
    _usuario = campos[2];
    _marca = campos[3];
    _modelo = campos[4];
    fecha_incorp = campos[5];
    fecha_modif = campos[6];
    fecha_desinc = campos[7];
}

// Genera el texto para guardar en el archivo

string Bien::texto() {
    vector<string> campos = {
        _nro, _dpto, _usuario, _marca, _modelo, fecha_incorp, fecha_modif, fecha_desinc
    };
    string texto;
    stringstream stream(texto);

    for (string &campo : campos) {
        stream.write(campo.c_str(), campo.size());
        stream << '|';
    }

    texto = stream.str();

    return texto;
}

// Crea un vector con todos los campos del objeto

vector<string> Bien::_vector() {
    return { _nro, _dpto, _usuario, _marca, _modelo, fechaIncorp(), fechaModif(), fechaDesinc() };
}

// Getters y setters para los distintos campos del bien

string Bien::nro() { return _nro; }
string Bien::dpto() { return _dpto; }
string Bien::usuario() { return _usuario; }
string Bien::marca() { return _marca; }
string Bien::modelo() { return _modelo; }
void Bien::nro(string valor) { _nro = valor; actualizarFechaModif(); }
void Bien::dpto(string valor) { _dpto = valor; actualizarFechaModif(); }
void Bien::usuario(string valor) { _usuario = valor; actualizarFechaModif(); }
void Bien::marca(string valor) { _marca = valor; actualizarFechaModif(); }
void Bien::modelo(string valor) { _modelo = valor; actualizarFechaModif(); }

// Actualiza la fecha de modificación y desincorporacion

void Bien::actualizarFechaModif() {
    std::chrono::time_point tiempo = std::chrono::system_clock::now();
    fecha_modif = std::format("{:%FT%TZ}", tiempo);
}

void Bien::desincorporar() {
    std::chrono::time_point tiempo = std::chrono::system_clock::now();
    fecha_desinc = std::format("{:%FT%TZ}", tiempo);
}

// Devuelven las distintas fechas en formato local y legible

string Bien::fechaIncorp() { return fechaLegible(fecha_incorp); }
string Bien::fechaModif() { return fechaLegible(fecha_modif); }
string Bien::fechaDesinc() { return fechaLegible(fecha_desinc); }

string Bien::fechaLegible(string &fecha) {
    stringstream stream(fecha);
    std::chrono::system_clock::time_point tiempo;
    stream >> std::chrono::parse("%FT%TZ", tiempo);

    if (stream.fail()) {
        return "-";
    }
    else {
        auto tiempo_hh = std::chrono::zoned_time(std::chrono::current_zone(), tiempo);
        auto tiempo_local = tiempo_hh.get_local_time();

        return std::format("{:%d/%m/%Y, %I:%M %p}", tiempo_local);
    }
}