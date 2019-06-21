struct tipo_no {
    int dado;
    struct tipo_no *proximo;
};
typedef struct tipo_no No;

struct tipo_lista {
    No *primeiro;
};
typedef struct tipo_lista ListaCircular;

void inicializarLista (ListaCircular *lista);
int isEmpty (ListaCircular lista);
void inserirNoInicio (ListaCircular *lista, int valor);
void inserirNoFinal (ListaCircular *lista, int valor);
void buscar (ListaCircular *lista, int valor);
int removerInicio (ListaCircular *lista);
void removerFinal (ListaCircular *lista);
void limpar (ListaCircular *lista);
void listar (ListaCircular *lista);

