#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore
{
    char comparacao[20];
    char folha[20];
    char ramo;
    struct arvore* sim;
    struct arvore* nao;
}No;


No* criarArvoreDecisao(char comparacao[20], char folha[20],char ramo) // pode ser folha ou um no nao terminal
{
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->comparacao,comparacao);
    strcpy(novoNo->folha,folha);
    novoNo->ramo = ramo;
    novoNo->sim = NULL;
    novoNo->nao = NULL;
    return novoNo;
}

void trocar(int *valor1, int *valor2)
{
    int temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}


void bubbleSort(int array[], int tamanho,No** arvoreDecisao) {

    
  No* atual = NULL;
  for (int step = 0; step < tamanho - 1; ++step)
  {
    for (int i = 0; i < tamanho - step - 1; ++i)
    {

      char ramo = 'N';
      char comparacao[20] = "";

      sprintf(comparacao, "[ %d > %d ]", array[i], array[i + 1]);
      if (array[i] > array[i + 1])
      {
        ramo = 'Y';
        trocar(&array[i],&array[i + 1]);

      }

      
      No* novoNo = criarArvoreDecisao(comparacao,"", ramo);

      // ESTRUTURANDO A ARVORE DE DECISAO

      if(*arvoreDecisao == NULL)
      {
        *arvoreDecisao = novoNo;
        atual = novoNo;

      }else
      {
        if(ramo == 'Y') //se a comparacao deu o caminho Y (Yes)
        {
            atual->sim = novoNo;
        }else //se a comparacao deu o caminho N (No)
        {
            atual->nao = novoNo;
        }

        atual = novoNo;

      }
      

    }
  }
}


void percorrerArvoreDecisao(No* arvore)
{
    if(arvore == NULL) return;
    else
    {
        printf("Comparacao: %s | vindo do ramo(caminho): %c\n",arvore->comparacao,arvore->ramo);
        percorrerArvoreDecisao(arvore->sim);
        percorrerArvoreDecisao(arvore->nao);
    }
}


int main ()
{
    No* arvoreDecisao = NULL;

    int vetor[] = {2,1,4,3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    bubbleSort(vetor,tamanho,&arvoreDecisao);

    percorrerArvoreDecisao(arvoreDecisao);

    
}