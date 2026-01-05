#include <stdio.h>
#include "FILA.H"

void ParImpar(Fila *f)
{
    Fila *faux=CriaFila();
    Fila *faux2=CriaFila();
    Nos *aux=f->ini;
    while (aux!=NULL)
    {
        if (aux->info%2==0)
        {
            InsereFila(faux,aux->info);
        }
        else
        {
            InsereFila(faux2,aux->info);
        }
        aux=aux->prox;
    }

    imprimeFila(f);
    imprimeFila(faux);
    imprimeFila(faux2);
}

int main()
{
    Fila *f=CriaFila();
    int x,j,i;
    printf("Quantos numeros deseja digitar: ");
    scanf("%d",&j);
    for (i=0;i<j;i++)
    {
        printf("digite: ");
        scanf("%d",&x);
        InsereFila(f,x);
    }
    ParImpar(f);

    return 0;
}
