#include "prototipoFila.h"
#include <stdio.h>
#include <stdlib.h>


int main () {

    FilaArquivos f;
    inicializar(&f);

    inserir(&f, "tcc", 4);
    inserir(&f, "fichamento", 4);
    inserir(&f, "resumo", 4);
    listar(&f);
    return 0;
}