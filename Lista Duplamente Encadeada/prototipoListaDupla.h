struct tipo_no_duplo {
    int dado;
    struct tipo_no *proximo;
    struct tipo_no *anterior;
};
typedef struct tipo_no_duplo No;

struct tipo_lista_dupla {
    No *primeiro;
    No *ultimo;
};
typedef struct tipo_lista_dupla ListaDupla;

void inicializarLista (ListaDupla *lista);
void inserirNoInicio (ListaDupla *lista, int valor);
void inserirNoFinal (ListaDupla *lista, int valor);
int isEmpty (ListaDupla *lista);
int removerInicio (ListaDupla *lista);
int removerFinal (ListaDupla *lista);
void buscar (ListaDupla *lista, int valor);
void listar (ListaDupla *lista);
void limpar (ListaDupla *lista);
