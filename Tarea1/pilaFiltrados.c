#include "usmqp.h"
//Funciona
void PushFiltrados(filtrados ** end, char * phone){ //Añade a la lista de numeros filtrados cada numero filtrado
    filtrados * nuevo = malloc(sizeof(filtrados));
    nuevo -> fono = phone;
    nuevo -> previo = *end;
    *end = nuevo;
}

//Weck

int VerificarFiltrado(filtrados * end, char * nume){ //Retorna 1 si fue filtrado, retorna 0 en caso contrario
    filtrados * recorredor = end;
    int flag = 0;
    while(recorredor){
        if(strcmp(nume, recorredor -> fono) == 0){
            flag = 1;
            printf("El numero se ha filtrado\n");
        }
        recorredor = recorredor -> previo;
    }
    return flag;

}

void PopFiltrados(filtrados ** end){
    printf("DentroFiltrados\n");
    filtrados * sicario = *end;
    *end = sicario -> previo;
    free(sicario);
    printf("\n\nNueva cabeza: %s\n\n", (*end)-> fono);
}
void VaciarFiltrados(filtrados ** end){ //Una vez que se termina de usar la pila, esta función liberará el espacio
    filtrados * recorredor = *end;
    while(recorredor -> previo != NULL){
        filtrados * temp = recorredor;
        recorredor = recorredor -> previo;
        free(temp);
    }
    free(*end);
}