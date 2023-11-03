#include <format>
#include <locale>
#include <string>
#ifdef UNIX
#include <ncurses.h>
#else
#include <iostream>
#include <Windows.h>
#endif
#include "Interfaz.hpp"

using std::string;

// Funciones para obtener el tamaño de la consola, sin acceder directamente a las variables

int Interfaz::obtenerAncho() {
    return ancho;
}

int Interfaz::obtenerAlto() {
    return alto;
}

// Funciones para manejar la consola
// Siempre se usan estas funciones, ya que dependen del sistema operativo

void Interfaz::mover(int y, int x) {
    #ifdef UNIX
    move(--y, --x);
    refresh();
    #else
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;
    dwPos.X = --x;  
    dwPos.Y = --y;  
    SetConsoleCursorPosition(hcon, dwPos);  
    #endif
}

void Interfaz::escribir(const char *texto) {
    #ifdef UNIX
    addstr(texto);
    refresh();
    #else
    std::cout << texto;
    #endif
}

void Interfaz::escribir(string texto) {
    #ifdef UNIX
    addstr(texto.c_str());
    refresh();
    #else
    std::cout << texto;
    #endif
}

string Interfaz::leerLinea(int caracteres) {
    #ifdef UNIX
    char texto[caracteres];
    getnstr(texto, caracteres);
    return string(texto);
    #else
    string texto;
    std::cin.getline(texto, caracteres);
    return texto;
    #endif
}

// Pronto será una función para utilizar cualquier combinación de colores, no solo alternar entre blanco y negro

void Interfaz::alternarColores() {
    this->invertido = !this->invertido;

    #ifdef UNIX
    if (this->invertido) {
        attron(COLOR_PAIR(1));
    } else {
        attroff(COLOR_PAIR(1));
    }
    refresh();
    #else
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, this->invertido ? 112 : 7);
    #endif
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

    #ifdef UNIX
    WINDOW *ventana = initscr();
    keypad(ventana, true);
    curs_set(1);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    getmaxyx(ventana, alto, ancho);
    #else
    system("cls");
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    alto = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    SetConsoleTextAttribute(hConsole, 119);
    #endif

    setlocale(LC_ALL, ".UTF-8");

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

void Interfaz::mostrarFormulario(vector<string> campos) {
    int y = 5;

    for(string campo : campos) {
        mover(y, ancho / 2 - campo.size());
        escribir(campo);

        y++;
    }
}

void Interfaz::mostrarPopup(string mensaje) {
    int longitud = mensaje.size();

    alternarColores();

    for (int y = -1; y < 2; y++) {
        mover(alto / 2 + y, ancho / 2 - longitud / 2 - 1);
        escribir(string(longitud + 2, ' '));
    }

    mover(alto / 2, ancho / 2 - longitud / 2);
    escribir(mensaje);
    alternarColores();
    
    std::getchar();
}

void Interfaz::cerrar() {
    #ifdef UNIX
    endwin();
    #else
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    system("cls");
    #endif
}