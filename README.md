# ChukutoInventory

Pronto será un programa de inventario.

## Requisitos

- Compilador que soporte C++20
    - GCC y Clang soportan C++20 parcialmente
    - MSVC soporta C++20 en su totalidad
- CMake
- Ncurses (_en caso de compilar en Linux_)

## Instalación

Se clona el repositorio, y dentro de la carpeta del proyecto se ejecuta CMake. Esto solo se realiza una vez.

```sh
git clone git@github.com:achgee/ChukutoInventory.git
cd ChukutoInventory
mkdir build
cd build
cmake ..
```

## Construcción

Para constuir el proyecto después de modificar el código fuente, solo es necesario ejecutar un comando.

```sh
# Dentro de la carpeta ChukutoInventory/build
cmake --build .
```

El comando crea un archivo ejecutable dentro de la carpeta `build/bin/`. Dependiendo del entorno, éste puede crear carpetas adicionales.

## Uso

El programa se ejecuta desde la consola.

```sh
# Dentro de la carpeta ChukutoInventory/build
bin/ChukutoInventory
```

Mostrará un menú con las distintas opciones que debe tener el programa de inventario. Al seleccionar una opción correcta, se mostrará el mensaje **Opción no implementada**. De lo contrario, se mostrará el mensaje **Opción invalida**.

## Problemas

- Al ejecutar el programa en Android con Termux, ocurre un error de memoria (**segfault**)