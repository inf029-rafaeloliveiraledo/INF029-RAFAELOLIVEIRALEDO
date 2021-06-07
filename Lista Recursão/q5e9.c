#include <stdlib.h>
#include <stdio.h>
int soma=0;
/*Crie uma função recursiva que receba um número inteiro positivo N e calcule o
somatório dos números de 1 a N. */

int somatorio(int n){
    if(n==1){
        return soma+=n;
    }
    soma+=n;
    somatorio(n-1);
}

int main(){
    int n=0;
    wprintf(L"Digite um número: ");
    scanf("%d", &n);
    printf("%d\n", somatorio(n));
}
