CC=gcc
FLAGS= -Wall -O3

TAREA1: main.o LeerArchivo.o pila.o contactos.o ventana.o pilaFiltrados.o
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.c
	$(CC) -c $^ $(FLAGS)

LeerArchivo.o: LeerArchivo.c
	$(CC) -c $^ $(FLAGS)

pila.o: pila.c
	$(CC) -c $^ $(FLAGS)

contactos.o: contactos.c
	$(CC) -c $^ $(FLAGS)

ventana.o: ventana.c
	$(CC) -c $^ $(FLAGS)

pilaFiltrados.o: pilaFiltrados.c
	$(CC) -c $^ $(FLAGS)

main.o: usmqp.h
LeerArchivo.o: usmqp.h
pila.o: usmqp.h
contactos.o: usmqp.h
ventana.o: usmqp.h
pilaFiltrados.o: usmqp.h


