# ChukutoInventory

Pronto será un programa de inventario.

## Requisitos

- Compilador de C++
- CMake

## Instalación

Se clona el repositorio, y dentro de la carpeta del proyecto se ejecuta CMake. Esto solo se realiza una vez.

```sh
git clone git@github.com:achgee/ChukutoInventory.git
cd ChukutoInventory
cmake .
```

## Construcción

Para constuir el proyecto después de modificar el código fuente, solo es necesario ejecutar un comando.

```sh
make
```

El comando crea un archivo ejecutable dentro de la carpeta `bin/`

## Uso

Se entra a la carpeta donde se encuentra el ejecutable y se ejecuta el programa

```sh
cd bin/
./ChukutoInventory
```

Mostrará un menú con las distintas opciones que debe tener el programa de inventario. Al seleccionar una opción correcta, se mostrará el mensaje **Opción no implementada**. De lo contrario, se mostrará el mensaje **Opción invalida**.

## Problemas

- Al introducir texto en lugar de un número, el programa se vuelve loco.
    - Esto sucede porque se intenta guardar el texto introducido en una variable numérica. Pronto se corregirá, utilizando `cin.get()` en lugar de siempre esperar por una línea.