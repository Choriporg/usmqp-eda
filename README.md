# Tarea 1 ELO-320: Estructura de datos y algoritmos - USMQP

Este repositorio contiene la implementación en C de un visor de conversaciones para la asignatura ELO-320 de la Universidad Técnica Federico Santa María.

## Estructura del repositorio
- `Tarea1/`: código fuente del programa junto a archivos de ejemplo y un Makefile para la compilación.

## Dependencias
- [GCC](https://gcc.gnu.org/) o cualquier compilador de C compatible.
- [Make](https://www.gnu.org/software/make/).

## Compilación
Dentro del directorio `Tarea1` ejecutar:

```bash
make
```

Este comando genera el ejecutable `TAREA1`.

## Ejecución
Una vez compilado, el programa se ejecuta con:

```bash
./TAREA1 <archivo_usuarios> <archivo_conversacion>
```

- `<archivo_usuarios>`: archivo con la lista de contactos.
- `<archivo_conversacion>`: archivo con los mensajes filtrados de la conversación.

Los archivos de entrada deben tener el mismo formato que los ejemplos incluidos en el repositorio.

## Funcionalidades principales
El programa permite:
- Leer archivos de usuarios y mensajes.
- Crear una lista de contactos utilizando una TDA.
- Guardar los mensajes asociados a cada contacto.
- Buscar mensajes específicos.
- Mostrar una ventana de diez mensajes por consola con desplazamiento.
- Eliminar contactos.

## Estado del proyecto
Completado.
