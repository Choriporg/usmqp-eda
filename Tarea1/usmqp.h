#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Lista usuarios
typedef struct user{
    char * telefono; // String: número de teléfono del usuario
    char * nombre; // String: nombre del usario
    struct user * sgte; // puntero: siguiente
} contacto;

//Implementación Contactos
void FirstContact(contacto ** HeadUser, char * phone, char * name);
void AddContact(contacto * HeadUser, char * phone, char * name);
void Clear(contacto * asesinoSerial);
contacto * SearchContact(contacto * HeadUser, char * fonoBusqueda);
void DeleteContact(contacto ** HeadUser, char * nombreEliminado);
void imprimirContactos(contacto * HeadUser);

//Lista Conversación
typedef struct WazaaaApp{
    char * fecha; // String: fecha del mensaje
    char * hora; // String: hora del mensaje
    contacto * emisor; // puntero a emisor del mensaje
    char * contenido; // String: contenido del mensaje
    struct WazaaaApp * sgte; // puntero: siguiente
} mensaje;

//Implementación Mensajes
void FirstMessage(mensaje ** headChat, contacto * remitente, char * date, char * hour, char * msg);
void AddMessage(mensaje * headChat, contacto * remitente, char * date, char * hour, char * msg);
void ClearMessage(mensaje * asesinoSerial);

//Pila Filtrados
typedef struct pilaF{
    char * fono;
    struct pilaF * previo;
} filtrados;

//Implementacion Filtrados
void PushFiltrados(filtrados ** end, char * phone);
void PopFiltrados(filtrados ** end);
void VaciarFiltrados(filtrados ** end);

//Lectura del Archivo
void LeerArchivo(char * FileName1, char * FileName2);
// int VerificarFiltrado(filtrados * end, char * nume);

