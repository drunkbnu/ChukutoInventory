#include <sstream>
#include <string>
#include <vector>
#include "Programa.hpp"

using std::string;
using std::stringstream;
using std::vector;

Interfaz interfaz("ChukutoInventory - Menú Principal", "(C) 2023-2024 drunkbnu");

int main(int argc, char const *argv[]) {
    vector<string> opciones = {
        "1. Crear registro",
        "2. Listar registros",
        "3. Buscar registro",
        "4. Actualizar registro",
        "5. Eliminar registro",
        "6. Salir"
    };
    int opcion;
    stringstream stream;
    string texto;

    while(opcion != 6) {
        interfaz.cabecera("ChukutoInventory - Menú Principal");
        interfaz.pie("(C) 2023-2024 drunkbnu");
        interfaz.limpiar();
        interfaz.menu(opciones);

        texto = interfaz.leerLinea(1);
        stream << texto;
        stream >> opcion;
        stream.clear();
        stream.str(texto);

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
                interfaz.popup("Opción inválida");
                break;
        }
    }

    interfaz.cerrar();

    return 0;
}