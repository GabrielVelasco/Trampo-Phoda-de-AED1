#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void printa_lst(Lista lst){
    int pot, coef, cnt = 1;
    while(1){
        if(get_pos(lst, &pot, &coef, cnt) == 0)
            break;
        if(coef == 0)
            continue;
        if(coef > 0)
            printf("+ ");
        printf("%dx^%d ", coef, pot);
        cnt++;
    }
    printf("\n");
}
int main()
{
    int p, t;
    Lista lst = cria_lista();
    while(1){
        printf("potencia: ");
        scanf("%d", &p);
        printf("coeficiente: ");
        scanf("%d", &t);
        insere_termo(&lst, p, t);
        printa_lst(lst);
    }
    return 0;
}
