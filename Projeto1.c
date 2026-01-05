#include <stdio.h>
#include "FILA.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void Inserir(Fila* f, int valor, int valor2)
{
    int idade1;
    char nome1[MAX_NOME];
    char espec1[MAX_ESP];
    int dia,mes,ano;
    printf("Digite o Nome de seu Pet: ");
    scanf("%s",nome1);
    printf("Digite a especie de seu Pet: ");
    scanf("%s",espec1);
    printf("Digite a idade de seu Pet: ");
    scanf("%d",&idade1);
    printf("Digite o dia do nascimento de seu Pet: ");
    scanf("%d",&dia);
    printf("Digite o mes de nascimento de seu Pet: ");
    scanf("%d",&mes);
    printf("Digite o ano de nascimento de seu Pet: ");
    scanf("%d",&ano);

    InsereFila(f,valor,nome1,espec1,idade1,valor2,dia,mes,ano);
}

void ProcuraPet(Fila*f,Fila*f1,Fila *f2)
{
    Nos* aux=f->ini;
    Nos* aux2=f1->ini;
    Nos* aux3=f2->ini;
    int x,y,k;
    char nome[MAX_NOME];
    printf("Deseja procurar seu Pet pelo Nome ou ID(digite 0 para nome ou 1 para ID):  ");
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
            printf("prioridade: %d (0-Emergencial / 1-Consulta Padrao- ",aux->info->prioridade);
            printf("dia: %d -",aux->info->aniversario->dia);
            printf("mes: %d  -",aux->info->aniversario->mes);
            printf("ano: %d  \n",aux->info->aniversario->ano);
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
            printf("prioridade: %d (0-Emergencial / 1-Consulta Padrao- ",aux2->info->prioridade);
            printf("dia: %d -",aux2->info->aniversario->dia);
            printf("mes: %d  -",aux2->info->aniversario->mes);
            printf("ano: %d  \n",aux2->info->aniversario->ano);
            }
            aux2=aux2->prox;
        }
        while(aux3!=NULL)
        {
            if(aux3->info->id==y)
            {
            printf("Encontrado na Fila de Atendidos: \n");
            printf("%d - ",aux3->info->id);
            printf("%s - ",aux3->info->nome);
            printf("%s - ",aux3->info->espec);
            printf("%d  ",aux3->info->idade);
            printf("prioridade: %d (0-Emergencial / 1-Consulta Padrao- ",aux3->info->prioridade);
            printf("dia: %d -",aux3->info->aniversario->dia);
            printf("mes: %d  -",aux3->info->aniversario->mes);
            printf("ano: %d  \n",aux3->info->aniversario->ano);
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
            k=strcmp(aux->info->nome,nome);
            if(k==0)
            {
            printf("Encontrado na Fila de Atendimento Emergencial: \n");
            printf("%d - ",aux->info->id);
            printf("%s - ",aux->info->nome);
            printf("%s - ",aux->info->espec);
            printf("%d  ",aux->info->idade);
            printf("prioridade: %d (0-Emergencial / 1-Consulta Padrao- ",aux->info->prioridade);
            printf("dia: %d -",aux->info->aniversario->dia);
            printf("mes: %d  -",aux->info->aniversario->mes);
            printf("ano: %d  \n",aux->info->aniversario->ano);
            }
            aux=aux->prox;
        }
        while(aux2!=NULL)
        {
            k=strcmp(aux2->info->nome,nome);
            if(k==0)
            {
            printf("Encontrado na Fila de Atendimento Padrao: \n");
            printf("%d - ",aux2->info->id);
            printf("%s - ",aux2->info->nome);
            printf("%s - ",aux2->info->espec);
            printf("%d  ",aux2->info->idade);
            printf("prioridade: %d (0-Emergencial / 1-Consulta Padrao- ",aux2->info->prioridade);
            printf("dia: %d -",aux2->info->aniversario->dia);
            printf("mes: %d  -",aux2->info->aniversario->mes);
            printf("ano: %d  \n",aux2->info->aniversario->ano);
            }
            aux2=aux2->prox;
        }
        while(aux3!=NULL)
        {
            k=strcmp(aux3->info->nome,nome);
            if(k==0)
            {
            printf("Encontrado na Fila de Atendidos: \n");
            printf("%d - ",aux3->info->id);
            printf("%s - ",aux3->info->nome);
            printf("%s - ",aux3->info->espec);
            printf("%d  ",aux3->info->idade);
            printf("prioridade: %d (0-Emergencial / 1-Consulta Padrao- ",aux3->info->prioridade);
            printf("dia: %d -",aux3->info->aniversario->dia);
            printf("mes: %d  -",aux3->info->aniversario->mes);
            printf("ano: %d  \n",aux3->info->aniversario->ano);
            }
            aux3=aux3->prox;
        }
    }

}

int main ()
{
    int x,id=0,n;
    int prio1=1;
    int prio0=0;
    Pet *animais = NULL;
    Fila *fn=CriaFila();
    Fila *feme=CriaFila();
    Fila *flix=CriaFila();

    printf("Bem Vindo ao Veterinario\n");
    while(1)
    {
        printf("\nEscolha uma opcao de Atendimento ou Funcionalidade:\n0-Emergencia \n1-Consulta Padrao \n2-Atender Pet \n3-Buscar Pet \n4-Imprimir todos os Pets registrados \n5-Imprimir Prox Pet \n6-Imprimir Pets Atend \n7-Finalizar o Sistema\n");
        scanf("%d",&x);
        switch (x)
        {
            case 0:  //Emergencia
               id=CodigoID(feme);
               Inserir(feme,id,prio0);
               imprime1termoFila(feme);
               printf("\n");
               system("pause");
               system("cls");
                break;

            case 1:  //Atendimento Padrao
               id=CodigoID(fn);
               Inserir(fn,id,prio1);
               imprime1termoFila(fn);
               printf("\n");
               system("pause");
               system("cls");
                break;

            case 2:  //Atender Pet
                if (!VaziaFila(feme))
                {
                    RetiraFila(feme,flix);
                    printf("Paciente de Emergencia Atendido");
                    imprime1termoFila(flix);
                }
                else
                {
                    RetiraFila(fn,flix);
                    printf("Paciente de Consulta Padrao Atendido");
                    imprime1termoFila(flix);
                }
                  printf("\n");
                  system("pause");
                  system("cls");
                break;

            case 3:  //Buscar Pet
                ProcuraPet(feme,fn,flix);
                printf("\n");
                system("pause");
                system("cls");
                break;

            case 4:  //Imprimir todos os Pets Registrados
                printf("Fila de Emergencia: \n");
                imprimeFila(feme);
                printf("Fila de Atendimento Padrao: \n");
                imprimeFila(fn);
                printf("\n");
                system("pause");
                system("cls");
                break;

            case 5:  //Imprimir Prox Pet
            if (!VaziaFila(feme)) // se houver f�mea
            {
                imprime1termoFilaIni(feme);
            }
            else if (!VaziaFila(fn)) // se n�o houver f�mea mas houver macho
            {
                imprime1termoFilaIni(fn);
            }
            else // se ambas estiverem vazias
            {
                printf("Nenhum paciente a ser atendido.\n");
            }
                printf("\n");
                system("pause");
                system("cls");
            break;

            case 6:  //Imprimir Pets Atendidos
                printf("Fila de Atendidos: \n");
                imprimeFila(flix);
                printf("\n");
                system("pause");
                system("cls");
                break;

            case 7: //Finaliza Programa
                exit(1);
                break;


            default:
                printf("\n\topcao invalida");
                break;
        }

    }
return 0;
    }
