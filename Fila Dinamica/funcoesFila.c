#include "prototipoFila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializar(FilaArquivos *arquivos) {
    arquivos->inicio = NULL;
    arquivos->fim = NULL;
}

void inserir (FilaArquivos *arquivos, literal nome, int tam) {
    No *novo = (No*)(malloc(sizeof(No)));
    strcpy (novo->nomedoarquivo, nome); //copia o que tá em nome pra novo->nomedoarquivo
    novo->tamanho = tam;
    novo->proximo = NULL;
    if (arquivos->inicio == NULL) { //se lista vazia
        arquivos->inicio = novo; //novo passa a ser o primeiro da fila
    }
    else {
        arquivos->fim->proximo = novo; //senão insere no fim (regra fifo)
    }
    arquivos->fim = novo;
}

void remover (FilaArquivos *arquivos) {
    if (arquivos->inicio != NULL) {
        No *aux = arquivos->inicio;
        printf("O valor %s foi removido da fila\n",aux->nomedoarquivo);
        arquivos->inicio = arquivos->inicio->proximo;
        if (arquivos->inicio == NULL) {
            arquivos->fim == NULL; //fila ficará vazia
        }
        free(aux);
    }
}

void listar (FilaArquivos *arquivos) {
    No *aux = arquivos->inicio;
    do {
        printf("%s - %d kb\n", aux->nomedoarquivo, aux->tamanho);
        aux = aux->proximo;
    } while (aux != arquivos->fim);
}