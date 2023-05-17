#include "usmqp.h"

void AddLista(Ventana ** End, mensaje * dato, int index){
    Ventana * nuevo = malloc(sizeof(Ventana));
    nuevo -> chat = dato;
    nuevo -> indice = index;
    nuevo -> previo = (*End);
    nuevo -> sgte = NULL;
    (*End) = nuevo;
}

int ConstruirLista(Ventana ** Head, Ventana ** End, mensaje * top){
    mensaje * recorredor = top;
    Ventana * actual = malloc(sizeof(Ventana));
    int index = 0;
    actual -> chat = (recorredor -> contenido); // Se agrega el primer elemento a la lista de ventana
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

