#include "usmqp.h"

int main(int argc, char **argv){ // Al llamar a main debo ingresar el archivo de usuarios y después el de la conversación
    int opcion = 0;
    mensaje * cabezaMensaje = NULL;
    Ventana * Head = NULL;
    Ventana * End = NULL;

    printf("\n\n>>>>Bienvenido al programa de Farándula USMQP!<<<< \n\n"); 
    cabezaMensaje = LeerArchivo(argv[1], argv[2]);
    printf("\n\nDireccion Pila Mensajes: %p\n\n", cabezaMensaje);
    ImprimirPila(cabezaMensaje);
    //int SizeLista = ConstruirLista(&Head, &End, cabezaMensaje);
    //printf("\n\nSize Lista: %d\n\n", SizeLista);

    while(opcion < 6){
        printf("\n\t(1) Imprimir mensajes. \n\t(2) Verificar posición en la conversación. \n\t(3) Scroll Up. \n\t(4) Scroll Down. \n\t(5) Buscar mensaje. \n\t(6) Salir\n");
        printf("\nIngrese opción: ");
        scanf("%d", &opcion);

        if(opcion == 1){
            //ImprimirMensajes();
        }   
    }
    
    //VaciarLista(&Head, SizeLista);
    return 0;
}