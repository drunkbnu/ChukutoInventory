#include <sstream>
#include <string>
#include <vector>
#include "clases/Interfaz.hpp"
#include "Programa.hpp"

using std::string;
using std::stringstream;
using std::vector;

Interfaz interfaz("ChukutoInventory - Menú Principal", "(C) 2023 achgee");

int opcion;

int main(int argc, char const *argv[]) {
    vector<string> opciones = {
        "1. Crear registro",
        "2. Listar registros",
        "3. Buscar registro",
        "4. Actualizar registro",
        "5. Eliminar registro",
        "6. Salir"
    };

    string vacio = string();
    stringstream stream(vacio);

    while(opcion != 6) {
        interfaz.establecerCabecera("ChukutoInventory - Menú Principal");
        interfaz.establecerPie("(C) 2023 achgee");
        interfaz.limpiarContenido();
        interfaz.mostrarMenu(opciones);

        stream << interfaz.leerLinea();
        stream >> opcion;
        stream.clear();
        stream.str(vacio);

        switch (opcion) {
            case 1:
                crear();
                break;
            case 2:
                listar();
                break;
            case 3:
                buscar();
                break;
            case 4:
                actualizar();
                break;
            case 5:
                eliminar();
                break;
            case 6:
                break;
            default:
                interfaz.mostrarPopup("Opción inválida");
                break;
        }
    }

    interfaz.cerrar();

    return 0;
}