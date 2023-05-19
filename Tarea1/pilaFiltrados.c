#include "usmqp.h"

//Agregar numero a la pila

void PushFiltrados(filtrados ** top, char * nume){
    filtrados * nuevo = malloc(sizeof(filtrados));
    nuevo -> num = malloc(sizeof(nume) +1);
    strcpy(nuevo ->num, nume);
    nuevo -> previo = *top;
    *top = nuevo;
    }

//Eliminar primer elemento de la pila

void PopFiltrados(filtrados ** top){
    filtrados * sicario = *top;
    *top = (*top) -> previo;
    free(sicario);
}
void PeakFiltrados(filtrados * top){
    printf("\n\ntop: %s\n\n", top -> num);
}

void ClearFiltrados(filtrados ** top){
    filtrados * sicario = *top;
    filtrados * victima = NULL;
    while(sicario){
        victima = sicario -> previo;
        free(sicario);
        sicario = victima;
    }
}

//Función Encargada de verificar si el numero fue filtrado.
int VerificarFiltrado(filtrados * top, char * nume){ //Retorna 1 si fue filtrado, retorna 0 en caso contrario
    int flag = 0;
    filtrados * recorredor = top;

    while(recorredor != NULL){
        if(strcmp(recorredor ->num, nume) == 0){ //El numeró sí se filtró
            flag = 1;
        }
        recorredor = recorredor -> previo;
    }

    return flag;
}
//FUNCIONA
void ImprimirFiltrados(filtrados * top){
    filtrados * recorredor = top;
    while(recorredor){
        printf("\n\nnumero: %s\n\n", recorredor -> num);
        recorredor = recorredor -> previo;

    }
}