#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Programa.hpp"
#include "clases/Bien.hpp"

using std::fstream;
using std::pair;
using std::string;
using std::stringstream;

void actualizar() {
    interfaz.cabecera("Actualización de Registro");
    interfaz.pie("");
    interfaz.limpiar();

    fstream archivo("bienes.txt", std::ios::in),
        auxiliar("bienes.aux.txt", std::ios::out);
    vector<Bien> bienes;
    string linea, nro;
    bool encontrado = false;

    if (!auxiliar.is_open()) {
        interfaz.popup("No se pudo abrir el archivo auxiliar");
        return;
    }

    while (std::getline(archivo, linea)) {
        Bien bien(linea);
        bienes.insert(bienes.end(), bien);
    }

    archivo.close();

    interfaz.formulario({ "# Bien: " });

    interfaz.mover(5, interfaz.ancho() / 2);
    nro = interfaz.leerLinea(15);

    for (Bien &bien : bienes) {
        if (bien.nro() == nro && !encontrado) {
            encontrado = true;

            vector<string> valores, opciones = {
                "1. Ver datos",
                "2. Modificar departamento",
                "3. Modificar marca",
                "4. Modificar modelo",
                "5. Volver"
            }, campos = {
                "# Bien: ",
                "Departamento: ",
                "Marca: ",
                "Modelo: ",
                "Fecha incorp.: ",
                "Fecha modif.: ",
                "Fecha desinc.: "
            };

            int opcion;
            stringstream stream;
            string texto;

            interfaz.menu(opciones);

            while (opcion != 5) {
                interfaz.cabecera("Registro encontrado");
                interfaz.pie("");
                interfaz.limpiar();
                interfaz.menu(opciones);

                texto = interfaz.leerLinea(1);
                stream << texto;
                stream >> opcion;
                stream.clear();
                stream.str(texto);

                switch (opcion) {
                    case 1:
                        valores = bien._vector();

                        interfaz.cabecera("Datos del registro");
                        interfaz.pie("Presione cualquier tecla para volver al menú de actualización");
                        interfaz.limpiar();
                        interfaz.formulario(campos);

                        for (int i = 0; i < valores.size(); i++) {
                            interfaz.mover(i + 5, interfaz.ancho() / 2);
                            interfaz.escribir(valores[i]);
                        }

                        interfaz.caracter();
                        break;
                    case 2:
                        interfaz.cabecera("Modificando departamento");
                        interfaz.limpiar();
                        interfaz.formulario({ "Departamento: " });
                        interfaz.mover(5, interfaz.ancho() / 2);
                        bien.dpto(interfaz.leerLinea(15));
                        break;
                    case 3:
                        interfaz.cabecera("Modificando marca");
                        interfaz.limpiar();
                        interfaz.formulario({ "Marca: " });
                        interfaz.mover(5, interfaz.ancho() / 2);
                        bien.marca(interfaz.leerLinea(15));
                        break;
                    case 4:
                        interfaz.cabecera("Modificando modelo");
                        interfaz.limpiar();
                        interfaz.formulario({ "Modelo: " });
                        interfaz.mover(5, interfaz.ancho() / 2);
                        bien.modelo(interfaz.leerLinea(15));
                        break;
                    case 5:
                        break;
                    default:
                        interfaz.popup("Opción inválida");
                        break;
                }
            }
        }

        auxiliar << bien.texto() << std::endl;
    }

    auxiliar.close();

    std::rename("bienes.txt", "bienes.bak.txt");
    std::rename("bienes.aux.txt", "bienes.txt");
    std::remove("bienes.bak.txt");

    if (!encontrado)
        interfaz.popup("No se encontró ningún registro");
}