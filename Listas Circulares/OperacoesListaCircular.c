#include "prototipoListaCircular.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale(LC_ALL, "portuguese");
    ListaCircular lista_circular;
    //criar lista
    inicializarLista(&lista_circular);
    int valor, opcao, elem;
    do {
        puts("[1] - Inserir valor no inicio");
        puts("[2] - Inserir valor no fim");
        puts("[3] - Retirar valor do Inicio");
        puts("[4] - Retirar valor do Final");
        puts("[5] - Buscar valor na lista Circular");
        puts("[6] - Listar valores");
        puts("[7] - Limpar a lista Circular");
        printf("Sua opção: "); scanf("%d", &opcao);
        system("clear");
        switch (opcao) {
            case 1:
                printf("Valor que deseja inserir: "); scanf("%d", &valor);
                inserirNoInicio(&lista_circular, valor);
                break;
            case 2:
                printf("Valor que deseja inserir: "); scanf("%d", &valor);
                inserirNoFinal(&lista_circular, valor);
                break;
            case 3:
                removerInicio(&lista_circular);
                break;
            case 4:
                removerFinal(&lista_circular);
                break;
            case 5:
                printf("Valor que deseja buscar: "); scanf("%d", &valor);
                buscar(&lista_circular, valor);
                break;
            case 6:
                listar(&lista_circular);
                break;
            case 7:
                 limpar(&lista_circular);
                break;
            default:
                if (opcao != 999) puts("Não temos essa opção!");
        }
    } while (opcao != 999);

    return 0;
}
