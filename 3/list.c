// ex3
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node{
	float info;
	List next;

};

List createList(){
	return NULL;
}

int emptyList(List lst){
	// verifica se E o primeiro node
	if(lst == NULL)
		return 1; // lista vazia
	else
		return 0;
}

int insertOrd(List *lst, float elem){
	// *lst == end memo do ponteiro p/ primeiro node
	// primeiro cria o node a ser inserido e atribui os valores

	List node = (List) malloc(sizeof(struct node));
	if(node == NULL) return 0; // node nao alocado por falta de memoria
	node->info = elem;

	if(emptyList(*lst) || elem <= (*lst)->info){
		node->next = *lst; // atual primeiro node passa a ser o segundo
		*lst = node; // node passa a ser o novo primeiro

		return 1;
	}

	// percorrer para encontrar pos correta
	List tmp = *lst;
	while(tmp->next != NULL && tmp->next->info < elem)
		tmp = tmp->next;

	node->next = tmp->next;
	tmp->next = node;

	return 1;
}

int removeOrd(List *lst, float elem){
	if(emptyList(*lst) || elem < (*lst)->info) return 0;
	List tmp = *lst; // tmp = atual peimeiro node

	// verf se o primeiro elem da lista é o alvo
	if( (*lst)->info == elem ){
		*lst = tmp->next; // primeiro node passa a ser o atual segundo
		free(tmp); // deleta node que era o primeiro
		return 1;
	}

	// elem pode estar mais a direita, percorrer
	while(tmp->next != NULL && tmp->next->info < elem)
		tmp = tmp->next; // avanca para proximo node

	if(tmp->next == NULL || tmp->next->info > elem) 
		return 0; // chegou no final da lista ou nao achou elem
	// cara que vem A DIREITA do node TMP vou remover
	List tmp2 = tmp->next; // tmp2 = node a ser removido
	tmp->next = tmp2->next;
	free(tmp2);

	return 1;
}

int getSize(List lst){
	if(emptyList(lst)) return 0;

	int size = 1; // se n esta vazia ja tem pelo menos um node
	while(lst->next != NULL){
		lst = lst->next;
		size ++;
	}

	return size;
}

int getElem(List lst, int idx, float *num){
	// retorna o conteudo do node dado o indice (posicao do node) a partir do 0
	if(idx >= getSize(lst)) return 0; // fora da lista

	while(idx --)
		lst = lst->next;

	// tmp == node a ser retornado
	*num = lst->info;
	return 1;
}

void imprimiLista(List lst){
	// trata 1° node separado
	printf("[%.2f] ", lst->info);
	while( lst->next != NULL ){
		lst = lst->next;
		printf("[%.2f] ", lst->info);
	}
}

int comparaLista(List L, List L2){
	if( emptyList(L) || emptyList(L2) ) return 0;
	if( getSize(L) != getSize(L2) ) return 0;

	List tmpL = L;
	int cont = 0;
	if( L->info == L2->info ) 
		cont ++;
	else 
		return 0;

	while( (L->next != NULL) && (L->next->info == L2->next->info) ){

		L = L->next;
		L2 = L2->next;
		cont ++;
	}

	if( cont == getSize(tmpL) ) return 1;
	else return 0;
}

void inserePos(List *node, float elem){
	// node == ultimo node da l3
	List newNode = (List) malloc(sizeof(struct node));
	if(newNode == NULL) exit(1);

	newNode->info = elem;
	newNode->next = NULL;
	if(*node != NULL)
		(*node)->next = newNode;
	*node = newNode;
}

void intercalar(List l1, List l2, List *l3){
	if( emptyList(l1) && emptyList(l2) ){
		printf("Listas vazias!\n");
		return;
	}
	if( !emptyList(*l3) && clearList(l3) )
		printf("Limpando lista 3 e intercalando...\n");

	int ch = 1;
	List tmp3 = *l3; 
	// neste momento tmp3 e l3 aponta para null (l3 vazia)
	// porem o objetivo e tmp3 eh apontar para o ultimo node da l3
	// para nao ter que percorrer toda l3 ate o final quando for add um novo node
	// ch serve para fazer l3 apontar para o primeiro node da l3 para n perder a lista
	// se l1 == vazia, l3 = l2 ou l2 == vazia, l3 = l1
	if( emptyList(l1) ){
		while( l2 != NULL ){
			inserePos(&tmp3, l2->info);
			l2 = l2->next;
			if(ch){
				*l3 = tmp3; // tmp3 eh o unico node em l3
				ch = 0;
			}
		}
		return;

	}else if( emptyList(l2) ){
		while( l1 != NULL ){
			inserePos(&tmp3, l1->info);
			l1 = l1->next;
			if(ch){
				*l3 = tmp3;
				ch = 0;
			}
		}
		return;
	}
	// ch tem objetivo de verificar se estou adc o primeiro node em l3
	// se sim, l3 aponta para o 
	// se chegou ate aqui l1 e l2 tem pelo menos um node
	while( (l1 != NULL) && (l2 != NULL) ){
		if( l1->info <= l2->info ){
			inserePos(&tmp3, l1->info);
			l1 = l1->next;
			if(ch){
				*l3 = tmp3;
				ch = 0;
			}

		}else{
			// l1->info > l2->info
			inserePos(&tmp3, l2->info);
			l2 = l2->next;
			if(ch){
				*l3 = tmp3;
				ch = 0;
			}
		}
	}

	// se sobrar elementos na l1 ou l2
	while(l1 != NULL){
		inserePos(&tmp3, l1->info);
		l1 = l1->next;
	}
	while(l2 != NULL){
		inserePos(&tmp3, l2->info);
		l2 = l2->next;
	}
}

int clearList(List *lst){
	if(emptyList(*lst)) return 0;

	// Limpar node por node
	List tmp;
	while(*lst != NULL){
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}

	return 1;
}

// void intercalar(List L, List L2, List *L3){
// 	// L3 contem elemento, logo tenho que limpar antes de intercalar
// 	if( !emptyList(*L3) && clearList(L3) )
// 		printf("Lista 3 limpa, intercalando...\n");
	
// 	// primeiro copiar L para L3
// 	// trata primeiro node separado, se L tiver pelo menos 1 node
// 	int a;
// 	if( !emptyList(L) && insertOrd(L3, L->info) ){
// 		while( L->next != NULL ){
// 			L = L->next;
// 			a = insertOrd(L3, L->info);
// 		}
// 	}

// 	if( emptyList(L2) ) return; // L3 == L pois L2 esta vazia
// 	a = insertOrd(L3, L2->info); // trata primeiro node
// 	while( L2->next != NULL ){
// 		L2 = L2->next;
// 		a = insertOrd(L3, L2->info);
// 	}
// }