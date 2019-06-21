#include "prototipoListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>


void create (struct Lista *lista) {
    lista->inicio = NULL;
}

void inserirNoInicio (struct Lista *lista, int elemento) {
    struct Caixinha *nova;
    nova = (struct Caixinha *)(malloc(sizeof(struct Caixinha)));
    if (nova == NULL) {
        puts("Falta memória");
        exit(1);
    } else {
        nova->elemento = elemento;
        nova->proximo = lista->inicio;
        lista->inicio = nova;
    }
}

void inserirNoFinal (struct Lista *lista, int elemento) {
    struct Caixinha *nova;
    struct Caixinha *aux;
    nova = (struct Caixinha *)(malloc(sizeof(struct Caixinha)));
    nova->elemento = elemento;
    nova->proximo = NULL;
    //está vazia?
    if (lista->inicio == NULL) {
        lista->inicio = nova;
    } else {
        aux = lista->inicio;
        while (aux->proximo != NULL) { //percorre a lista até elemento que o prox dele aponta para null
            aux = aux->proximo;
        }
        aux->proximo = nova; //ao chegar no elemento que o proximo é null, esse proximo deixa de apontar pra null e aponta para o novo elemento
    }
}

int isEmpty (struct Lista *lista) {
    return (lista->inicio == NULL);
}

int retirarInicio (struct Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista já esta vazia\n");
        exit(1);
    } else {
        struct Caixinha *aux = lista->inicio;
        int elemento = aux->elemento;
        lista->inicio = aux->proximo; 
        free(aux);
        aux = NULL;
        return elemento;
    }
}

int retirarFinal (struct Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista já esta vazia\n");
        exit(1);
    } else {
        struct Caixinha *aux, *proxAnterior;
        aux = lista->inicio;
        while (aux->proximo != NULL) {
            proxAnterior = aux;
            aux = aux->proximo;
        }
        proxAnterior->proximo = NULL;
        free(aux) ;
    }
}

void buscar (struct Lista *lista, int valor) {
    if (isEmpty(lista)) {
        puts("Não há o que buscar");
        exit(1);
    } else {
        struct Caixinha *aux = lista->inicio;
        int achou = 0;
        do {
            if (aux->elemento == valor) achou = 1;
            else aux = aux->proximo;
        } while ((aux->proximo != NULL) && (achou == 0));
        if (achou == 1) puts("Valor encontrado na lista");
        else puts("Valor não encontrado na lista");
    }
}

void listar (struct Lista lista) {
    if (lista.inicio == NULL) {
        printf("Não há o que remover\n");
        exit(1);
    } else {
        struct Caixinha *aux = lista.inicio;
        while (aux != NULL) {
            printf("%d ", aux->elemento);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

void limpar (struct Lista *lista) {
    struct Caixinha *aux = lista->inicio, *anterior;
    aux = lista->inicio;
    anterior = NULL;
    while (aux->proximo != NULL) {
        anterior = aux;
        aux = aux->proximo;
        free(anterior);
    }
    lista->inicio = NULL;
}
