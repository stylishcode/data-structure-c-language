#include <stdio.h>
#include <stdlib.h>
 
struct tipo_no {
    int dado;
    struct tipo_no * proximo;
    struct tipo_no * anterior;
};
typedef struct tipo_no No;
struct tipo_lista{
     No *primeiro;
     No *ultimo;
};
typedef struct tipo_lista ListaDupla;  
void inicializarLista(ListaDupla* lista){
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}
void inserirFinal(ListaDupla* lista, int valor){  
  No *novo;  
  novo = (No*)malloc(sizeof(No));
  novo->dado = valor;
  novo->anterior = NULL;
  novo->proximo  = NULL;
  if(lista->primeiro == NULL){
      lista->primeiro = novo;            
  }else{
     lista->ultimo->proximo = novo;
     novo->anterior = lista->ultimo;
  }  
  lista->ultimo = novo;                              
}
void inserirInicio(ListaDupla* lista, int valor){  
  No *novo;  
  novo = (No*)malloc(sizeof(No));
  novo->dado = valor;
  novo->anterior = NULL;
  novo->proximo  = NULL;
  if(lista->primeiro == NULL){
      lista->ultimo = novo;            
  }else{
     novo->proximo = lista->primeiro;
     lista->primeiro->anterior = novo;
  }  
  lista->primeiro = novo;                              
}
void removerFinal(ListaDupla* lista){
  if(lista->primeiro->proximo == NULL){
     No* aux = lista->ultimo;
     lista->primeiro = NULL;
     lista->ultimo = NULL;  
     free(aux);                                    
  }else{
    No* aux = lista->ultimo;
    lista->ultimo->anterior->proximo=NULL;
    lista->ultimo = lista->ultimo->anterior;
    free(aux);      
  }          
}
void listar(ListaDupla* lista,char opcao){
  system("cls");  
  printf("LISTAGEM\n");  
  No* aux = NULL;
  if(opcao == '1') aux = lista->primeiro;
  else
    aux = lista->ultimo;
  if(aux != NULL){
     while(aux != NULL){
        printf("%d ", aux->dado);                
        if(opcao == '1') aux = aux -> proximo;                
        else
          aux = aux -> anterior;
    }
     printf("\n----------------------\n");
  }  
}
No* consultar(ListaDupla* lista,int valor){
  No* aux = lista->primeiro;
  if(aux != NULL){
     while((aux != NULL) && (aux->dado != valor )){
        aux = aux -> proximo;                      
    }
    return aux;
  }  
}
int main(int argc, char *argv[]){
  ListaDupla* lista = (ListaDupla*) malloc(sizeof (ListaDupla));  
  inicializarLista(lista);
  int op=0,valor;
  do{
    system("cls");  
    printf("\n1-Inserir no INICIO");
    printf("\n2-Inserir no FINAL");
    printf("\n3-Listar Inicio->Fim");
    printf("\n4-Listar Fim->Inicio");
    printf("\n5-Consultar");
    printf("\n6-Remover do Final");
    printf("\n7-SAIR\n");
    scanf("%d",&op);
    switch(op){
       case 1:printf("\nInforme o Valor:");
              scanf("%d",&valor);
              inserirInicio(lista,valor);
              break;
       case 2:printf("\nInforme o Valor:");
              scanf("%d",&valor);
              inserirFinal(lista,valor);
              break;                    
       case 3:listar(lista,'1');
              system("pause");
              break;
       case 4:listar(lista,'2');
              system("pause");
              break;      
       case 5:printf("\nInforme o Valor:");
              scanf("%d",&valor);      
              No* res = consultar(lista,valor);
              if(res == NULL) printf("\n Valor Inexistente !\n");
              else printf("\n Valor Localizado !\n");
              system("pause");  
              break;    
      case 6: removerFinal(lista);    
    }  
  }while(op != 7);    
  system("PAUSE");     
  return 0;
}