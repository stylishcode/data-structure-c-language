#include <stdio.h>
#include <stdlib.h>

int dados[10];
int aux[10];

//parametros da funcao: ini1: posicao inicial segmento 1, ini2: posicao inicial segmento 2, fim2: posicao final seg2
void combinacao (int vetor[], int vetoraux[], int ini1, int ini2, int fim2) {
    int in1=ini1, in2=ini2, fim1=in2-1,au=0,i,j;
    while (in1<=fim1 && in2<=fim2) { //enquanto n for o final do primeiro e nem do segundo segmento
        if (vetor[in1] < vetor[in2]) {// elemento do primeiro segmento é maior que o segundo??
            vetoraux[au++] = vetor[in1++];//copia o elemento para o aux
        }
        else { //elemento do segundo segmento é maior que o do primeiro??
            vetoraux[au++] = vetor[in2++];//copia o elemento para o aux
        }
    }//vai copiando até o fim desse while
    while (in1<=fim1) { //copia os elementos do primeiro segmento para o vetor aux (ja ordenados pelo while anterior)
        vetoraux[au++] = vetor[in1++];
    }
    while (in2<=fim2) { ////copia os elementos do segundo segmento para o vetor aux (ja ordenados pelo while anterior)
        vetoraux[au++] = vetor[in2++];
    }
    for (i=0;i<au;i++) {//copia todos os elementos do vetor aux para o vetor principal (ja ordenados)
        vetor[i+ini1] = vetoraux[i];
    }
}

void segmentacao (int vetor[], int vetoraux[], int esquerda, int direita) {
    int meio, i;
    if (esquerda<direita) {
        meio = (esquerda+direita)/2;
        segmentacao (vetor, vetoraux, esquerda, meio); //segmenta o vetor da posicao inicial ate o meio do vetor
        segmentacao (vetor, vetoraux,meio+1,direita); //segmenta o vetor do meio do vetor ate o seu final
        combinacao (vetor,vetoraux,esquerda,meio+1,direita); //ordena os segmentos
        /* 
            Por exemplo, se o vetor tem 10 posições, a instrução da linha 5 representa a ordenação do segmento das posições 0 a 4 e a instrução da linha 6 a ordenação dos elementos das posições 5 a 9.
        */
    }
}

void inserir () {
    int i;
    for (i=0; i<10; i++) {
        system("clear");
        printf("Informe o %d o elemento de 10 elementos: ",(i+1));
        scanf("%d", &dados[i]);
    }
}

void listar () {
    int i;
    for (i=0; i<10; i++) {
        printf("%d ",dados[i]);
    }
    printf("\n");
    getchar();
}

void menu () {
    int opcao;
    do {
        printf("1-Inserir\n2-Listar\n3-Ordenar\n0-Sair\nEscolha uma das opcoes: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                inserir();
                break;
            case 2:
                listar();
                break;
            case 3:
                segmentacao(dados,aux,0,9);
                puts("Ordenado com sucesso");
                break;
        }
    } while (opcao != 0);
}

int main (int argc, const int argv[]) {
    menu();
    return 0;
}