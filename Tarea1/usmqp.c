#include "usmqp.h"

//Usuario

int FirstContact(contacto ** HeadUser, char * phone, char * name){
    contacto * nuevo = malloc(sizeof(contacto));
    *HeadUser = nuevo;
    nuevo->telefono = phone;
    nuevo -> nombre = name;   
    nuevo -> sgte = NULL; 
    int contactLen = 1;

    return contactLen;
}

void AddContact(contacto * HeadUser, char * phone, char * name){
    contacto * nuevo = malloc(sizeof(contacto));
    contacto * recorredor = HeadUser;
    while(recorredor -> sgte != NULL){
        recorredor = recorredor -> sgte;
    }
    nuevo -> telefono = phone;
    nuevo -> nombre = name;
    nuevo -> sgte = NULL;
    recorredor -> sgte = nuevo;
}