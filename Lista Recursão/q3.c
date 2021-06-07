#include <stdlib.h>
#include <stdio.h>
//Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321
int cont1=10,cont2=1;
int inverter(int n)
{
    if((n%cont1)/cont2==0)
    {
        return 1;
    }
    printf("%d", (n%cont1)/cont2);
    cont1*=10;
    cont2*=10;
    return inverter(n); 
}
int main()
{
    int n=0;
    printf("Digite um número: ");
    scanf("%d", &n);
    inverter(n);
}
