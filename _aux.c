#include <stdio.h>
#include <stdlib.h>



struct pacientes{
  int cor;
  int ord;
  int status;
  struct pacientes* prox;
};
typedef struct pacientes Pacientes;

Pacientes* lst_cria (void){
  return NULL;                   // retornar a lista vazia
}

Pacientes* lst_insere_ordenado (Pacientes* lst, int cor, int* ord){
  Pacientes* novo;               // ponteiro para elemento a ser inserido
  Pacientes* ant = NULL;         // ponteiro para elemento anterior 
  Pacientes* p = lst;            // ponteiro para percorrer a lista 

  // buscar o ponto de inserção desejado, ou o fim da lista 
  while (p != NULL && p->cor <= cor && p->ord < *ord) {
  ant = p;
  p = p->prox;
  }
  
  // criar o novo elemento a ser inserido
  novo = (Pacientes*) malloc(sizeof(Pacientes));
  novo->cor = cor;
  novo->ord = *ord;
  
  // casos para a inserção do elemento 
  if (ant == NULL) {            // inserir no início da lista
    novo->prox = lst;
    lst = novo;
  }
    
  else {                        // inserir no meio da lista
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  
  (*ord)++;                     // aumenta o contador da ordem de chegada para os próximos que chegarem no hospital
  return lst;                   // retorna ponteiro para o primeiro elemento 
}

Pacientes* lst_remove(Pacientes* lst,int ord){
  Pacientes*ant=NULL;                // ponteiro para o elemento anterior
  Pacientes*p=lst;                   // ponteiro para percorrer a lista
  while(p!=NULL&&p->ord!=ord){       // loop para percorrer a lista até chegar no elemento a ser removido, ou o                                           fim da lista
    ant=p;
    p=p->prox;
  }
  
  if (p==NULL){                      // se não encontrar o elemento a ser removido
    return lst;
  }
  
  if (ant==NULL){                    // se o elemento a ser retirado for o primeiro da lista
    lst=p->prox;
  }
    
  else{                              // se o elemento a ser retirado estiver no meio da lista
    ant->prox=p->prox;
  }
  free(p);                           // liberar a memória alocada pelo elemento a ser removido, assim o excluindo
  return lst;
}

void lst_imprime (Pacientes* lst){
  Pacientes* p;                              // ponteiro para percorrer a lista
  
  for (p = lst; p != NULL; p = p->prox){     // percorrer por cada elemento até o final da lista
    if (p->cor==1)                           // como imprimir caso a urgência seja vermelha
      printf("Ordem de chegada: %d - Cor: %s\n",p->ord, "Vermelho");
    else if (p->cor==2)                      // como imprimir caso a urgência seja amarela
      printf("Ordem de chegada: %d - Cor: %s\n",p->ord, "Amarelo");
    else                                     // como imprimir caso a urgência seja verde
      printf("Ordem de chegada: %d - Cor: %s\n",p->ord, "Verde");
  }
  printf("Fim da lista\n");                  // indicar o fim da lista
}

void lst_conta_cor (Pacientes* lst){
  int verm=0,verd=0,amar=0;          // contadores para cada grau de urgência
  Pacientes*p;                       // ponteiro para percorrer a lista
  
  for(p=lst;p!=NULL;p=p->prox){      // percorrer por cada elemento até o final da lista
    if (p->cor==1)                   // caso o elemento tenha grau vermelho de urgência
      verm++;
    else if (p->cor==2)              // caso o elemento tenha grau amarelo de urgência
      amar++;
    else                             // caso o elemento tenha grau verde de urgência
      verd++;
  }
  
  // exibir o resultado encontrado
  printf("Numero de pacientes por cor:\nVermelho: %d - Amarelo: %d - Verde: %d\n\n",verm,amar,verd);
  return;
}

void lst_libera (Pacientes*lst){
  Pacientes* p=lst;                  // ponteiro para percorrer a lista
  
  while (p!=NULL){                   // enquanto não chegar no final da lista
    Pacientes*t=p->prox;             // ponteiro para armazenar o endereço do próximo elemento
    free(p);                         // libera o elemento
    p=t;                             // pega o proximo elemento
  }
}


