#include <stdlib.h>
#include <stdio.h>
#define chamada 1
int cont = 0,result = 0;
/* Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule kn. Utilize apenas multiplicações. O programa principal
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da função.*/
int multiplicar(int k, int n)
{
    if(cont < chamada)
    {
        result += k * n;
        cont++;
    }
    if(cont == chamada)
    {
        return result;
    }
    return multiplicar(k,n);             
}

int main()
{
    int k = 0,n = 0;
    printf("Digite k e depois n: ");
    scanf("%d%d", &k, &n);
    printf("%d\n", multiplicar(k, n));
}
