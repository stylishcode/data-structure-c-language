typedef char literal[30];
struct item_no {
    literal nomedoarquivo;
    int tamanho;
    struct item_no *proximo;
};
typedef struct item_no No;

struct fila {
    No *inicio;
    No *fim;
};
typedef struct fila FilaArquivos;

void inicializar (FilaArquivos *arquivos);
void inserir (FilaArquivos *arquivos, literal nome, int tam);
void remover (FilaArquivos *arquivos);
void listar (FilaArquivos *arquivos);