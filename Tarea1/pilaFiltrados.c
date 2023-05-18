#include "usmqp.h"

//Agregar numero a la pila

void PushFiltrados(filtrados * top, char * nume){
    filtrados * nuevo = malloc(sizeof(filtrados));
    strcpy(nuevo ->num, nume);
    nuevo -> previo = top;
    top = nuevo;
}

//Eliminar primer elemento de la pila

void PopFiltrados(filtrados * top){
    filtrados * sicario = top;
    top = sicario -> previo;
    free(sicario);
}

void ClearFiltrados(filtrados * top){
    while(top){
        PopChat(top);
    }
    free(top);
}

//Función Encargada de verificar si el numero fue filtrado.

int VerificarFiltrado(filtrados * top, char * nume){ //Retorna 1 si fue filtrado, retorna 0 en caso contrario
    int flag = 0;
    filtrados * recorredor = top;

    while(recorredor != NULL && flag == 0){
        if(strcmp(recorredor ->num, nume) == 0){
            flag = 1;
        }
        recorredor = recorredor -> previo;
    }

    return flag;
}