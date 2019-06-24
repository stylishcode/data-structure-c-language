#include "prototipoDeque.h"
#include <stdio.h>


int main () {

    Deque d;
    inicializar(&d);

    inserir(&d, "nome", 21, "cargo");
    inserir(&d, "nome", 19, "cargo");
    inserir(&d, "nome", 19, "cargo");
    listar(&d);
    return 0;
}