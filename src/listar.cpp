#include <format>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "Programa.hpp"
#include "clases/Bien.hpp"

using std::fstream;
using std::pair;
using std::string;
using std::stringstream;

void listar() {
    interfaz.cabecera("Listado de Registros");
    interfaz.pie("");
    interfaz.limpiar();

    fstream archivo("bienes.txt", std::ios::in);
    vector<Bien> bienes;
    vector<string> valores(8);
    vector<int> longitudes = { 15, 100, 30, 30, 30, 25, 25, 25 };
    string linea;
    stringstream stream("");

    while (std::getline(archivo, linea)) {
        Bien bien(linea);
        bienes.insert(bienes.end(), bien);
    }

    int c = 0, p = 0, w = interfaz.ancho(), h = interfaz.alto();

    for(Bien bien : bienes) {
        valores = bien._vector();
        
        for(int i = 0; i < valores.size(); i++)
            valores[i].insert(valores[i].begin(), longitudes[i] - valores[i].size(), ' ');

        linea = std::format(
            "{} {} {} {} {} {} {}",
            valores[0],
            w > 263 ? valores[1] : "",
            w >  43 ? valores[2] : "",
            w >  74 ? valores[3] : "",
            w > 105 ? valores[4] : "",
            w > 136 ? valores[5] : "",
            w > 162 ? valores[6] : ""
        );

        interfaz.mover(5 + c, (w / 2) - (linea.size() / 2));
        interfaz.escribir(linea);

        c++;

        if (c == (h - 8)) {
            interfaz.pie(std::format("Mostrando registros {}-{} de {}", p + 1, p + c, bienes.size()));

            interfaz.caracter();
            p += c;
            c = 0;
            interfaz.limpiar();
        }
    }

    interfaz.pie(std::format("Mostrando registros {}-{} de {}", p + 1, p + c, bienes.size()));

    interfaz.caracter();
}