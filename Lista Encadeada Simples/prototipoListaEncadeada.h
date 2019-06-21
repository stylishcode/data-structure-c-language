//estrutura do tipo caixinha (nó)
struct Caixinha {
    int elemento;
    struct Caixinha *proximo;
};
// estrutura lista que contem um tipo caixinha (nó)
struct Lista {
    struct Caixinha *inicio;
};

//prototipo das funções
void create (struct Lista *lista);
void inserirNoFinal (struct Lista *lista, int elemento);
void inserirNoInicio (struct Lista *lista, int elemento);
int isEmpty (struct Lista *lista); //aqui, lista não precisa ser um ponteiro já que isEmpty é um função que não modifica nada
int retirarInicio (struct Lista *lista);
int retirarFinal (struct Lista *lista);
void listar (struct Lista lista); //aqui, lista não precisa ser ponteiro também "" "" ""
void inserir (struct Lista* lista, int elemento);
void buscar (struct Lista *lista, int valor);
void limpar (struct Lista *lista);
