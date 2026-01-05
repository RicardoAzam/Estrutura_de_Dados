#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* FUNÇÕES DE MANIPULAÇÃO DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA ESTÁ VAZIA RETORNA 1 QUANDO ESTÁ VAZIA

void InsereFila (Fila* f, int v) INSERÇÃO

int RetiraFila (Fila* f) REMOÇÃO

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/

#define MAX_NOME 50
#define MAX_ESP 30

typedef struct DATA
{
    int dia,mes,ano;
}data;

typedef struct PETS
{
    int id;
    char nome[MAX_NOME];
    char espec[MAX_ESP];
    int idade;
    int prioridade;
    data* aniversario;
} Pet;
typedef struct nos
{
    Pet* info;
    struct nos *prox;
}Nos;

typedef struct fila
{
    Nos * ini;
    Nos * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

Nos* ins_fim (Nos *fim, int A, char nomem[], char espe[], int idad, int priori,int dia1,int mes1, int ano1)
{
    Nos* p = (Nos*) malloc(sizeof(Nos));
    p->info = (Pet*)malloc(sizeof(Pet));
    p->info->aniversario=(data*)malloc(sizeof(data));

    p->info->id = A;
    strcpy(p->info->nome, nomem);
    strcpy(p->info->espec, espe);
    p->info->idade = idad;
    p->info->prioridade = priori;
    p->info->aniversario->dia=dia1;
    p->info->aniversario->mes=mes1;
    p->info->aniversario->ano=ano1;

    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int v, char nome[], char especie[], int idade, int priorid,int diao, int meso, int anoo)
{
    f->fim = ins_fim(f->fim,v, nome, especie, idade, priorid, diao, meso, anoo);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}


Nos* retira_ini (Nos* ini)
{
    Nos* p = ini->prox;
    free(ini);
    return p;
}

void RetiraFila (Fila* f,Fila* f1)
{
    int id, idade,dia,mes,ano, prior;
    char nome[MAX_NOME];
    char esp[MAX_ESP];
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    id = f->ini->info->id;
    idade=f->ini->info->idade;
    prior=f->ini->info->prioridade;
    dia= f->ini->info->aniversario->dia;
    mes= f->ini->info->aniversario->mes;
    ano= f->ini->info->aniversario->ano;
    strcpy(nome,f->ini->info->nome);
    strcpy(esp,f->ini->info->espec);
    InsereFila(f1, id,nome,esp,idade,prior, dia,mes,ano);

    f->ini = retira_ini(f->ini);
    if (f->ini == NULL)
    {/* fila ficou vazia? */
    f->fim = NULL;
    }
    f->fim = NULL;

    //return f1;
}

void imprimeFila (Fila* f)
{
    Nos* q;
    printf("\n\t");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("%d - ",q->info->id);
        printf("%s - ",q->info->nome);
        printf("%s - ",q->info->espec);
        printf("%d - ",q->info->idade);
        printf("prioridade:%d  (0-Emergencial / 1-Consulta Padrao - ",q->info->prioridade);
        printf("dia: %d -",q->info->aniversario->dia);
        printf("mes: %d  -",q->info->aniversario->mes);
        printf("ano: %d  ",q->info->aniversario->ano);
        printf("\n\t");
    }
    printf("\n");
}

void imprime1termoFila (Fila* f)
{
    Nos* q;
    printf("\n\t");
    q=f->fim;
        printf("%d - ",q->info->id);
        printf("%s - ",q->info->nome);
        printf("%s - ",q->info->espec);
        printf("%d  ",q->info->idade);
        printf("prioridade:%d  (0-Emergencial / 1-Consulta Padrao - ",q->info->prioridade);
        printf("dia: %d -",q->info->aniversario->dia);
        printf("mes: %d  -",q->info->aniversario->mes);
        printf("ano: %d  ",q->info->aniversario->ano);
}

void imprime1termoFilaIni (Fila* f)
{
    Nos* q;
    printf("\n\t");
    q=f->ini;
        printf("%d - ",q->info->id);
        printf("%s - ",q->info->nome);
        printf("%s - ",q->info->espec);
        printf("%d  ",q->info->idade);
        printf("prioridade:%d  (0-Emergencial / 1-Consulta Padrao - ",q->info->prioridade);
        printf("dia: %d -",q->info->aniversario->dia);
        printf("mes: %d  -",q->info->aniversario->mes);
        printf("ano: %d  ",q->info->aniversario->ano);
}

