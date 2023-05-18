#include "usmqp.h"

void PushChat(mensaje ** end, contacto * remitente, char * date, char * hour, char * msg){
    mensaje * nuevo = malloc(sizeof(mensaje));
    strcpy(nuevo -> fecha, date);   
    strcpy(nuevo -> hora, hour);
    nuevo -> emisor = remitente;
    nuevo -> sgte = *end;
    *end = nuevo;    
}

void PopChat(mensaje ** end){
    mensaje * sicario = *end;
    *end = sicario -> sgte;
    free(sicario);
}

mensaje * PeekChat(mensaje * end){
    return (end);
}

void VaciarPilaChat(mensaje ** end){
    while((*end) -> sgte != NULL){
        PopChat(end);
    }
    PopChat(end);
}

void ImprimirPila(mensaje * end){
    mensaje * recorredor = end;
    if(recorredor -> sgte == NULL){
        printf("\n\nNo está enlazado\n");
    }else{
        printf("\n\nDirección sgte: %p\n\n", recorredor -> sgte);
    }
    while(recorredor){
        printf("\n\nDireccion remitente: %p\n\n",recorredor -> emisor);
        printf("\n\nFecha: %s\n\n",recorredor -> fecha);
        printf("\n\nHora: %s\n\n", recorredor -> hora);
        printf("\n\nNombre Emisor: %s\n\n",  recorredor -> emisor ->nombre);
        printf("\n\nNumero Emisor: %s\n\n", recorredor -> emisor -> telefono);
        printf("\n\nMensaje: %s\n\n", recorredor -> contenido);
        recorredor = recorredor -> sgte;
    }
}
