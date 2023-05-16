#include "usmqp.h"

//Interfaz Usuario

void FirstContact(contacto ** HeadUser, char * phone, char * name){ //Crea el primer contacto de la lista
    contacto * nuevo = malloc(sizeof(contacto));
    *HeadUser = nuevo;
    nuevo->telefono = phone;
    nuevo -> nombre = name;   
    nuevo -> sgte = NULL; 
}

void AddContact(contacto * HeadUser, char * phone, char * name){ //Añade un contacto a la ista
    contacto * nuevo = malloc(sizeof(contacto));
    contacto * recorredor = HeadUser;
    while(recorredor -> sgte != NULL){
        recorredor = recorredor -> sgte;
    }
    nuevo -> telefono = phone;
    nuevo -> nombre = name;
    nuevo -> sgte = NULL;
    recorredor -> sgte = nuevo; 
}

contacto * SearchContact(contacto * HeadUser, char * fonoBusqueda){ //Busca un contacto en la lista
    contacto * recorredor = HeadUser;
    int flag = 0;
    while (recorredor && flag == 0){ // Si llega al final de la lista de contactos,  o encuentra al contacto se terminará el bucle
        if(strcmp(recorredor -> telefono, fonoBusqueda) != 0){
            recorredor = recorredor -> sgte;
        }else if(strcmp(recorredor -> telefono, fonoBusqueda) == 0){ //Encuentra al contacto
                flag = 1;
        }
    }  

    if(flag == 0){
        return NULL;
    } else{
        return recorredor;
    }
}

void DeleteContact(contacto ** HeadUser, char * nombreEliminado){ //Elimina un contacto de la lista
    contacto * sicario = *HeadUser; //Ubicará al nodo que se va a
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

void Clear(contacto * asesinoSerial){ //Elimina todos los contactos de forma recursiva
    if(asesinoSerial != NULL){
        Clear(asesinoSerial -> sgte); //Esta parte de la función hará que se llame a si misma hasta que se llegue al extremo y se irá vaciando desde el último nodo hacia atrás
        free(asesinoSerial);
    }
}
