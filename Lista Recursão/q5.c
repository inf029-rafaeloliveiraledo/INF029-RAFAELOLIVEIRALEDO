#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
//Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321
int cont1=10,cont2=1, result=0;
int somatorio(int n)
{
    if((n%cont1)/cont2==0)
    {
        return result;
    }
    result+=(n%cont1)/cont2;
    cont1*=10;
    cont2*=10;
    return somatorio(n); 
}
int main()
{
    int n=0;
    setlocale(LC_ALL,"Portuguese");
    wprintf(L"Digite um número: ");
    scanf("%d", &n);
    int soma=0;
    soma = somatorio(n);
    printf("%d\n", soma);
}
