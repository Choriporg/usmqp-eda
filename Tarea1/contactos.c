#include "usmqp.h"

//Interfaz Usuario

void FirstContact(contacto ** HeadUser, char * phone, char * name){ //Crea el primer contacto de la lista
    contacto * nuevo = malloc(sizeof(contacto));
    nuevo -> telefono= malloc(sizeof(phone) +1);
    nuevo -> nombre = malloc(sizeof(name) + 1);
    *HeadUser = nuevo;
    strcpy(nuevo->telefono, phone);
    strcpy(nuevo -> nombre, name);   
    nuevo -> sgte = NULL; 
}

void AddContact(contacto * HeadUser, char * phone, char * name){ //Añade un contacto al final la ista
    contacto * nuevo = malloc(sizeof(contacto));
    nuevo -> nombre = malloc(sizeof(name) +1);
    nuevo -> telefono = malloc(sizeof(phone) +1);

    contacto * recorredor = HeadUser;
    while(recorredor -> sgte != NULL){
        recorredor = recorredor -> sgte;
    }
    strcpy(nuevo -> telefono, phone);
    strcpy(nuevo -> nombre, name);
    nuevo -> sgte = NULL;
    recorredor -> sgte = nuevo; 
}

int VerificarExistencia(contacto * HeadUser, char * fono){
    contacto * recorredor = HeadUser;
    int flag = 0;
    while (recorredor != NULL && flag == 0){ // Si llega al final de la lista de contactos,  o encuentra al contacto se terminará el bucle
        if(strcmp(recorredor -> telefono, fono) == 0){ //Encuentra al contacto
            flag = 1;
        }
        recorredor = recorredor -> sgte;
    }  

    return flag;
}

contacto * SearchContact(contacto * head, char * nume){
    contacto * recorredor = head;
    while(strcmp(recorredor ->telefono, nume) != 0){
        recorredor = recorredor -> sgte;
    }
    return recorredor;
}

void DeleteContact(contacto ** HeadUser, char * nombreEliminado){ //Elimina un contacto de la lista
    contacto * sicario = *HeadUser; //Ubicará al nodo que se va a elimnar
    contacto * testigo = *HeadUser; //Ubicará al contacto previo al que va a eliminar sicario. (Por algo es testigo)
    int lugarAsesinato = 0;

    if(strcmp(nombreEliminado, (*HeadUser) -> nombre) == 0){ //Caso donde el contacto que se elimina es el primero de la lista
        *HeadUser = (*HeadUser) -> sgte;
        free(sicario);  
    }

    while(strcmp(sicario -> nombre, nombreEliminado) != 0){ //Se ubica al contacto que se va a eliminar
        sicario = sicario -> sgte;
        lugarAsesinato ++; 
    }
    int j;
    
    for(j = 0; j < lugarAsesinato -1; j++){ //Se ubica al contacto previo (testigo) al que se va a eliminar
        testigo = testigo -> sgte;
    }

    testigo -> sgte = sicario -> sgte;
    free(sicario);
}

void Clear(contacto * Head){ //Elimina todos los contactos de forma recursiva
    if(Head){
        Clear(Head -> sgte);
        free(Head);
    }
}

void ImprimirContactos(contacto * head){
    contacto * recorredor = head;
    while(recorredor != NULL){
        printf("\n\nnumero: %s\n\n", recorredor -> telefono);
        printf("\n\nNombre: %s\n\n", recorredor -> nombre);
        recorredor = recorredor -> sgte;
    }
}
