#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* obtiene largo del numero de telefono*/
int main(){
    FILE * archivo = fopen("users.wzp", "r");
    char * fono = malloc(30 * sizeof(char));
    int maxSize = 0;
    char * stringPro = malloc(sizeof(fono));
    while(fscanf(archivo, "%[^\n]%*c", fono) != EOF){
        if(strlen(fono) > maxSize){
            maxSize = strlen(fono);
            stringPro = realloc(stringPro, maxSize * sizeof(char));
            stringPro = fono;
        }
    }
    printf("%s\n", stringPro);
    printf("%d\n", maxSize);
    fclose(archivo);
    free(fono);
    free(stringPro);
    return 0;
}