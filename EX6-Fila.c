#include <stdio.h>
#include "FILA.h"

void ParImpar(Fila *f)
{
    Fila *faux=CriaFila();
    Fila *faux2=CriaFila();
    int x;
    while(!VaziaFila(f))
    {
        x=RetiraFila(f);
        if(x%2==0)
        {
            InsereFila(faux,x);
        }
        else{
            InsereFila(faux2,x);
        }
    }
    imprimeFila(faux2);
    imprimeFila(faux);
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
