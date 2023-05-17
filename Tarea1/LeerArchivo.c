#include "usmqp.h"

//Se encarga de leer los archivos, y asignar la información a donde corresponda

mensaje * LeerArchivo( char *FileName, char * FileName2){ //Funcion encargada de leer los archivos correspondientes
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
    free(number);

    rewind(archUser);

    char *contenido = malloc((2 * largoMaxMsg * sizeof(char))+ 1); //Reserva la cantidad de memoria que puede usar contenido
    free(msg);

    rewind(archMsg); 

    char date[11];
    char hora[9];
    char name[25];
    char num[largoMaxNum + 1];
    char texto[largoMaxMsg + 1];
    int flag = 0;

    contacto * headContact = NULL;
    contacto * aux = NULL;
    mensaje * headMsg = NULL;

    while(fscanf(archMsg, "%[^\n]%*c", contenido) != EOF){ //Lee el chat filtrado linea a linea
        sscanf(contenido, "[%[^' '] %[^]] %*c%*c%[^+]  %[^:] %*c%[^\n]]", date, hora, name, num, texto); //Extrae la información de cada mensaje filtrado
        
        if(VerificarFiltrado(FileName, num, largoMaxNum) == 1){ //Caso en que el número sí se filtró.
            if(flag == 0){ //Caso en que no se ha creado ningun contacto.
                FirstContact(&headContact, num, name);
                flag = 1;
            } else{
                if(SearchContact == NULL){ //Caso en que el contacto no ha sido agregado.
                    AddContact(headContact, num, name);
                } else{ //Caso en que el contacto ya se ha creado
                    aux = SearchContact(headContact, num);
                    PushChat(&headMsg, aux, date, hora, texto);
                }
            }
        }                
    }

    free(contenido);
    fclose(archUser);
    fclose(archMsg);
    Clear(headContact);
    return headMsg;
}