#include <format>
#include <string>
#if PLATFORM == Linux
#include <ncurses.h>
#elif PLATFORM == Windows
// TODO: Determinar que librería usar en Windows para manejar la consola
#endif
#include "Interfaz.hpp"

using std::string;

#if PLATFORM == Linux
WINDOW ventana;
#endif

// Funciones para manejar la consola
// Siempre se usan estas funciones, ya que dependen del sistema operativo

void Interfaz::mover(int y, int x) {
    #if PLATFORM == Linux
    move(--y, --x);
    refresh();
    #elif PLATFORM == Windows
    // TODO
    #endif
}

void Interfaz::escribir(const char *texto) {
    #if PLATFORM == Linux
    addstr(texto);
    refresh();
    #elif PLATFORM == Windows
    // TODO
    #endif
}

void Interfaz::escribir(string texto) {
    #if PLATFORM == Linux
    addstr(texto.c_str());
    refresh();
    #elif PLATFORM == Windows
    // TODO
    #endif
}

string Interfaz::leerLinea() {
    char *texto;
    getstr(texto);
    return string(texto);
}

// Pronto será una función para utilizar cualquier combinación de colores, no solo alternar entre blanco y negro

void Interfaz::alternarColores() {
    if (this->invertido) {
        #if PLATFORM == Linux
        attroff(COLOR_PAIR(2));
        refresh();
        #elif PLATFORM == Windows
        // TODO
        #endif
    } else {
        #if PLATFORM == Linux
        attron(COLOR_PAIR(2));
        refresh();
        #elif PLATFORM == Windows
        // TODO
        #endif
    }

    this->invertido = !this->invertido;
}

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

    #if PLATFORM == Linux
    ventana = *initscr();
    curs_set(1);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    getmaxyx(&ventana, alto, ancho);
    #elif PLATFORM == Windows
    system("cls");
    ancho = 80;
    alto = 24;
    #endif

    mostrarCabecera();
    mostrarPie();
}

// Funciones para mostrar la cabecera y el pie sin alterar el resto de la pantalla
// Se utilizan códigos ANSI para cambiar la posición del cursor, y el color del texto y el fondo

void Interfaz::mostrarCabecera() {
    alternarColores();
    mover(1, 1);
    escribir(string(ancho * 3, ' '));
    escribir("        ");
    mover(2, ancho / 2 - cabecera.length() / 2);
    escribir(cabecera);
    alternarColores();
}

void Interfaz::mostrarPie() {
    alternarColores();
    mover(alto - 2, 1);
    escribir(string(ancho * 3, ' '));
    mover(alto - 1, ancho / 2 - pie.length() / 2);
    escribir(pie);
    alternarColores();
}

// Funciones para mostrar distinto contenido, sin alterar el resto de la pantalla
// Deben usar las funciones genéricas especificadas arriba

void Interfaz::limpiarContenido() {
    mover(4, 1);
    escribir(string(ancho * (alto - 6), ' '));
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
        mover(y, ancho / 2 - longitud / 2);
        escribir(opcion);

        y++;
    }

    mover(++y, ancho / 2 - longitud / 2);
    escribir("Opción: ");
}

void Interfaz::mostrarPopup(string mensaje) {
    int longitud = mensaje.size();

    alternarColores();

    for (int y = -1; y < 2; y++) {
        mover(alto / 2 + y, ancho / 2 - longitud / 2);
        escribir(string(longitud + 2, ' '));
    }

    mover(alto / 2, ancho / 2 - longitud / 2 + 1);
    escribir(mensaje);
    alternarColores();
    
    getchar();
}

void Interfaz::cerrar() {
    #if PLATFORM == Linux
    endwin();
    #elif PLATFORM == Windows
    system("cls");
    #endif
}