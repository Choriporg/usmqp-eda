#include "usmqp.h"

void PushFiltrados(filtrados ** end, char * phone){ //Añade a la lista de numeros filtrados cada numero filtrado
    filtrados * nuevo = malloc(sizeof(filtrados));
    nuevo -> fono = phone;
    nuevo -> previo = *end;
    *end = nuevo;
}

int VerificarFiltrado(filtrados * end, char *nume){ //Retorna 1 si fue filtrado, retorna 0 en caso contrario
    filtrados * recorredor = end;
    int flag = 0;
    while(recorredor -> previo != NULL && flag == 0){
        if (strcmp(recorredor -> fono, nume) != 0){
            flag = 1; //Valor que retornará la función si el contacto si fue filtrado
        }
        recorredor = recorredor -> previo;
    }
    return flag;
}

void VaciarFiltrados(filtrados ** end){ //Una vez que se termina de usar la pila, esta función liberará el espacio
    filtrados * asesinoSerial = *end;
    while((*end) -> previo != NULL){
        (*end) = asesinoSerial -> previo;
        free(asesinoSerial);
    }
}
