#include <iostream>
#include "clases/Bien.hpp"

using std::string;

int main(int argc, char const *argv[]) {
    string ruta = "data/1.txt";

    Bien bien = Bien::desde_archivo(ruta);

    std::cout << bien.nro_bien << std::endl;
    return 0;
}