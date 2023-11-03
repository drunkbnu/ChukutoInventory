#include <format>
#include <fstream>
#include <string>
#include "Programa.hpp"
#include "clases/Bien.hpp"

using std::fstream;
using std::getline;
using std::string;

void crear() {
    interfaz.establecerCabecera("Creación de Registro");

    fstream archivo("registros.txt", std::ios::in);
    int num_registro = 1;
    string linea;

    while (getline(archivo, linea)) {
        num_registro++;
    }

    archivo.close();

    interfaz.establecerPie(std::format("Creando registro #{}", num_registro));
    interfaz.limpiarContenido();
    
    vector<string> campos = {
        "# Bien: ",
        "Departamento: ",
        "Marca: ",
        "Modelo: "
    };

    interfaz.mostrarFormulario(campos);

    vector<string> valores(4);
    vector<int> longitudes = {
        10, 50, 20, 20
    };
    
    for (int i = 0; i < valores.size(); i++) {
        interfaz.mover(i + 5, interfaz.obtenerAncho() / 2);

        if (valores[i] != "") {
            interfaz.escribir(valores[i]);
            continue;
        }

        string valor = interfaz.leerLinea(longitudes[i]);

        if (valor.find('|') < valor.size()) {
            interfaz.mostrarPopup("El texto no puede contener el caracter |");
            interfaz.limpiarContenido();
            interfaz.mostrarFormulario(campos);
            i = -1;
            continue;
        }

        valores[i] = valor;
    }

    archivo.open("registros.txt", std::ios::app);

    if (!archivo.is_open()) {
        interfaz.mostrarPopup("No se pudo abrir el archivo de registros");
        return;
    }

    Bien bien(valores[0], valores[1], valores[2], valores[3]);

    archivo << bien.generarTexto() << std::endl;
    archivo.close();

    interfaz.mostrarPopup("Registro creado satisfactoriamente");
}