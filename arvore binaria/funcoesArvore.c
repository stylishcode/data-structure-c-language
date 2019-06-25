#include "prototipo.h"
#include <stdlib.h>
#include <stdio.h>


void inicializar (ArvoreBinaria *arvore) {
    *arvore = NULL;
}

void inserir (ArvoreBinaria *arvore, int valor) {
    if ((*arvore) == NULL) { //importante referenciar arvore com parenteses pra conseguir acessar seus elementos
        *arvore = (No*)malloc(sizeof(No)); //para criar não é necessário usar os parênteses
        (*arvore)->esquerda = NULL; 
        (*arvore)->direita = NULL;
        (*arvore)->valor = valor;
        // a esquerda e a direita for null significa que o elemento inserido é o primeiro (no raiz da arvore)
    }
    if (valor < (*arvore)->valor) {
        inserir(&(*arvore)->esquerda, valor);
    }
    else {
        if (valor > (*arvore)->valor) {
            inserir(&(*arvore)->direita, valor);
        }
    }
   
}

int buscar (ArvoreBinaria arvore, int valor) {
    if (arvore != NULL) {
        if (arvore->valor = valor) {
            return 1;
        }
        else {
            if (arvore->valor < valor) {
                return buscar (arvore->direita, valor);
            }
            else {
                return buscar (arvore->esquerda, valor);
            }
        }
    }
    else {
        return 0;
    }
}

void exibirNosPrefixados (ArvoreBinaria arvore) {
    if (arvore != NULL) {
        printf("(%d) ", arvore->valor);
        if (arvore->esquerda != NULL) exibirNosPrefixados(arvore->esquerda);
        if (arvore->direita != NULL) exibirNosPrefixados(arvore->direita);
    }
}

void exibirNosCentral (ArvoreBinaria arvore) {
    if (arvore != NULL) {
        if (arvore->esquerda != NULL) exibirNosCentral(arvore->esquerda);
            printf("(%d) ", arvore->valor);
        if (arvore->direita != NULL) exibirNosCentral(arvore->direita);
    }
}

void exibirNosPosfixado (ArvoreBinaria arvore) {
    if (arvore != NULL) {
        if (arvore->esquerda != NULL) exibirNosPosfixado(arvore->esquerda);
        if (arvore->direita != NULL) exibirNosPosfixado(arvore->direita);
        printf("(%d) ", arvore->valor);
   }
}

void listarPares (ArvoreBinaria no) {
    if (no != NULL) {
        if ((no->esquerda != NULL) && (no->esquerda->valor % 2 == 0))
            listarPares (no->esquerda);
            printf("(%d) ", no->valor);
        if ((no->direita != NULL) && (no->direita->valor % 2 == 0))
            listarPares (no->direita);
    }
}
