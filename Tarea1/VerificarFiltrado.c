#include "usmqp.h"

int VerificarFiltrado(char * fileName, char * nume, int maxSize){ //Retorna 1 si fue filtrado, retorna 0 en caso contrario
    FILE *arch = fopen(fileName, "r");
    char * number = malloc(maxSize);
    int flag = 0;
    while(fscanf(arch, "%[^\n]%*c", number) != EOF){
        if(strcmp(number, nume) == 0){
            printf("\n\nEl numero se ha filtrado\n\n");
            flag = 1; //Retorna 1 si se ha filtrado el numero
        }
    }
    fclose(arch);
    free(number);
    return flag;
}