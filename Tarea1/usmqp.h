#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user{
    char * telefono; // String: número de teléfono del usuario
    char * nombre; // String: nombre del usario
    struct user * sgte; // puntero: siguiente
} contacto;

typedef struct WazaaaApp{
    char * fecha; // String: fecha del mensaje
    char * hora; // String: hora del mensaje
    contacto * emisor; // puntero a emisor del mensaje
    char * contenido; // String: contenido del mensaje
    struct WazaaaApp * sgte; // puntero: siguiente
} mensaje;

//Implementación Contactos

int FirstContact(contacto ** HeadUser, char * phone, char * name);
int AddContact(contacto * HeadUser, char * phone, char * name, int Len);
int Clear(contacto ** HeadUser);
contacto SearchContact(contacto * HeadUser, char * nombreBusqueda);
int DeleteContact(contacto ** HeadUser, char * nombreEliminado, int Len);

//Implementación Mensajes
