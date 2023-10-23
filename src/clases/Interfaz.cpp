#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include "Interfaz.hpp"

using std::cin;
using std::cout;
using std::string;

struct winsize tamaño;

// Funciones para establecer y obtener la cabecera y el pie
// Se crearon para evitar modificación directa de las variables

void Interfaz::establecerCabecera(string cabecera) {
    this->cabecera = cabecera;

    mostrarCabecera();
}

void Interfaz::establecerPie(string pie) {
    this->pie = pie;

    mostrarPie();
}

string Interfaz::obtenerCabecera() {
    return cabecera;
}

string Interfaz::obtenerPie() {
    return pie;
}

// Constructor
// Se limpia la pantalla, se guarda el tamaño de la consola y se muestra la cabecera y el pie

Interfaz::Interfaz(string cabecera, string pie) {
    this->cabecera = cabecera;
    this->pie = pie;

    system("clear");

    // Función para obtener el tamaño de la consola en Linux
    ioctl(fileno(stdout), TIOCGWINSZ, &tamaño);

    mostrarCabecera();
    mostrarPie();
}

// Funciones para mostrar la cabecera y el pie sin alterar el resto de la pantalla
// Se utilizan códigos ANSI para cambiar la posición del cursor, y el color del texto y el fondo

void Interfaz::mostrarCabecera() {
    cout << "\x1b[1;1f\x1b[1;7m" << string(tamaño.ws_col * 3, ' ') << "\x1b[2;" << tamaño.ws_col / 2 - cabecera.length() / 2 << "f"
        << cabecera << "\x1b[0m";
}

void Interfaz::mostrarPie() {
    cout << "\x1b[" << tamaño.ws_row - 2 << ";1f\x1b[1;7m" << string(tamaño.ws_col * 3, ' ') << "\x1b[" << tamaño.ws_row - 1 << ";"
        << tamaño.ws_col / 2 - pie.length() / 2 << "f" << pie << "\x1b[0m";
}

// Funciones para mostrar distinto contenido, sin alterar el resto de la pantalla

void Interfaz::limpiarContenido() {
    cout << "\x1b[4;1f" << string(tamaño.ws_col * (tamaño.ws_row - 6), ' ');
}

void Interfaz::mostrarMenu(vector<string> opciones) {
    // Primero se obtiene la longitud de la opción mas larga, para así centrar el menú

    int longitud = 0, y = 5;

    for(string opcion : opciones) {
        if (longitud < opcion.size()) {
            longitud = opcion.size();
        }
    }

    // Ahora si se muestran las opciones

    for(string opcion : opciones) {
        cout << "\x1b[" << y << ";" << tamaño.ws_col / 2 - longitud / 2 << "f" << opcion;

        y++;
    }

    cout << "\x1b[" << ++y << ";" << tamaño.ws_col / 2 - longitud / 2 << "f" << "Opción: ";
}

void Interfaz::mostrarPopup(string mensaje) {
    int longitud = mensaje.size();

    cout << "\x1b[1;7m";

    for (int y = -1; y < 2; y++) {
        cout << "\x1b[" << tamaño.ws_row / 2 + y << ";" << tamaño.ws_col / 2 - longitud / 2 << "f" << string(longitud + 2, ' ');
    }

    cout << "\x1b[" << tamaño.ws_row / 2 << ";" << tamaño.ws_col / 2 - longitud / 2 + 1 << "f" << mensaje << "\x1b[0m";

    // Por alguna razón el primer uso de la función detecta Enter
    // Se llama dos veces para asegurar que el usuario presione una tecla

    cin.get();
    cin.get();
}