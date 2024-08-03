# Get Next Line

## Descripción

El proyecto "Get Next Line" tiene como objetivo implementar una función en C que permita leer una línea desde un file descriptor. Esta función es esencial para manejar la lectura de archivos y la entrada estándar de manera eficiente y práctica, agregando una herramienta útil a cualquier colección de utilidades en C.

## Funcionalidades

- Lectura de línea por línea: La función `get_next_line` permite leer el contenido de un archivo línea por línea, mejorando la gestión de la entrada de datos.
- Soporte para múltiples file descriptors: La versión mejorada (bonus) puede gestionar múltiples file descriptors simultáneamente, manteniendo el hilo de lectura de cada uno.
- Tamaño de buffer configurable: La función puede ser compilada con un tamaño de buffer definido por el usuario, optimizando el rendimiento según las necesidades específicas de la aplicación.

## Uso

### Función Principal

- Nombre de la función: `get_next_line`
- Prototipo: `char *get_next_line(int fd);`
- Parámetros: 
  - `fd`: File descriptor desde el cual se leerá la línea.
- Valor de retorno:
  - Devuelve la línea leída si la operación es exitosa.
  - Devuelve `NULL` en caso de error o si no hay más líneas por leer.

### Compilación

Para compilar el proyecto, utiliza el siguiente comando:

cc -Wall -Werror -Wextra -D BUFFER_SIZE=<tamaño> <archivos>.c

Por ejemplo, para compilar con un tamaño de buffer de 42:

cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line

### Archivos

- Parte obligatoria:
  - `get_next_line.c`
  - `get_next_line_utils.c`
  - `get_next_line.h`
- Parte bonus:
  - `get_next_line_bonus.c`
  - `get_next_line_bonus.h`
  - `get_next_line_utils_bonus.c`

### Notas Relevantes

- La función está diseñada para manejar adecuadamente la memoria asignada, liberándola cuando sea necesario para evitar fugas de memoria.
- La función no utiliza funciones como `lseek` ni variables globales, garantizando un comportamiento más predecible y seguro.
- La implementación es compatible tanto con archivos normales como con la entrada estándar (`stdin`).

### Bonus

- Implementación con una sola variable estática para mejorar la eficiencia y la gestión de recursos.
- Capacidad para gestionar múltiples file descriptors simultáneamente, permitiendo leer de varios archivos o entradas de manera alternada sin perder el estado de cada lectura.

---
