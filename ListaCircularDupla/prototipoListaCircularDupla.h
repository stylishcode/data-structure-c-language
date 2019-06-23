struct tipoNoDuplo {
    int dado;
    struct tipoNoDuplo *anterior;
    struct tipoNoDuplo *proximo;
};
typedef struct tipoNoDuplo NoDuplo;

struct ListaCircularDupla {
    NoDuplo *inicio;
};
typedef struct ListaCircularDupla ListaDupla;

void inicializar (ListaDupla *lista);
int isEmpty (ListaDupla *lista);
void inserirNoInicio (ListaDupla *lista, int valor);
void inserirNoFinal (ListaDupla *lista, int valor);
void removerInicio (ListaDupla *lista);
void removerFinal (ListaDupla *lista);
void buscar (ListaDupla *lista, int valor);
void listar (ListaDupla *lista);
