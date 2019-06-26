#include <stdio.h>
#include <stdlib.h>


void trocar (int vetor[], int esquerda, int direita) {
    int aux;
    aux = vetor[esquerda];
    vetor[esquerda] = vetor[direita];
    vetor[direita] = aux;
}

void ordenar_quick (int vetor[], int inicial, int final) {
    int i, j, pivo;
    i = inicial; //posicao inicial do vetor
    j = final; //posicao final do vetor
    pivo = vetor[(inicial+final)/2]; //divisao do vetor
    while (i<=j) { //enquanto o inicio for menor ou igual ao final
        while (vetor[i] < pivo && i < final) i++; //valor a esquerda do pivo é menor ou igual a ele? se sim, avança
        while (vetor[j] > pivo && j > inicial) j--; //valor a direita do pivo é maior ou igual a ele, se sim, avança
        if (i<=j) { //valor da esquerda do pivo é maior que o valor a direira do pivo?? Se sim,trocar
            trocar(vetor,i,j);
            i++; //incrementa esquerda em mais 1 -> -> avança pra proxima verificação
            j--; //decrementa direita em menos 1 <- <- avança pra proxima verificao
        }
    }
    if (j > inicial) ordenar_quick (vetor, inicial, j); //se direita for maior que o inicio chamar recursivamente
                                                        //da esquerda (posicao inicial) ate posição do pivo - 1
    if (i < final) ordenar_quick (vetor, final, i); //se esquerda for menor que o final chamar recursivamente
                                                    //da direita (pivo+1) ate o final do vetor
}

int main (int argc, const char argv[]) {
    int MAX = 4;
    int dados[MAX];
    int i = 0;
    for (i=0;i<MAX;i++) {
        printf("Informe o valor para insercao no vetor: ");
        scanf("%d", &dados[i]);
    }
    ordenar_quick (dados,0,MAX-1);
    puts("Vetor ordenado!");
    for (i=0;i<MAX;i++) {
        printf("%d", dados[i]);
    }
    printf("\n");
    getchar();
    return 0;
}