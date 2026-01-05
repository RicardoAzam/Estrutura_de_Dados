#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore
{
    int info;
    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArv;

typedef struct Arvore
{
    NoArv *raiz;
} Arv;

/* protótipos */
Arv* CriaArv(void);
void LiberaNos(NoArv *no);
void LiberaArv(Arv *A);
int VaziaArv(Arv *A);
void Inserir(Arv *A, int valor);
NoArv* inserir_no(NoArv *no, int valor);
void ImprimirInOrder(NoArv *no);
void ImprimirPreOrder(NoArv *no);
void ImprimirPosOrder(NoArv *no);
int Compara(NoArv* A, int valor);
int Busca(Arv *A, int valor);
NoArv* buscar_no(NoArv *no, int valor);
Arv* Remover(Arv *A, int valor);
NoArv* remover_aux(NoArv *no, int valor);
int SomaPares(NoArv *raiz);


/* IMPLEMENTAÇÃO COMEÇA AQUI */

/* implementação */

Arv* CriaArv(void)
{
    Arv *A = (Arv*) malloc(sizeof(Arv));
    A->raiz = NULL;
    return A;
}

int VaziaArv(Arv *A)
{
    if (A == NULL) return 1; /* considerar vazia se ponteiro inválido */
    return (A->raiz == NULL);
}

NoArv* inserir_no(NoArv *no, int valor)
{
    if (no == NULL)
    {
        NoArv *novo = (NoArv*) malloc(sizeof(NoArv));
        if (novo == NULL)
        {
            fprintf(stderr, "Erro ao alocar nó\n");
            return NULL;
        }
        novo->info = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (valor < no->info)
    {
        no->esq = inserir_no(no->esq, valor);
    }
    else if (valor > no->info)
    {
        no->dir = inserir_no(no->dir, valor);
    }
    else
    {
        /* valor já existe: não insere duplicatas */
    }
    return no;
}

void Inserir(Arv *A, int valor)
{
    if (A == NULL) return;
    A->raiz = inserir_no(A->raiz, valor);
}

void ImprimirInOrder(NoArv *no)
{
    if (no == NULL) return;
    ImprimirInOrder(no->dir);
    printf("%d ", no->info);
    ImprimirInOrder(no->esq);
}

void ImprimirPreOrder(NoArv *no)
{
    if (no == NULL) return;
    printf("%d ", no->info);
    ImprimirPreOrder(no->dir);
    ImprimirPreOrder(no->esq);
}

void ImprimirPosOrder(NoArv *no)
{
    if (no == NULL) return;
    ImprimirPosOrder(no->dir);
    ImprimirPosOrder(no->esq);
    printf("%d ", no->info);
}

int Compara(NoArv* A, int valor)
{
   if (A->info==valor)
   {
       return 1;
   }
   if(valor> A->info)
   {
       if(A->dir!=NULL)
       {
         return Compara(A->dir,valor);
       }
       return 0;
   }
    if(A->esq!=NULL)
    {
        return Compara(A->esq,valor);
    }
       return 0;

}


int Busca(Arv *A, int valor)
{
    NoArv *r = buscar_no(A ? A->raiz : NULL, valor);
    return (r != NULL) ? 1 : 0;
}

NoArv* buscar_no(NoArv *no, int valor)
{
    if (no == NULL) return NULL;
    if (valor == no->info) return no;
    if (valor < no->info) return buscar_no(no->esq, valor);
    return buscar_no(no->dir, valor);
}

void LiberaNos(NoArv *no)
{
    if (no == NULL) return;
    LiberaNos(no->esq);
    LiberaNos(no->dir);
    free(no);
}

void LiberaArv(Arv *A)
{
    if (A == NULL) return;
    LiberaNos(A->raiz);
    free(A);
}


NoArv* remover_aux(NoArv *no, int valor)
{
    if (no == NULL) return NULL;

    if (valor < no->info)
    {
        no->esq = remover_aux(no->esq, valor);
    }
    else if (valor > no->info)
    {
        no->dir = remover_aux(no->dir, valor);
    }
    else
    {
        /* achou o nó a remover */
        if (no->esq == NULL && no->dir == NULL)
        {
            free(no);
            return NULL;
        }
        else if (no->esq == NULL)
        {
            NoArv *temp = no->dir;
            free(no);
            return temp;
        }
        else if (no->dir == NULL)
        {
            NoArv *temp = no->esq;
            free(no);
            return temp;
        }
        else
        {
            /* dois filhos: substituir pelo maior da subárvore esquerda */
            NoArv *pred = maior_no(no->esq);
            no->info = pred->info;
            no->esq = remover_aux(no->esq, pred->info);
        }
    }
    return no;
}

Arv* Remover(Arv *A, int valor)
{
    if (A == NULL) return NULL;
    A->raiz = remover_aux(A->raiz, valor);
    return A;
}

int SomaPares(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;

    int soma = 0;

    if (raiz->info % 2 == 0)
        soma += raiz->info;

    // primeiro direita, depois esquerda
    soma += SomaPares(raiz->dir);
    soma += SomaPares(raiz->esq);

    return soma;
}


#endif /* ARVORE_H_INCLUDED */
