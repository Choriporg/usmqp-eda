#include "usmqp.h"

//Interfaz Usuario

int FirstContact(contacto ** HeadUser, char * phone, char * name){ //Crea el primer contacto de la lista
    contacto * nuevo = malloc(sizeof(contacto));
    *HeadUser = nuevo;
    nuevo->telefono = phone;
    nuevo -> nombre = name;   
    nuevo -> sgte = NULL; 
    int contactLen = 1;
    return contactLen;
}

int AddContact(contacto * HeadUser, char * phone, char * name, int Len){ //Añade un contacto a la ista
    contacto * nuevo = malloc(sizeof(contacto));
    contacto * recorredor = HeadUser;
    while(recorredor -> sgte != NULL){
        recorredor = recorredor -> sgte;
    }
    nuevo -> telefono = phone;
    nuevo -> nombre = name;
    nuevo -> sgte = NULL;
    recorredor -> sgte = nuevo;
    int Lengh = Len + 1;
    return Lengh;  
    
}

contacto SearchContact(contacto * HeadUser, char * fonoBusqueda){ //Busca un contacto en la lista
    contacto * recorredor = HeadUser;

    while (strcmp(recorredor -> telefono ,  fonoBusqueda) != 0){
        recorredor = recorredor -> sgte;
    }
    return *recorredor;
}

int DeleteContact(contacto ** HeadUser, char * nombreEliminado, int Len){ //Elimina un contacto de la lista
    contacto * sicario = *HeadUser; //Ubicará al nodo que se va a
    contacto * testigo = *HeadUser; //Ubicará al contacto previo al que va a eliminar sicario. (Por algo es testigo)
    int lugarAsesinato = 0;

    if(strcmp(nombreEliminado, (*HeadUser) -> nombre) == 0){ //Caso donde el contacto que se elimina es el primero de la lista
        *HeadUser = (*HeadUser) -> sgte;
        free(sicario);
        return Len -1;        
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
    return Len -1;
}

int Clear(contacto ** HeadUser){ //Elimina todos los contactos
    contacto * asesinoSerial = *HeadUser;
    while((*HeadUser) != asesinoSerial){
        asesinoSerial = (*HeadUser) -> sgte;
        (*HeadUser) -> sgte = asesinoSerial -> sgte;
        free(asesinoSerial);
    }
    free(HeadUser);
    return  0;
}