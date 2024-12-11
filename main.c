
#include <stdio.h>
#include <stdlib.h>
#include "aux.h"

#define Vermelho 1
#define Amarelo 2
#define Verde 3


int main(void) {
  Pacientes* lst=lst_cria();

  // criar o contador da ordem de chegada dos pacientes
  int* cont=(int*)malloc(sizeof(int));
  if (cont==NULL){
    printf("erro ao alocar memoria\n");
    return 1;
  }
  *cont=1;
  
  // inserir os pacientes de acordo com a chegada e sua urgência
  lst=lst_insere_ordenado(lst, Verde, cont);
  lst=lst_insere_ordenado(lst, Vermelho, cont);
  lst=lst_insere_ordenado(lst, Verde, cont);
  lst=lst_insere_ordenado(lst, Amarelo, cont);
  lst=lst_insere_ordenado(lst, Vermelho, cont);
  lst=lst_insere_ordenado(lst, Vermelho, cont);
  lst=lst_insere_ordenado(lst, Verde, cont);
  lst=lst_insere_ordenado(lst, Vermelho, cont);
  printf("\nChegada dos primeiros pacientes:\n");
  lst_imprime(lst);
  lst_conta_cor(lst);
  
  // alterações na lista
  lst=lst_remove(lst, 5);
  printf("\nPaciente 5 é atendido:\n");
  lst_imprime(lst);
  lst_conta_cor(lst);

  lst=lst_remove(lst, 4);
  printf("\nPaciente 4 é atendido:\n");
  lst_imprime(lst);
  lst_conta_cor(lst);
  
  lst=lst_insere_ordenado(lst, Verde, cont);
  lst=lst_insere_ordenado(lst, Amarelo, cont);
  lst=lst_insere_ordenado(lst, Vermelho, cont);
  lst=lst_insere_ordenado(lst, Amarelo, cont);
  printf("\nChegam os pacientes 9, 10, 11 e 12:\n");
  lst_imprime(lst);
  lst_conta_cor(lst);
  
  lst=lst_remove(lst, 2);
  lst=lst_remove(lst, 6);
  printf("\nSao atendidos os pacientes 2 e 6:\n");
  lst_imprime(lst);
  lst_conta_cor(lst);

  lst=lst_remove(lst, 3);
  printf("\nPaciente 3 desiste e vai embora:\n");
  // estado final da lista
  lst_imprime(lst);
  lst_conta_cor(lst);
  
  lst_libera(lst);
  free(cont);
  
  return 0;
}

