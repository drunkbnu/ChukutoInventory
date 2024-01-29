# ChukutoInventory

Un programa de inventario sin futuro.

## Requisitos

- Compilador que soporte C++20
    - GCC y Clang soportan C++20 parcialmente
    - MSVC soporta C++20 en su totalidad
- CMake
- Ncurses (_en caso de compilar en Linux_)

## Instalación

Se clona el repositorio, y dentro de la carpeta del proyecto se crea una carpeta de construcción, en la cual se ejecuta CMake. Esto solo se realiza una vez.

```sh
git clone git@github.com:drunkbnu/ChukutoInventory.git
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

Mostrará un menú con las distintas opciones que debe tener el programa de inventario. Por ahora solo está implementada la opción **Creación de registro**

Al seleccionar una opción del listado no implementada, se mostrará el mensaje **Opción no implementada**. De lo contrario, se mostrará el mensaje **Opción invalida**.

### Creación de registro

En dicho procedimiento, se solicitan 4 datos:

- Número de bien
- Departamento
- Marca
- Modelo

Si alguno de los datos contiene el caracter **|**, se mostrará un mensaje de error, y se debe volver a introducir el dato erróneo. Además, si se intenta introducir un número de bien ya registrado, se devolverá un error.

Después de introducir todos los datos, se guardan los mismos junto con la fecha de creación en el archivo `bienes.txt`

### Listado de registros

Muestra todos los registros. El listado se ajusta al tamaño de la terminal, e incluye paginación.

### Busqueda de registro

Se solicita el número de bien, ya que es un valor único. De encontrarse un bien con dicho número, se mostraran todos los datos del bien, incluyendo las fechas de incorporación, modificación y desincorporación.

### Actualización de registro

Se solicita el número de bien. De encontrarse un bien con dicho número, se mostrará un menú con opciones para ver los datos del bien, o modificar ciertos campos. Al modificar cualquier campo, se agrega la fecha de modificación.

### Eliminacion de registro

Se solicita el número de bien. De encontrarse un bien con dicho número, se mostrará un menú con opciones para ver los datos del bien, o eliminar el registro. De seleccionar la opción de eliminar, no se eliminará por completo. Se guardará en un archivo excluido por el sistema.