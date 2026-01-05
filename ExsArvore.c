#include <stdio.h>
#include "ARVORE.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    Arv* A=CriaArv();
    int x,y=0;
    int valor;
    while(1)
    {
        printf("Digite a opção desejada:\n\t1- Insere\n\t2-ImpInORDER\n\t3-ImpPosORDER\n\t4-ImpPreORDER\n\t5-Busca\n\t6-Libera\n\t7-MaiorNO\n\t8-Finaliza\n\t9-ApagaNo\n\n");
        scanf("%d",&x);
        switch (x)
        {
            case 1: 
            printf("Digite o valor desejado: ");
            scanf("%d",&valor);
            Inserir(A,valor);
                break;

            case 2: 
            ImprimirInOrder(A->raiz);
            printf("\n");
                break;

            case 3: 
            ImprimirPreOrder(A->raiz);
            printf("\n");
                break;

            case 4: 
            ImprimirPosOrder(A->raiz);
            printf("\n");
                break;

            case 5:  
            printf("Digite o valor desejado: ");
            scanf("%d", &valor);
            y = Compara(A->raiz, valor);
            printf("Ocorrencia %d encontrado na árvore.\n", y);
            break;

            case 6: 
            LiberaArv(A);
            break;

            case 7: 
            valor=SomaPares(A->raiz);  
            printf("Maior valor da arvore: %d",valor);           
                break;

            case 8: 
                exit(1);    
            break;

           case 9: 
            printf("Digite o valor desejado: ");
            scanf("%d",&valor);
            Remover(A,valor);   
            break;

            default:
                printf("\n\topção inválida");
                break;
        }

    }
return 0;
}