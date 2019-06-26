#include <stdio.h>
#include <stdlib.h>


void trocar (int vetor[], int esquerda, int direita) {
    int aux; 
    aux = vetor[esquerda];
    vetor[esquerda] = vetor[direita];
    vetor[direita] = aux;
}

void ordenar_bolha (int vetor[], int tamanho) {
    int houve_troca = 1;
    int passo = 1, comp;
    while ((passo < tamanho) && houve_troca == 1) {
        houve_troca = 0;
        for (comp = 0; comp < tamanho-passo; comp++) {
            if (vetor[comp] > vetor[comp+1]) {
                houve_troca = 1;
                trocar(vetor, comp, comp+1);
            }
        }
        passo++;
    }
}

void inserir (int vetor[], int tamanho) {
    int i = 0;
    for (i = 0; i < tamanho; i++) {
        printf("Informe um valor: ");
        scanf("%d", &vetor[i]);
    }
    printf("\n");
}

void listar (int vetor[], int tamanho) {
    int i = 0;
    for (i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
    }
    printf("\n");
}

void main () {
    int dados[5];
    int opcao;
    do {
        printf("[1] - INSERIR\n[2] - LISTAR\n[3] - ORDENAR\n[0] - SAIR\nESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                inserir(dados, 5);
                break;
            case 2:
                listar(dados, 5);
                break;
            case 3:
                ordenar_bolha (dados, 5);
                break;
            puts("Ordenacao REALIZADA COM SUCESSO");
            puts("Para visualizar como o vetor ficou, escolha a opcao LISTAR [2]!");
        }
    } while (opcao != 0);
}