#include "usmqp.h"

void PushFiltrados(filtrados ** end, char * phone){
    filtrados * nuevo = malloc(sizeof(filtrados));
    nuevo -> fono = phone;
    nuevo -> previo = *end;
    *end = nuevo;
}
