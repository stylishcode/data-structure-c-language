#include "prototipoListaDupla.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista (ListaDupla *lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

int isEmpty (ListaDupla *lista) {
    return (lista->primeiro == NULL);
}

void inserirNoInicio (ListaDupla *lista, int valor) {
    No *novo;
    novo = (No *)(malloc(sizeof(No)));
    if (novo == NULL) {
        printf("Falta de memória");
        exit(1); }
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    if (isEmpty(lista)) //se lista vazia
        lista->primeiro = novo;
    else {
        (lista->primeiro)->anterior = novo;
        novo->proximo = lista->primeiro;
    }
    lista->primeiro = novo;
}

void inserirNoFinal (ListaDupla *lista, int valor) {
    No *novo;
    novo = (No *)(malloc(sizeof(No)));
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    if (isEmpty(lista)) //se lista vazia
        lista->primeiro = novo;
    else {
        (lista->ultimo)->proximo = novo;
         novo->anterior = lista->ultimo;
    }
    lista->ultimo = novo;
}

int removerFinal (ListaDupla *lista) {
    if (isEmpty(lista)) {
        puts("Não há o que remover!");
        exit(1); }
    if ((lista->primeiro)->proximo == NULL) { //único elemento
        No *aux = lista->ultimo;
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        free(aux);
    } else {
        No *aux = lista->ultimo;
        No *penultimo = lista->ultimo->anterior;
        penultimo->proximo = NULL;
        lista->ultimo = penultimo;
        free(aux);
    }
}

void buscar (ListaDupla *lista, int valor) {
    if (isEmpty(lista)) {
        puts("Não há o que buscar!");
        exit (1); }
    No *aux = lista->primeiro;
    int achou = 0;
    do {
        if (aux->dado == valor) achou = 1;
        else aux = aux->proximo;
    } while ((aux->proximo != NULL) && (achou == 0));
    if (achou == 1) puts("Valor encontrado na lista!");
    else puts("Valor não encontrado na lista!"); 
}

void listar (ListaDupla *lista) {
    if (isEmpty(lista)) {
        puts("Não há que o mostrar!");
        exit(1); }
    No *aux = lista->primeiro;
    do {
        printf("%d ", aux->dado);
        aux = aux->proximo;
    } while (aux->proximo != NULL);
}
