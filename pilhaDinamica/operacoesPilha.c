#include "prototipoPilha.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int valor, resto;
    Pilha p;
    create(&p);

    printf("Digite um valor: ");
    scanf("%d", &valor);

    while (valor !=0) {
        resto = valor % 2;
        push(&p, resto);
        valor = valor / 2;
    }

    while (!isEmpty(&p)) {
        resto = pop(&p);
        printf("%d ", resto);
    }
    printf("\n");

    return 0;
}