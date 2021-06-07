#include <stdlib.h>
#include <stdio.h>
int cont=0,numE=0;;
/*Crie um programa em C que receba um vetor de números reais com 100 elementos.
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor. */
float inverte(float *vet)
{
    if(cont==0)
    {
        printf("%.2f", vet[cont]);
        return 0;
    }
    printf("%.2f ", vet[cont]);
    cont--;
    return inverte(vet);
}
int main()
{
    float vet[100];
    printf("Digite quantos elementos vai preencher: "); 
    scanf("%d", &numE);
    cont = numE - 1;
    for(int i=0; i<numE; i++)
    {
        scanf("%f", &vet[i]);
    }
    inverte(vet);
    free(vet);
}   
