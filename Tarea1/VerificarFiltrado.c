#include "usmqp.h"

//Función Encargada de verificar si el numero fue filtrado.

int VerificarFiltrado(char * fileName, char * nume, int maxSize){ //Retorna 1 si fue filtrado, retorna 0 en caso contrario
    FILE *arch = fopen(fileName, "r");
    char * number = malloc(maxSize + 1);
    int flag = 0;
    while(fscanf(arch, "%[^\n]%*c", number) != EOF){
        if(strcmp(number, nume) == 0){
            flag = 1; //Retorna 1 si se ha filtrado el numero
        }
    }
    fclose(arch);
    free(number);
    return flag;
}