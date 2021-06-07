#include <stdlib.h>
#include <stdio.h>
// Façaa uma função recursiva que calcule e retorne o fatorial de um número inteiro N
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
    scanf("%d", &n);
    fat1= fat(n);
    printf("%d\n", fat1);
    return 0;
}
