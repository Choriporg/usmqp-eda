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
int VerificarExistencia(contacto * HeadUser, char * fono);
void DeleteContact(contacto ** HeadUser, char * nombreEliminado);
void ImprimirContactos(contacto * head);
contacto * SearchContact(contacto * head, char * nume);

//PILA FILTRADOS

typedef struct filtrados{
    char * num;
    struct filtrados * previo;
} filtrados;

//Implementación Filtrados

void PushFiltrados(filtrados ** top, char * nume);
void PopFiltrados(filtrados ** top);
void ClearFiltrados(filtrados **     top);
int VerificarFiltrado(filtrados * top, char * nume);
void ImprimirFiltrados(filtrados * top);
void PeakFiltrados(filtrados * top);

//Pila Conversación
typedef struct WazaaaApp{
    char * fecha; // String: fecha del mensaje
    char * hora; // String: hora del mensaje
    contacto * emisor; // puntero a emisor del mensaje
    char * contenido; // String: contenido del mensaje
    struct WazaaaApp * sgte; // puntero: siguiente
} mensaje;

//Implementación Mensajes
void PushChat(mensaje ** end, contacto * remitente, char * date, char * hour, char * msg);
void PopChat(mensaje ** end);
mensaje * PeekChat(mensaje * end);
void VaciarPilaChat(mensaje ** asesinoSerial);
void ImprimirPila(mensaje * end);

//Lectura del Archivo
mensaje * LeerArchivo(char * FileName1, char * FileName2);


//Ventana
typedef struct ventana{
    mensaje * chat;
    int indice;
    struct ventana * previo;
    struct ventana * sgte;
}Ventana;

//Implementación Ventana

int ConstruirLista(Ventana ** Head, Ventana ** End, mensaje * top);
void AddLista(Ventana **End, mensaje * dato, int index);
//void VaciarLista(Ventana ** Head, int MaxIndex);