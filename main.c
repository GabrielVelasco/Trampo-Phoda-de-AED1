#include <stdio.h>
#include <stdlib.h>
#include "headers/header.h"
void imprime(Lista l)
{
    int i,n;
    for(i=1; ; i++){
        if(get_elemento(l,i,&n)==0){
            break;
        }
        printf("%d\n",n);
    }
}
int main()
{

    Lista lista,l2;
    int n;
    printf("diga um numero\n");
    scanf("%d",&n);
    lista=cria_lista();
    if(insere_elemento(&lista,n)==1){
        printf("exito\n");


        printf("EXIBINDO\n");
    }
        printf("diga um numero\n");
    scanf("%d",&n);

    if(insere_elemento(&lista,n)==1){
        printf("exito\n");

    }

imprime(lista);
l2=multiplo_de_3(lista);
printf("lista 2\n");
imprime(l2);
    /*

    if(remove_maior_elemento(&lista)==1){
        printf("removido\n");

    }
    if(lista_vazia(lista)==1){
        printf("a lista esta vazia");
    }

    */
    return 0;
}
