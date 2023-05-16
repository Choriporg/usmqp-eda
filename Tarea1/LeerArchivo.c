#include "usmqp.h"

void LeerArchivo( char *FileName, char * FileName2){ //Funcion encargada de leer los archivos correspondientes
    FILE *archUser = NULL; //Archivo usuarios
    FILE *archMsg = NULL; //Archivo conversación
    archUser = fopen(FileName, "r");
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
    rewind(archUser);

    filtrados * endFiltrados = NULL;

    while(fscanf(archUser, "%[^\n]%*c", number) != EOF){ //Agrega a la pila cada numero filtrado
        PushFiltrados(&endFiltrados, number);
        printf("\n\n Recien agregado: %s\n\n", endFiltrados ->fono);
    }

//ESTE BUCLE FUNCIONA PERFECTAMENTE

    char *contenido = malloc((2 * largoMaxMsg * sizeof(char))+ 1); //Reserva la cantidad de memoria que puede usar contenido
    free(msg);

    rewind(archMsg); 

    char date[11];
    char hora[9];
    char name[25];
    char num[largoMaxNum];
    char texto[largoMaxMsg];
    int flag = 0;

    contacto * headContact = NULL;
    mensaje * headMsg = NULL;

    while(fscanf(archMsg, "%[^\n]%*c", contenido) != EOF){ //Lee el chat filtrado linea a linea
        sscanf(contenido, "[%[^' '] %[^]] %*c%*c%[^+]  %[^:] %*c%[^\n]]", date, hora, name, num, texto); //Extrae la información de cada mensaje filtrado
        printf("\n Resultado Verificar: %d\n", VerificarFiltrado(endFiltrados, num));
        
        if(VerificarFiltrado(endFiltrados, num) == 1){ //Verifica si el numero está dentro de la lista de filtrados.
            
    }
    free(contenido);
    free(number);
    fclose(archUser);
    fclose(archMsg);
    Clear(headContact);
}