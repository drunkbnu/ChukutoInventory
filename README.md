# ChukutoInventory

Programa en C++ que lee un archivo de texto, guarda los datos en un objeto e imprime uno de los datos.

Pronto será un programa de inventario.

## Requisitos

- Compilador de C++ que soporte C++20
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

Es necesario crear la carpeta `data/` en la carpeta donde se encuentra el ejecutable, y dentro de la carpeta `data/` un archivo de texto con al menos 4 líneas llamado `1.txt` para probar la lectura.

No arrojará un error, simplemente no imprime nada si no existe dicho archivo.