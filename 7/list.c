// ex4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node{
	char nome[20];
	struct node* next;

};

// int alloc_check(const void* tmp){
// 	if(tmp == NULL){
// 		printf("Erro na alocacao!\n");
// 		exit()
// 	}
// }

List _cria_lista(){ return NULL; }

int _lista_vazia(List lst){
	// lista vazia so tem cabecalho
	if(lst == NULL)
		return 1;
	else
		return 0;	
}

// int _qntd_sold(List lst){	return lst->next->qnt_soldados; }

int _insere_soldado(List* lst, char nome_sld[]){
	// insere soldado no final
	List node = (List) malloc(sizeof(struct node));
	if(node == NULL) return 0;

	strcpy(node->nome, nome_sld);
	if(_lista_vazia(*lst))
		node->next = node; // node aponta para cabecalho	

	else{
		node->next = (*lst)->next; // aponta para o primeiro node
		(*lst)->next = node; // add node no final
	}

	*lst = node; // ponteiro para o ultimo node
	return 1;
}

void _remove_cur_next(List cur){
	List tmp = cur->next;
	cur->next = tmp->next;
	free(tmp);
}

void _contador_elimina(List* lst, List cur, int s, int opc, char rem[]){
	if(cur->next == cur){
		printf("[%s] VAI SOBREVIVER!\n", cur->nome);
		return;
	}

	if(opc > 0){
		// fica um node antras do node que sera usado para
		// iniciar a contagem
		while(opc--)
			cur = cur->next;
	}
	int i = 0;
	while(i < (s-1)){
		cur = cur->next;
		i ++;
	}
	// cur == um node antes do que eu quero remover
	strcpy(rem, cur->next->nome);
	if(cur->next == *lst) *lst = cur; // se o node a ser removido for o ultimo
	_remove_cur_next(cur);
	printf("Soldado [%s] eliminado!\n", rem);
	_contador_elimina(lst, cur, s, opc, rem);
}

void _printa_lista(List lst){
	List ult = lst;
	while(lst->next != ult){
		printf("[%s] ", lst->next->nome);
		lst = lst->next;
	}
	printf("[%s] \n", ult->nome);
}