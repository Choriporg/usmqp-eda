#include "usmqp.h"

Ventana * AddLista(Ventana ** End, Ventana * before, mensaje * dato){//Agrega un nuevo nodo a la lista de mensajes que se van a imprimir.
    Ventana * nuevo = malloc(sizeof(Ventana));
    nuevo -> chat = dato;
    before -> sgte = nuevo;
    nuevo -> previo = before;
    nuevo -> sgte = NULL;
    (*End) = nuevo;
    return nuevo;
}

void Refresh(){
        printf("\033[2J\033[1;1H"); //Secuencia de escape  ANSI para refrescar la pantalla
}

void ConstruirLista(Ventana ** Head, Ventana ** End, mensaje * top){ //Construye la lista doblemente enlazada que se utilizará para la vetaa deslizante
    //Esta lista se contruye en orden: más reciente a más viejo
    mensaje * recorredor = top;
    Ventana * actual = malloc(sizeof(Ventana));
    int index = 0;
    actual -> chat = recorredor; // Se agrega el primer elemento a la lista de ventana
    actual -> previo = NULL;
    actual -> sgte = NULL;
    *Head = actual;
    *End = actual;
    printf("\nActual: %p\n", actual);    
    printf("Primer end: %p", *End);
    while(recorredor){
        index ++;
        actual -> sgte = AddLista(End, actual, recorredor); //Agrega un nuevo nodo a la lista
        actual = actual -> sgte;
        recorredor = recorredor -> sgte;
    }
}

int VerificarPosicion(Ventana * posicion, Ventana * inicio, Ventana * fin){ //Funcion que verificará si se encuentra al final de la conversacion.
    if(posicion == inicio){//Retorna -1 si se encuentra en el inicio de la conversación
        return -1;
    } else if(posicion == fin){//Retorna 1 si se encuentra al final de la conversación
        return 1;
    } else{//Retorna 0 si se encuentra en medio de la conversacion
        return 0;
    }
}

/*
Ventana * SearchMsg(Ventana * Head, char * word){
    Ventana * recorredor = Head;
    int encontrado = 0;
    int contadorCoincidencias = 0;
    while(recorredor != NULL){
        if (strstr(recorredor -> chat -> contenido, word) != NULL){

        }
    }
}
*/
Ventana * ImprimirVentana(Ventana * posicion){//Imprime en pantalla el chat filtrado, retorna el indice del ultimo nodo impreso
    Ventana * recorredor = posicion;
    int cont;
    for(cont = 0; cont < 10 && recorredor != NULL; cont++){
        printf("\n[%s %s] %s %s: %s\n", recorredor -> chat -> fecha, recorredor -> chat -> hora, recorredor -> chat -> emisor -> nombre,
        recorredor -> chat -> emisor -> telefono, recorredor -> chat -> contenido);
        recorredor = recorredor -> previo;
    }
    
    return recorredor;
}
