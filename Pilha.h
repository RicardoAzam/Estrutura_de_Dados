#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdlib.h>

/* FUN ES DE MANIPULA O DE PILHA�� ��
Pilha* CriaPilha () CRIA A PILHA
No* ins (No* t, int a) AUXILIAR DA INSER O��
void push (Pilha* p, int v) INSER O��
No* ret_ini (No* l) AUXILIAR DA REMO O��
int pop (Pilha* p) REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO
int vaziaPilha(Pilha *p) VERIFICA SE A PILHA EST VAZIA, RETORNA 1�
void imprime (Pilha *p)
No* LiberaPilha (Pilha *p)
*/
typedef struct no
{
int info;
struct no *prox;
}No;
typedef struct pilha
{
No *Topo;
}Pilha;

Pilha* CriaPilha (void)
{
Pilha *p;
p=(Pilha*)malloc(sizeof(Pilha));
p->Topo = NULL;
return p;
}

No* ins_ini (No* t, int a)
{
No* aux = (No*) malloc(sizeof(No));
aux->info = a;
aux->prox = t;
return aux;
}

void push (Pilha* p, int v)
{
p->Topo = ins_ini(p->Topo,v);
}

No* ret_ini (No* aux)
{
No* p = aux->prox;
free(aux);
return p;
}
int pop (Pilha *p)
{
No* aux=p->Topo;
int v;
if (aux==NULL)
{
printf("\n\n\t==> Pilha VAZIA, IMPOSSIVEL CONTINUAR.\b\n");
exit(1); /* aborta programa */
}
v = p->Topo->info;
p->Topo = ret_ini(p->Topo);
return v;
}

No* LiberaPilha(Pilha *p)
{
    No* aux;
    while(p->Topo!=NULL)
    {
        aux=p->Topo->prox;
        free(p->Topo);
        p->Topo=aux;
    }
    free(p);
}

void imprime(Pilha *p)
{
    No*aux=p->Topo;
    while(aux!=NULL)
    {
        printf("\n\t%d",aux->info);
        aux=aux->prox;
    }
}

#endif // PILHA_H_INCLUDED
