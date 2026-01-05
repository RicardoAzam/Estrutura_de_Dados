#ifndef ARVOREPR_H_INCLUDED
#define ARVOREPR_H_INCLUDED
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_NOME 50
#define MAX_VEND 50
#define MAX_MATR 10

typedef struct DATAVenda
{
    int dia,mes,ano;
}data;

typedef struct NoArvore
{
    int id;
    char cliente[MAX_NOME];
    char vendedor[MAX_VEND];
    char idV[MAX_MATR];
    int preco;
    data* transacao;
    struct NoArvore *esq;
    struct NoArvore *dir;
}NoArv;


typedef struct Arvore
{
    NoArv *raiz;
}Arv;

//cria arvore
Arv* CriaArv()
{
    Arv* A = (Arv*) malloc(sizeof(Arv));
    A->raiz=NULL;
    return A;
}

NoArv* aux_inserir(NoArv* A, int id1, char cliente1[],char vendedor1[], char idv1[], int preco1,int dia1,int mes1, int ano1)
{
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*) malloc(sizeof(NoArv));
    novo->transacao = (data*) malloc(sizeof(data));

    novo->id = id1;
    strcpy(novo->cliente, cliente1);
    strcpy(novo->vendedor, vendedor1);
    strcpy(novo->idV, idv1);
    novo->preco = preco1;
    novo->transacao->dia = dia1;
    novo->transacao->mes = mes1;
    novo->transacao->ano = ano1;
    novo->esq = NULL;
    novo->dir = NULL;

    if (A == NULL)
    {
        return novo;
    }
    else
    {
        Pai = A;
        flag = 0;

        while (flag == 0)
        {
            if (Pai->id < id1)
            {
                if (Pai->dir == NULL)
                {
                    Pai->dir = novo;
                    flag = 1;
                }
                else
                {
                    Pai = Pai->dir;
                }
            }
            else
            {
                if (Pai->id > id1)
                {
                    if (Pai->esq == NULL)
                    {
                        Pai->esq = novo;
                        flag = 1;
                    }
                    else
                    {
                        Pai = Pai->esq;
                    }
                }
                else
                {
                    printf("Ja existe\n");
                    flag=1;
                }
            }
        }
    }

    return A;
}


void Inserir1(Arv* A, int id, char idv[])
{
    char cliente1[MAX_NOME];
    char vendedor1[MAX_VEND];
    int dia1, mes1, ano1, preco1;
    printf("Digite o nome de Cliente: ");
    scanf("%s", cliente1);
    printf("Digite o nome do Vendedor: ");
    scanf("%s", vendedor1);
    printf("Digite o valor da venda: ");
    scanf("%d", &preco1);
    printf("Digite o dia da venda: ");
    scanf("%d", &dia1);
    printf("Digite o mes da venda: ");
    scanf("%d", &mes1);
    printf("Digite o ano da venda: ");
    scanf("%d", &ano1);

    A->raiz = aux_inserir(A->raiz, id, cliente1, vendedor1, idv,preco1, dia1, mes1, ano1);
}


  //imprimir arvore(In-Order)

  void Imprimir(NoArv* B)
  {
      if (B == NULL) return;
      if(B->dir!=NULL)
      {
       Imprimir(B->dir);
      }
      printf("\n\tID:%d",B->id);
      printf("\tCliente:%s",B->cliente);
      printf("\tVendedor:%s",B->vendedor);
      printf("\tID Vendedor:%s",B->idV);
      printf("\tPreco:%d",B->preco);
      printf("\tDia:%d",B->transacao->dia);
      printf("\tMes:%d",B->transacao->mes);
      printf("\tAno:%d\n",B->transacao->ano);
       if(B->esq!=NULL)
      {
       Imprimir(B->esq);
      }
  }


  //Lista vazia
  int VaziaArv(Arv* A)
  {
      if(A->raiz==NULL)
      {
          return 1;
      }
      return 0;
  }



//Libera arvore(pos order)

void Liber(NoArv* A)
  {
      if(A->dir!=NULL)
      {
       Liber(A->dir);
      }
       if(A->esq!=NULL)
      {
       Liber(A->esq);
      }
      free(A);
  }


NoArv *remover_aux(NoArv *pai, int num)
{
    if (pai == NULL)
    {
        printf("\n\nnão encontrado na árvore");
    }
    else
    {
        if (num > pai->id)
        {
            pai->dir = remover_aux(pai->dir, num);
        }
        else
        {
            if (num < pai->id)
            {
                pai->esq = remover_aux(pai->esq, num);
            }
            else
            {
                if (pai->dir == NULL && pai->esq == NULL)
                {
                    free(pai);
                    pai = NULL;
                }
                else
                {
                    if (pai->esq == NULL)
                    {
                        NoArv *aux = pai;
                        pai = pai->dir;
                        free(aux);
                    }
                    else
                    {
                        if (pai->dir == NULL)
                        {
                            NoArv *aux = pai;
                            pai = pai->esq;
                            free(aux);
                        }
                        else /* tem os dois filhos */
                        {
                            NoArv *aux;
                            aux = pai->esq;
                            while (aux->dir != NULL)
                            {
                                aux = aux->dir;
                            }
                            pai->id = aux->id; /* troca as informações */
                            aux->id = num;
                            pai->esq = remover_aux(pai->esq, num);
                        }
                    }
                }
            } // achou o nó a ser removido
        }
    } // else do não estar vazio
    return pai;
}

Arv* remover(Arv *RAIZ, int num)
{
    NoArv *aux = RAIZ->raiz;
    if (aux->id == num && aux->dir == NULL && aux->esq == NULL)
    {
        free(aux);
        free(RAIZ);
        return NULL;
    }
    RAIZ->raiz = remover_aux(RAIZ->raiz, num);
    return RAIZ;
}


  //compara arvore
int Compara(NoArv* A, int valor)
{
    if(A==NULL)
    {
        return 0;
    }
   if (A->id==valor)
   {
       return 1;
   }
   if(valor> A->id)
    {
         return Compara(A->dir,valor);
    }
    else
    {
        return Compara(A->esq,valor);
    }
}


  //compara id do vendedor na arvore
int ComparaIDV(NoArv* A, char numV[])
{
    if (A == NULL)
        return 0;

    if (strcmp(A->idV, numV) == 0)
        return 1;

    // busca primeiro na direita, depois na esquerda
    return ComparaIDV(A->dir, numV) || ComparaIDV(A->esq, numV);
}



//gera id
int CodigoID(Arv *a)
{
    
    int min = 1000;
    int max = 9999;
    int x,y=1;

    do {
    x=(rand() % (max - min + 1)) + min;
    y=Compara(a->raiz,x);
    } while (y==1);

    return x;
}

void CodigoIDVendedor(NoArv *a, char matricula[6])
{
    int x = 1;
    int numero_aleatorio;
    char letra = 'V';
    int min = 99;
    int max = 1000;

    do {
        numero_aleatorio = (rand() % (max - min + 1)) + min;
        sprintf(matricula, "%c%03d", letra, numero_aleatorio);
        x = ComparaIDV(a,matricula);
    } while (x == 1);
}


#endif // ARVOREPR_H_INCLUDED