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

void eliminar() {
    interfaz.cabecera("Eliminación de Registro");
    interfaz.pie("");
    interfaz.limpiar();

    fstream archivo("bienes.txt", std::ios::in),
        auxiliar("bienes.aux.txt", std::ios::out),
        cementerio("cementerio.txt", std::ios::app);
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
                "2. Eliminar registro",
                "3. Volver"
            }, campos = {
                "# Bien: ",
                "Departamento: ",
                "Usuario: ",
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

            while (opcion != 3) {
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
                        interfaz.pie("Presione cualquier tecla para volver al menú de eliminación");
                        interfaz.limpiar();
                        interfaz.formulario(campos);

                        for (int i = 0; i < valores.size(); i++) {
                            interfaz.mover(i + 5, interfaz.ancho() / 2);
                            interfaz.escribir(valores[i]);
                        }

                        interfaz.caracter();
                        break;
                    case 2:
                        interfaz.cabecera("¿Está seguro de que desea eliminar éste registro?");
                        interfaz.limpiar();
                        interfaz.menu({ "1. Continuar", "2. Volver" });

                        texto = interfaz.leerLinea(1);
                        stream << texto;
                        stream >> opcion;
                        stream.clear();
                        stream.str(texto);

                        if (opcion == 1) {
                            bien.desincorporar();
                            interfaz.popup("Registro eliminado del listado principal");
                            opcion = 3;
                        }
                        break;
                    case 3:
                        break;
                    default:
                        interfaz.popup("Opción inválida");
                        break;
                }
            }
        }

        if (bien.fechaDesinc() == "-")
            auxiliar << bien.texto() << std::endl;
        else
            cementerio << bien.texto() << std::endl;
    }

    auxiliar.close();
    cementerio.close();

    std::rename("bienes.txt", "bienes.bak.txt");
    std::rename("bienes.aux.txt", "bienes.txt");
    std::remove("bienes.bak.txt");

    if (!encontrado)
        interfaz.popup("No se encontró ningún registro");
}