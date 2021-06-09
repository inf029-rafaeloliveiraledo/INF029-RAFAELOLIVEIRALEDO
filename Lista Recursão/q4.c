#include <stdlib.h>
#include <stdio.h>
#define TAM 5

// Faça uma função recursiva que permita somar os elementos de um vetor de inteiros

int somaElementos (int *p)
{
    static int cont=0, soma=0;
    if(cont==TAM){
        int retorno = soma;
        cont=0, soma=0;
        return retorno;
    }
    soma+=p[cont];
    cont++;
    return somaElementos(p);
}

int main(){
    int *vet= malloc(TAM*sizeof(int));
    int continuar=1;
    do{
        for(int i = 0; i< TAM; i++){
            printf("Digite o elemento %d: ", i+1);
            printf("\n");
            scanf("%d", &vet[i]);
        }
        int result = 0;
        result = somaElementos(vet);
        printf("%d", result);
        free(vet);
        printf("\nProsseguir/Iniciar/Continuar (1) Sair (0)\n");
        scanf("%d", &continuar);
    }
    while(continuar);
}

