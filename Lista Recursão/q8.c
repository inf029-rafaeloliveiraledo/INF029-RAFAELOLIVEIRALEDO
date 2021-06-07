#include <stdlib.h> 
#include <stdio.h>
#include <locale.h>
int divisor=2, mdc=1, cont=0;
/* O máximo divisor comum dos inteiros x e y é o maior inteiro que divide x e y. Escreva uma função recursiva mdc em C, que retorna o máximo divisor comum de x
e y. O mdc de x e y é definido como segue: se y é igual a 0, então mdc(x,y) é x; caso contrário, mdc(x,y) é mdc (y, x%y), onde % é o operador resto. */

int mdc1(int n, int num)
{
    if((n>1 && num>1) && (divisor<num && divisor <n))
    {
        if(n%divisor==0 && num%divisor==0)
        {
            mdc*=divisor;
            cont++;
            n/=divisor;
            num/=divisor;
        }
        else
        {
            divisor++;
        }
    }
    else
    {
        return mdc;
    }
    mdc1(n,num);
    if(cont==0)
    {
        return 1;
    }
}
int main()
{
    int n,n1;
    setlocale(LC_ALL,"Portuguese");
    printf("Digite n e n1: ");
    scanf("%d%d", &n,&n1);
    wprintf(L"Máximo Divisor Comum: %d\n", mdc1(n,n1));
}