Fila* liberaFila (Fila* f)
{
    Nos* q = f->ini;
    while (q!=NULL)
    {
        Nos* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

int comparaFila(Fila* f, int valor)
{
    Nos* aux=f->ini;
    if(aux==NULL)
    {
        return 1;
    }
    while(aux!=NULL)
    {
        if(aux->info->id==valor)
        {
            return 0;
        }
        aux=aux->prox;
    }
    return 1;
}

int CodigoID(Fila *F)
{
    int x=0;
    int min = 100;
    int max = 999;
    int numero_aleatorio;

    srand(time(NULL));
    while(x=0)
    {
    numero_aleatorio = (rand() % (max - min + 1)) + min;

    x=comparaFila(F,numero_aleatorio);
    }

return numero_aleatorio;
}

/*
void ProcuraPet(Fila*f,Fila*f1,Fila *f2)
{
    Nos* aux=f->ini;
    Nos* aux2=f1->ini;
    Nos* aux3=f2->ini;
    int x,y;
    char nome[MAX_NOME];
    printf("Deseja procurar seu Pet pelo Nome ou ID(digite 1 para nome ou 0 para ID):  ");
    scanf("%d",&x);

    if(x==1)
    {
        printf("Digite o ID: ");
        scanf("%d",&y);
        while(aux!=NULL)
        {
            if(aux->info->id==y)
            {
            printf("Encontrado na Fila de Atendimento Emergencial: \n");
            printf("%d - ",aux->info->id);
            printf("%s - ",aux->info->nome);
            printf("%s - ",aux->info->espec);
            printf("%d  ",aux->info->idade);
            printf("dia: %d -",aux->info->aniversario->dia);
            printf("mes: %d  -",aux->info->aniversario->mes);
            printf("ano: %d  ",aux->info->aniversario->ano);
            }
            aux=aux->prox;
        }
        while(aux2!=NULL)
        {
            if(aux2->info->id==y)
            {
            printf("Encontrado na Fila de Atendimento Padrao: \n");
            printf("%d - ",aux2->info->id);
            printf("%s - ",aux2->info->nome);
            printf("%s - ",aux2->info->espec);
            printf("%d  ",aux2->info->idade);
            printf("dia: %d -",aux2->info->aniversario->dia);
            printf("mes: %d  -",aux2->info->aniversario->mes);
            printf("ano: %d  ",aux2->info->aniversario->ano);
            }
            aux2=aux2->prox;
        }
        while(aux3!=NULL)
        {
            if(aux3->info->id==y)
            {
            printf("Encontrado na Fila de Atendimentos: \n");
            printf("%d - ",aux3->info->id);
            printf("%s - ",aux3->info->nome);
            printf("%s - ",aux3->info->espec);
            printf("%d  ",aux3->info->idade);
            printf("dia: %d -",aux3->info->aniversario->dia);
            printf("mes: %d  -",aux3->info->aniversario->mes);
            printf("ano: %d  ",aux3->info->aniversario->ano);
            }
            aux3=aux3->prox;
        }
    }
    if(x==0)
    {
        printf("Digite o Nome de seu pet: ");
        scanf("%s",nome);
        while(aux!=NULL)
        {
            if(aux->info->nome==nome)
            {
            printf("Encontrado na Fila de Atendimento Emergencial: \n");
            printf("%d - ",aux->info->id);
            printf("%s - ",aux->info->nome);
            printf("%s - ",aux->info->espec);
            printf("%d  ",aux->info->idade);
            printf("dia: %d -",aux->info->aniversario->dia);
            printf("mes: %d  -",aux->info->aniversario->mes);
            printf("ano: %d  ",aux->info->aniversario->ano);
            }
            aux=aux->prox;
        }
        while(aux2!=NULL)
        {
            if(aux2->info->nome==nome)
            {
            printf("Encontrado na Fila de Atendimento Padrao: \n");
            printf("%d - ",aux2->info->id);
            printf("%s - ",aux2->info->nome);
            printf("%s - ",aux2->info->espec);
            printf("%d  ",aux2->info->idade);
            printf("dia: %d -",aux2->info->aniversario->dia);
            printf("mes: %d  -",aux2->info->aniversario->mes);
            printf("ano: %d  ",aux2->info->aniversario->ano);
            }
            aux2=aux2->prox;
        }
        while(aux3!=NULL)
        {
            if(aux3->info->nome==nome)
            {
            printf("Encontrado na Fila de Atendimentos: \n");
            printf("%d - ",aux3->info->id);
            printf("%s - ",aux3->info->nome);
            printf("%s - ",aux3->info->espec);
            printf("%d  ",aux3->info->idade);
            printf("dia: %d -",aux3->info->aniversario->dia);
            printf("mes: %d  -",aux3->info->aniversario->mes);
            printf("ano: %d  ",aux3->info->aniversario->ano);
            }
            aux3=aux3->prox;
        }

}*/

#endif // FILA_H_INCLUDED
