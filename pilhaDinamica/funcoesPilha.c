#include <stdlib.h>
#include <stdio.h>
#include "prototipoPilha.h"


void create (Pilha *pilha) {
    pilha->topo = NULL;
}

void push (Pilha* pilha, int valor) {
    No *novo = (No *)(malloc(sizeof(No*)));
    novo->dado = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int pop (Pilha *pilha) {
    if (isEmpty(pilha)) {
        puts("Não há o que remover");
        exit(1); }
    int valor;
    No *aux = pilha->topo;
    pilha->topo = aux->proximo;
    valor = aux->dado;
    free(aux);
    return valor;
}

int isEmpty (Pilha *pilha) {
    return (pilha->topo == NULL);
}