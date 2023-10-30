#include <format>
#include <fstream>
#include "Programa.hpp"

using std::format;
using std::fstream;
using std::getline;

void crear() {
    interfaz.establecerCabecera("Creación de Registro");

    fstream archivo("registros.txt", std::ios::in);
    int num_registro = 1;
    string linea;

    while (getline(archivo, linea)) {
        num_registro++;
    }

    archivo.close();

    interfaz.establecerPie(format("Creando registro #{}", num_registro));
    interfaz.limpiarContenido();
    
    vector<string> campos = {
        "# Bien: ",
        "Departamento: ",
        "Marca: ",
        "Modelo: "
    };

    interfaz.mostrarFormulario(campos);

    int y = 5;

    vector<string> valores(4);
    vector<int> longitudes = {
        10, 50, 20, 20
    };
    
    for (int i = 0; i < valores.size(); i++) {
        interfaz.mover(y, interfaz.obtenerAncho() / 2);
        valores[i] = interfaz.leerLinea(longitudes[i]);

        y++;
    }

    archivo.open("registros.txt", std::ios::app);

    if (!archivo.is_open()) {
        interfaz.mostrarPopup("No se pudo abrir el archivo de registros");
        return;
    }

    for (int i = 0; i < valores.size(); i++) {
        archivo << valores[i] << "|";
    }

    archivo << std::endl;
    archivo.close();

    interfaz.mostrarPopup("Registro creado satisfactoriamente");
}