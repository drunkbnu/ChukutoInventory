#include <format>
#include <fstream>
#include <map>
#include <string>
#include "Programa.hpp"
#include "clases/Bien.hpp"

using std::fstream;
using std::map;
using std::string;

void crear() {
    interfaz.cabecera("Creación de Registro");

    fstream archivo("bienes.txt", std::ios::in);
    map<string, Bien> bienes;
    string linea, nro;

    while (std::getline(archivo, linea)) {
        Bien bien(linea);
        bienes.insert(std::make_pair(bien.nro(), bien));
    }

    archivo.close();
    archivo.open("bienes.txt", std::ios::app);

    if (!archivo.is_open()) {
        interfaz.popup("No se pudo abrir el archivo de bienes");
        return;
    }

    interfaz.pie(std::format("Creando registro #{}", bienes.size() + 1));
    interfaz.limpiar();
    
    vector<string> campos = {
        "# Bien: ",
        "Departamento: ",
        "Marca: ",
        "Modelo: "
    };

    interfaz.formulario(campos);

    vector<string> valores(4);
    vector<int> longitudes = {
        10, 50, 20, 20
    };
    
    for (int i = 0; i < valores.size(); i++) {
        interfaz.mover(i + 5, interfaz.ancho() / 2);

        if (valores[i] != "") {
            interfaz.escribir(valores[i]);
            continue;
        }

        string valor = interfaz.leerLinea(longitudes[i]);

        if (i == 0 && bienes.count(valor)) {
            interfaz.popup("Ya existe un registro con el mismo número de bien");
            interfaz.limpiar();
            interfaz.formulario(campos);
            i = -1;
            continue;
        }

        if (valor.find('|') < valor.size()) {
            interfaz.popup("El texto no puede contener el caracter |");
            interfaz.limpiar();
            interfaz.formulario(campos);
            i = -1;
            continue;
        }

        valores[i] = valor;
    }

    Bien bien(valores[0], valores[1], valores[2], valores[3]);

    archivo << bien.texto() << std::endl;
    archivo.close();

    interfaz.popup("Registro creado satisfactoriamente");
}