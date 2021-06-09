#include <stdlib.h>
#include <stdio.h>

/* Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192 */

//int cont1=10,cont2=1,repeticoes=0;

int contar(int n, int k){
    static int cont1=10,cont2=1,repeticoes=0;
    if((n%cont1)/cont2==0){
        int retorno = repeticoes;
        cont1=10,cont2=1;repeticoes=0;
        return retorno;
    }
    if((n%cont1)/cont2==k){
        repeticoes++;
    }
    cont1*=10;
    cont2*=10;
    return contar(n,k);
}
int main(){
    int n=0,k=0;
    printf("Digite um número e outro para checar quantas vezes se repete no primeiro: ");
    scanf("%d%d", &n,&k);
    printf("%d\n", contar(n,k));
}
