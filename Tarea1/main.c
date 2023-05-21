#include "usmqp.h"

int main(int argc, char **argv){ // Al llamar a main debo ingresar el archivo de usuarios y después el de la conversación
    int opcion = 0;
    mensaje * cabezaMensaje = NULL;
    Ventana * Head = NULL;
    Ventana * End = NULL;

    printf("\n\n>>>>Bienvenido al programa de Farándula USMQP!<<<<\n\n"); 
    cabezaMensaje = LeerArchivo(argv[1], argv[2]);
    contacto * cabeza = cabezaMensaje -> emisor;
    ConstruirLista(&Head, &End, cabezaMensaje);
    Ventana * posicion = End;
    int cont;

    while(opcion < 6){
        printf("\n\t(1) Imprimir mensajes. \n\t(2) Verificar posición en la conversación. \n\t(3) Scroll Up. \n\t(4) Scroll Down. \n\t(5) Buscar mensaje. \n\t(6) Salir\n");
        printf("\nIngrese opción: ");
        scanf("%d", &opcion);

        if(opcion == 1){//Imprime los mensajes
            posicion = ImprimirVentana(posicion);

        } else if(opcion == 2){
            if(VerificarPosicion(posicion, Head,End) == -1){
                printf("\nSe encuentra al inicio de la conversación.\n");
            }else if(VerificarPosicion(posicion, Head,End) == 0){
                printf("\nSe encuentra en medio de la conversación.\n");
            }else{
                printf("\nSe encuentra al final de la conversación\n");
            }
        } else if(opcion == 3){//Scroll Up
            for(cont = 0; cont < 3; cont++){
                posicion = posicion -> sgte;
            }
            Refresh();
            ImprimirVentana(posicion);
        }else if(opcion == 4){//Scroll Down
            for(cont = 0; cont < 3; cont++){
                posicion = posicion -> previo;
            }
            Refresh();
            ImprimirVentana(posicion);
        }else if(opcion == 5){ //Buscar mensaje por una palabra
            Refresh();
            char * palabra = malloc( 20 * sizeof(char));
            printf("\nIngrese la palabra que desea buscar: ");
            scanf("%s", palabra);
            Ventana * resultado = SearchMsg(Head, palabra);
            if(resultado != NULL){
                printf("\nCoincidencia: %s\n", resultado -> chat -> contenido);
            } else{
                printf("\nNo hay coincidencias\n");
            }
            free(palabra);

        }
    }
    Clear(&cabeza);
    VaciarPilaChat(&cabezaMensaje);
    VaciarVentana(&End);

    return 0;
}