#include "usmqp.h"

void PushChat(pilaChat ** end, mensaje * filtracion){
    pilaChat * nuevo = malloc(sizeof(pilaChat));
    nuevo -> filtrado = filtracion;   
    nuevo -> previo = *end;
    *end = nuevo;    
}

void PopChat(pilaChat ** end){
    pilaChat * sicario = *end;
    *end = sicario -> previo;
    free(sicario);
}

pilaChat * PeekChat(pilaChat * end){
    pilaChat * primerElem = end;
    return (primerElem);
}

void VaciarPilaChat(pilaChat ** end){
    while((*end) -> previo != NULL){
        PopChat(end);
    }
}