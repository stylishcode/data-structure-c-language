typedef char string[20];
struct tipo_no_duplo {
    string nome;
    string cargo;
    int idade;
    struct tipo_no_duplo *anterior;
    struct tipo_no_duplo *proximo;
};
typedef struct tipo_no_duplo No;

struct tipo_deque {
    No *inicio;
    No *fim;
};
typedef struct tipo_deque Deque;

void inicializar (Deque *deque);
int isEmpty (Deque *deque);
void inserir (Deque *deque, string nome, int idade, string cargo);
void remover (Deque *deque);
void listar (Deque *deque);