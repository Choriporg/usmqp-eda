#include "usmqp.h"

void AddLista(Ventana ** End, mensaje * dato, int index){
    Ventana * nuevo = malloc(sizeof(Ventana));
    nuevo -> chat = dato;
    nuevo -> indice = index;
    nuevo -> previo = (*End);
    nuevo -> sgte = NULL;
    (*End) = nuevo;
}

void Refresh(){
    int i;
    for(i = 0; i < 40; i++){
        printf("\n");
    }
}

int ConstruirLista(Ventana ** Head, Ventana ** End, mensaje * top){
    //Esta lista se contruye en orden: más reciente a más viejo
    mensaje * recorredor = top;
    Ventana * actual = malloc(sizeof(Ventana));
    int index = 0;
    actual -> chat = recorredor; // Se agrega el primer elemento a la lista de ventana
    actual -> indice = index;
    actual -> previo = NULL;
    actual -> sgte = NULL;
    *Head = actual;
    *End = actual;
    recorredor = recorredor -> sgte;

    while(recorredor -> sgte != NULL){
        index ++;
        AddLista(End, recorredor, index);
        recorredor = recorredor -> sgte;
    }
    return index;
}

int VerificarPosicion(int index, Ventana * inicio, Ventana * fin){
    if(index == inicio -> indice){//Retorna -1 si se encuentra en el inicio de la conversación
        return -1;
    } else if(index == fin -> indice){//Retorna 1 si se encuentra al final de la conversación
        return 1;
    } else{//Retorna 0 si se encuentra en medio de la conversacion
        return 0;
    }
}

int ImprimirVentana(Ventana * Head, Ventana * end, int index, int orden){ //Imprime en pantalla el chat filtrado, retorna el indice del ultimo nodo impreso
    Ventana * recorredor = Head;
    int cont;
    while(recorredor -> indice < index){//Posiciona el puntero recorredor en el primer nodo que se desea imprimir
        recorredor -> sgte;
    }
    if(orden == 0){ //Scroll Up
        for(cont = 0; cont < 9; cont++){
            //Extrae la informacion para imprimirla
            char * fecha = strcpy(fecha, recorredor -> chat -> fecha);
            char * hora = strcpy(hora, recorredor -> chat ->hora);
            char * usuario = strcpy(usuario, recorredor -> chat -> emisor ->nombre);
            char * fono = strcpy(fono, recorredor -> chat -> emisor -> telefono);
            char * msg = strcpy(msg, recorredor -> chat -> contenido);
            printf("\n[%s %s] %s %s: %s\n",fecha, hora, usuario, fono, msg);
            
            //Revisa si se puede seguir avanzando en la conversación
            if(VerificarPosicion(recorredor -> indice, Head, end) == 0){ //Caso en que no se ha impreso el ultimo mensaje
                recorredor = recorredor -> sgte;
            }else{//Caso en que el mensaje que se acaba de imprimir sea el último
                cont = 9;
            }
        }
    } else{ //Scroll Down
        for(cont = 0; cont < 9; cont++){
            //Extrae la informacion para imprimirla
            char * fecha = strcpy(fecha, recorredor -> chat -> fecha);
            char * hora = strcpy(hora, recorredor -> chat ->hora);
            char * usuario = strcpy(usuario, recorredor -> chat -> emisor ->nombre);
            char *fono = strcpy(fono, recorredor -> chat -> emisor -> telefono);
            char * msg = strcpy(msg, recorredor -> chat -> contenido);
            printf("\n[%s %s] %s %s: %s\n",fecha, hora, usuario, fono, msg); 
        
            //Revisa si se puede seguir avanzando en la conversación
            if(VerificarPosicion(recorredor -> indice, Head, end) == 0){ //Caso en que no se ha impreso el ultimo mensaje
                recorredor = recorredor -> previo;
            }else{//Caso en que el mensaje que se acaba de imprimir sea el último
                cont = 9;
            }
        }
    }
    return recorredor -> indice;
}
