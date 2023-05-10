#include "usmqp.h"

void LeerArchivo( char *FileName, char * FileName2, contacto ** headUser, mensaje ** headChat){ //Funcion encargada de leer los archivos correspondientes
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

    char date[11];
    char hora[9];
    char name[25];
    char num[largoMaxNum];
    char texto[largoMaxMsg];
    int flag = 0;
    contacto * headContact = *headUser;

    while(fscanf(archMsg, "%[^\n]%*c", contenido) != EOF){ //Lee el chat filtrado linea a linea
        sscanf(contenido, "[%[^' '] %[^]] %*c%*c%[^+]  %[^:] %*c%[^\n]]", date, hora, name, num, texto); //Extrae la información de cada mensaje filtrado
        
        if(flag == 0){ //Bandera que se utiliza para saber si ya se creó el primer contacto en la lista
            FirstContact(headUser, num, name);
            flag = 1;
        }
        
        if(SearchContact(headContact, num) == 1){
            AddContact(headContact, num, name);
        
        }



    }
    free(contenido);
    free(number);
    fclose(archUser);
    fclose(archMsg);
}
//NO HAY FUGA DE MEMORIA :D
/*
int main(){
    LeerArchivo("users.wzp", "shatira-pike-2023.wzp");

    return 0;
}
*/