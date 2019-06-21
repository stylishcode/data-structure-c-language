#define MAX 50
#define INVALIDO -1

struct nodo {
    int item;
    int prox;
};

typedef struct nodo tipo_nodo;

struct lista {
    tipo_nodo A[MAX];
    int inicio;
    int disponivel;
};

typedef struct lista tipo_lista;

void inicializarLista (tipo_lista *lista) {
    int i;
    for (i=0; i<MAX-1; i++) {
        lista->A[i].prox = i + 1;
    }
    lista->A[MAX-1].prox = INVALIDO;
    lista->inicio = INVALIDO;
    lista->disponivel = 0;
}

int tamanho (tipo_lista *lista) {
    int i = lista->inicio;
    int tamanho = 0;
    while (i != INVALIDO) {
        tamanho++;
        i = lista->A[i].prox;
    }
    return tamanho;
}

void exibirLista (tipo_lista *lista) {
    int i = lista->inicio;
    while (i != INVALIDO) {
        printf("%d ", lista->A[i].item);
        i = lista->A[i].prox;
    }
    printf("\"\n");
}

int buscaSequencialOrd (tipo_lista *lista, int itemProcurado) {
    int i = lista->inicio;
    while (i != INVALIDO && lista->A[i].item < itemProcurado) 
        i = lista->A[i].prox;
    if (i != INVALIDO && lista->A[i].item == itemProcurado) 
        return i;
    else return INVALIDO;
}

int obterNodo (tipo_lista *lista) {
    int resultado = lista->disponivel;
    if(lista->disponivel != INVALIDO)
        lista->disponivel = lista->A[lista->disponivel].prox;
    return resultado;
}

int insListaOrd (tipo_lista *lista, int item) {
    if (lista->disponivel == INVALIDO) return 0;
    int ant = INVALIDO;
    int i = lista->inicio;
    int chave = lista->A[i].item;
    while ((i != INVALIDO) && (lista->A[i].item < chave)) {
        ant = i;
        i = lista->A[i].prox;
    }
    if (i != INVALIDO && lista->A[i].item == chave) return 0; //impede a duplicação
    i = obterNodo(lista);
    lista->A[i].item = item;
    if (ant == INVALIDO) {
        lista->A[i].prox = lista->inicio;
        lista->inicio = i;
    } else {
        lista->A[i].prox = lista->A[ant].prox;
        lista->A[ant].prox = i;
    }
    return 1;
}

void devolverNo (tipo_lista *lista, int j) {
    lista->A[j].prox = lista->disponivel;
    lista->disponivel = j;
}

int excluirElemLista (tipo_lista *lista, int itemProcurado) {
    int ant = INVALIDO;
    int i = lista->inicio;
    while ((i != INVALIDO) && (lista->A[i].item < itemProcurado)) {
        ant = i;
        i = lista->A[i].prox;
    }
    if (i == INVALIDO || lista->A[i].item != itemProcurado) return 0;
    if (ant == INVALIDO) lista->inicio = lista->A[i].prox; 
    else lista->A[ant].prox = lista->A[i].prox;
    devolverNo (lista, i);
}

void reinicializarLista(tipo_lista *lista) {
    inicializarLista(lista);
}

