#include "usmqp.h"

int main(int argc, char **argv){ // Al llamar a main debo ingresar el archivo de usuarios y después el de la conversación
    int opcion = 0;
    printf(">>>>Bienvenido al programa de Farándula USMQP!<<<< \n\n");
    while(opcion < 6){
        printf("\t(1) Imprimir mensajes. \n\t(2) Verificar posición en la conversación. \n\t(3) Scroll Up. \n\t(4) Scroll Down. \n\t(5) Buscar mensaje. \n\t(6) Salir\n");
        printf("Ingrese opción: ");
        scanf("%d", &opcion);
        if(opcion == 1){
            //ImprimirMensajes();
        }   
    }
    
    LeerArchivo(argv[1], argv[2]);
    return 0;
}