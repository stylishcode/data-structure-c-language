#include "prototipoListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale(LC_ALL, "portuguese");
    struct Lista lista;
    //criar lista
    create(&lista);
    int valor, opcao, elem;
    do {
        puts("[1] - Inserir valor no inicio");
        puts("[2] - Inserir valor no fim");
        puts("[3] - Retirar valor do Inicio");
        puts("[4] - Retirar valor do Final");
        puts("[5] - Buscar valor na lista");
        puts("[6] - Listar valores");
        puts("[7] - Limpar a lista");
        printf("Sua opção: "); scanf("%d", &opcao);
        system("clear");
        switch (opcao) {
            case 1:
                printf("Valor que deseja inserir: "); scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("Valor que deseja inserir: "); scanf("%d", &valor);
                inserirNoFinal(&lista, valor);
                break;
            case 3:
                retirarInicio(&lista);
                break;
            case 4:
                retirarFinal(&lista);
                break;
            case 5:
                printf("Valor que deseja buscar: "); scanf("%d", &valor);
                buscar(&lista, valor);
                break;
            case 6:
                listar(lista);
                break;
            case 7:
                limpar(&lista);
                break;
            default:
                if (opcao != 999) puts("Não temos essa opção!");
        }
    } while (opcao != 999);

    return 0;
}