#include "LeerArchivo.h"

void LeerArchivo( char *FileName, char * FileName2){ //Funcion encargada de leer los archivos correspondientes
    FILE *archUser = NULL; //Archivo usuarios
    FILE *archMsg = NULL; //Archivo conversación
    archUser = fopen(FileName, "r");  // apunta al fichero y lo abre en modo lectura
    archMsg= fopen(FileName2, "r");
    int largoMaxMsg = 0;
    int largoMaxNum = 0;
    char * number = malloc(1024 * sizeof(char));
    char * msg = malloc(1024 * sizeof(char)); 

    while(fscanf(archMsg, "%[^\n]%*c", msg) != EOF){ //Obtener el largo del mensaje más largo
        if(strlen(msg) > largoMaxMsg){
            largoMaxMsg = strlen(msg);
        }
    }   

    while(fscanf(archUser, "%[^\n]%*c", number) != EOF ){
        if(strlen(number) > largoMaxNum){
            largoMaxNum = strlen(number);
        }
    }
   number = realloc(number, largoMaxNum * sizeof(char));
//ESTE BUCLE FUNCIONA PERFECTAMENTE

    char *contenido = malloc((2 * largoMaxMsg * sizeof(char))+ 1); //Reserva la cantidad de memoria que puede usar contenido
    free(msg);
    rewind(archUser);
    rewind(archMsg); 

    while(fscanf(archMsg, "%[^\n]%*c", contenido) != EOF){ //Lee el chat filtrado linea a linea
        char date[11];
        char hora[9];
        char name[25];
        char num[largoMaxNum];
        char texto[largoMaxMsg];
        
        sscanf(contenido, "[%[^' '] %[^]] %*c%*c%[^+]  %[^:] %*c%[^\n]]", date, hora, name, num, texto); //Extrae la información de cada mensaje filtrado
        //Ya extrae bien la información
        printf("\n\n Fecha: %s\n\n", date);
        printf("\n\n Hora: %s\n\n", hora);
        printf("\n\n Nombre: %s\n\n", name);
        printf("\n\n Número: %s\n\n", num);
        printf("\n\n Mensaje: %s\n\n", texto);
    }
    free(contenido);
    free(number);
    fclose(archUser);
    fclose(archMsg);
}
//NO HAY FUGA DE MEMORIA :D
int main(){
    LeerArchivo("users.wzp", "shatira-pike-2023.wzp");

    return 0;
}
