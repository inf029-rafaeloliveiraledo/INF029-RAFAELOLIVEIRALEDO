#include <stdlib.h>
#include <stdio.h>
#define TAM 5
int cont=0;
int soma=0;
// Faça uma função recursiva que permita somar os elementos de um vetor de inteiros
int somaElementos (int *p)
{
    if(cont==TAM){
        return soma;
    }
    soma+=p[cont];
    cont++;
    return somaElementos(p);
}

int main()
{
    int *vet= malloc(TAM*sizeof(int));
    for(int i = 0; i< TAM; i++)
    {
        scanf("%d", &vet[i]);
    }
    int result = 0;
    result = somaElementos(vet);
    printf("%d", result);
    free(vet);
}
