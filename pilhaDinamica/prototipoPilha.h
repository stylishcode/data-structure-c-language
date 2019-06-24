struct tipo_no {
    int dado;
    struct tipo_no *proximo;
};
typedef struct tipo_no No;

struct t_pilha {
    No *topo;
};
typedef struct t_pilha Pilha;

void create (Pilha *pilha);
void push (Pilha* pilha, int valor);
int pop (Pilha *pilha);
int isEmpty (Pilha *pilha);