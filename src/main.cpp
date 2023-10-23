#include <iostream>
#include <string>
#include <vector>
#include "clases/Interfaz.hpp"

using std::cin;
using std::string;
using std::vector;

Interfaz interfaz("ChukutoInventory - Menú Principal", "(C) 2023 achgee");

void crearRegistro();
void listarRegistros();
void buscarRegistro();
void actualizarRegistro();
void eliminarRegistro();
void opcionNoImplementada(string cabecera, string pie);

int main(int argc, char const *argv[]) {
    vector<string> opciones = {
        "1. Crear registro",
        "2. Listar registros",
        "3. Buscar registro",
        "4. Actualizar registro",
        "5. Eliminar registro",
        "6. Salir"
    };

    int opcion = 0;

    while(opcion != 6) {
        interfaz.establecerCabecera("ChukutoInventory - Menú Principal");
        interfaz.establecerPie("(C) 2023 achgee");
        interfaz.limpiarContenido();
        interfaz.mostrarMenu(opciones);

        cin >> opcion;

        switch (opcion) {
            case 1:
                crearRegistro();
                break;
            case 2:
                listarRegistros();
                break;
            case 3:
                buscarRegistro();
                break;
            case 4:
                actualizarRegistro();
                break;
            case 5:
                eliminarRegistro();
                break;
            case 6:
                break;
            default:
                interfaz.mostrarPopup("Opción invalida");
                break;
        }
    }

    system("clear");

    return 0;
}

void crearRegistro() {
    opcionNoImplementada("Creación de Registro", "");
}

void listarRegistros() {
    opcionNoImplementada("Listado de Registros", "");
}

void buscarRegistro() {
    opcionNoImplementada("Busqueda de Registro", "");
}

void actualizarRegistro() {
    opcionNoImplementada("Actualización de Registro", "");
}

void eliminarRegistro() {
    opcionNoImplementada("Eliminación de Registro", "");
}

void opcionNoImplementada(string cabecera, string pie) {
    interfaz.establecerCabecera(cabecera);
    interfaz.establecerPie(pie);
    interfaz.limpiarContenido();
    interfaz.mostrarPopup("Opción no implementada");
}