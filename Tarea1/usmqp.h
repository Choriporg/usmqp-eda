#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Lista usuarios
typedef struct user{
    char * telefono; // String: número de teléfono del usuario
    char * nombre; // String: nombre del usario
    struct user * sgte; // puntero: siguiente
} contacto;


//Lista Conversación
typedef struct WazaaaApp{
    char * fecha; // String: fecha del mensaje
    char * hora; // String: hora del mensaje
    contacto * emisor; // puntero a emisor del mensaje
    char * contenido; // String: contenido del mensaje
    struct WazaaaApp * sgte; // puntero: siguiente
} mensaje;

//Pila Conversación
/*typedef struct pila{
    mensaje -> fecha;
    mensaje -> hora;
    mensaje -> emisor;


}
*/
//Implementación Contactos

void FirstContact(contacto ** HeadUser, char * phone, char * name);
void AddContact(contacto * HeadUser, char * phone, char * name);
void Clear(contacto ** HeadUser);
int SearchContact(contacto * HeadUser, char * fonoBusqueda);
void DeleteContact(contacto ** HeadUser, char * nombreEliminado);
//Lectura del Archivo
void LeerArchivo(char * FileName1, char * FileName2, contacto ** headUser, mensaje ** headChat);
//Implementación Mensajes