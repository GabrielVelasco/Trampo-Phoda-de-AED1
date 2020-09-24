/*
	ex7
	Sera usado encadeamento circular pois posso adicionar soldados no final da lista sem
	precisar percorre-la e fica mais facil de dar "voltas" na lista
	nome dos soldados e lido ate EOF
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

int main(){
	char nome_sld[20];
	int pos, s, randon_pos = 0, qntd_sold = 0, ch = 0;
	List lst_soldados = _cria_lista();
	// lst aponta para o ultimo node(soldado)
	// entrada dos nomes
	// a cada node aloca um node
	printf("Digite os nomes dos soldados cercados:\n");
	while(scanf("%s", nome_sld) != EOF){
		if(_insere_soldado(&lst_soldados, nome_sld)){
			printf("Soldado inserido com sucesso!\n");
			qntd_sold ++;
		}else
			printf("Erro ao inserir soldado na lista\n");
	}

	printf("\nLista de soldados em volta da fogueira a beira da morte:\n");
	if(_lista_vazia(lst_soldados)){
		printf("Nenhum, todos ja morreram! RIP\n");
		exit(0);
	}else
		_printa_lista(lst_soldados);

	printf("\n\n");
	printf("1 - Iniciar contagem a partir do primeiro soldado da lista.\n");
	printf("2 - Iniciar contagem a partir de uma posição sorteada aleatoriamente da lista.\n");
	printf("3 - Iniciar contagem a partir de um soldado específico.\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &pos); getchar();
	srand(time(0));
	s = (rand()%100) + 1;

	switch(pos){
		case 1:
			if(_lista_vazia(lst_soldados)) 
				printf("Lista vazia!\n");
			else{
				printf("\nContar [%d] soldado(s) a partir do primeiro(inclusive)\n", s);
				_contador_elimina(&lst_soldados, lst_soldados, s, randon_pos, nome_sld);
				ch = 1;
			}
			break;

		case 2:
			// sorteia um numero de 0 a [qntd_sold-1] == indice do soldado no qual sera
			// iniciado a contagem
			if(_lista_vazia(lst_soldados))
				printf("Lista vazia!\n");
			else{
				randon_pos = rand()%qntd_sold;
				_get_elem(lst_soldados, randon_pos, qntd_sold-1, nome_sld); // pega nome do soldado sorteado
				printf("\nContar [%d] soldado(s) a partir do soldado [%s]\n", s, nome_sld);
				_contador_elimina(&lst_soldados, lst_soldados, s, randon_pos, nome_sld);
				ch = 1;
			}
			break;

		case 3:
			if(_lista_vazia(lst_soldados))
				printf("Lista vazia!\n");
			else{
				printf("Digite o nome do soldado onde sera iniciada a contagem: ");
				scanf("%s", nome_sld);
				randon_pos = _busca_nome(lst_soldados, nome_sld, qntd_sold-1);
				if(randon_pos != -1){
					printf("\nContar [%d] soldado(s) a partir do soldado [%s]\n", s, nome_sld);
					_contador_elimina(&lst_soldados, lst_soldados, s, randon_pos, nome_sld);
					ch = 1;
				}else
					printf("Soldado [%s] nao existe\n", nome_sld);
			}
			break;

		default:
			printf("Opcao invalida!\n");
			_limpa_lista(&lst_soldados);

	}
	if(ch){
		_printa_lista(lst_soldados); // unico soldado restante
		printf(" VAI SOBREVIVER!\n");
		_limpa_lista(&lst_soldados);
		
		if(_lista_vazia(lst_soldados))
			printf("Lista limpa, saindo...\n");
	}

	return 0;
}