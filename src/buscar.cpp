#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Programa.hpp"
#include "clases/Bien.hpp"

using std::fstream;
using std::string;
using std::stringstream;

void buscar() {
    interfaz.cabecera("Busqueda de Registro");
    interfaz.pie("");
    interfaz.limpiar();

    fstream archivo("bienes.txt", std::ios::in);
    vector<Bien> bienes;
    string linea, nro;
    bool encontrado = false;

    while (std::getline(archivo, linea)) {
        Bien bien(linea);
        bienes.insert(bienes.end(), bien);
    }

    archivo.close();

    interfaz.formulario({ "# Bien: "});

    interfaz.mover(5, interfaz.ancho() / 2);
    nro = interfaz.leerLinea(15);

    for (Bien &bien : bienes) {
        if (bien.nro() == nro && !encontrado) {
            encontrado = true;

            vector<string> valores = bien._vector();

            interfaz.cabecera("Registro encontrado");
            interfaz.pie("Presione cualquier tecla para volver al menú principal");
            interfaz.limpiar();

            vector<string> campos = {
                "# Bien: ",
                "Departamento: ",
                "Marca: ",
                "Modelo: ",
                "Fecha incorp.: ",
                "Fecha modif.: ",
                "Fecha desinc.: "
            };

            interfaz.formulario(campos);

            for (int i = 0; i < valores.size(); i++) {
                interfaz.mover(i + 5, interfaz.ancho() / 2);
                interfaz.escribir(valores[i]);
            }

            interfaz.caracter();
        }
    }

    if (!encontrado)
        interfaz.popup("No se encontró ningún registro");
}