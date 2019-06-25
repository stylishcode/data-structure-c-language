#include "prototipo.h"
#include <stdlib.h>
#include <stdio.h>


int main () {
    ArvoreBinaria a;
    inicializar(&a);

    inserir (&a, 4);
    inserir (&a, 6);
    inserir (&a, 2);
    inserir (&a, 3);
    inserir (&a, 1);
    inserir (&a, 7);
    inserir (&a, 5);
    printf("Prefixados: "); exibirNosPrefixados (a); printf("\n");
    printf("Central: "); exibirNosCentral (a); printf("\n");
    printf("Posfixados: "); exibirNosPosfixado(a); printf("\n");
    printf("Pares: "); listarPares(a); printf("\n");
    printf("\n");
    return 0;
}