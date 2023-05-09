#include "LeerArchivo.h"

void LeerArchivo( char *FileName, char * FileName2){ //Funcion encargada de leer los archivos correspondientes
    FILE *archUser = NULL; //Archivo usuarios
    FILE *archMsg = NULL; //Archivo conversación
    archUser = fopen(FileName, "r");  // apunta al fichero y lo abre en modo lectura
    archMsg= fopen(FileName2, "r");
    int largoMax = 0;
    char * msg = malloc(1024 * sizeof(char)); 

    while(fscanf(archMsg, "%[^\n]%*c", msg) != EOF){ //Obtener el largo del mensaje más largo
        if(strlen(msg) > largoMax){
            largoMax = strlen(msg);
        }
    }   

//ESTE BUCLE FUNCIONA PERFECTAMENTE

    char *contenido = malloc((2 * largoMax * sizeof(char))+ 1); //Reserva la cantidad de memoria que puede usar contenido
    free(msg);

    rewind(archMsg); 

    while(fscanf(archMsg, "%[^\n]%*c", contenido) != EOF){ //Lee el chat filtrado linea a linea
        char date[11];
        char hora[8];
        char franja[2];
        char name[25];
        
        sscanf(contenido, "%[*c%[^' ']] %[^]]", date, hora); //Problema con horas de dos digitos

        printf("\n\n Fecha: %s\n\n", date);
        printf("\n\n Hora: %s\n\n", hora);

    
            
    }
    


    free(contenido);
    fclose(archUser);
    fclose(archMsg);
}
/*
int main(){
    LeerArchivo("users.wzp", "shatira-pike-2023.wzp");

    return 0;
}
*/