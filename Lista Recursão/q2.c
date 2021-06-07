#include <stdlib.h>
#include <stdio.h>

/*Faça uma função recursiva que calcule e retorne o N-�simo termo da sequência
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89... */

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    int n=0,fib1=0 ;
    scanf("%d", &n);
    fib1= fib(n);
    printf("%d\n", fib1);
}
