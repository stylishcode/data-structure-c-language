#include "prototipoListaCircularDupla.h"
#include <stdio.h>
#include <stdlib.h>


void inicializar (ListaDupla *lista) {
    lista->inicio = NULL;
}

NoDuplo *cauda (ListaDupla *lista) {
    NoDuplo *c = lista->inicio;
    while (c->proximo != lista->inicio) {
            c = c->proximo;
    }
    return c;
}

int isEmpty (ListaDupla *lista) {
    return (lista->inicio == NULL);
}

void inserirNoInicio (ListaDupla *lista, int valor) {
    NoDuplo *novo;
    novo = (NoDuplo *)(malloc(sizeof(NoDuplo)));
    novo->dado = valor;
    if (isEmpty(lista)) {
        novo->anterior = novo;
        novo->proximo = novo;
        lista->inicio = novo;
    }
    else {
        NoDuplo *cauda = lista->inicio;
        while (cauda->proximo != lista->inicio) {
            cauda = cauda->proximo;
        }
        lista->inicio->anterior = novo;
        cauda->proximo = novo;
        novo->anterior = cauda;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
}

void inserirNoFinal (ListaDupla *lista, int valor) {
    NoDuplo *novo; //cria novo nó
    novo = (NoDuplo *)(malloc(sizeof(NoDuplo))); //aloca memória
    novo->dado = valor; //nó recebe o valor
    if (isEmpty(lista)) { //se lista vazia (ou seja, ele será o único elemento)
        novo->anterior = novo; //anterior de próximo aponta para ele mesmo
        novo->proximo = novo; //proximo de nó aponta para ele mesmo
        lista->inicio = novo; // inicio da lista passa a ser novo
    }
    else {
        NoDuplo *aux = lista->inicio; //cria nó com indice inicio
        while (aux->proximo != lista->inicio) { //enquanto prox de aux não for inicio
            aux = aux->proximo;
        }
        novo->anterior = aux; // anterior de novo aponta para o aux
        aux->proximo = novo; //aux aponta para o novo elemento
        lista->inicio->anterior = novo; //anterior de inicio aponta para o novo
        novo->proximo = lista->inicio; //prox de novo aponta para o inicio
    }
}

void removerInicio (ListaDupla *lista) {
    if (isEmpty(lista)) {
        puts("Não há o que remover");
        exit(1); }
    NoDuplo *aux = lista->inicio;
    NoDuplo *cauda = lista->inicio; //como não tem cauda definida, tem que percorrer pra criar uma cauda
         while (cauda->proximo != lista->inicio) //enquanto proximo for diferente do ultimo elemento ( será a cauda da lista)
            cauda = cauda->proximo;
    if (lista->inicio == cauda) {
        lista->inicio = NULL;
        free(aux);
    }
    else {
        lista->inicio = aux->proximo; //novo inicio da lista
        //parte circular
        lista->inicio->anterior = cauda; //anterior do inicio aponta pro fim da lista
        cauda->proximo = lista->inicio; //proximo do fim aponta pro inicio da lista
        free(aux);
    }
}

void removerFinal (ListaDupla *lista) {
    if (isEmpty(lista)) {
        puts("Não há o que remover");
        exit(1); }
    NoDuplo *aux = lista->inicio;
    NoDuplo *cauda = lista->inicio; //como não tem cauda definida, tem que percorrer pra criar uma cauda
         while (cauda->proximo != lista->inicio) //enquanto proximo for diferente do ultimo elemento ( será a cauda da lista)
            cauda = cauda->proximo;
    if (lista->inicio == cauda) {
        removerInicio(lista);
        return;
    } 
    else {
        NoDuplo *aux = cauda;
        cauda = aux->anterior; //anterior de aux(cauda) passa a ser a nova cauda
        //parte circular
        cauda->proximo = lista->inicio; //proxima da nova cauda aponta pro inico
        lista->inicio->anterior = cauda; //anterior do inicio aponta para a cauda
        free(aux);
    }
}

void listar (ListaDupla *lista) {
    if (isEmpty(lista)) {
        puts("Não há o que exibir");
        exit(1); }
    NoDuplo *aux;
    aux = lista->inicio;
    do {
        printf("%d ", aux->dado);
        aux = aux->proximo;
    } while (aux != lista->inicio);
    printf("\n");
}