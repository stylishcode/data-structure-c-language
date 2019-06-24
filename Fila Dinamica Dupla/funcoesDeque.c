#include "prototipoDeque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializar (Deque *deque) {
    deque->inicio = NULL;
    deque->fim = NULL;
}

int isEmpty (Deque *deque) {
    return (deque->inicio == NULL);
}

void inserir (Deque *deque, string nome, int idade, string cargo) {
    No *novo = (No*)(malloc(sizeof(No)));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->proximo = NULL;
    novo->anterior = NULL;
    strcpy(novo->cargo, cargo);
    if (isEmpty(deque)) {
        deque->inicio = novo;
    }
    else {
        deque->fim->proximo = novo; //ultimo elemento aponta pro elemento que está sendo inserido ->->->
        novo->anterior = deque->fim; //elemento inserido aponta pro que já está inserido <-<-<-
    }
    deque->fim = novo; //novo passa a ser o último elemento
}

void remover (Deque *deque) {
    if (deque->inicio != NULL) {
        No *aux = deque->inicio;
        deque->inicio = deque->inicio->proximo;
        printf("Funcionario: %s foi removido\n", aux->nome);
        if (deque->inicio == NULL) {
            deque->fim == NULL;
        }
        else {
            deque->inicio->anterior = NULL;
        }
        free(aux);
    }
}

void listar (Deque *deque) {
    No *aux = deque->inicio;
    do {
        printf("Nome: %s\nIdade: %d\nCargo:%s\n", aux->nome, aux->idade, aux->cargo);
        printf("\n");
        aux = aux->proximo;
    } while (aux != deque->fim->proximo);
    printf("\n");
}