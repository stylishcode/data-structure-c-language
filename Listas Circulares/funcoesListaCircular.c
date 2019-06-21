#include "prototipoListaCircular.h"
#include <stdio.h>
#include <stdlib.h>


void inicializarLista (ListaCircular *lista) {
    lista->primeiro = NULL;
}

int isEmpty (ListaCircular lista) {
    return (lista.primeiro == NULL);
}

void inserirNoInicio (ListaCircular *lista, int valor) {
    No *novo;
    novo = (No*)(malloc(sizeof(No)));
    novo->dado = valor;
    if (lista->primeiro == NULL) {
        novo->proximo = novo;
    } else {
        novo->proximo = lista->primeiro;
        No *aux = lista->primeiro;
        while (aux->proximo != lista->primeiro) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    lista->primeiro = novo; //aqui o novo elemento passa a ser o primeiro
}

void inserirNoFinal (ListaCircular *lista, int valor) {
    No *novo;
    novo = (No *)(malloc(sizeof(No)));
    novo->dado = valor;
    if (lista->primeiro == NULL) {
        novo->proximo = novo; //proximo dele aponta para ele mesmo
        lista->primeiro = novo;
    } else {
        No *aux = lista->primeiro;
        while (aux->proximo != lista->primeiro) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->proximo = lista->primeiro; //aqui, o novo proximo que é o último elemento, passa a apontar pro primeiro
    }
}

void buscar (ListaCircular *lista, int valor) {
    if (lista->primeiro != NULL) {
        No *aux = lista->primeiro;
        int achou = 0;
        do {
            if (aux->dado == valor) achou = 1;
            else aux = aux->proximo;
        } while ((aux->proximo != lista->primeiro) && (achou == 0));
        if (achou == 1) printf("Valor encontrado!\n");
        else printf("Valor inexistente!\n");
    }
}

int removerInicio (ListaCircular *lista) {
    if (lista->primeiro == NULL) {
        printf("Não há o que remover\n");
        exit(1);
    } else {
        if (lista->primeiro != NULL) {
            if ((lista->primeiro)->proximo == lista->primeiro) {
                No *aux = lista->primeiro;
                free(aux);
                lista->primeiro == NULL;
            } else {
                No *aux = lista->primeiro;
                No *pAux = aux->proximo;
                No *ultimo = NULL;
                while (pAux != aux) {
                    if (pAux->proximo == aux) ultimo = pAux;
                    pAux = pAux->proximo;
                }
                lista->primeiro = aux->proximo;
                ultimo->proximo = lista->primeiro;
                free(aux);            }
        }
    }
}

void removerFinal (ListaCircular *lista) {
    if (lista->primeiro == NULL) {
        printf("Não há o que remover\n");
        exit(1);
    } else {
        if (lista->primeiro != NULL) {
            if ((lista->primeiro)->proximo == lista->primeiro) {
                No *aux = lista->primeiro;
                free(aux);
                lista->primeiro == NULL;
            } else {
                No *aux = lista->primeiro;
                No *anterior = NULL;
                while (aux->proximo != lista->primeiro) {
                    anterior = aux;
                    aux = aux->proximo;
                }
                free(aux);
                anterior->proximo = lista->primeiro; 
            }
        }
    }
}

void limpar (ListaCircular *lista) {
    No *aux = lista->primeiro, *anterior;
    aux = lista->primeiro;
    anterior = NULL;
    do {
        anterior = aux;
        aux = aux->proximo;
        free(anterior);
    } while (aux->proximo != lista->primeiro);
    lista->primeiro = NULL;
}

void listar (ListaCircular *lista) {
    if (lista->primeiro == NULL) {
        printf("Não há o que listar\n");
        exit(1);
    } else {
        No *aux = lista->primeiro;
        do {
            printf("%d ", aux->dado);
            aux = aux->proximo;
        } while (aux != lista->primeiro);
        printf("\n");
    }
}
