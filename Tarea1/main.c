#include "usmqp.h"

int main(int argc, char **argv){ // Al llamar a main debo ingresar el archivo de usuarios y después el de la conversación
    printf("%d\n", argc);
    printf("\n%s\n%s\n",argv[1], argv[2]);
    LeerArchivo(argv[1], argv[2]);
    return 0;
}