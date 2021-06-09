#include <stdlib.h>
#include <stdio.h>
// Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N
int fat(int n)
{
    if(n==2)
    {
        return 2;
    }
    return n*fat(n-1);  
}

int main()
{
    int n=0, fat1=0;
    printf("Digite um número para se calcular o fatorial: ");
    scanf("%d", &n);
    printf("%d\n", fat(n));
    return 0;
}
