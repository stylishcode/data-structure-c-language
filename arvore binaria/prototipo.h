struct no_arvore {
    struct no_arvore *esquerda;
    int valor;
    struct no_arvore *direita;
};
typedef struct no_arvore No;
typedef No *ArvoreBinaria;

void inicializar (ArvoreBinaria *arvore);
void inserir (ArvoreBinaria *arvore, int valor);
void exibirNosPrefixados (ArvoreBinaria arvore);
void exibirNosCentral (ArvoreBinaria arvore);
void exibirNosPosfixado (ArvoreBinaria arvore);
void listarPares (ArvoreBinaria no);