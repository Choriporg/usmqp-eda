#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE * archivo = fopen("users.wzp", "r");
    char * fono = malloc(20 * sizeof(char));
    int maxSize = 0;
    while(fscanf(archivo, "[^\n]%*c", fono) != EOF){
        if(strlen(fono) > maxSize){
            maxSize = strlen(fono);
        }
    }
    printf("%d", maxSize);
    return 0;
}